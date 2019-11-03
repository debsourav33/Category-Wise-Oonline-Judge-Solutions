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

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

//less_equal(int) for multiset, less<int> for set
typedef tree<int, null_type, less_equal<int>, rb_tree_tag,
        tree_order_statistics_node_update>
        ordered_set;


const int maxn= 1e5+5;

int n, par[maxn];
vector<int> v[maxn];

ordered_set s[maxn];

void reset(){
    clr(par);
}

int finds(int r)
{
    if (par[r]==r)
        return r;
    return par[r]= finds(par[r]);

}

void unions(int a, int b){
    int p1= finds(a);
    int p2= finds(b);

    if(p1==p2)
        return;
    //outii(s[p1].size(),s[p2].size());


    ordered_set :: iterator itr;

    if(s[p1].size()<s[p2].size()){
        for(itr=s[p1].begin();itr!=s[p1].end();itr++){
            int o= *itr;
            s[p2].insert(o);
        }

        par[p1]= p2;
    }
    else{
        for(itr=s[p2].begin();itr!=s[p2].end();itr++){
            int o= *itr;
            s[p1].insert(o);
        }

        par[p2]= p1;
    }
}

void inserts(int a, int t){
    int p1= finds(a);

    s[p1].insert(t);
}

int query(int a, int t1, int t2){
    int p1= finds(a);

    int d= s[p1].order_of_key(t2+1) - s[p1].order_of_key(t1);
    return d;
}

int main()
{
    int opt, cas= 1;
    si(opt);

    while(cas<=opt)
    {
        printf("Case %d:\n",cas++);
        int q, o, t1, t2, f1, f2;
        sii(n, q);

        fr1(n) par[i] = i;

        while (q--)
        {
            si(o);

            if (o == 0) {
                sii(f1, f2);

                unions(f1, f2);
            } else if (o == 1) {
                sii(f1, t1);
                inserts(f1, t1);
            } else {
                siii(f1, t1, t2);

                outi(query(f1, t1, t2));
            }
        }

        fr1(maxn-1){
            s[i].clear();
            v[i].clear();
        }
    }

}

/*
 3 6
1 2 7
2 1 1 10
0 2 1
2 1 1 10
1 2 2
1 2 5
2 1 1 10
*/
