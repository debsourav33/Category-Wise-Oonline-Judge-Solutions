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

const int maxn= 2e2+5;

int n, m, par[maxn];
vector<int> v[maxn];

struct edge {
    int u, v, w;
    bool operator<(const edge& p) const
    {
        return w < p.w;
    }
};

multiset<edge> edges;

void reset(){
    fr1(n)  v[i].clear();
    edges.clear();
}

int finds(int r)
{
    if (par[r]==r)
        return r;
    return par[r]= finds(par[r]);
}

i64 mst(int n, edge nw)
{
    int cx= nw.u, cy= nw.v, fl= 1;

    multiset<edge>::iterator itr;
    for(itr= edges.begin(); itr!=edges.end(); itr++) {
        edge e= *itr;
        if ((e.u == cx && e.v == cy) || (e.u == cy && e.v == cx)) {
            if(nw.w < e.w)  edges.erase(itr);
            else  fl= 0;
            break;
        }
    }

    multiset<edge> new_edges;
    if(fl)  edges.insert(nw);

    for (int i = 1; i <= n; i++)
        par[i] = i;

    i64 count = 0, s = 0;

    for(itr= edges.begin(); itr!=edges.end(); itr++) {
        edge e= *itr;

        int x = finds(e.u);
        int y = finds(e.v);

        if (x != y) {
            new_edges.insert(e);

            par[x] = y;
            count++;
            s += e.w;
            if (count == n - 1) {
                edges= new_edges;
                return s;
            }
        }

    }

    edges= new_edges;
    return -1;
}

main(){
    int opt, c=0;
    si(opt);
    while(opt--) {
        reset();
        printf("Case %d:\n",++c);

        sii(n, m);
        fr(m) {
            int x, y, w;
            siii(x, y, w);
            edge e;


            if(y<x)  swap(x,y);

            e.u = x;
            e.v = y;
            e.w = w;

            outl(mst(n,e));
        }

    }
}

/*
9
 0 2 50
 0 4 150
 2 1 100
 2 3 200
 4 5 90
 3 7 130
 3 6 120
 6 8 110
*/
