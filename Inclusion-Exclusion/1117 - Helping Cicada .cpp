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

vector<pll> d;
vector<i64> preds;

void call(int pos, i64 curr, i64 cnt){
    if(pos==preds.size()){

        d.pb(mp(curr,cnt%2));  //cnt%2==1 means inclusion, cnt%2==0 means exclusion
        return;
    }

    i64 lcm= (curr*preds[pos])/__gcd(curr,preds[pos]);
    call(pos+1,curr,cnt);
    call(pos+1,lcm,cnt+1);
}

main(){
    int opt, n, m;
    i64 a;
    si(opt);

    frj(opt) {
        d.clear();
        preds.clear();

        sii(n,m);
        fr(m) {
            sl(a);
            preds.pb(a);
        }

        fr(preds.size())
            call(i+1,preds[i],1);

        i64 cnt= n;
        fr(d.size()){
            i64 f= d[i].ff, s= d[i].ss;

            if(s%2)
                cnt-= n/f;
            else
                cnt+= n/f;
        }

        printf("Case %d: %lld\n",j+1,cnt);
    }
}