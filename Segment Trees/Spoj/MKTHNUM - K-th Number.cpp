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

#define left 2*at
#define right 2*at+1

const int maxn= 100005;

int a[maxn], n, k;
vector<int> tree[4*maxn];

void marge(int at){
    tree[at].clear();
    int i=0, ls= tree[left].size();
    int j=0, rs= tree[right].size();

    while(i<ls && j<rs){
        if(tree[left][i]<tree[right][j])  tree[at].pb(tree[left][i++]);
        else  tree[at].pb(tree[right][j++]);
    }

    for(i=i;i<ls; )  tree[at].pb(tree[left][i++]);
    for(j=j;j<rs; )  tree[at].pb(tree[right][j++]);
}

void build(int at, int l, int r){
    if(l==r){
        tree[at].clear();
        tree[at].pb(a[l]);
        return;
    }

    int mid= (l+r)/2;

    build(left,l,mid);
    build(right,mid+1,r);
    marge(at);
}

vector<int> query(int x, int y, int at, int l, int r){
    if(l>=x && r<=y){
        return tree[at];
    }

    if(l>y || r<x)  return vector<int>();

    int mid= (l+r)/2;
    vector<int> a= query(x,y,left,l,mid);
    vector<int> b= query(x,y,right,mid+1,r);

    vector<int> tmp;
    int i=0, ls= a.size();
    int j=0, rs= b.size();

    while(i<ls && j<rs){
        if(a[i]<b[j])  tmp.pb(a[i++]);
        else  tmp.pb(b[j++]);
    }

    for(i=i;i<ls; )  tmp.pb(a[i++]);
    for(j=j;j<rs; )  tmp.pb(b[j++]);

    return tmp;
}

main(){
    //fastIO();
    int m;
    sii(n,m);


    fr(n)
        si(a[i]);

    int q, x, y, k;

    build(1,0,n-1);

    while(m--){
        siii(x,y,k);
        vector<int> tmp = query(x-1,y-1,1,0,n-1);
        printf("%d\n",tmp[k-1]);
    }
}
