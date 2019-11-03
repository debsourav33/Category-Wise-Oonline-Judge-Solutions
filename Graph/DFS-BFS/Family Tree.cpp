#include<bits/stdc++.h>
using namespace std;

//{
#define si(a) scanf("%d",&a)
#define sii(a,b) scanf("%d %d",&a,&b);
#define siii(a,b,c) scanf("%d %d %d",&a,&b,&c);

#define sl(a) scanf("%lld",&a)
#define sll(a,b) scanf("%lld %lld",&a,&b);
#define slll(a,b,c) scanf("%lld %lld %lld",&a,&b,&c);

#define outi(a) printf("%d\n",a)
#define outii(a,b) printf("%d %d\n",a,b)
#define outis(a) printf(" %d",a)

#define outl(a) printf("%lld\n",a)
#define outll(a,b) printf("%lld %lld\n",a,b)
#define outls(a) printf(" %lld",a)

#define cel(n,k) ((n-1)/k+1)
#define sets(a) memset(a, -1, sizeof(a))
#define clr(a) memset(a, 0, sizeof(a))
#define max(a,b) ((a)>(b)? (a):(b))
#define min(a,b) ((a)<(b)? (a):(b))
#define fr(n) for(int i=0;i<n;i++)
#define fr1(n) for(int i=1;i<=n;i++)
#define pb push_back
#define all(v) v.begin(),v.end()
#define mp make_pair
#define ff first
#define ss second
#define INF 10000007
#define fastIO() ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long i64;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;
//}

vector<int> v[100005];
int vis[100005], parent[100005], n, worth[100005], maxi[100005], mini[100005];

void reset(){
    clr(vis);
    sets(parent);
}

int diff= -1;

int dfs(int u){
    vis[u]= 1;

    fr(v[u].size()){
        int nd= v[u][i];
        if(nd==parent[u]) continue;

        if(!vis[nd]){
            parent[nd]= u;
            int m= dfs(nd);
            maxi[u]= max(m, maxi[u]);

            diff= max(diff,abs(worth[u]-maxi[u]));
        }

    }

    vis[u]= 2;
    return maxi[u];
}

int mdfs(int u){
    vis[u]= 1;

    fr(v[u].size()){
        int nd= v[u][i];
        if(nd==parent[u]) continue;

        if(!vis[nd]){
            parent[nd]= u;
            int m= mdfs(nd);
            mini[u]= min(m, mini[u]);

            diff= max(diff,abs(worth[u]-mini[u]));
        }

    }

    vis[u]= 2;
    return mini[u];
}

main(){
    int a, b;

    si(n);

    fr1(n)
        si(worth[i]), maxi[i]= worth[i], mini[i]= worth[i];

    int root;
    fr1(n){
        si(a);
        if(a!=-1)
            v[a].pb(i);
        else
            root= i;
    }

    reset();
    dfs(root);
    reset();
    mdfs(root);

    outi(diff);

}
