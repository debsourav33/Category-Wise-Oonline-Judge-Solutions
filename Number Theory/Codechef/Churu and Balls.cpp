#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

//{
#define si(a) scanf("%d",&a)
#define sii(a,b) scanf("%d %d",&a,&b);
#define siii(a,b,c) scanf("%d %d %d",&a,&b,&c);

#define sl(a) scanf("%lld",&a)
#define sll(a,b) scanf("%lld %lld",&a,&b);
#define slll(a,b,c) scanf("%lld %lld %lld",&a,&b,&c);

#define outi(a) printf("%d\n",a)
#define outii(a,b) printf("%d %d\n",a,b)
#define outiii(a,b,c) printf("%d %d %d\n",a,b,c)
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

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef long long i64;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;
//}

const int N= 1e4+5;

bool mark[N];
vector <i64> primes;

void sieve(i64 n){
    i64 limit= sqrt(n)+2;
    mark[0]= mark[1]= 1;

    primes.pb(2);

    for(i64 i=4; i<n; i+=2)
        mark[i]= true;

    for(i64 i=3; i<n; i+=2){
        if(mark[i])
            continue;

        primes.pb(i);

        if(i<limit){
            for(i64 j=i*i; j<n; j+=i*2){
                mark[j]=1;
            }
        }

    }
}

int a[N], n, ans, sum[N];

i64 get(i64 p){
    i64 tot= 0;
    int addi= p-(a[0]%p);
    addi %= p;

    tot+= addi;
    int last= a[0]+addi, cur;



    fr1(n-1){
        cur= a[i];


        addi= p - (cur%p);
        addi %= p;

        tot+= addi;
    }


    return tot;
}

i64 get2(i64 p){
    i64 tot= 0, pos= 0, cur= p;

    while(pos<n){
        i64 up= upper_bound(a,a+n,cur) - a;

        i64 gap= up-pos;

        tot+= gap*cur;

        if(up>0){
            i64 s= sum[up-1];
            if(pos>0)  s-= sum[pos-1];
            tot-= s;

        }

        /*outl(cur);
        outll(pos,up);
        outl(tot);*/

        cur+= p;
        pos= up;
    }

    return tot;
}

int main(){
    sieve(N-1);
    int opt;
    si(opt);

    while(opt--){
        si(n);

        int init= 0;

        fr(n){
            si(a[i]);

            if(i && a[i]<a[i-1]){
                init+= a[i-1] - a[i];
                a[i]= a[i-1];

            }

            sum[i]= sum[i-1] + a[i];
        }

        sum[0]= a[0];

        i64 ans= 1e15;

        for(i64 p: primes) {
            if(p<sqrt(10000))
                ans = min(ans, get(p));
            else
                ans= min(ans,get2(p));
        }

        outl(ans+init);
    }
}