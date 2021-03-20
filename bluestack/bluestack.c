#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <errno.h>
#define FREE(x)		if (NULL != x) {\
                                free(x);\
                                x = NULL;\
			}
#define	 ELF_FORMAT	0x7F454C46
#define  ELF_OFFSET	0x00
#define  ARCH_OFFSET	0x12
#define	 ARBITS_OFST	0x04
/*
 * https://en.wikipedia.org/wiki/Executable_and_Linkable_Format
 */
enum arch {
	NOARH=0x00,
	SPARC=0x02,
	X86=0x03,
	MIPS=0x08,
	POWERPC=0x14,
	S390=0x16,
	ARM=0x28,
	SUPERH=0x2A,
	IA64=0x32,
	AMD64=0x3E,
	AARCH64=0xB7,
	RISCV=0xF3
};

enum arch_bits {
	ARCH32=0x01,
	ARCH64=0x02
};

char **library_list = NULL;

int read_file_header (const char *name, unsigned char **header,
	       		int size, unsigned char offset)
{
	FILE *file;
	//printf("Calling: %s()\n", __func__);

	if((file = fopen(name, "rb"))==NULL) {
		printf("%s\n", name);
		perror("Error: ");
		exit(1);
	}

	fseek(file, offset, SEEK_SET);
	*header = (unsigned char *) malloc(size * sizeof(unsigned char));
	if (NULL == *header) {
		perror("Malloc:");
		exit(1);
	}
	fread(*header, sizeof(char), size, file);

	fclose(file);

	return 0;
}

int store_lib_names (int lib_count, char *path) {
	int len = 0;
	len = strlen(path);

	if (lib_count == 1) {
		library_list = (char **) malloc(lib_count * sizeof(char *));
		if (NULL == library_list) {
			printf("Failed to allocate library-list\n");
			return -1;
		}
	} else if ( NULL == (library_list = realloc(library_list,
				lib_count * sizeof(char *)))) {
		printf("Failed to reallocate library-list\n");
		return -1;
	}

	library_list[--lib_count] = (char *) malloc(strlen(path)+1);
	if (NULL == library_list[lib_count]) {
		printf("Failed to allocate pathmemory\n");
		return -1;
	}

	memcpy(library_list[lib_count], path, len+1);
	//printf("Copied Path%d: %s\n", lib_count, library_list[lib_count]);

	return 0;
}

int get_library_count (const char *dName) {

	DIR *directory 		= NULL;
	struct dirent *dir 	= NULL;
	FILE *file 		= NULL;
	unsigned char *header 	= NULL;
	char fName[260] 	= {0};
	long fSize 		= 0;
	int lib_count 		= 0;
	unsigned int val 	= 0;

	//printf("Calling: %s()\n", __func__);

	directory = opendir(dName);
	if (directory) {

		while ((dir = readdir(directory)) != NULL) {
			bzero(fName, 260);
			sprintf(fName, "%s/%s", dName, dir->d_name);
			read_file_header(fName, &header, 4, ELF_OFFSET);
			val = header[0] << 24 | header[1] << 16 |
				header[2] << 8 | header[3];

			if (ELF_FORMAT == val) {
				++lib_count;
				fSize = strlen(fName);

				if (store_lib_names(lib_count, fName)) {
					printf("Failed to store libs\n");
					FREE(header);
					exit(1);
				}
			}

			FREE(header);
		}/*while-loop*/
		closedir(directory);
	}/*if-end*/

	return lib_count;

}/*function End*/


char *arch (unsigned char *header) {

	switch (*header) {
		case NOARH:
			return "noarch";
			break;
        	case SPARC:
			return "sparc";
			break;
        	case X86:
			return "x86";
		case MIPS:
			return "mips";
			break;
		case POWERPC:
			return "powerpc";
			break;
		case S390:
			return "s390";
			break;
		case ARM:
			return "arm";
			break;
		case SUPERH:
			return "superh";
			break;
		case IA64:
			return "ia64";
			break;
		case AMD64:
			return "amd64";
			break;
		case AARCH64:
			return "aarch64";
			break;
		case RISCV:
			return "riscv";
			break;
		default:
			return "invalid";
	}
}


char *arch_bits(unsigned char *bits) {

	switch (*bits) {
		case ARCH32:
			return "-32";
			break;
		case ARCH64:
			return "-64";
			break;
	}
}


void process_files_architecture (int count) {
	unsigned char *header = NULL;
	int i = -1;

	for (i = 0; i < count; i++) {
		/*for arch identification*/
		read_file_header(library_list[i], &header, 2, ARCH_OFFSET);
		printf("%s\t: %s", library_list[i], arch(header));
		FREE(header);
		/*32/64-bit*/
		read_file_header(library_list[i], &header, 1, ARBITS_OFST);
		printf("%s\n", arch_bits(header));
		FREE(header);
	}

	FREE(header);

	return;
}


int main (int argc, char *argv[]) {

	if (argc < 2) {
		printf("usage: <binary> <path for folder>\n");
		return -1;
	}

	int count = -1;
	int i = -1;

	count = get_library_count(argv[1]);
	if (0 == count) {
		printf("There is no ELF in directory\n");
		return 0;
	} else {
		printf("Total number of libraries: %d\n", count);
		process_files_architecture(count);
	}

	for (i = 0; i < count; i++) {
		FREE(library_list[i]);
	}

	FREE(library_list);

	return 0;
}
