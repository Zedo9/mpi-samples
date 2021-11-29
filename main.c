#include <stdio.h>
#include <stdlib.h> //to use system()

void printMenu();

int main()
{
    char *command;
    char input;
    printMenu();
    scanf("%c", &input);
    while (input != 'e')
    {
        if (input == 'a')
        {
            printf("*********Choice A*********\n");
            system("mpirun -np 8 ./dist_reduction_sum.out");
        }
        if (input == 'b')
        {
            printf("*********Choice B*********\n");
            system("mpirun -np 8 ./dist_reduction_product_bcast.out");
        }
        if (input == 'c')
        {
            printf("*********Choice C*********\n");
            system("mpirun -np 8 ./ring.out");
        }
        scanf("%c", &input);
    }
    return 0;
}

void printMenu()
{
    printf("**********************************\n");
    printf("Collective communication :\n");
    printf("    a- Distributed reduction (Sum)\n");
    printf("    b- Distributed reduction (Product) with result broadcasting\n");
    printf("c- Point to Point communication in a ring\n");
    printf("e- Exit\n");
}