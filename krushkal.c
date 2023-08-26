#include<stdio.h>
int cost[10][10],t[10][10],parent[10],n;
void kruskal()
{
 int i,j,u,v;
 int count=0;
 int k=0;
 int sum=0;
 for(i=0;i<n;i++)
 {
   parent[i]=i;
 }
 while(count!=n-1)
 {
  int min=999;
  for(i=0;i<n;i++)
  {
   for(j=0;j<n;j++)
   {
    if(cost[i][j]<min&&cost[i][j]!=0)
    {
      min=cost[i][j];
      u=i;
      v=j;
    }
   }
  }
  i=find(u);
  j=find(v);
  if(i!=j)
  {
   t[k][0]=u;
   t[k][1]=v;
   k++;
   count++;
   sum=sum+cost[u][v];
   union_ij(i,j);
  }
  cost[u][v]=cost[v][u]=999;
 }
 printf("Spanning Tree:\n");
 for(i=0;i<n;i++)
 printf("%d->%d\t",t[i][0],t[i][1]);
 printf("\nTotal Cost=%d",sum);
 getch();
}

void union_ij(int i,int j)
{
 if(i<j)
 {
 parent[j]=i;
 }
 else
 {
 parent[i]=j;
 }
}

int find(int v)
{
 while(parent[v]!=v)
 {
  v=parent[v];
 }
 return v;
}

int main()
{
 int i,j;
 printf("\nEnter the number of vertices:");
 scanf("%d",&n);
 printf("\Enter the cost matrix:");
 for(i=0;i<n;i++)
 {
  for(j=0;j<n;j++)
  {
    scanf("%d",&cost[i][j]);
  }
 }
 kruskal();
 return 0;
}