//BFS with color
#include<bits/stdc++.h>

using namespace std;

#define WHITE 1
#define GRAY 2
#define BLACK 3

int adj[100][100];
int color[100];
int parent[100];
int dis[100];

int node, edge;

void bfs(int startingnode)
{
    for( int i=0 ; i<node ; i++)
    {
       color[i]=WHITE; //unvisited hole color hobe i
       dis[i]=INT_MIN;
       parent[i]=-1;
    }

    dis[startingnode]=0;
    parent[startingnode]=-1;

    queue <int> q;
    q.push(startingnode);

    while(!q.empty())
    {
        int x;
        x = q.front();
        q.pop();
        color[x]=GRAY; //visited hole grey

        printf("%d\t", x);

        for(int i=0 ; i<node ; i++)
        {
            if(adj[x][i]==1)
            {
                if(color[i]==WHITE)
                {
                    //x er neighbour i
                    //x node e hocche i er parent
                    dis[i]=dis[x]+1;
                    parent[i]=x;
                    q.push(i);
                }
            }
        }
        color[x]=BLACK;
    }
}

int main()
{
    scanf("%d %d", &node, &edge);

    int n1, n2;

    for( int i=0 ; i<edge ; i++ )
    {
       scanf("%d %d", &n1, &n2);
       adj[n1][n2] = 1;
       adj[n1][n2] = 1;
    }
    bfs(0);
    printf("\n%d", parent[5]);
    printf("\n%d", dis[7]);
    return 0;
}
