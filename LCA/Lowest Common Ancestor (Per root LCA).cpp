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

const int maxn= 2e5+5;

int vis[maxn], n, T[maxn], P[maxn][22], L[maxn], Dist[maxn];
vector<int> v[maxn];

void dfs(int u, int p){
    T[u]= p;
    L[u]= (p>-1) ? L[p]+1 : 1;

    for(int s: v[u]){
        if(s==T[u]) continue;

        dfs(s,u);
    }
}


void init_LCA(int n){
    sets(P);

    fr1(n){
        P[i][0]= T[i];
    }

    for(int j=1; (1<<j)<n;j++){
        fr1(n){
            if(P[i][j-1]!=-1)
                P[i][j]= P[P[i][j-1]][j-1];
        }

    }
}

int lca_query(int p, int q)
{
    int tmp, log, i;

    if (L[p] < L[q])
        tmp = p, p = q, q = tmp;

    log = 1;
    while (1) {
        int next = log + 1;
        if ((1 << next) > L[p])break;
        log++;

    }

    for (i = log; i >= 0; i--)
        if (L[p] - (1 << i) >= L[q])
            p = P[p][i];

    if (p == q)
        return p;

    for (i = log; i >= 0; i--)
        if (P[p][i] != -1 && P[p][i] != P[q][i])
            p = P[p][i], q = P[q][i];

    return T[p];
}

i64 getDist(int x, int y){
    int lc= lca_query(x,y);

    return L[x]+L[y]- 2*L[lc];
}

i64 lca_score(int r, int u, int v, int x){
    return getDist(x,u)+getDist(x,v)+getDist(x,r);
}

main(){
    int a,b;
    si(n);

    fr(n-1){
        sii(a,b);

        v[a].pb(b);
        v[b].pb(a);
    }

    L[1]= 0;
    dfs(1,-1);
    init_LCA(n);

    int opt;
    si(opt);

    int x, y, r;

    while(opt--){
        siii(r,x,y);

        i64 ans= r, mini= 1e16;

        int lca_rx= lca_query(r,x), lca_ry= lca_query(r,y), lca_xy= lca_query(x,y);

        if(lca_score(r,x,y,x)<mini) ans= x, mini= lca_score(r,x,y,x);
        if(lca_score(r,x,y,y)<mini) ans= y, mini= lca_score(r,x,y,y);
        if(lca_score(r,x,y,lca_rx)<mini) ans= lca_rx, mini= lca_score(r,x,y,lca_rx);
        if(lca_score(r,x,y,lca_ry)<mini) ans= lca_ry, mini= lca_score(r,x,y,lca_ry);
        if(lca_score(r,x,y,lca_xy)<mini) ans= lca_xy, mini= lca_score(r,x,y,lca_xy);

        outl(ans);
    }
}

/*
10
0 1 0 2
1 3 1 4
3 5 3 6
4 7
2 8 2 9

 */
