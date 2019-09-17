/* *************************************************************************************************************************** */
/* Name of the program :  ProgramOne                                                                                           */
/*                                                                                                                             */
/* Authors:           Aaksha Jaywant                                                                                           */
/*                    Sarayu Managoli                                                                                          */
/*                                                                                                                             */
/* Compiler used:     GCC                                                                                                      */
/*                                                                                                                             */
/* Program statement: Create a C program that will take as input a numeric value, a radix, and an                              */
/*                    operand size. Your program will need to error check for invalid inputs. Radix values are limited         */
/*                    to 8, 10, 16. Operand size values are limited to bit sizes of 4,8,16. Numeric input must be valid        */
/*                    for the operand size (that is, a number larger than the operand size should throw an error). For         */
/*                    each input line read, return the following output to the console (for capture into an output file)       */
/*                    – the following output is for the input -6, 10, 4 (numeric value, radix of the value, operand bit        */
/*                    size). Any values that cannot be calculated should show the word Error for a result in the table.        */
/*                    Note that the first four outputs in the table display absolute values, the last three are signed.        */
/*                    Input: Value -6 Radix 10 Operand Size 4                                                                  */
/*                    Output:                    Value       Maximum      Minimum                                              */
/*                    Binary (abs)               0b0110      0b1111       0b0000                                               */
/*                    Octal (abs)                 06         017           0                                                   */
/*                    Decimal (abs)               6           15           0                                                   */
/*                    Hexadecimal (abs)           0x6        0xF           0x0                                                 */
/*                    Signed One’s Compliment     0b1001     0b0111        0b1000                                              */
/*                    Signed Two’s Compliment     0b1010     0b0111        0b1001                                              */
/*                    Sign-Magnitude              0b1110     0b0111        0b1111                                              */
/*                    Your C program should run against the following data:                                                    */
/*                    Input Set {Value, Radix, Operand Size}                                                                   */
/*                    {-6, 10, 4}, {-6, 9, 4}, {-6, 10, 5}, {-9, 10, 4}, {237, 10, 8}, {0354, 8, 8}, {0xEB, 16, 8},            */
/*                    {-125, 10, 8}, {65400, 10, 8}, {65400, 10, 16}, {-32701, 10, 16}                                         */
/*                                                                                                                             */
/*                    Applicable links: http://www.embhack.com/find-twos-complement-of-a-number                                */
/*   					https://www.geeksforgeeks.org/1s-2s-complement-binary-number/			       */



#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int value,radix,operand,valueoct,valuedec,valuehex;
char minb[20]={0},maxb[20]={0},mino[20]={0},maxo[20]={0},mind[20]={0},maxd[20]={0},minh[20]={0},maxh[20]={0},minoc[20]={0},maxoc[20]={0},mintc[20]={0},maxtc[20]={0},minsm[20]={0},maxsm[20]={0};

int printoutbound()
{
        {
            printf("The value is out of bounds\n");
            exit(0);
        }
    return 0;
}
int printinvalid()
{
        {
            printf("Invalid input\n");
            exit(0);
        }
    return 0;
}

int printbdh()
{
    printf("Octal(abs)                     0%o                 0377                         0000\n",value); //Octal
    printf("Decimal(abs)                   %d                  255                          0\n",value); //Decimal
    printf("Hexadecimal(abs)               0x%X                0xFF                         0x00\n",value);  //Hexadecimal
    return(0);
}

int printdec()
{
    printf("Octal(abs)\t\t\t0%o\t\t\t%s\t\t\t%s\n",abs(value),maxo,mino); //Octal
    printf("Decimal(abs)\t\t\t%d\t\t\t%s\t\t\t%s\n",abs(value),maxd,mind); //Decimal
    printf("Hexadecimal(abs)\t\t\t0x%X\t\t\t%s\t\t\t%s\n",abs(value),maxh,minh); //hexadecimal
    return(0);
}

int octfunction()
{
    int i;
    long binary=0;
    printf("Output:                        Value              Maximum                     Minimum\n");
    valuedec=valueoct;
    i = 1;
    while (valueoct != 0)
    {
	binary = binary + (valueoct % 2) * i;
	valueoct = valueoct / 2;
	i = i * 10;
    }


    printf("Binary(abs)                   0b%ld          0b11111111                  0b00000000\n",binary);  //Binary

    printbdh();

    //For 1s complement
    if((operand==4&&valuedec>7)||(operand==8&&valuedec>127)||(operand==16&&valuedec>32767))
    printf("Signed One’s Complement       Error               0b01111111                  0b10000000\n");
    else if ((operand==4&&valuedec<=7)||(operand==8&&valuedec<=127)||(operand==16&&valuedec<=32767))
    printf("Signed One’s Complement       0b%ld                0b01111111                  0b10000000\n",binary);

    //For 2s complement
    if((operand==4&&valuedec>7)||(operand==8&&valuedec>127)||(operand==16&&valuedec>32767))
    printf("Signed Two's Complement       Error               0b01111111                  0b10000001\n");
    else if ((operand==4&&valuedec<=7)||(operand==8&&valuedec<=127)||(operand==16&&valuedec<=32767))
    printf("Signed Two’s Complement       0b%ld                0b01111111                  0b10000001\n",binary);

    //Signed magnitude
    if((operand==4&&valuedec>7)||(operand==8&&valuedec>127)||(operand==16&&valuedec>32767))
    printf("Sign-Magnitude                Error               0b01111111                  0b11111111\n");
    else if ((operand==4&&valuedec<=7)||(operand==8&&valuedec<=127)||(operand==16&&valuedec<=32767))
    printf("Sign-Magnitude                0b%ld                0b01111111                  0b11111111\n",binary);


return 0;
}

int hexfunction()
{
    int i=1;
    long binary=0;
    printf("Output:                        Value              Maximum                     Minimum\n");

    //ltoa(value,binarystr,2);  //Binary
    valuedec=valuehex;
    while (valuehex != 0)
    {
	binary = binary + (valuehex % 2) * i;
	valuehex = valuehex / 2;
	i = i * 10;
    }


    valuedec=(int)value;
    printf("Binary(abs)                    0b%ld               0b11111111                  0b00000000\n",binary);

    printbdh();

    //For 1s complement
    if((operand==4&&valuedec>7)||(operand==8&&valuedec>127)||(operand==16&&valuedec>32767))
    printf("Signed One’s Complement        Error              0b01111111                  0b10000000\n");
    else if ((operand==4&&valuedec<=7)||(operand==8&&valuedec<=127)||(operand==16&&valuedec<=32767))
    printf("Signed One’s Complement        0b%ld               0b01111111                  0b10000000\n",binary);

    //For 2s complement
    if((operand==4&&valuedec>7)||(operand==8&&valuedec>127)||(operand==16&&valuedec>32767))
    printf("Signed Two's Complement        Error              0b01111111                   0b10000001\n");
    else if ((operand==4&&valuedec<=7)||(operand==8&&valuedec<=127)||(operand==16&&valuedec<=32767))
    printf("Signed Two’s Complement        0b%ld               0b01111111                   0b10000001\n",binary);

    //Signed magnitude
    if((operand==4&&valuedec>7)||(operand==8&&valuedec>127)||(operand==16&&valuedec>32767))
    printf("Sign-Magnitude                 Error              0b01111111                   0b11111111\n");
    else if ((operand==4&&valuedec<=7)||(operand==8&&valuedec<=127)||(operand==16&&valuedec<=32767))
    printf("Sign-Magnitude                 0b%ld               0b01111111                   0b11111111\n",binary);

return 0;
}

int decfunction()
{
    int binary[17]={0},binaryoc[17]={0},binarytc[16]={0},i,dectemp=0,decabs=0;
    int carry=1;
    printf("Output:                        Value              Maximum                     Minimum\n");
    if(value>=0)  //for positive
    {
        //Binary
        i=0;
        dectemp=value;
        while (dectemp != 0)
        {
            binary[i] = dectemp % 2;
            dectemp = dectemp / 2;
            i++;
        }
        binary[operand]='\0';

        printf("Binary(abs)\t\t\t0b");
        for(i=operand-1;i>=0;i--) printf("%d",binary[i]);
        printf("\t\t\t%s\t\t\t%s\n",maxb,minb);

        printdec();

        //Ones complement
        if((operand==4&&value>7)||(operand==8&&value>127)||(operand==16&&value>32767))
        printf("Signed One's complement\t\tError\t\t\t%s\t\t\t%s\n",maxoc,minoc);

        if((operand==4&&value<=7)||(operand==8&&value<=127)||(operand==16&&value<=32767))
        {
            printf("Signed One's complement\t\t\t0b");
            for(i=operand-1;i>=0;i--) printf("%d",binary[i]);
            printf("\t\t%s\t\t\t%s\n",maxoc,minoc);
        }

        //Twos complement
        if((operand==4&&value>7)||(operand==8&&value>127)||(operand==16&&value>32767))
        printf("Signed Two's complement\t\tError\t\t\t%s\t\t\t%s\n",maxtc,mintc);

        if((operand==4&&value<=7)||(operand==8&&value<=127)||(operand==16&&value<=32767))
        {
            printf("Signed Two's complement\t\t\t0b");
            for(i=operand-1;i>=0;i--) printf("%d",binary[i]);
            printf("\t\t%s\t\t\t%s\n",maxtc,mintc);
        }

        //Sign magnitude
        if((operand==4&&value>7)||(operand==8&&value>127)||(operand==16&&value>32767))
        printf("Sign-Magnitude\t\t\tError\t\t\t%s\t\t\t%s\n",maxsm,minsm);

        if((operand==4&&value<=7)||(operand==8&&value<=127)||(operand==16&&value<=32767))
        {
            printf("Sign-Magnitude\t\t\t0b");
            for(i=operand-1;i>=0;i--) printf("%d",binary[i]);
            printf("\t\t\t%s\t\t\t%s\n",maxsm,minsm);
        }
    }
    else   //For negative
    {   //Binary
        i=0;
        decabs=abs(value);
        while(decabs != 0)
        {
            binary[i] = decabs % 2;
            decabs = decabs / 2;
            i++;
        }
        binary[operand]='\0';

        printf("Binary(abs)\t\t\t0b");
        for(i=operand-1;i>=0;i--) printf("%d",binary[i]);
        printf("\t\t\t%s\t\t\t%s\n",maxb,minb);

        printdec();

        //Ones complement
        if((operand==4&&value<-7)||(operand==8&&value<-127)||(operand==16&&value<-32767))
        printf("Signed One's complement\t\tError\t\t\t%s\t\t\t%s\n",maxoc,minoc);

        if((operand==4&&value>=-7)||(operand==8&&value>=-127)||(operand==16&&value>=-32767))
        {
            for(i=0;i<operand;i++)
            {
                if(binary[i]==0)binaryoc[i]=1;
                else binaryoc[i]=0;
            }
            binaryoc[operand]='\0';

            printf("Signed One's complement\t\t\t0b");
            for(i=operand-1;i>=0;i--) printf("%d",binaryoc[i]);
            printf("\t\t%s\t\t\t%s\n",maxoc,minoc);
        }

        //Twos complement
        if((operand==4&&value<-7)||(operand==8&&value<-127)||(operand==16&&value<-32767))
        printf("Signed Two's complement\t\t\tError\t\t\t%s\t\t\t%s\n",maxtc,mintc);

        if((operand==4&&value>=-7)||(operand==8&&value>=-127)||(operand==16&&value>=-32767))
        {
            for(i=0;i<operand;i++)
            {
                if(carry==1&&binaryoc[i]==1)
                {
                    carry=1;
                    binarytc[i]=0;
                }
                else if(carry==1&&binaryoc[i]==0)
                {
                    carry=0;
                    binarytc[i]=1;
                }
                else if(carry==0)
                {
                binarytc[i]=binaryoc[i];
                }
            }
            binarytc[operand]='\0';

            printf("Signed Two's complement\t\t\t0b");
            for(i=operand-1;i>=0;i--) printf("%d",binarytc[i]);
            printf("\t\t%s\t\t\t%s\n",maxtc,mintc);
        }

        //Sign magnitude
        if((operand==4&&value<-7)||(operand==8&&value<-127)||(operand==16&&value<-32767))
        printf("Sign-Magnitude\t\t\tError\t\t\t%s\t\t\t%s\n",maxsm,minsm);

        if((operand==4&&value>=-7)||(operand==8&&value>=-127)||(operand==16&&value>=-32767))
        {
            binary[operand-1]=1;
            printf("Sign-Magnitude\t\t\t0b");
            for(i=operand-1;i>=0;i--) printf("%d",binary[i]);
            printf("\t\t\t%s\t\t\t%s\n",maxsm,minsm);
        }

    }
    return 0;
}

int main()
{
    printf("\nEnter the radix value");
    scanf("%d",&radix);

    if(radix!=8&&radix!=10&&radix!=16) printinvalid();

    printf("\nEnter the operand value");
    scanf("%d",&operand);

    if(operand!=4&&operand!=8&&operand!=16) printinvalid();

    if((radix==8||radix==10||radix==16)&&operand==4)
    {
        strcpy(maxb,"0b1111");
        strcpy(minb,"0b0000");
        strcpy(maxo,"017");
        strcpy(mino,"0");
        strcpy(maxd,"15");
        strcpy(mind,"0");
        strcpy(maxh,"0xF");
        strcpy(minh,"0x0");
        strcpy(maxoc,"0b0111");
        strcpy(minoc,"0b1000");
        strcpy(maxtc,"0b0111");
        strcpy(mintc,"0b1001");
        strcpy(maxsm,"0b0111");
        strcpy(minsm,"0b1111");

    }
    else if((radix==8||radix==10||radix==16)&&operand==8)
    {
        strcpy(maxb,"0b11111111");
        strcpy(minb,"0b00000000");
        strcpy(maxo,"0377");
        strcpy(mino,"0");
        strcpy(maxd,"255");
        strcpy(mind,"0");
        strcpy(maxh,"0xFF");
        strcpy(minh,"0x00");
        strcpy(maxoc,"0b01111111");
        strcpy(minoc,"0b10000000");
        strcpy(maxtc,"0b01111111");
        strcpy(mintc,"0b10000001");
        strcpy(maxsm,"0b01111111");
        strcpy(minsm,"0b11111111");
    }
    else if((radix==8||radix==10||radix==16)&&operand==16)
    {
        strcpy(maxb,"0b1111111111111111");
        strcpy(minb,"0b0000000000000000");
        strcpy(maxo,"0177777");
        strcpy(mino,"0");
        strcpy(maxd,"65535");
        strcpy(mind,"0");
        strcpy(maxh,"0xFFFF");
        strcpy(minh,"0x0000");
        strcpy(maxoc,"0b0111111111111111");
        strcpy(minoc,"0b1000000000000000");
        strcpy(maxtc,"0b0111111111111111");
        strcpy(mintc,"0b1000000000000001");
        strcpy(maxsm,"0b0111111111111111");
        strcpy(minsm,"0b1111111111111111");
    }
    if(radix==8&&(operand==4||operand==8||operand==16))
    {
        printf("\nEnter the value in octal");
        scanf("%o",&value);
        valueoct=(int)value;
        if((int)value>(pow(2,operand)-1)) printoutbound();
        else octfunction();
    }
    if(radix==10&&(operand==4||operand==8||operand==16))
    {
        printf("\nEnter the value in decimal\n");
        scanf("%d",&value);
        if((int)value>(pow(2,operand)-1)) printoutbound();
        else decfunction();
    }
    if(radix==16&&(operand==4||operand==8||operand==16))
    {
        printf("\nEnter the value in hex\n");
        scanf("%X",&value);
        valuehex=(int)value;
        if((int)value>(pow(2,operand)-1)) printoutbound();
        else hexfunction();
    }
    return 0;
}

