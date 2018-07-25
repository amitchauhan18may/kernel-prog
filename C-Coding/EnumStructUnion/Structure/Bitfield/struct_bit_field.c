#include <stdio.h>

struct date {
    unsigned int date;
    unsigned int month;
    unsigned int year;
};

struct optimize_date {
    unsigned int date : 5;/*Here we specifying 5-bits for variable*/
    unsigned int month: 4;
    unsigned int year;
};


int main () {
    struct date my_date = {
        .date  = 10,
        .month = 2,
        .year  = 2018
    };

    struct optimize_date optimize_my_date = {
        .date  = 10,
        //.date  = 1000,
        /* Here we are demonstrating out of range value
         * warning: large integer implicitly truncated to unsigned type
         * O/P: In this case was 8*/
        .month = 2,
        .year  = 2018
    };

    printf("Size of struct date: %lu\n", sizeof(struct date));
    printf("Date: %u/%u/%u\n", my_date.date, my_date.month, my_date.year);

    printf("\nSize of struct optimize_date: %lu\n",
            sizeof(struct optimize_date));
    printf("Date: %u/%u/%u\n", optimize_my_date.date,
            optimize_my_date.month, optimize_my_date.year);
    return 0;
}
