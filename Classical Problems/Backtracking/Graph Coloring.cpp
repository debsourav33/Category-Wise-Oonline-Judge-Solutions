#include<bits/stdc++.h>
using namespace std;

//{
#define sets(a) memset(a, -1, sizeof(a))
#define clr(a) memset(a, 0, sizeof(a))
#define max(a,b) ((a)>(b)? (a):(b))
#define min(a,b) ((a)<(b)? (a):(b))
#define fr(n) for(int i=0;i<n;i++)
#define ull unsigned long long
#define ll long long
#define pb push_back
#define INF 10000007
#define all(v) v.begin(),v.end()
//}

vector<int> v[100005];
int n, cols, v_color[100005];

bool isSafe(int u, int col){
    fr(v[u].size()){
        int nd= v[u][i];
        if(v_color[nd]==col)
            return false;
    }

    return true;
}

void call(int cnt){
    if(cnt==n){
        fr(n)
            cout<<i<<": "<<v_color[i]<<endl;
        puts("");
        return;
    }

    fr(cols){
        if(isSafe(cnt,i)){
            v_color[cnt]= i;
            call(cnt+1);
            v_color[cnt]= -1;
        }
    }
}


main(){
    sets(v_color);
    int edges, a, b;
    cin>>n>>edges;

    cin>>cols;

    fr(edges){
        cin>>a>>b;
        v[a].pb(b);
        v[b].pb(a);
    }

    call(0);
}
