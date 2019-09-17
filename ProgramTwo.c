
/* *************************************************************************************************************************** */
/* Name of the program :  ProgramTwo                                                                                           */
/*                                                                                                                             */
/* Authors:           Aaksha Jaywant                                                                                           */
/*                    Sarayu Managoli                                                                                          */
/*                                                                                                                             */
/* Compiler used:     GCC                                                                                                      */
/*                                                                                                                             */
/* Program statement: Write a program that uses a logical expression that tests whether a given character code is a            */
/*                    lower case					                                            	       */
/*                    upper case						                                               */
/*                    digit												       */
/*                    white space (like null, backspace, space, tabs, etc.)						       */
/*                    or a special character (like ! or >) in ASCII.							       */
/*                    You can document your decisions of segregating the ASCII codes into the categories.	               */
/*                    For each test input print the input code, the type of character, and the ASCII character to the console  */
/*                    (for capture to ProgramTwo.out). A typical printed line would look like:                                 */
/*                    Code: 66 Type: Upper Case ASCII Char: B				                            	       */
/*                    Test it on the following ASCII codes:                                                                    */
/*                    {66,114,117,99,101,32,83,97,121,115,32,72,105,33,7,9,50,48,49,57}                                        */
/*                                                                                                                             */
/*Applicable link:    http://www.asciitable.com/									       */

#include <stdint.h>
#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x;
    printf("Please enter the code\t");
    scanf("%d",&x);

    printf("Code: %d",x);

    if(97<=x && x<=122)
    {
        printf("\t\tType: Lower Case");
    }
    else if(65<=x && x<=90)
    {
        printf("\t\tType: Upper Case");
    }

    else if(48<=x && x<=57)
    {
        printf("\t\tType: Digit");
    }
    else if(0<=x && x<=32)
    {
        printf("\t\tType: White Space");
    }
    else
    {
        printf("\t\tType: Special Character");
    }

    printf("\t\tASCII Char: %c",x);
    return 0;
}
