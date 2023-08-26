#include<stdio.h>
int n;
 int c[10][10],d[10][10];
void floyds();
int main()
{
    int i,j;
    printf("\nEnter the number of vertices:");
    scanf("%d",&n);
    printf("\nEnter the cost matrix:");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            scanf("%d",&c[i][j]);
        }
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
            {
                d[i][j]=0;
            }
    }
    floyds();
    return 0;
}

void floyds()
{
    int i,j,k;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            d[i][j]=c[i][j];
        }
    }
    for(k=1;k<=n;k++)
    {
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                d[i][j]=d[i][j]>(d[i][k]+d[k][j])?(d[i][k]+d[k][j]):d[i][j];
            }
        }
    }
    printf("\nThe distance matrix is:\n");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            printf("%d\t",d[i][j]);
        }
        printf("\n");
    }
}