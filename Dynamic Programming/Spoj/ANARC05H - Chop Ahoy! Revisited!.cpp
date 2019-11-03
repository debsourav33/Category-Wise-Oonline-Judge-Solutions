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

i64 n, dp[300][30];
char str[30];

i64 call(i64 sum, int pos){
    if(pos==n)  return 1;
    if(dp[sum][pos]!=-1)  return dp[sum][pos];

    i64 s=0, cnt=0;
    for(int i=pos;i<n;i++){
        s+= str[i]-'0';

        if(s>=sum)
            cnt+= call(s,i+1);
    }


    return dp[sum][pos]= cnt;
}


main(){
    for(int i=1; ;i++){
        sets(dp);
        scanf("%s",str);

        if(str[0]=='b')
            return 0;

        n= strlen(str);

        printf("%d. %lld\n",i,call(0,0));
    }
}
