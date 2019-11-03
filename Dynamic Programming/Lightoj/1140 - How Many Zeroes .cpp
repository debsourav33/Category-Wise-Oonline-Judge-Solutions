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

i64 x, y;
vector<i64> a, b;
i64 dp[20][2][2][2][20];

i64 call(i64 pos, i64 f1, i64 f2, i64 f, i64 prev0){
    if(pos==b.size())  return prev0;

    i64 &ret= dp[pos][f1][f2][f][prev0];
    if(ret!=-1)  return ret;

    i64 lim= b[pos], st= a[pos];
    if(f1)  st= 0;
    if(f2)  lim= 9;

    i64 opt= 0;
    for(i64 i=st;i<=lim;i++){
        opt+= call(pos+1,f1||i>a[pos],f2||i<b[pos], f||i, f*(prev0+ (i==0)));
    }

    return ret= opt;
}

i64 solve(i64 x, i64 y){
    sets(dp);
    a.clear();
    b.clear();

    while(x){
        a.pb(x%10);
        x/=10;
    }

    while(y){
        b.pb(y%10);
        y/=10;
    }

    while(a.size()<b.size())
        a.pb(0);

    reverse(all(a));
    reverse(all(b));

    i64 ans= call(0,0,0,0,0);
    return ans;
}

int main(){
    int opt, cas= 1;
    si(opt);

    while(cas<=opt) {
        sll(x, y);

        i64 ans= solve(x, y);
        printf("Case %d: %lld\n",cas++,ans+(x==0));
    }
}
