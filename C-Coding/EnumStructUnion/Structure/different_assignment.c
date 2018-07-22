#include <stdio.h>

struct details {
    char name[25];
    int age;
    float salary_pm;
};

int main (void) {
/*Designated initialization of structure*/
#if 1
    struct details my_detail = {
        .name      = "Amit Chauhan",
        .age       = 29,
        .salary_pm = 150000.5
    };
#else
/*Initializer list initialization of structure*/  
    struct details my_detail = {"Amit Chauhan", 29, 150000.5};
#endif
    printf("Details:\nName: %s\nAge: %d\nSalary/Month: %f\n",
            my_detail.name, my_detail.age, my_detail.salary_pm);

    return 0;
}
