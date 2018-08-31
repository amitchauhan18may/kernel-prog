#include <stdio.h>
void my_strcat(char *dest, char *src)
{
  printf("Destination: %c\n", *dest);
  printf("Source: %c\n", *src);

  (*dest)? my_strcat(++dest, src): (*dest++ = *src++)? my_strcat(dest, src): 0 ;
}
 
/* driver function to test above function */
int main()
{
  char dest[100] = "geeksfor";
  char *src = "geeks";
  my_strcat(dest, src);
  printf(" %s ", dest);
  return 0;
}
