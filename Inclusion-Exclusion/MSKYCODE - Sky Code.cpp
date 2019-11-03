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


const int N= 1e4+5;

vector<pll> d;
vector<i64> picks;
i64 mul[N], a[N], ans;
int n;

bool mark[N];
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

i64 nC4(i64 n){
    return (n*(n-1)*(n-2)*(n-3))/(4*3*2*1);
}

void call(int pos, i64 curr, i64 cnt){
    if(pos==picks.size()){
        if(curr>=N)  return;

        if(mul[curr]>=4 && cnt) {
            i64 sum = nC4(mul[curr]);
            if(cnt%2)  ans-= sum;
            else  ans+= sum;
        }

        return;
    }

    if(curr>=N)  return;
    if(mul[curr]<4)  return;

    call(pos+1,curr,cnt);
    call(pos+1,curr*picks[pos],cnt+1);
}

void precalc(){
    fr(n) {
        i64 num= a[i], j;
        for (j = 1; j*j < num; j++) {
            if(num%j==0)  mul[j]++, mul[num/j]++;
        }

        if(j*j==num)  mul[j]++;
    }


    for(i64 p: primes){
        if(mul[p]>=4)  picks.pb(p);
    }
}

main(){
    sieve(N-2);

    while(si(n)!=EOF) {
        picks.clear();
        clr(mul);

        fr(n) {
            sl(a[i]);
        }

        if(n<4){
            puts("0");
            continue;
        }

        precalc();

        ans= nC4(n);

        call(0,1,0);
        outl(ans);
    }
}
