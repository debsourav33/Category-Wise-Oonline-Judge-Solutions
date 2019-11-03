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

const int maxn= 1e5;

int n, a[maxn], root[maxn], s[4*maxn], L[4*maxn], R[4*maxn], nxt= 1;

void marge(int at){
    s[at]= s[L[at]]+ s[R[at]];
}

void build(int at, int l, int r){
    if(l==r){
        s[at]= a[l];
        return;
    }

    L[at]= ++nxt;
    R[at]= ++nxt;

    int mid= (l+r)/2;

    build(L[at],l,mid);
    build(R[at],mid+1,r);
    marge(at);

}

int update(int at, int l, int r, int p, int v){
    int id= ++nxt;
    if(l==r){
        s[id]= (a[p]+=v);
        return id;
    }

    L[id]= L[at];  R[id]= R[at];

    int mid= (l+r)/2;

    if(p<=mid)  L[id]= update(L[id],l,mid,p,v);
    else  R[id]= update(R[id],mid+1,r,p,v);

    marge(id);

    return id;
}

int query(int id, int l, int r, int x, int y){
    if(l>=x && r<=y)  return s[id];
    if(l>y || r<x)  return 0;

    int mid= (l+r)/2;
    int a= query(L[id],l,mid,x,y);
    int b= query(R[id],mid+1,r,x,y);

    return a+b;
}


main(){
    sl(n);

    fr(n)
        sl(a[i]);

    build(1,0,n-1);

    i64 qr, p[10004], v[10004];
    sl(qr);
    fr(qr)
        sll(p[i],v[i]);

    root[0]= update(1,0,n-1,p[0],v[0]);

    fr1(qr-1){
        root[i]= update(root[i-1],0,n-1,p[i],v[i]);
    }

    int mq,x,y,up;
    si(mq);

    fr(mq){
        siii(x,y,up);
        cout<<query(root[up-1],0,n-1,x,y)<<endl;
    }
}
/*
8
0 1 2 3 4 5 6 7
3
1 2
3 4
7 10
10
0 1 1
0 0 1
1 1 1
2 3 1
2 3 2
*/
