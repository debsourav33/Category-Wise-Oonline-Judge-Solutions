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

const int maxn=2e3+5;

int n, k, dp[maxn][maxn][3];
char s[maxn];

int check(char c, int i){
    if ((i==0 && c=='R')||(i==1 && c=='G')||(i==2 && c=='B'))
        return 1;

    return 0;
}

int call(int i, int q, int now){

    if(q==k)  return 0;
    if(i==n)  return 1e6;

    if(dp[i][q][now]!=-1)  return dp[i][q][now];

    int o1=1e5, o2=1e5, o3= 1e5, o4= 1e5, o5= 1e5;

    if(check(s[i],now))
        o1= call(i+1,q+1,(now+1)%3);

    o2= 1+ call(i+1,q+1,(now+1)%3);
    o3= call(i+1,0,0);
    o4= call(i+1,0,1);
    o5= call(i+1,0,2);

   int mini= min(min(o1,o2),min(o3,o4));

   return dp[i][q][now]= min(mini,o5);

}

int main(){
    int opt=0;
    si(opt);

    while(opt--){
        sii(n,k);

        fr(n){
            for(int j=0;j<k;j++){
                dp[i][j][0]= -1;
                dp[i][j][1]= -1;
                dp[i][j][2]= -1;
            }
        }

        scanf("%s",s);

        int o1=call(0,0,0), o2= call(0,0,1), o3= call(0,0,2);
        outi(min(min(o1,o2),o3));

    }
}
