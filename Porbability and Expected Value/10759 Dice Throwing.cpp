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

#define outlflf(a,b) printf("%llf %llf\n",a,b);

const i64 N= 25;
i64 n, x, dp[N][155], space[N];

i64 call(i64 k, i64 score){
    if(k==n) return score>=x;
    if(dp[k][score]!=-1)  return dp[k][score];

    i64 events= 0;

    fr1(6)
        events+= call(k+1,score+i);

    return dp[k][score]= events;

}

void calc_space(){
    space[0]= 1;

    fr1(24){
        space[i]= space[i-1]*6;
    }
}

main(){
    calc_space();

    while(1) {
        sets(dp);
        sll(n, x);

        if(n==0)  return 0;

        i64 events= call(0,0);

        i64 gcd= __gcd(events,space[n]);

        if(space[n]/gcd==1)  outl(events/gcd);
        else  printf("%lld/%lld\n",events/gcd,space[n]/gcd);
    }
}
