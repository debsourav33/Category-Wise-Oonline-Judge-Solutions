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

i64 n;

bool mark[1000006];
vector <int> primes;

void sieve(int n){
    int limit= sqrt(n)+2;
    mark[0]= mark[1]= 1;

    primes.pb(2);

    for(int i=4; i<n; i+=2)
        mark[i]= 1;

    for(int i=3; i<n; i+=2){
        if(mark[i])
            continue;

        primes.pb(i);

        if(i<limit){
            for(int j=i*i; j<n; j+=i*2){
                mark[j]=1;
            }
        }

    }

}


i64 factorize(i64 n){
    i64 ans= 1;

    for(i64 i=0; i<primes.size() && primes[i]*primes[i]<=n; i++){
        i64 fl=0, cnt=0;

        i64 pr= primes[i];

        while(n%pr==0){
            n/= pr;
            cnt++;
            fl= 1;
        }

        if(fl)  ans*= (1+cnt);
    }

    if(n>1)  ans*=2;

    return ans;
}



int main(){
    sieve(1e6);
    cout<<primes[primes.size()-1]<<endl;
    int opt;
    si(opt);

    for(int o=1;o<=opt;o++) {
        i64 n;
        sl(n);

        i64 divs= factorize(n);
        printf("Case %d: %lld\n",o,divs-1);
    }

}
