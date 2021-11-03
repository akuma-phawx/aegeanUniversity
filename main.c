#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
char* toBinary(int num)
{
    int mask = 1 << (31);
    static char res[40] = {0};
    for (short i = 0; i < 39; i++)
    {
        res[i] = (num & mask ? '1' : '0');
        num <<= 1;
        if(i % 5 == 3) res[++i] = ' ' ;  // the trick: increment i and write a space
    };
    res[39] = '\0';   // never forget the terminating null when building a string
    return res;
}

double calculateFactorial(double num)
{

}
void runExerciseOne()
{
    double number;
    double functionResult;
    printf("Please enter a number: ");
    scanf("%lf", &number);
    fflush(stdin);
    if(number<-1)
    {
        printf("\t\n Given number is not inside the domain of the function\n\n");
    }
    else if(number <= 1)
    {
        functionResult = sqrt(1+number);
        printf("\tResult is: %.2lf\n\n",functionResult);
    }
    else if(number<=25)
    {
        functionResult = 1 / (number*pow(log(number),2)) ;
        printf("\tResult is: %.2lf\n\n",functionResult);
    }
    else
    {
        functionResult = exp(pow(number,5)) / (3*pow(number,4)-1) ;
        printf("\tResult is: %.2lf\n",functionResult);
        printf("\t 1.#J is Positive Infinity - -1.#J is Negative Infinity\n\n");
    }
}

void runExerciseTwo()
{
    int integerToBinary;

    printf("Please enter an integer: ");
    scanf("%d", &integerToBinary);

    fflush(stdin);
    printf("\nBinary Representation of %d is:\n\t ", integerToBinary);
    printf(toBinary(integerToBinary));

    printf("\n\n");
}
void runExerciseThree()
{
    double functionResult;
    double lastSum = 0.0;
    double newSum = 0.0;
    double tempSum = 0.0;

    double step = 0.0;
    double stepFractional = 0/2;
    double constantPart = 2 / sqrt(M_PI);
    double terminationCondition = exp(-6);

    double number;

    printf("Please enter a number: ");
    scanf("%lf", &number);
    fflush(stdin);
    printf("Calculating...\n");
    do
    {
        double numerator = pow(-1,stepFractional)*pow(number,2*step+1);


        double factorial = step==0.0 ? 1 : tgamma(step);
        double denominator = factorial *(2*step+1);


        newSum = lastSum + (numerator/denominator);

        tempSum = lastSum;
        lastSum = newSum;
        step+=0.5;
        stepFractional+= 1/2;
    }
    while((newSum - tempSum)>terminationCondition);

    functionResult = constantPart*lastSum;
    printf("\tFor x=%.2lf, f(x)=%.2lf\n",number,functionResult);
    printf("\t1.#J = Positive Infinity - -1.#J = Negative Infinity\n\n");

}

// Returns true if s is a number else false
int isNumber(char s[])
{
    for (int i = 0; i < sizeof(s); i++)
        if (isdigit(s[i]) == 1)
            return -1;

    return 1;
}


int main(int argc, char** argv)
{

    char input[10];

    do
    {
        printMenu();
        printf("Enter: ");
        scanf("%s", &input);
        printf("\n------------------------------------\n");
        int inputToInteger = atoi(input);
        switch(inputToInteger)
        {
        case 1:
            printf("|      Running Exercise 1          |\n");
            printf("------------------------------------\n\n");
            runExerciseOne();
            break;
        case 2:
            printf("|      Running Exercise 2          |\n");
            printf("------------------------------------\n\n");
            runExerciseTwo();
            break;
        case 3:
            printf("|      Running Exercise 3          |\n");
            printf("------------------------------------\n\n");
            runExerciseThree();
            break;
        case 4:
            printf("|       Now exiting..Byebye!       |\n");
            printf("------------------------------------\n\n");
            exit(0);
            break;
        default:
            printf("| Invalid Input, please try again. |\n");
            printf("------------------------------------\n\n");
            break;
        }
    }
    while(isNumber(input)==-1 || input < 1 || input > 4);
    return 0;
}

void printMenu()
{

    printf("[Menu]:\n");
    printf("\t[1]Run exercise 1 (Function values)\n");
    printf("\t[2]Run exercise 2 (Binary Representation of Integer)\n");
    printf("\t[3]Run exercise 3 (Taylor)\n");
    printf("\t[4]Exit\n\n");

}





