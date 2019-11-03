#include<bits/stdc++.h>
using namespace std;

#define clr(a) memset(a,0,sizeof(a))
#define sets(a) memset(a,-1,sizeof(a))
#define pb push_back

int visited[1000][1000], level[1000][1000], m, n;
char grid[1000][1000];

void reset(){
    clr(visited);
    clr(level);
}

int dr[]= {1,-1,0,0};
int dc[]= {0,0,1,-1};

struct node{
    int i, j;
    node(int _i, int _j){
        i=_i;
        j=_j;
    }
    node(){}
}parent[1000][1000];

bool is_valid(int i, int j){
    return i>=0 && j>=0 && i<=m && j<=n && grid[i][j]=='.' && !visited[i][j];
}


void bfs(node source){
    queue<node> q;
    q.push(source);
    parent[source.i][source.j]= node(-1,-1);
    visited[source.i][source.j]= 1;
    level[source.i][source.j]= 0;

    while(!q.empty()){
        node cell= q.front();
        q.pop();
        int i= cell.i, j= cell.j;

        for(int k=0;k<4;k++){
            int d_i= i+dr[k], d_j= j+dc[k];

            if(is_valid(d_i,d_j)){
                visited[d_i][d_j]= 1;
                level[d_i][d_j]= level[i][j]+1;
                parent[d_i][d_j]= node(i,j);
                q.push(node(d_i,d_j));

            }
        }
    }
}

void print_path(node nd){
    int i=nd.i, j=nd.j;

    if(parent[i][j].i==-1){
        cout<<i<<"-"<<j;
        return;
    }

    print_path(parent[i][j]);
    cout<<" "<<i<<"-"<<j;
}


main(){
    reset();
    cin>>m>>n;

    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            cin>>grid[i][j];

    bfs(node(0,0));
    cout<<level[m-1][n-1]<<endl;

    print_path(node(m-1,n-1));
    puts("");
}

