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

const int N= 2e5+5;

i64 n, fullmask, fac[15], dp[4097][15];

bool checkBit(i64 mask, i64 i){
    return mask & (1LL<<i);
}

i64 setBit(i64 mask, i64 i){
    return mask | (1LL<<i);
}

i64 resetBit(i64 mask, i64 i){
    return mask & ~(1LL<<i);
}

i64 call(i64 mask, i64 person){
    if(mask== fullmask && person==n)  return 1;
    else if(person==n)  return 0;

    if(dp[mask][person]!=-1)  return dp[mask][person];

    i64 ways= 0;

    for(i64 i=0; i<n; i++){
        if(person==i || checkBit(mask,i)) continue;

        ways+= call(setBit(mask,i),person+1);

    }

    return dp[mask][person]= ways;
}

void calc(){
    fac[0]= 1;

    fr1(14){
        fac[i]= fac[i-1]*i;
    }
}

main(){
    calc();
    int q;
    si(q);

    while(q--) {
        sets(dp);
        si(n);

        fullmask = 1;
        fr(n) {
            fullmask *= 2;
        }
        fullmask--;

        i64 events = call(0, 0);
        i64 space = fac[n];


        printf("%lld/%lld\n", events, space);
    }
}
