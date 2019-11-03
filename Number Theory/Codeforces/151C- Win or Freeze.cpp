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

i64 n;
vector<pll> factors;

void factorize(i64 n){
    factors.clear();

    for(i64 i=2; i*i<=n; i++){
        i64 fl=0, cnt=0;

        while(n%i==0){
            n/= i;
            cnt++;
            fl= 1;
        }


        if(fl)  factors.pb(mp(i,cnt));
    }

    if(n>1)  factors.pb(mp(n,1));
}

main(){
    i64 a;
    sl(a);

    factorize(a);

    if(a==1 || factors[0].ff==a){
        puts("1");
        puts("0");
        return 0;
    }

    fr(factors.size()){
        if(factors[i].ss>=2 && (factors[i].ff*factors[i].ff)<a){
            puts("1");
            outl(factors[i].ff*factors[i].ff);
            return 0;
        }
    }

    if(factors.size()>2){
        puts("1");
        outl(factors[0].ff*factors[1].ff);
        return 0;
    }

    puts("2");
}