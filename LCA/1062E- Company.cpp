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

#define lefts 2*at
#define rights 2*at+1

const int maxn= 1e5+5;

int vis[maxn], n, T[maxn], P[maxn][22], L[maxn], d[maxn], d_pos[maxn], t=0;
int lca[4*maxn], mini[4*maxn], maxi[4*maxn];
vector<int> v[maxn];

void dfs(int u, int p){
    T[u]= p;
    L[u]= (p>-1) ? L[p]+1 : 0;

    d[t]= u;
    d_pos[u]= t;
    t++;

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
    if(p==-1)  return q;
    if(q==-1)  return p;

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

void merge(int at){
    lca[at]= lca_query(lca[lefts], lca[rights]);
}

void build(int at, int L, int R){
    if(L==R){
        lca[at]= L;
        return;
    }

    int mid= (L+R)/2;

    build(lefts,L,mid);
    build(rights,mid+1,R);

    merge(at);
}

int query(int at, int L, int R, int l, int r){
    if(l>r)  return -1;
    if(r<L || l>R)  return -1;
    if(l<=L && r>=R)  return lca[at];

    int mid= (L+R)/2;

    int x= query(lefts, L, mid, l, r);
    int y= query(rights, mid+1, R, l, r);

    return lca_query(x,y);
}

void merge2(int at){
    mini[at]= min(mini[lefts],mini[rights]);
    maxi[at]= max(maxi[lefts],maxi[rights]);
}

void build2(int at, int L, int R){
    if(L==R){
        mini[at]= d_pos[L];
        maxi[at]= d_pos[L];
        return;
    }

    int mid= (L+R)/2;

    build2(lefts,L,mid);
    build2(rights,mid+1,R);

    merge2(at);
}

pii query2(int at, int L, int R, int l, int r){
    if(r<L || l>R)  return mp(1e6,0);
    if(l<=L && r>=R)  return mp(mini[at],maxi[at]);

    int mid= (L+R)/2;

    pii x= query2(lefts, L, mid, l, r);
    pii y= query2(rights, mid+1, R, l, r);

    int mn= min(x.ff,y.ff), mx= max(x.ss,y.ss);
    return mp(mn,mx);
}

main(){
    int a,b,q ;
    sii(n,q);

    for(int i=2;i<=n;i++){
        si(a);

        v[i].pb(a);
        v[a].pb(i);
    }

    L[1]= 0;
    dfs(1,-1);
    init_LCA(n);

    build(1,1,n);
    build2(1,1,n);

    fr(q){
        sii(a,b);

        pii m= query2(1,1,n,a,b);
        int mn= d[m.ff], mx= d[m.ss];

        //outii(mn,mx);

        int l1= query(1,1,n,a,mn-1), l2= query(1,1,n,mn+1,b);
        int lc1= lca_query(l1,l2);

        l1= query(1,1,n,a,mx-1), l2= query(1,1,n,mx+1,b);
        int lc2= lca_query(l1,l2);

        if(L[lc1]>=L[lc2])  outii(mn,L[lc1]);
        else  outii(mx,L[lc2]);

    }

}

