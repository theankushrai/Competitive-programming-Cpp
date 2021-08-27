 
#include<stdio.h>
void main()
{
    int n,d=0,e=0,o=0;
    printf("Enter order of matrix :");
    scanf("%d",&n);
    int a[n][n];
    printf("Enter %d elements",n*n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf(" %d",&a[i][j]);
            if(i==j)d+=a[i][j];
            if(a[i]%2==0) e+=a[i][j];
            else o+=a[i][j];
        }   
    }
    printf("The given matrix\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ",a[i][j]);
        }
        printf("\n");
        
    }
    printf("The sum of diagonal elements = %d\n",d);       
    printf("The sum of even elements = %d\n",e);       
    printf("The sum of odd elements = %d\n",o);       
}