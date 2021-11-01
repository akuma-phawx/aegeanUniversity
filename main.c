#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv)
{

    printMenu();




    return 0;
}

void printMenu(){
    int input;
    do{
    printf("[Menu]:\n");
    printf("\t[1]Run exercise 1 (Function values)\n");
    printf("\t[2]Run exercise 2 (Binary Representation of Integer)\n");
    printf("\t[3]Run exercise 3 (Taylor)\n");
    printf("\t[4]Exit\n\n");

    printf("Enter: ");
    scanf("%d", &input);
    printf("-----------\n");
    switch(input){
        case 1:
            runExerciseOne();
            break;
        case 2:
            runExerciseTwo();
            break;
        case 3:
            runExerciseThree();
            break;
        case 4:
            printf("Now exiting..\n");
            exit(0);
            break;
        default:
            printf("Invalid Input, please try again.\n\n");
            break;
    }

    }while(input !=4);
}


void runExerciseOne(){
    printf("Exercise 1\n");
}

void runExerciseTwo(){
    int integerToBinary;
    printf("Please enter an integer: ");
    scanf("%d", &integerToBinary);
    printf("Binary Representation of %d is:\n\t ", integerToBinary);
    unsigned i;
    for (i = 1 << 31; i > 0; i = i / 2)
        (integerToBinary & i) ? printf("1") : printf("0");

    printf("\n");
}
void runExerciseThree(){
    printf("Exercise 3\n");
}