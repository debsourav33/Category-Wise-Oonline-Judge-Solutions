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
vector<i64> digits;
int n;
i64 dp[12][12];

i64 call(int prev, int pos){
    if(pos==n )   return 1;
    if(dp[prev][pos]!=-1)  return dp[prev][pos];

    i64 opt= 0;
    fr(digits.size()){
        if(abs(prev-digits[i])<=2)
            opt+= call(digits[i],pos+1);
    }

    return dp[prev][pos]= opt;
}

int main(){
    int opt, cas=1;
    si(opt);

    while(cas<=opt){
        digits.clear();
        sets(dp);

        int m,a;
        sii(m,n);

        fr(m){
            si(a);
            digits.pb(a);
        }

        i64 ans= 0;

        fr(m){
            ans+= call(digits[i],1);
        }

        printf("Case %d: %lld\n",cas++,ans);
    }
}

