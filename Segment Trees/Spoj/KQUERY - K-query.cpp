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

int n, a[100005], sum[400020], ans[200005], p[100005], r[200005], x[200005], y[200005], k[200005];

bool cmp(int x, int y){
    return a[x] < a[y];
}

bool cmp2(int x, int y){
    return k[x] < k[y];
}

void build(int at, int L, int R){
    if(L==R){
        sum[at]= 1;
        return;
    }

    int mid= (L+R)/2;

    build(lefts,L,mid);
    build(rights,mid+1,R);

    sum[at]= sum[lefts]+ sum[rights];
}

void update(int at, int L, int R, int pos){
    if(L==R){
        sum[at]= 0;
        return;
    }

    int mid= (L+R)/2;
    if(pos<=mid)
        update(lefts, L, mid, pos);
    else
        update(rights, mid+1, R, pos);

    sum[at]= sum[lefts]+ sum[rights];
}

int query(int at, int L, int R, int l, int r){

    if(r<L || l>R)  return 0;
    if(l<=L && r>=R)  return sum[at];

    int mid= (L+R)/2;

    int x= query(lefts, L, mid, l, r);
    int y= query(rights, mid+1, R, l, r);

    return x+y;
}

main(){
    si(n);

    fr(n){
        si(a[i]);
        p[i]= i;
    }

    sort(p,p+n,cmp);

    build(1,0,n-1);

    int q, po=0;
    si(q);

    fr(q){
       siii(x[i],y[i],k[i]);
       r[i]= i;
    }
    sort(r,r+q,cmp2);

    fr(q){
        while(po<n && a[p[po]] <= k[r[i]])
            update(1,0,n-1,p[po++]);

        ans[r[i]]= query(1,0,n-1,x[r[i]]-1,y[r[i]]-1);
    }

    fr(q)
        printf("%d\n",ans[i]);
}

/*
8
8 5 9 8 3 11 7 4
3
1 4 5
1 8 12
3 7 8
*/
