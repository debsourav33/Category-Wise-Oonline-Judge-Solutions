#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

//{
#define si(a) scanf("%d",&a)
#define sii(a,b) scanf("%d %d",&a,&b);
#define siii(a,b,c) scanf("%d %d %d",&a,&b,&c);

#define sl(a) scanf("%lld",&a)
#define sll(a,b) scanf("%lld %lld",&a,&b);
#define slll(a,b,c) scanf("%lld %lld %lld",&a,&b,&c);

#define outi(a) printf("%d\n",a)
#define outii(a,b) printf("%d %d\n",a,b)
#define outiii(a,b,c) printf("%d %d %d\n",a,b,c)
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

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef long long i64;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;
//}

const int N= 2e5+5, mod= 1000000007;

#define lefts 2*at
#define rights 2*at+1

i64 n, a[N], b[N], sum[4*N];

void merge(i64 at){
    sum[at]= sum[lefts]+ sum[rights];
    sum[at]%= mod;
}

void build(i64 at, i64 L, i64 R){
    if(L==R){
        sum[at]= 0;
        return;
    }

    i64 mid= (L+R)/2;

    build(lefts,L,mid);
    build(rights,mid+1,R);

    merge(at);
}

void update(i64 at, i64 L, i64 R, i64 pos, i64 val){
    if(L==R){
        sum[at]+= val;
        sum[at]%= mod;
        return;
    }

    i64 mid= (L+R)/2;
    if(pos<=mid)
        update(lefts, L, mid, pos, val);
    else
        update(rights, mid+1, R, pos, val);

    merge(at);
}

i64 query(i64 at, i64 L, i64 R, i64 l, i64 r){
    if(r<L || l>R)  return 0;
    if(l<=L && r>=R)  return sum[at]%mod;

    i64 mid= (L+R)/2;

    i64 x= query(lefts, L, mid, l, r);
    i64 y= query(rights, mid+1, R, l, r);

    return (x+y)%mod;
}

main(){
    int opt, t=1;
    si(opt);

    while(opt--){
        si(n);
        fr(n){
            sl(a[i]);
            b[i]= a[i];
        }

        sort(b,b+n);

        fr(n)  a[i]= upper_bound(b,b+n,a[i]) - b;

        //fr(n)  outls(a[i]); puts("");

        build(1,0,N-1);

        fr(n){
            i64 s= query(1,0,N-1,0,a[i]-1);

            update(1,0,N-1,a[i],s+1);
        }

        printf("Case %d: %lld\n",t++,sum[1]%mod);
    }

}