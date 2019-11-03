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

const int N= 1e5+5;

int a[N], n, k;
double dp[N];
int num;
vector<int> divs[N];

void sieve_div(int n){
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j+=i){
            divs[j].pb(i);
        }
    }
}

double call(int num){
    if(num==1)  return 0.0;
    if(dp[num]!=-1)  return dp[num];

    double ans= 0;
    double opt= divs[num].size();

    fr(divs[num].size()-1){
        int d= divs[num][i];
        ans+= 1/opt * (1+call(d));
    }

    ans= (ans+1/opt)*(opt/(opt-1));  //t(2)= 1/2 (1+ t(2))+ 1/2 + (1+t(1)) --> solve this equation for t(2)
    return dp[num]= ans;
}

main(){
    fr(N-2)  dp[i]= -1;
    sieve_div(N-2);

    int opt, cas=1;
    si(opt);

    while(opt--) {
        si(num);

        printf("Case %d: %lf\n", cas++, call(num));
    }
}
