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

i64 n, a[5003], dp[10][5003];
char str[5003];

i64 call(int prev, int i){
    if(i==n)  return 1;
    if(dp[prev][i]!=-1)  return dp[prev][i];

    i64 opt1=0, opt2=0;

    if(prev && 10*prev+a[i]<=26)
        opt1= call(0,i+1);

    if(a[i])
        opt2= call(a[i],i+1);

    return dp[prev][i]= opt1+opt2;
}

main(){
    while(1){
        sets(dp);
        scanf("%s",str);

        if(str[0]=='0')
            break;

        n= strlen(str);
        fr(n){
            a[i]= str[i]- '0';
        }

        printf("%lld\n",call(a[0],1));
    }
}
