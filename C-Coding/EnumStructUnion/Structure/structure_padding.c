#include <stdio.h>

/*structure A*/
typedef struct structa_tag
{
    char        c;
    short int   s;
} structa_t;

/*structure B*/
typedef struct structb_tag
{
    short int   s;
    char        c;
    int         i;
} structb_t;

/*Explaination:
 * char c  : 1 + 7(padding byte)
 * double d: 8
 * int s   : 4 + 4(padding byts)
 * Total   : 24 bytes
 */
/*structure C*/
typedef struct structc_tag
{
    char        c;
    double      d;
    int         s;
} structc_t;

/*structure D*/
typedef struct structd_tag
{
    double      d;
    int         s;
    char        c;
} structd_t;

int main()
{
    printf("sizeof(structa_t) = %ld\n", sizeof(structa_t));
    printf("sizeof(structb_t) = %ld\n", sizeof(structb_t));
    printf("sizeof(structc_t) = %ld\n", sizeof(structc_t));
    printf("sizeof(structd_t) = %ld\n", sizeof(structd_t));

    return 0;
}
