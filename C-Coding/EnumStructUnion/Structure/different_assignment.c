#include <stdio.h>

struct details {
    char name[25];
    int age;
    float salary_pm;
};

int main (void) {
    struct details assign_detail;
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


/*Assignment and comparision between two objects of same structure*/
    assign_detail = my_detail;
    printf("\nAssigned Details:\nName: %s\nAge: %d\nSalary/Month: %f\n",
            assign_detail.name, assign_detail.age, assign_detail.salary_pm);

/*Comparision
 * error: invalid operands to binary == (have ‘struct details’ and ‘struct details’)
    if (assign_detail == my_detail) {
        printf("\nassign_detail == my_detail\n");
    } else {
        printf("\nassign_detail != my_detail\n");
    }
 */
    return 0;
}
