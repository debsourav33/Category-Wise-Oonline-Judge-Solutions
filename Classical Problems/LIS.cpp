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

i64 n, a[100005], dp[100005], dir[100005];

i64 call(int pos){
    if(dp[pos]!=-1)  return dp[pos];
    i64 maxi= 0;

    for(int i=pos+1; i<n; i++){
        if(a[i]>a[pos]){
            i64 tmp= call(i);

            if(tmp>maxi){
                maxi= tmp;
            }
        }
    }

    return dp[pos]= maxi+1;
}


main(){
    sets(dp);
    i64 ans= 0;
    sl(n);

    fr(n)
        sl(a[i]);

    fr(n)
        ans= max(ans,call(i));

    cout<<ans<<endl;
}

/*
7
1 1 2 5 4 3 4
*/
