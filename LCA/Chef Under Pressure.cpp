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

const int maxn= 1e4+5;

int mini[105][maxn], n, item[maxn], T[maxn], P[maxn][22], L[maxn], k, r;
vector<int> v[maxn];

int item_dfs(int u, int p, int it){
    mini[it][u]= (item[u]==it) ? u: maxn;

    for(int s: v[u]){
        if(s==p) continue;

        mini[it][u]= min(mini[it][u], item_dfs(s,u, it));
    }

    return mini[it][u];
}

void dfs(int u, int p){
    T[u]= p;
    L[u]= (p>-1) ? L[p]+1 : 0;

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

int getParent(int p, int no){
    no--;
    if(no==-1)  return p;

    int log = 1;
    while (1) {
        int next = log + 1;
        if ((1 << next) > L[p])break;
        log++;

    }

    for(int i=log;i>=0;i--){
        if((1<<i)<=no) {
            p = P[p][i];
            no-= (1<<i);
        }
    }

    return P[p][0];
}

int can(int r, int k, int it){
    int par= getParent(r,k);

    return mini[it][par];
}

void binary_search(int a, int b){
    int lo= 0, hi= L[a];

    while(lo<hi){
        int mid= (lo+hi)/2;

        if(can(a,mid,b)!=maxn)  hi= mid;
        else  lo= mid+1;
    }

    //outi(mini[b][getParent(a,lo)]);
    if(can(a,lo,b)!=maxn)  outi(can(a,lo,b));
    else  puts("-1");
}

main(){
    int a,b, tmp;
    siii(n,k,r);

    fr(n-1){
        sii(a,b);

        v[a].pb(b);
        v[b].pb(a);
    }

    fr1(n)  si(item[i]);

    fr1(100)  tmp= item_dfs(r,-1, i);
    dfs(r,-1);

    L[r]= 0;
    init_LCA(n);

    int q;
    si(q);

    while(q--){
        sii(a,b);

        binary_search(a,b);
    }

}