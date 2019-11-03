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

/*
 Idea/Hint:

 we have to find a+(a+1)+(a+2)+....+b= num
                => [(a+b) * (b-a+1)] /2= num
                => (a+b) * (b-a+1)= num*2
 Observations:

 1. (a+b) must be greater than n= (b-a+1)
 2. if a+b is odd, n should be even i.e. different parity

 So, iterate over all possible divisors of num*2, and consider the divisor as n= b-a+1
 Then, (num*2)/divisor is equal to a+b

 Just check if these pairs of n and a+b meets condition 1 and 2 and if so, increment the count! :)
 */

const int N= 1e5+5;

int opt;
i64 num, no, ab;
vector<i64> d;

vector<pll> factors;

bool mark[10000007];
vector <i64> primes;

void sieve(i64 n){
    i64 limit= sqrt(n)+2;
    mark[0]= mark[1]= 1;

    primes.pb(2);

    for(i64 i=4; i<n; i+=2)
        mark[i]= 1;

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
        if(i>n)  break;
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
    sieve(10000007);
    si(opt);

    for(int o=1;o<=opt;o++){
        sl(num);

        d.clear();
        factorize(2*num);
        genDiv(0,1);
        sort(all(d));
        //for(i64 ds: d)  outls(ds);

        i64 ans= 0;

        fr1(d.size()-2){
            no= (2*num)/d[i];
            ab= d[i];

            if(ab<=no) continue;  //(a+b) must be greater than n= (b-a+1)
            if(ab%2==no%2) continue;  //if a+b is odd, n should be even i.e. different parity

            ans++;
        }

        printf("Case %d: %lld\n",o,ans);
        // outl(ans);
    }
}
