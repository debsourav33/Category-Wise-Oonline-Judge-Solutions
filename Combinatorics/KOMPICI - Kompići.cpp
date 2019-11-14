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

i64 mask[1030], n;
i64 a[N];

main(){

    sl(n);

    fr(n) {
        sl(a[i]);

        int num = 0;

        while (a[i]) {
            i64 dig = a[i] % 10;

            num = num | (1 << dig);

            a[i] /= 10;
        }

        mask[num]++;
    }

    i64 ans = 0;

    fr1(1024) {
        for (int j = i + 1; j <= 1024; j++) {
            if (i != j && (i & j)) {
                ans += mask[i] * mask[j];
            }
        }
    }

    fr1(1024)  ans += (mask[i] * (mask[i] - 1)) / 2; //nC2= n*(n-1)/2

    outl(ans);

}
