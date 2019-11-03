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

const int maxn= 10004;

i64 n, a[2][maxn], len[2], offset= 10000, occur[2][20004], dp[maxn][2];

i64 call(int pos, int rot){
    if(pos==len[rot])  return 0;
    if(dp[pos][rot]!=-1)  return dp[pos][rot];

    i64 opt1= -INF, opt2= -INF;

    opt1= a[rot][pos]+ call(pos+1,rot)- offset;
    if(occur[1-rot][a[rot][pos]]!=-1)
        opt2= a[rot][pos]+ call(occur[1-rot][a[rot][pos]]+1, 1-rot)- offset;

    return dp[pos][rot]= max(opt1,opt2);
}

main(){
    while(true){
        sets(dp);
        sets(occur);
        sl(len[0]);

        if(len[0]==0)  break;

        fr(len[0]){
            sl(a[0][i]);
            a[0][i]+= offset;
            occur[0][a[0][i]]= i;
        }

        sl(len[1]);

        fr(len[1]){
            sl(a[1][i]);
            a[1][i]+= offset;
            occur[1][a[1][i]]= i;
        }

        i64 ans= max(call(0,0),call(0,1));
        printf("%lld\n",ans);
    }
}
