#include<bits/stdc++.h>
using namespace std;

//{
#define si(a) scanf("%d",&a)
#define sii(a,b) scanf("%d %d",&a,&b);
#define siii(a,b,c) scanf("%d %d %d",&a,&b,&c);

#define sl(a) scanf("%lld",&a)
#define sll(a,b) scanf("%lld %lld",&a,&b);
#define slll(a,b,c) scanf("%lld %lld %lld",&a,&b,&c);

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

#define lefts 2*at
#define rights 2*at+1

i64 n, a[200005], prefix[200005];
vector<i64> tree[800020];

void marge(int at){
    tree[at].clear();
    int i= 0, ls= tree[lefts].size();
    int j= 0, rs= tree[rights].size();

    while(i<ls && j<rs){
        if(tree[lefts][i]<tree[rights][j])  tree[at].pb(tree[lefts][i++]);
        else tree[at].pb(tree[rights][j++]);
    }

    for(i=i;i<ls; )  tree[at].pb(tree[lefts][i++]);
    for(j=j;j<rs; )  tree[at].pb(tree[rights][j++]);
}

void build(int at, int L, int R){
    if(L==R){
        tree[at].clear();
        tree[at].pb(prefix[L]);
        return;
    }

    int mid= (L+R)/2;

    build(lefts,L,mid);
    build(rights,mid+1,R);
    marge(at);
}

i64 query(int at, int L, int R, int l, int r, i64 val){
    if(r<L || l>R)  return 0;
    if(l<=L && r>=R){
        i64 p= upper_bound(tree[at].begin(),tree[at].end(),val-1)- tree[at].begin();
        return p;
    }

    int mid= (L+R)/2;

    i64 x= query(lefts, L, mid, l, r, val);
    i64 y= query(rights, mid+1, R, l, r, val);
    return x+y;
}

main(){
    i64 t;
    sll(n,t);

    fr1(n){
        sl(a[i]);
        prefix[i]= prefix[i-1]+ a[i];
    }

    build(1,0,n);

    i64 ans=0;

    fr1(n){
        ans+= query(1,0,n,i,n,prefix[i-1]+t);
    }

    printf("%lld\n",ans);
}
