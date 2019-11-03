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

const int N= 1e6+6;

i64 n;
vector<pll> factors;

bool mark[N];
vector <i64> primes, d;

void sieve(i64 n){
    i64 limit= sqrt(n)+2;
    mark[0]= mark[1]= 1;

    primes.pb(2);

    for(i64 i=4; i<n; i+=2)
        mark[i]= true;

    for(i64 i=3; i<n; i+=2){
        if(mark[i])
            continue;

        primes.pb(i);

        if(i<limit){
            for(i64 j=i*i; j<n; j+=i*2){
                mark[j]=1;
            }
        }

    }
}


void factorize(i64 n){
    factors.clear();

    for(i64 i: primes){
        if(i*i>n)  break;

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

void genDiv(int pos, i64 prev){
    if(pos==factors.size()){
        d.pb(prev);
        return;
    }

    genDiv(pos+1,prev);

    i64 curr= 1;

    fr(factors[pos].ss) {
        curr*= factors[pos].ff;
        genDiv(pos + 1, prev * curr);
    }
}

main(){
    sieve(N-2);

    int opt, cas=1;
    si(opt);

    while(opt--) {
        i64 st;
        sll(n, st);

        factorize(n);
        d.clear();
        genDiv(0, 1);
        sort(all(d));

        i64 ans = 0;


        for (i64 div: d) {
            if (div >= n/div) break;

            if (div >= st && n/div >=st) ans++;
        }


        printf("Case %d: %lld\n",cas++,ans);
    }
}
