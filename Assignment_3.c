#include<stdio.h>
struct student
{
    int Roll_No;
    char Name[20];
    char Division;
    char Add[20];
};

void accept(struct student students[20], int n)
{
    int i;
    for ( i = 0; i < n; i++)
    {
        printf("Roll No. : ");
        scanf("%d",&students[i].Roll_No);
        printf("Name : ");
        scanf(" %s",students[i].Name);
        printf("Division : ");
        scanf(" %c",&students[i].Division);
        printf("Add : ");
        scanf(" %s",students[i].Add);
    }
}

void Write_To_File(struct student students[20],int n)
{
    int i;
    FILE *fp;
    fp=fopen("data.txt","a");

    if (fp==0)
    {
        printf("ERROR\n");
        return;
    }
    else
    {
        for (i = 0; i < n ; i++)
        {
            fputs("\n",fp);
            fprintf(fp,"%d\t%s\t%c\t%s",students[i].Roll_No,students[i].Name,students[i].Division,students[i].Add);
        }
    }
    fclose(fp);
}

void Display(struct student students[20])
{
    FILE *fp;
    char ch;
    fp=fopen("data.txt","r");
    printf("Display :\n");
    if(fp==0)
    {
        printf("ERROR\n");
        return;
    }
    while((ch=getc(fp))!=EOF)
    {
        if(ch==',')
            printf("\t\t");
        else
          printf("%c",ch);  
    }
    fclose(fp);
}

void Display_Particular()
{
    struct student s;
    FILE *fp;
    int roll_no;
    fp=fopen("data.txt","r");
    printf("Enter Roll Number of students which you want to search : \n");
    scanf("%d",&roll_no);
    while(fscanf(fp,"%d%s%c%s",&s.Roll_No,s.Name,&s.Division,s.Add)!=EOF)
    {
        if(s.Roll_No==roll_no)
        {
            printf("Record Found \n");
            printf("%d\t\t%s\t\t%c\t\t%s\n",s.Roll_No,s.Name,s.Division,s.Add);
            return;
        }
    }
    fclose(fp);
    printf("No Records Found \n");
}

void Delete()
{
    struct student s;
    FILE *fp,*fp2;
    int roll_no;
    int found=0;
    fp=fopen("data.txt","r");
    fp2=fopen("temp.txt","w");
    printf("Enter Roll Number which you want to delete : \n");
    scanf("%d",&roll_no);
    if(fp==0 || fp2==0)
    {
        printf("ERROR\n");
        return;
    }
    while(fscanf(fp,"%d%s%c%s",&s.Roll_No,s.Name,&s.Division,s.Add)!=EOF)
    {
        if(s.Roll_No==roll_no)
        {
            found=1;
        }
        else
        {
            fprintf(fp2,"\n%d\t\t\t%s\t\t\t%c\t\t\t%s",s.Roll_No,s.Name,s.Division,s.Add);
        }     
    }
    fclose(fp);
    fclose(fp2);
    if(found)
    {
        fp2=fopen("temp.txt","r");
        fp=fopen("data.txt","w");
        while(fscanf(fp,"%d%s%c%s",&s.Roll_No,s.Name,&s.Division,s.Add)!=EOF)
        {
            fputs("\n",fp);
            fprintf(fp,"%d\t\t\t%s\t\t\t%c\t\t\t%s",s.Roll_No,s.Name,s.Division,s.Add);
        }
        fclose(fp);
        fclose(fp2);
    }
    else
    {
        printf("No Record Found \n");
    } 
}

int main(int argc, char const *argv[])
{
    struct student students[20];
    int n;
    int choice;
    do
    {
        printf("\n1.Create\n2.Display\n3.Display_Particular\n4.Delete\n5.Exit\nEnter Your Choice : ");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            printf("Enter Number of Students ");
            scanf("%d",&n);
            accept(students,n);
            Write_To_File(students,n);
            break;
        case 2:
            Display(students);
            break;
        case 3:
            Display_Particular();
            break;
        case 4:
            Delete();
            break;
        case 5:
            printf("\n**THANK YOU**\n");
            return 0;
        default:
            printf("\nInvalid Choice ! \n");
            break;
        }
    }while(choice!=5);
}
