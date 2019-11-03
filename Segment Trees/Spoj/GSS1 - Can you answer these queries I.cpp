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

i64 sum[200005], left_max[200005], right_max[200005], maxi[200005];
i64 num[50004];

struct node{
    i64 s, l, r, m;

    node(i64 _l, i64 _r, i64 _m, i64 _s){
        l= _l;
        r= _r;
        m= _m;
        s= _s;
    }
};

void marge(int at){

    left_max[at]= max(left_max[at*2], sum[at*2]+left_max[at*2+1]);
    right_max[at]= max(right_max[at*2+1], sum[at*2+1]+right_max[at*2]);
    maxi[at]= max( max(maxi[at*2],maxi[at*2+1]), right_max[at*2]+left_max[at*2+1]);
    sum[at]= sum[at*2]+ sum[at*2+1];
}

void build(int at, int l, int r){
    if(l==r){
        left_max[at]= num[l];
        right_max[at]= num[l];
        maxi[at]= num[l];
        sum[at]= num[l];

        return;
    }

    int mid= (l+r)/2;

    build(2*at,l,mid);
    build(2*at+1,mid+1,r);
    marge(at);
}

node query(int x, int y, int at, int l, int r){
    if(l>=x && r<=y)  return node(left_max[at], right_max[at], maxi[at], sum[at]);
    if(l>y || r<x)  return node(-INF,-INF,-INF,-INF);

    int mid= (l+r)/2;

    node a= query(x,y,2*at,l,mid);
    node b= query(x,y,2*at+1,mid+1,r);

    i64 le= max(a.l, a.s+ b.l);
    i64 ri= max(b.r, b.s+ a.r);
    i64 ma= max(max(a.m,b.m), a.r+b.l);
    i64 su= a.s+ b.s;

    return node(le,ri,ma,su);
}

main(){
    int n;
    si(n);

    fr(n)
        sl(num[i]);

    int q, x, y;
    cin>>q;

    build(1,0,n-1);

    while(q--){
        sii(x,y);

        node ans= query(x-1, y-1, 1, 0, n-1);
        printf("%lld\n",ans.m);
    }
}
