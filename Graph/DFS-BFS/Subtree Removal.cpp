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
#define fr(n) for(int i=0;i<n;i++)
#define fr1(n) for(int i=1;i<=n;i++)
#define frj(n) for(int j=0;j<n;j++)
#define frj1(n) for(int j=1;j<=n;j++)
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

const int maxn= 1e5+5;

vector<int> v[maxn];
i64 vis[maxn], val[maxn], n, k;

void reset(){
    fr(maxn)  v[i].clear();
    clr(vis);
}

i64 dfs(int u){
    vis[u]= 1;
    i64 gain= val[u];

    fr(v[u].size()){
        int nd= v[u][i];

        if(!vis[nd]){
            vis[nd]= 1;
            gain+= dfs(nd);

        }
    }

    gain= max(gain, -k);

    return gain;
}

main(){
    int opt;
    si(opt);

    while(opt--) {
        reset();
        int a, b;

        sii(n, k);

        fr1(n)
            sl(val[i]);

        fr(n - 1) {
            sii(a, b);

            v[a].pb(b);
            v[b].pb(a);
        }

        outl(dfs(1));
    }
}

/*
2
11 5

7 -6 3 7 -15 2 3 1 -2 -2 -6

1 2 1 3
2 4 2 5 2 6 5 7 5 8
4 9
3 10 3 11
*/
