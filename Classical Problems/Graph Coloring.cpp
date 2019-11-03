#include<bits/stdc++.h>
using namespace std;

vector<int> v[100005];
int n, cols, v_color[100005];

bool isSafe(int u, int col){
    for(int i=0;i<v[u].size();i++){
        int nd= v[u][i];
        if(v_color[nd]==col)
            return false;
    }

    return true;
}

void call(int at){
    if(at==n){
        for(int i=0;i<n;i++)
            cout<<i<<": "<<v_color[i]<<endl;
        puts("");
        return;
    }

    for(int i=1;i<=cols;i++){
        if(isSafe(at,i)){
            v_color[at]= i;
            call(at+1);
            v_color[at]= -1;
        }
    }
}


main(){
    puts("Enter no of vertices, no of edges:");
    memset(v_color,-1,sizeof(v_color));
    int edges, a, b;
    cin>>n>>edges;

    puts("Enter edges");

    for(int i=0;i<edges;i++){
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    puts("Enter no of colors:");
    cin>>cols;

    call(0);
}
