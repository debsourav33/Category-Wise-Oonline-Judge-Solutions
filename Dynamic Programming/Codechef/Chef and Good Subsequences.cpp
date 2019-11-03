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

#define lefts 2*at
#define rights 2*at+1

const int N= 1e5+5, mod= 1000000007;
i64 a[N], cnt[N], dp[8003][8003];
int n, k;
vector<i64> b;

i64 call(int pos, int rem){
    if(b.size()-1-pos < rem)
        rem=  b.size()-pos-1;

    if (pos==b.size()-1 || !rem)  return cnt[b[pos]];
    if(dp[pos][rem]!=-1)  return dp[pos][rem];

    i64 c= cnt[b[pos]];
    i64 cn= c;

    for(int i=pos+1; i<b.size();i++){
        cn+= (c * call(i,rem-1)) % mod;
    }

    return dp[pos][rem]= cn % mod;
}

void input(){
    sii(n,k);

    fr(n)  si(a[i]);

    sort(a,a+n);

    b.pb(a[0]);  cnt[a[0]]++;

    fr1(n-1){
        cnt[a[i]]++;
        if(a[i]!=a[i-1])
            b.pb(a[i]);
    }

}

int main(){
    sets(dp);
    input();
    if(k>b.size())  k= b.size();

    i64 ans= 1;

    fr(b.size()){
        ans+= call(i,k-1);
        ans%= mod;
    }

    outl(ans);


}