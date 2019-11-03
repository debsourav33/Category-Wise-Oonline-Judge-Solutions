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

const int N= 62+5;

char s[N], t[N];
int n1, n2, dp[N][N][N][N][2];

int call(int i1, int i2, int j1, int j2, int turn){
    if(i1>j1 || i2>j2)  return 0;
    if(dp[i1][i2][j1][j2][turn]!=-1)  return  dp[i1][i2][j1][j2][turn];

    int ans= 0;
    if(!turn)
    {
        for(int i=i1; i<=j1;i++){
            for(int j=i2;j<=j2;j++) {
                //outii(s[i],s[j]);
                if(s[i]==t[j])
                    ans= max(ans, 1+call(i+1,j+1,j1,j2,1-turn));

            }
        }
    }
    else{
        int i= -1, j= -1;
        for(i= j1; i>=i1;i--)
            if(s[i]==s[i1-1])  break;

        for(j= j2; j>=i2;j--)
            if(t[j]==s[i1-1])  break;

        if(i>=i1 && j>=i2)
            ans= 1+ call(i1,i2,i-1,j-1,1-turn);
    }


    return dp[i1][i2][j1][j2][turn]= ans;
}

//cfcfaafc efagfc  afbcdfca bcadfcgyfka

main(){
    int opt, cas= 1;
    si(opt);

    while(opt--) {
        sets(dp);
        scanf("%s", s);
        scanf("%s", t);

        n1 = strlen(s), n2 = strlen(t);

        printf("Case %d: ",cas++);
        outi(call(0, 0, n1 - 1, n2 - 1, 0));
    }
}
