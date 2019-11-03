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

i64 n, q, a[N], presum[N][320], pre[N], sqroot;

void preprocess(){
    fr1(sqroot)
    {
        frj1(i)
        {
            i64 sum= 0, turn=1;
            for(int l=j; l<=n;l+=i)
            {
                int r= l+i-1;
                if(r>n)  break;

                sum+= (pre[r]-pre[l-1]) * turn;
                presum[r][i]= sum;

                turn*=-1;
            }
        }
    }
}

void query1(int l, int r, int k){
    i64 ans= presum[r][k]- presum[l-1][k];

    int odd= (l-1)/k;
    if(odd%2)  ans*=-1;

    outl(ans);
}

void query2(int l, int r, int k){
    i64 ans= 0, turn= 1;
    int st= l+k-1;

    for(int i=st; i<=r;i+=k){
        ans+= (pre[i]- pre[i-k]) * turn;
        turn*= -1;
    }

    outl(ans);
}



main(){
    sll(n,q);
    fr1(n){
        sl(a[i]);
        pre[i]= pre[i-1]+a[i];
    }

    sqroot= (i64) sqrt(n);

    preprocess();

    int l, r, k;

    while(q--){
        siii(l,r,k);

        if(k>=sqroot)  query2(l,r,k);
        else  query1(l,r,k);
    }
}
