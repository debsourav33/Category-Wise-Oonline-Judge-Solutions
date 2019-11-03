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

const int N= 1e6+5, mod= 1000003;

i64 fac[N];

void preprocess(){
    i64 f= 1;
    fac[0]= 1;
    fr1(N){
        f*= i;
        f%= mod;

        fac[i]= f;
    }
}

i64 exp(i64 b, i64 e, i64 M){
    i64 ans=1;

    while(e){
        if(e&1)  ans= (ans*b) % M;
        b= (b*b) % M;
        e/= 2;
    }

    return ans;
}

i64 C(i64 n, i64 r) {
    if(r==0 || r==n)  return 1;

    if(r > n - r) r = n - r;
    i64 div= (fac[r]*fac[n-r]);

    i64 div_inv=  exp(div,mod-2,mod);

    i64 ans = fac[n]*div_inv;

    return ans%mod;
}

main(){
    preprocess();
    int opt, cas= 1;
    si(opt);

    i64 n,k;

    while(cas<=opt){
        sll(n,k);
        printf("Case %d: %lld\n",cas++,C(n,k));
    }
}
