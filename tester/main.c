/**< Write a program that accepts a base ten (non-fractional) number at the command line and outputs the binary representation of that number. Sample input is:

dectobin 120 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void PrintDigit(unsigned int NumToConvert);

int main(int argc, char* argv[])
{
    if (argc == 2) //proceed only with correct number of arguments
    {
        printf("Hello world!\n");
        unsigned int NumToConvert = atoi(argv[1]); //pulls number from command line when program is run in the expected way
        if (atoi(argv[1])<0)    //we will assume that input is only zero or a positive integer
        {
            printf("Please enter a positive integer\n");
            return -1;
        }
        printf("Decimal: %d\n", NumToConvert);
        printf("Binary: ");
        PrintDigit(NumToConvert);
        return 0;
    }
    else
    {
        return -1;
    }
}

void PrintDigit(unsigned int NumToConvert)
{
    unsigned int NextDigit = (unsigned int) log2(NumToConvert);
    if (NumToConvert >0)
    {
        NumToConvert-=(unsigned int) exp2(NextDigit); //gets modified every time we find a power of 2 smaller than it
        printf("1");
        if (NumToConvert == 0)
        {
            for (int i=NextDigit; i>0; i--) //handle trailing zeros when NumToConvert becomes an integer power of 2
            {
                printf("0");    //prints trailing zeros
            }
        }
        else
        {
            PrintDigit(NumToConvert);
        }
    }
    else
    {
        printf("0");    //prints zero if NumToConvert starts out as zero
    }

}
