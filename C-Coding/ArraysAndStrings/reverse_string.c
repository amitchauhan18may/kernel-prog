#include <stdio.h>
#include <string.h>
char* reverse_string (char* reverse) {
    int len = strlen(reverse);
    int i, j;
    char temp;
    for (i = 0, j = len -1; i < j; i++, j--) {
        temp = reverse[i];
        reverse[i] = reverse[j];
        reverse[j] = temp;
    }

    printf("string: %s\n", reverse);
    return reverse;
}

<<<<<<< HEAD
void recursive_reverse (char *reverse, int start, int end) {
    char temp;

    if (start > end)
        return;
    temp = *(reverse + start);
    *(reverse + start) = *(reverse + end);
    *(reverse + end) = temp;

    recursive_reverse(reverse, ++start, --end);
}

int main () {
    char string[] = "abcd";
    int len = strlen(string);
#if 0
    reverse_string(string);
#else
    recursive_reverse(string, 0, len - 1);
#endif

    printf("After reverse: %s\n", string);

=======
int main () {
    char string[] = "abcd";
    reverse_string(string);
>>>>>>> 86a8788b3c3261c38dc2cdbc9515be4a30b75486
    return 0;
}
