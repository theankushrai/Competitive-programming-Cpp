
#include<stdio.h>
void main()
{
    int choice;
printf("1. Lowercase to Uppercase\n2. Uppercase to Lowercase\n");
printf("Enter your option : ");
scanf("%d",&choice);

switch (choice)
{
case 1:
    {
        char ch;
        printf("Enter a lowercase character : ");
        scanf("%c",&ch);
        if(ch>='A'&&ch<='Z')printf("%c is not a lowercase character",ch);
        ch-=32;
        printf("Uppercase character : %c\n",ch);
    }
    break;

case 2:{
        char ch;
        printf("Enter a uppercase character : ");
        scanf("%c",&ch);
        if(ch>='a'&&ch<='z')printf("%c is not a uppercase character",ch);
        ch+=32;
        printf("Lowercase character : %c\n",ch);
}
}
}