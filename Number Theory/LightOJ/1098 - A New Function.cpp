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
i64 num;

i64 solve(i64 num){
    if(num==0)  return 0;

    i64 st= (i64) sqrt(num), lim= num/st, csod=0;
    //outll(st,lim);

    for(i64 i=2;i<=lim;i++){
        csod+= i* (num/i-1);
    }

    for(i64 i=st-1;i>=2;i--){
        i64 b= num/i, a=1+ num/(i+1);

        csod+= ((a+b)*(b-a+1)/2) * (i-1); //for i=5, for num=100:  (100/5)+1=21 to (100/4)=25 will occur 4 times
    }

    return csod;
}

main(){
    int opt;
    si(opt);

    for(int o=1;o<=opt;o++){
        sl(num);

        i64 ans= solve(num);
        printf("Case %d: %lld\n",o,ans);
    }
}
