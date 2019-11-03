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

i64 n, k, a[100005], dp[102][102][102];

i64 call(i64 p, i64 amount, i64 i){
    if(amount==0)  return 0;
    if(i>k || amount<0)  return 10e12;
    if(dp[p][amount][i]!=-1)  return dp[p][amount][i];

    i64 opt1= 10e12, opt2= 10e12;

    if(p<n && a[i]!=-1)
    opt1= a[i]+ call(p+1,amount-i,i);

    opt2= call(p,amount,i+1);


    return dp[p][amount][i]= min(opt1,opt2);
}


main(){
    int opt;
    si(opt);

    while(opt--){
        sets(dp);
        sll(n,k);
        fr1(k)
            sl(a[i]);

        i64 ans= call(0,k,1);

        if(ans==10e12)  printf("-1\n");
        else printf("%lld\n",ans);
    }
}
