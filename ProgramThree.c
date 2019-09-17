/* *************************************************************************************************************************** */
/* Name of the program :  ProgramThree                                                                                         */
/*                                                                                                                             */
/* Authors:           Aaksha Jaywant                                                                                           */
/*                    Sarayu Managoli                                                                                          */
/*                                                                                                                             */
/* Compiler used:     GCC                                                                                                      */
/*                                                                                                                             */
/* Program statement: Given the starting integer value 0xCAFE, perform each of these operations in series, that is, each       */
/*                    operation should be performed on the result of the previous function.  Print the results of each         */
/*                    function to the command line (to capture as ProgramThree.out).                                           */
/*                    ? Print the original input in hexadecimal                                                                */
/*                    ? Test if 3 of last 4 bits are on, and print the value in binary (along with the result of the           */
/*                        test � true/false)                                                                                  */
/*                    ? Reverse the byte order, print the value in hexadecimal                                                 */
/*                    ? Test if 3 of last 4 bits are on, and print the value in binary (along with the result of the           */
/*                        test � true/false)                                                                                  */
/*                    ? Rotate the value by four bits to the left, print the value in hexadecimal                              */
/*                    ? Test if 3 of last 4 bits are on, and print the value in binary (along with the result of the           */
/*                        test � true/false)                                                                                  */
/*                    ? Rotate the value by eight bits to the right, print the value in hexadecimal                            */
/*                    ? Test if 3 of last 4 bits are on, and print the value in binary (along with the result of the           */
/*                        test � true/false)                                                                                  */
/*                    Applicable links: http://blockofcodes.blogspot.com/2013/04/binary-to-hexadecimal-c-program.html          */
/*                        https://social.msdn.microsoft.com/Forums/vstudio/en-US/5511f617-f910-46e5-b5b5-f61d9c17a016/how-to   */
/*                        -swap-the-bytes-order-of-int-in-c?forum=vcgeneral                                                    */
/*                                                                                                                             */

#include<stdio.h>

int TestBits(int value)
{
    int remainder=0,count=0,binary=0,i=1;
    int temp,tempdec;
    temp=value&0x0F;
    tempdec=(int)temp;
    printf("\nValue of the last 4 bits %d",tempdec);
    while(tempdec!=0)
    {
        remainder=tempdec%2;
        if(remainder==1)count++;
        binary=binary+i*remainder;
        i*=10;
        tempdec=tempdec/2;
    }
    if(count==3) printf("\nTRUE, 3 of the last 4 bits are true");
    else printf("\nFALSE, 3 of the last 4 bits are 0");
    printf("\nLast 4 digits are: %d",binary);

    return 0;
}

int main()
{
    unsigned int hex=0xCAFE;
    int hexfirst,temp;
    //first answer
    printf("Input hexadecimal value is : 0x%X",hex);


    //second answer
    TestBits(hex);

    //Third
    temp=hex;
    hexfirst=temp & 0xFF;
    hexfirst=(hexfirst<<8) | ((temp >>8)& 0xFF);

    hex=hexfirst;
    printf("\n%X",hex);

    //Fourth
    TestBits(hex);

    //fifth rotate by left by 4
    temp=hex;
    hexfirst=(hex<<4) | (hex >>12);
    hexfirst=hexfirst&0xFFFF;
    hex=hexfirst;
    printf("\nThe left rotated output is %X",hex);

    //sixth
    TestBits(hex);

    //seventh rotate right
    temp=hex;
    hexfirst=(hex>>8) | (hex <<8);
    hexfirst=hexfirst&0xFFFF;
    hex=hexfirst;
    printf("\nThe right rotated output is %X",hex);

    //eight
    TestBits(hex);

return 0;

}
