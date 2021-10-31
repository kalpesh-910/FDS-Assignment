#include<stdio.h>

void accept(int *ptr, int n)
{   
    for(int i=0 ; i<n ; i++)
    {
        printf("Enter the %d element of set : \n",i+1);
        scanf("%d",(ptr+i));
    }
}

void display(int *ptr, int n)
{
    printf("{");
    for (int i = 0; i < n; i++)
    {
        printf("%d", *(ptr + i));
        if (i < n-1)
        {
            printf(",");
        }
    }
    printf("}\n");
}

void Union(int *a, int n1, int *b, int n2)
{
    int u[n1+n2], k=0 ,i1 ,i2,i3,j;
    for(i1=0 ; i1<n1 ; i1++)
    {
        u[k]=*(a+i1);
        k++;
    }
    for(j=0 ; j<n2 ; j++)
    {

        for(i2=0 ; i2<n1 ; i2++)
        {
            if(*(b+j)==*(a+i2))
            {break;}
        }
        if(i2==n1)
        {
            u[k]=*(b+j);
            k++;
        }
    }
    printf("Union Of Set is : \n");
    printf("U=");
    display(u,k);
}

void Intersetion(int *a, int n1, int *b, int n2)
{
    int  I[n1+n2], k=0, j, i, l; 
    for(j=0 ; j<n2 ; j++)
    {

        for(i=0 ; i<n1 ; i++)
        {
            if(*(a+j)==*(b+i))
            {
                I[k]=*(a+j);
                k++;
            }
        }
    }
    printf("Intersection of set is : \n");
    printf("I=");
    display(I,k);
}

void Difference_A(int *a, int n1, int *b, int n2)
{
    int i=0 , j=0 , k=0;
    int D[n1];
    for(i=0;i<n1;i++)
    {
        for(j=0;j<n2;j++){
            if(a[i]==b[j]){
                break;
            }
        }
        if(j==n2){
            D[k]=a[i];
            k++;
        }
    }
    printf("The elements of which are in set a but not in set b : \n");
    printf("D(a-b)=");
    display(D,k);
}

void Difference_B(int *a, int n1, int *b, int n2)
{
    int i=0 , j=0 , k=0;
    int D[n2];
    for(i=0;i<n2;i++)
    {
        for(j=0;j<n1;j++){
            if(b[i]==a[j]){
                break;
            }
        }
        if(j==n1){
            D[k]=b[i];
            k++;
        }
    }
    printf("The elements of which are in set b but not in set a : \n");
    printf("D(b-a)=");
    display(D,k);
}

void Symetric_Difference(int *a, int n1, int *b, int n2)
{
    int i=0 , j=0 , k=0;
    int D[n1+n2];
    for(i=0;i<n1;i++)
    {
        for(j=0;j<n2;j++){
            if(a[i]==b[j]){
                break;
            }
        }
        if(j==n2){
            D[k]=a[i];
            k++;
        }
    }
    for(i=0;i<n2;i++)
    {
        for(j=0;j<n1;j++){
            if(b[i]==a[j]){
                break;
            }
        }
        if(j==n1){
            D[k]=b[i];
            k++;
        }
    }
    printf("The symetric difference of set a and b : \n");
    printf("D=");
    display(D,k);
}


int main(int argc, char const *argv[])
{   int n1, n2;
    char expression;
    
    printf("Enter the size of set a \n");
    scanf("%d",&n1);
    int a[n1] ;
    printf("Enter the set a : \n");
    accept(a,n1);
    printf("Enter the size of set b \n");
    scanf("%d",&n2);
    int  b[n2];
    printf("Enter the set b : \n");
    accept(b,n2);
    printf("a=");
    display(a,n1);
    printf("b=");
    display(b,n2);
    int t;
    printf("Enter the number of operation you wants to do \n");
    scanf("%d",&t);
    while (t--)
    {
    printf("\n\nEnter the key as per your choice : \n1.Union 2.Intersection 3.Difference(a-b) 4.Difference(b-a) \n");
    scanf(" %c",&expression);
    switch (expression)
    {
    case '1':
        Union(a,n1,b,n2);
        break;
    case '2':
    Intersetion(a,n1,b,n2);
        break;
    case '3':
    Difference_A(a,n1,b,n2);
        break;
    case '4':
    Difference_B(a,n1,b,n2);
        break;
    case '5':
    Symetric_Difference(a,n1,b,n2);
        break;
    default:
        break;
    }
    }
    return 0;
}


