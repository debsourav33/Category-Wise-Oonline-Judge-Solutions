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

const int N= 1e6+5;

vector<pll> factors[N];
vector<i64> primes;
int mark[N], curr[N];

void sieve(i64 n){
    i64 limit= sqrt(n)+2;
    mark[0]= mark[1]= 1;

    primes.pb(2);

    for(int i=4; i<n; i+=2)
        mark[i]= 1;

    for(i64 i=3; i<n; i+=2)
    {
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

void sieve_factorize(i64 n){
    fr1(n)  curr[i]= i;

    for(i64 i: primes){
        for(i64 j=i; j<=n; j+=i)
        {
            i64 cnt= 0;
            while(curr[j]%i ==0)
            {
                cnt++;
                curr[j]/= i;
            }

            factors[j].pb(mp(i,cnt));
        }

    }
}

i64 nod(i64 n){
    i64 nods= 1;
    for(auto fac: factors[n])
        nods*= (1+fac.ss);

    return nods;
}

vector<i64> found;

main(){
    i64 n= 1000000;

    sieve(n);
    sieve_factorize(n);

    for(i64 i=2;i<=n;i++){
        i64 nods= nod(i);

        if(factors[nods].size()==2){
           if(factors[nods][0].ss==1 && factors[nods][1].ss==1)
               found.pb(i);
        }

    }

    for(int i=8;i<found.size();i+=9){
        outl(found[i]);
    }
}
