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

i64 n, a[22][22], dp[1048580][22];

i64 setbit(i64 num, i64 i){
    return num | (1LL<<i);
}

bool checkbit(i64 num, i64 i){
    return num & (1LL<<i);
}

i64 call(i64 B, i64 S){
    if(S==n)
        return 1;


    if(dp[B][S]!=-1)  return dp[B][S];

    i64 cnt= 0;

    fr(n){
        if(!checkbit(B,i) && a[S][i])
            cnt+= call(setbit(B,i), S+1);


    }

    return dp[B][S]= cnt;
}

main(){
    int opt;
    si(opt);

    while(opt--){
        sets(dp);
        sl(n);

        fr(n)
            for(int j=0;j<n;j++)
                sl(a[i][j]);

        printf("%lld\n",call(0,0));
    }
}

/*
20
0 1 1 1 0 1 0 0 0 1 0 1 1 1 1 1 1 1 1 1
0 0 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 0 1 0 0 0 0 0 1 0 1 1 1 1 1 1 1 1 1
0 1 0 1 0 1 0 1 0 1 1 1 1 1 1 1 1 1 1 1
1 0 0 1 0 0 0 0 1 0 1 1 1 1 1 1 1 1 1 1
0 0 1 0 1 1 0 0 0 0 1 1 1 1 1 1 1 1 1 1
1 0 1 0 1 1 1 0 1 1 0 1 1 1 1 1 1 1 1 1
1 0 1 1 0 1 1 0 0 1 0 1 1 1 1 1 1 1 1 1
0 0 1 1 0 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
0 1 0 0 0 0 0 0 0 1 1 1 1 1 1 1 1 1 1 1
0 1 1 0 0 0 0 0 1 0 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
*/
