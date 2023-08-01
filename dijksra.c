#include <stdio.h>
int dist[10],visited[10];
void dijkstra(int graph[10][10], int n, int source)
{
    int u,v;
    for(int i=0;i<n;i++)
    {
        visited[i]=0;
        dist[i]=graph[source][i];
    }
    visited[source]=1;
    for(int ne=0;ne<n;ne++)
    {
        int min=999;
        for(int i=0;i<n;i++)
        {
            if(visited[i]==0 && dist[i]<min )
            {
                min=dist[i];
                u=i;
            }
        }
        visited[u]=1; 
        for(int v=0;v<n;v++)
        {
            if(visited[v]==0&&dist[u]+graph[u][v]<dist[v])
            {
                dist[v]=dist[u]+graph[u][v];
                
            }
        }
    }
    
    
}

int main()
{
    int graph[10][10],n,source;
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
    source=0;
    dijkstra(graph,n,source);
    
    printf("...........shortest path from source to all other node..........\n");
    for(int i=0;i<n;i++)
    {
        printf("%d-------->%d= %d \n",source,i,dist[i]);
    }

    return 0;
}