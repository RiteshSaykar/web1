#include <stdio.h>
int visited[10];
int graph[10][10],n;
void BFS(int start_node)
{
    int u,v;
    int q[10],r=-1,f=0;
    for(int i=0;i<n;i++)
    {
        visited[i]=0;
    }
    visited[start_node]=1;
    q[++r]=start_node;
    while(r>=f)
    {
        u=q[f++];
        printf("\t %d",u);
        for(v=0;v<n;v++)
        {
            if(graph[u][v]==1&&visited[v]==0)
            {
                q[++r]=v;
                visited[v]=1;
            }
        }
        
    }
    
}

void main()
{
    int start_node=0;
    printf("Enter number of node=");
    scanf("%d",&n);
    printf("\n Enter weighted graph\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&graph[i][j]);
        }
    }
    printf("..................BFS Traversal..............\n");
    BFS(start_node);
    
  
}
