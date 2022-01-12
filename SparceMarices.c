#include <stdio.h>
void Accept(int a[15][15], int m, int n)
{
    int i,j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            printf("Enter a[%d][%d] element :\n", i, j);
            scanf(" %d", &a[i][j]);
        }
    }
}

void display(int s[100][3])
{
    int i;
    for (i = 0; i <= s[0][2]; i++)
    {
        printf("%d\t%d\t%d\n", s[i][0], s[i][1], s[i][2]);
    }
}


void Conversion(int a[15][15], int m, int n, int s[100][3])
{
    int k = 1;
    s[0][0] = m;
    s[0][1] = n;
    int i,j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (a[i][j] != 0)
            {
                s[k][0] = i;
                s[k][1] = j;
                s[k][2] = a[i][j];
                k++;
            }
        }
    }
    s[0][2] = k - 1;
    printf("\n*****Sparse Matrix*****\n");
    display(s);
}

void Simple_Transpose(int ST[100][3], int s[100][3])
{
    ST[0][0] = s[0][1];
    ST[0][1] = s[0][0];
    ST[0][2] = s[0][2];
    int k = 1;
    int i,j;
    for (i = 0; i <= s[0][1]; i++)
    {
        for (j = 1; j <= s[0][2]; j++)
        {
            if (i == s[j][1])
            {
                ST[k][0] = s[j][1];
                ST[k][1] = s[j][0];
                ST[k][2] = s[j][2];
                k++;
            }
        }
    }
    printf("\n*****Simple Transpose Matrix*****\n");
    display(ST);
}


void Fast_Transpose(int s[100][3], int FT[100][3])
{
    int i,k;
    int count[50]={0};
    int index[50]={0};
    FT[0][0]=s[0][1];
    FT[0][1]=s[0][2];
    FT[0][2]=s[0][2];

    for ( i = 1; i < s[0][2]; i++)
    {
        count[s[i][1]]+=1;
    }
    index[0]=1;
    for ( i = 1; i < s[0][2]; i++)
    {
        index[i]=index[i-1]+count[i-1];
    }
    for ( i = 1; i <= s[0][2]; i++)
    {
        k=index[s[i][1]];
        FT[k][0]=s[i][1];
        FT[k][1]=s[i][0];
        FT[k][2]=s[i][2];
        index[s[i][1]]+=1;
    }
    printf("\n*****Fast Transpose Matrix*****\n");
    display(FT);
}

int main(int argc, char const *argv[])
{
    int a[15][15], m, n, s[100][3], ST[100][3], FT[100][3];
    printf("Enter number of rows :\n");
    scanf(" %d", &m);
    printf("Enter number of columns :\n");
    scanf(" %d", &n);
    Accept(a, m, n);
    int operator;
    do
    {
        printf("\n1.Conversion\n2.Simple_Transpose\n3.Fast_Transpose\n");
        scanf(" %d", &operator);
        switch (operator)
        {
        case 1:
            Conversion(a, m, n, s);
            break;
        case 2:
            Simple_Transpose(ST,s);
            break;
        case 3:
            Fast_Transpose(s,FT);
            break;
        case 4:
            Fast_Transpose(s,FT);
        
        default:
            break;
        }

    } while (operator!= 0);

    return 0;
}
