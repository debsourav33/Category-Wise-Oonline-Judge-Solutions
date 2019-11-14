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
i64 dp[20][20][2][2][2];

i64 call(i64 st, i64 endi, i64 f2, i64 f1, i64 f){
    if(endi<st)  return f2 || f1;

    i64 &ret= dp[st][endi][f2][f1][f];
    if(ret!=-1)  return ret;

    i64 lim= b[st];
    if(f2)  lim= 9;

    i64 opt= 0;
    for(i64 i=0;i<=lim;i++){
        if(!f && i==0)
            opt+= call(st+1,endi,1,0,0);
        else
            opt+= call(st+1,endi-1,f2||i<b[st], (i<b[endi] || (i==b[endi] && f1)),1);
    }

    return ret= opt;
}

i64 solve(i64 x, i64 y){
    if(!y)  return 1;
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

    i64 ans= call(0,b.size()-1,0,1,0);
    return ans;
}

int main(){
    int opt, cas= 1;
    si(opt);

    while(cas<=opt) {
        sll(x, y);
        if(x>y){
            i64 tmp= x;
            x= y;
            y= tmp;
        }

        i64 ans= solve(0, y)- solve(0,x-1);
        printf("Case %d: %lld\n",cas++,ans);
    }
}