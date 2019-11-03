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

i64 sum[400005], maxi[400005], s_maxi[400005];
i64 num[100005];

struct node{
    i64 s, m, s_m;

    node(i64 _m, i64 _s_m, i64 _s){
        m= _m;
        s_m= _s_m;
        s= _s;
    }
};

void marge(int at){
    if(maxi[left]>=maxi[right]){
        maxi[at]= maxi[left];
        s_maxi[at]= max(s_maxi[left], maxi[right]);
    }
    else{
        maxi[at]= maxi[right];
        s_maxi[at]= max(s_maxi[right], maxi[left]);
    }

    sum[at]= maxi[at]+ s_maxi[at];
}

void build(int at, int l, int r){
    if(l==r){
        maxi[at]= num[l];
        s_maxi[at]= -INF;
        sum[at]= num[l];

        return;
    }

    int mid= (l+r)/2;

    build(2*at,l,mid);
    build(2*at+1,mid+1,r);
    marge(at);
}

void update(int at, int l, int r, int pos, int y){
    if(l==r){
        maxi[at]= y;
        s_maxi[at]= -INF;
        sum[at]= y;

        return;
    }

    int mid= (l+r)/2;

    if(pos<=mid) update(2*at,l,mid,pos,y);
    else  update(2*at+1,mid+1,r,pos,y);
    marge(at);
}

node query(int x, int y, int at, int l, int r){
    if(l>=x && r<=y)  return node(maxi[at], s_maxi[at], sum[at]);
    if(l>y || r<x)  return node(-INF,-INF,-INF);

    int mid= (l+r)/2;

    node a= query(x,y,2*at,l,mid);
    node b= query(x,y,2*at+1,mid+1,r);

    i64 mm, s_mm, ss;

    if(a.m>=b.m){
        mm= a.m;
        s_mm= max(a.s_m, b.m);
    }
    else{
        mm= b.m;
        s_mm= max(b.s_m, a.m);
    }

    ss= mm+s_mm;

    return node(mm,s_mm,ss);
}

main(){
    int n;
    si(n);

    fr(n)
        sl(num[i]);

    int q, x, y;
    char opt;
    cin>>q;

    build(1,0,n-1);

    while(q--){
        scanf("\n%c",&opt);
        sii(x,y);
        if(opt=='Q'){
            node ans= query(x-1, y-1, 1, 0, n-1);
            printf("%lld\n",ans.s);
        }
        else
            update(1,0,n-1,x-1,y);
    }
}

/*
7
-4 -9 -3 7 -4 11 2
7
Q 1 4
Q 1 3
U 1 2
Q 1 4
Q 2 7
U 6 -2
Q 4 7
*/
