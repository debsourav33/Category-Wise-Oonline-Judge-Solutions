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

char s[200005];
int n, a[200005], dp[200005][3];

int call(int i, int m){
    if(i==n)  return 0;
    if(dp[i][m]!=-1)  return dp[i][m];

    int opt1= 0, opt2= 0;

    if((a[i]+m)%3==0)  return dp[i][m]= 1+call(i+1,0);

    opt1= call(i+1, (a[i]+m)%3);
    if(a[i])  opt2= call(i+1, 0);

    return dp[i][m]= max(opt1,opt2);
}

main(){
    sets(dp);
    scanf("%s",s);
    n= strlen(s);

    fr(n){
        a[n-i-1]= s[i]-'0';
    }

    outi(call(0,0));


}
