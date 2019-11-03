
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

const i64 mod= 1e8;

i64 n, x, y, d[100005], f[100005], dp[100005];
pll p[100005];

bool cmp(pll p1, pll p2){
    if(p1.ff==p2.ff)  return p1.ss<p2.ss;
    return p1.ff<p2.ff;
}

i64 call(i64 pos){
    if(pos==n)  return 1;
    if(dp[pos]!=-1)  return dp[pos];

    i64 opt1= call(pos+1);
    i64 opt2= call(upper_bound(d+pos+1,d+n,f[pos]-1)- d);

    return dp[pos]= (opt1+opt2) % mod;
}

int main(){
    while(1) {
        sl(n);
        if(n==-1)  return 0;

        sets(dp);

        fr(n) {
            sll(x, y);
            p[i] = mp(x, y);
        }

        sort(p, p + n, cmp);

        fr(n) {
            d[i] = p[i].ff;
            f[i] = p[i].ss;
        }

        i64 ans= call(0) - 1;
        i64 tmp= ans;
        i64 digit= 0;

        while(tmp){
            tmp/=10;
            digit++;
        }

        fr((8-digit))  printf("0");
        outl(ans);
    }
}
