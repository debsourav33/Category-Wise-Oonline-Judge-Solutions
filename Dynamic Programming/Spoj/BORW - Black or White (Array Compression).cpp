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

const int maxn= 205;

int n, a[maxn], b[maxn], dp[maxn][maxn][maxn];

int call(int p1, int p2, int i){
    if(i==n)  return 0;
    int &ret= dp[p1][p2][i];
    if(ret!=-1)  return ret;

    int opt1=INF, opt2= INF, opt3= INF;

    if(a[i]>p1)  opt1= call(a[i],p2,i+1);
    if(a[i]<p2)  opt2= call(p1,a[i],i+1);

    opt3= 1+ call(p1,p2,i+1);

    return ret= min(min(opt1,opt2),opt3);
}

main(){
    while(true){
        sets(dp);
        si(n);

        if(n==-1)  return 0;

        fr(n){
            si(a[i]);
            b[i]= a[i];
        }

        sort(b,b+n);

        fr(n)
            a[i]= lower_bound(b,b+n,a[i])- b + 1;

        printf("%d\n",call(0,203,0));
    }
}
