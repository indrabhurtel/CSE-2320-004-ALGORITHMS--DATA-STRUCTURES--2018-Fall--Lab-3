/*
*
*lab3
*
*Created by Indra Bhurtel on 10/23/2018.
*
*
*Name:Indra Bhurtel
*I am senior at UTA. My major is software Engineering.
*UTA ID NO:1001542825
*
*lab 3 assignment
*
*Professor Bob Weems
*
*Code compilation in Omega as follows:
*    gcc lab3.c
*   ./a.out
*/

#include <stdio.h>
#include <stdlib.h>

void find_the_subset(int * S, int** C, int n, int m) ///function to find the subset and insert into the 2D array.
{
    int i, j, k, b;
    for(i=1; i<=m; i++)
    {
        for(j=1; j<=n; j++)
        {
            for(k=1; k<=n; k++)
            {
                int a;
                a=i-S[k];
                if(a<0)
                {
                    C[j][i]=n+1;
                }
                if(a>=0)
                {
                    b=C[j-1][a];
                    if(k>b)
                    {
                        C[j][i]=k;
                        break;
                    }
                    else
                    {
                        C[j][i]=n+1;
                    }
                }
            }
        }
    }
}

void writing_Output(int m,int n,int* S,int** C) ///function for printing the output values that determine cardinality of subset sums
{
    int i,j;

    printf("m is %d\n",m); ///prints m
    printf("   i   S\n---------\n");

    for(i=0; i<=n; i++)
    {
        printf("   %d   %d\n",i,S[i]); ///Prints all the elements of the set
    }


    printf("\n\n  i   Card   C\n---------------\n");  ///Prints the Cost table
    for(i=0; i<=m; i++)
    {
        for(j=1; j<=n; j++)
        {
            printf("  %d    %d   %d\n",i,j,C[j][i]);
        }
    }

    for(i=1; i<=n; i++)///prints final output
    {
        if(C[i][m]<n+1)
        {
            int x,y;
            printf("Solution with %d elements\n   i   S\n---------\n",i);
            printf("   %d   %d\n",C[i][m],S[C[i][m]]);
            x=m-S[C[i][m]];
            y=C[i-1][x];
            int k=2;
            while(y>0)
            {
                printf("   %d   %d\n",y,S[y]);
                x=x-S[y];
                y=C[i-k][x];
                k++;
            }
        }
        else
        {
            printf("No solution with %d elements \n",i);
        }
    }
    free(S); ///freeing the allocated memory for S
    for(i=0; i<=n; i++)
    {
        free(C[i]);  ///deleting the dynamically allocated array elements
    }
    free(C); ///freeing the allocated memory for C
}

int main()
{
    int first_num,second_num,i,j,k,b,sum_estimated;
    scanf("%d",&second_num);
    scanf("%d",&first_num);
    int *S;
    int **C;

    S = (int *)calloc(second_num+1,sizeof(int));///dynamically allocating memory for S
    C=(int **)calloc(second_num+1,sizeof(int*));///dynamically allocating memory for C
    for(i=0; i<=second_num; i++)
    {
        C[i]=(int *)calloc(first_num+1,sizeof(int));
    }
    C[0][0]=0;

    for(j=1; j<=first_num; j++)
    {
        C[0][j]=second_num+1;
    }
    for(j=1; j<=second_num; j++)
    {
        C[j][0]=second_num+1;
    }


    for(i=0; i<=second_num; i++)    ///Adds elements to array S
    {
        if(i==0)
        {
            S[0]=0;
        }
        else
        {
            scanf("%d",S+i);
        }
    }
    find_the_subset(S, C, second_num,first_num);
    writing_Output(first_num, second_num, S, C);
}
