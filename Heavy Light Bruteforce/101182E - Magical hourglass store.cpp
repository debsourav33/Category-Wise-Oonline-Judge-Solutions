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
const int sN= 450;

vector<int> v[sN][sN];
int base[N], n, t;

void update1(int m, int q){
    for(int i=m;i<=t;i+=q){
        base[i]+=1;
    }
}

void update2(int m, int q){
    int mm= m%q;
    v[q][mm].pb(m);
}

int query(int x){
    int ret= base[x];

    fr1(sN-3){
        int m= x % i;

        int p= upper_bound(all(v[i][m]),x)- v[i][m].begin();
        ret+= p;
    }

    return ret;
}

void postprocess(){
    fr1(sN-1)
    {
        frj(i)
        {
            int curr = 0, cnt = 0;
            if (v[i][j].size() == 0) continue;

            //increment all the t that has the mod = j while divided by i

            for (int k = v[i][j][0]; k <= t; k+=i) {
                while (curr < v[i][j].size() && k == v[i][j][curr]) cnt++, curr++;

                base[k] += cnt;
            }
        }
    }
}

main(){
    int m,q;
    sii(n,t);

    fr1(n){
        sii(m,q);
        if(q>=sN-2)  update1(m,q);
        else  update2(m,q);
    }

    fr1(sN-1)
        frj(i)
            sort(all(v[i][j]));

    postprocess();

    fr1(t){
        outis(base[i]);
    }
}
