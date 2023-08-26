#include<stdio.h>
#define MAX 7
int nodes[MAX];
int top=-1;
void main(){
    int i,j,n;
    printf("enter the number of nodes ");
    scanf("%d",&n);
    int matrix[n][n];
    printf("enter the values of matrix \n");
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            scanf("%d",&matrix[i][j]);
        }
    }
    topologicalSort(n,matrix);
}

void topologicalSort(int n, int matrix[n][n]){
    int i,j;
    int visited[MAX]={0};
    for(i=1;i<=n;i++){
        if(!visited[i])
            dfs(i,n,matrix,visited);
    }
    printf("Topological sort\n");
    while (top >= 0)
    {
        printf("%d ", nodes[top--]);
    }
}

void dfs(int v,int n,int matrix[n][n],int visited[n]){
    int i;
    visited[v]=1;
    for(i=1;i<=n;i++){
        if(matrix[v][i]==1 && !visited[i]){
            dfs(i,n,matrix,visited);
        }
    }
    nodes[++top]=v;
}