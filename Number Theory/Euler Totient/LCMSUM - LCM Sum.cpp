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

const int N= 1e6+5;

i64 res[N];

i64 phi[N], mark[N];

void sievephi(i64 n){
    fr1(n)  phi[i]= i;

    mark[1]= 1;
    phi[1]= 1;

    for(int i=2;i<=n;i++){
        if(mark[i])  continue;

        for(int j=i;j<=n;j+=i){
            mark[j]= 1;
            phi[j]= phi[j]- phi[j]/i;
        }
    }
}

void precalc(i64 n){
    for(i64 i=1;i<=n;i++){
        i64 cnt= 2;
        for(i64 j=i+i;j<=n;j+=i){
            res[j]+= (j*j)/i * phi[cnt++];  //phi[j/i]
        }
    }
}

main(){
    sievephi(N-2);
    precalc(N-2);

    i64 q, num;
    si(q);

    while(q--){
        sl(num);

        i64 ans= (res[num]+ 2* num)/2;
        outl(ans);
    }

}
