#include <stdio.h>
#include <string.h>
struct player
{
    char name[20], country[20], category[20];
    int age;
    int Avg_Batting_Score;
    int No_Of_Wickets;
    int t20, odi;
} p[10];
void Accept(int n);
void Display(int n);
void No_Of_Batsman(char c[], int n);
void No_Of_Bowler(char c[], int n);
void sort(int n);
void Highest_Wicket(int n);
void DisplayInformation(char nm[], int n);
void Highest_Age(int n);
int main()
{
    int n;
    int Operator;
    char c[20];
    printf("\nEnter the number of players ");
    scanf("%d", &n);
    Accept(n);
    while (1)
    {
        printf("\n\n===============================================");
        printf("\n0.Stop\n1.Display\n2.No_Of_Batsman\n3.No_Of_Bowler\n4.Sorted_list_Avg_Batting_score\n5.Highist_Age_Player\n6.Bowler_With_Highest_Wicket\n7.Particular_player_Details\n");
        printf("Enter choice : \n");
        scanf("%d", &Operator);
        switch (Operator)
        {
        case 0:
            printf("\nThank you ");
            return 0;
        case 1:
            Display(n);
            break;
        case 2:
            printf("\nEnter the country name in small case letters : ");
            scanf(" %[^\n]%*c", c);
            No_Of_Batsman(c, n);
            break;
        case 3:
            printf("\nEnter the country name in small case letters : ");
            scanf(" %[^\n]%*c", c);
            No_Of_Bowler(c, n);
            break;
        case 4:
            sort(n);
            break;
        case 5:
            Highest_Age(n);
            break;
        case 6:
            Highest_Wicket(n);
            break;
        case 7:
            printf("\nEnter the name of player : ");
            char nm[100];
            scanf("%s", nm);
            DisplayInformation(nm, n);
            break;
        default:
            printf("\nEnter valid choice ");
        }
    }
    return 0;
}
void Accept(int n)
{
    printf("\n*********Enter Details of Player**********\n");
    for (int i = 0; i < n; i++)
    {
        printf("Name of player %d : \n", (i + 1));
        scanf(" %[^\n]%*c", p[i].name);
        printf("Country of player %d : \n", (i + 1));
        scanf(" %[^\n]%*c", p[i].country);
        printf("Category of player %d : \n", (i + 1));
        scanf(" %[^\n]%*c", p[i].category);
        if (strcmp(p[i].category, "batsman") == 0 || strcmp(p[i].category, "allrounder") == 0)
        {
            printf("Average batting score of player %d : \n", (i + 1));
            scanf("%d", &p[i].Avg_Batting_Score);
        }
        if (strcmp(p[i].category, "bowler") == 0 || strcmp(p[i].category, "allrounder") == 0)
        {
            printf("Number of wickets taken by player %d : \n", (i + 1));
            scanf("%d", &p[i].No_Of_Wickets);
        }
        printf("Age of player %d : \n", (i + 1));
        scanf("%d", &p[i].age);
        printf("T20s played by player %d : \n",(i+1));
        scanf("%d", &p[i].t20);
        printf("Number of ODIs played by player %d : \n",(i+1));
        scanf("%d", &p[i].odi);
    }
}
void Display(int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("\n^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
        printf("Details of player: %d \n", (i + 1));
        printf("Name: %s \n", p[i].name);
        printf("Country: %s \n", p[i].country);
        printf("Category: %s \n", p[i].category);
        printf("Age: %d \n", p[i].age);
        printf("No. of T20 played: %d\n",p[i].t20);
        printf("No. of ODI played: %d\n",p[i].odi);
    }
}
void No_Of_Batsman(char c[], int n)
{
    int t = 0;
    for (int i = 0; i < n; i++)
    {
        if ((strcmp(p[i].country, c) == 0) && (strcmp(p[i].category, "batsman") == 0))
            t++;
    }
    printf("**The number of batsman of %s are %d \n", c, t);
}
void No_Of_Bowler(char c[], int n)
{
    int t = 0;
    for (int i = 0; i < n; i++)
    {
        if ((strcmp(p[i].country, c) == 0) && (strcmp(p[i].category, "bowler") == 0))
            t++;
        else if ((strcmp(p[i].country, c) == 0) && (strcmp(p[i].category, "allrounder") == 0))
            t++;
    }
    printf("**The number of bowler of %s are %d \n", c, t);
}
void sort(int n)
{
    int max;

    char temp[100];
    int tem = 0;
    int t = 0;
    for (int i = 0; i < n - 1; i++)
    {

        max = i;
        for (int j = i + 1; j < n; j++)
            if (p[j].Avg_Batting_Score > p[max].Avg_Batting_Score)
                max = j;

        tem = p[max].Avg_Batting_Score;
        p[max].Avg_Batting_Score = p[i].Avg_Batting_Score;
        p[i].Avg_Batting_Score = tem;
        strcpy(temp, p[max].name);
        strcpy(p[max].name, p[i].name);
        strcpy(p[i].name, temp);
        t = p[max].age;
        p[max].age = p[i].age;
        p[i].age = t;
        strcpy(temp, p[max].country);
        strcpy(p[max].country, p[i].country);
        strcpy(p[i].country, temp);
        strcpy(temp, p[max].category);
        strcpy(p[max].category, p[i].category);
        strcpy(p[i].category, temp);
        t = p[max].No_Of_Wickets;
        p[max].No_Of_Wickets = p[i].No_Of_Wickets;
        p[i].No_Of_Wickets = t;
    }
    printf("\n    Name        Country        Category     Age  Wickets  Bat_avg  T20's  ODI's ");
    for (int i = 0; i < n; i++)
    {
        printf("\n    %s        %s        %s     %d  %d  %d  %d  %d", p[i].name, p[i].country, p[i].category, p[i].age, p[i].No_Of_Wickets, p[i].Avg_Batting_Score,p[i].t20,p[i].odi);
    }
}
void Highest_Age(int n)
{
    int h = 0;
    int high = p[0].age;
    for (int i = 0; i < n; i++)
        if (p[i].age > high)
            h = i;
    printf("\nThe details of batsman are ");
    printf("\n    Name        Country        Category     Age  Wickets  Bat_avg  T20's  ODI's ");
    printf("\n    %s        %s        %s     %d  %d  %d  %d  %d", p[h].name, p[h].country, p[h].category, p[h].age, p[h].No_Of_Wickets, p[h].Avg_Batting_Score,p[h].t20,p[h].odi);
}
void Highest_Wicket(int n)
{
    int h = 0;
    int high = p[0].No_Of_Wickets;
    for (int i = 0; i < n; i++)
        if (p[i].No_Of_Wickets > high)
            h = i;
    printf("\nThe details of bowler are ");
    printf("\n    Name        Country        Category     Age  Wickets  Bat_avg  T20's  ODI's ");
    printf("\n    %s        %s        %s     %d  %d  %d  %d  %d", p[h].name, p[h].country, p[h].category, p[h].age, p[h].No_Of_Wickets, p[h].Avg_Batting_Score, p[h].t20, p[h].odi);
}
void DisplayInformation(char nm[], int n)
{
    int t = 0;
    for (int i = 0; i < n; i++)
        if (strcmp(nm, p[i].name) == 0)
        {
            printf("\n    Name        Country        Category     Age  Wickets  Bat_avg  T20's  ODI's ");
            printf("\n    %s        %s        %s     %d  %d  %d  %d  %d", p[i].name, p[i].country, p[i].category, p[i].age, p[i].No_Of_Wickets, p[i].Avg_Batting_Score, p[i].t20, p[i].odi);
            t = 1;
            break;
        }
    if (t == 0)
        printf("\nPlayer not found");
}