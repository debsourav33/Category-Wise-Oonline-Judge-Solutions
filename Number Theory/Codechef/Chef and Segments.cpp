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

const int N= 1e4+5;


int a[N], n, pow_of[N][103];

vector<pll> factors;

bool mark[103];
vector <i64> primes;

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

i64 exp(i64 b, i64 e, i64 M){
    i64 ans=1;

    while(e){
        if(e&1)  ans= (ans*b) % M;
        b= (b*b) % M;
        e/= 2;
    }

    return ans;
}

int main(){
    outl(exp(2,7,1000000000));
    outl(exp(2,10,1000000000));
    outl(exp(2,9,1000000000));
    outl(exp(2,5,1000000000));
    outl(exp(2,1,1000000000));

    si(n);
    clr(pow_of[0]);
    sieve(102);

    fr1(n){
        si(a[i]);
        factorize(a[i]);

        frj(102)  pow_of[i][j]=  pow_of[i-1][j];

        for(pll p: factors)
            pow_of[i][p.ff]+= p.ss;
    }

    int q,l,r,m;
    si(q);

    while(q--){
        siii(l,r,m);

        i64 ans= 1;

        for(i64 p: primes){
            i64 power= pow_of[r][p] - pow_of[l-1][p];
            i64 val= exp(p,power,m);

            ans= (ans*val) % m;
        }

        outl(ans);
    }

}