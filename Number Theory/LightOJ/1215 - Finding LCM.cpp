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
#define fr(n) for(i64 i=0;i<n;i++)
#define fr1(n) for(i64 i=1;i<=n;i++)
#define frj(n) for(i64 j=0;j<n;j++)
#define frj1(n) for(i64 j=1;j<=n;j++)
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

vector<pll> factors[3];

bool mark[N];
vector <i64> primes;
map<i64,i64> mark_l, max_p;

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

void factorize(i64 n, int c){
    factors[c].clear();

    for(i64 i: primes){
        if(i*i>n)  break;

        i64 fl=0, cnt=0;

        while(n%i==0){
            n/= i;
            cnt++;
            fl= 1;

        }
        if(fl)  factors[c].pb(mp(i,cnt));

    }

    if(n>1)  factors[c].pb(mp(n,1));
}

i64 check(i64 a, i64 b, i64 l){
    vector<i64> ab_primes;

    factorize(a,0);
    factorize(b,1);

    for(pll p: factors[0]){
        ab_primes.pb(p.ff);

        if(max_p.count(p.ff)==0 || p.ss>max_p[p.ff])
        max_p[p.ff]= p.ss;
    }

    for(pll p: factors[1]){
        ab_primes.pb(p.ff);

        if(max_p.count(p.ff)==0 || p.ss>max_p[p.ff])
            max_p[p.ff]= p.ss;
    }

    factorize(l,2);

    for(pll p: factors[2]){
        mark_l[p.ff]= p.ss;
    }

    for(i64 f: ab_primes){
        if(mark_l.count(f)==0 || mark_l[f] < max_p[f])
            return -1;
    }

    i64 c= 1;

    for(pll p: factors[2]){
        i64 f= p.ff, pw= p.ss;

        if(f>1e6 || max_p.count(f)==0 || max_p[f]<pw){
            fr(pw)  c*= f;
        }
    }

    return c;
}

main(){
    sieve(N-2);

    int opt, cas= 1;
    si(opt);

    while(opt--) {
        i64 a,b,l;
        slll(a,b,l);

        i64 ans= check(a,b,l);
        if(ans==-1)  printf("Case %d: impossible\n",cas++);
        else  printf("Case %d: %lld\n",cas++,ans);

        mark_l.clear();
        max_p.clear();
    }
}
