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
#define fr(n) for(i64 i=0;i<n;i++)
#define fr1(n) for(i64 i=1;i<=n;i++)
#define frj(n) for(i64 j=0;j<n;j++)
#define frj1(n) for(i64 j=1;j<=n;j++)
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

struct node{
    i64 ver, cost;
    node(i64 v, i64 w){
        ver= v;
        cost= w;
    }
};

struct edge{
    i64 a, b, w;
    edge(i64 _a, i64 _b, i64 _w){
        a= _a;
        b= _b;
        w= _w;
    }
};

vector<node> v[N][2];
i64 n, m, dist[N][2], f, parent[N][2], cnt=0, s, d, p;
vector<edge> edges;

bool operator<(node a, node b){
    return a.cost>b.cost;
}

void dijkstra(int source, int c){
    priority_queue<node> q;

    fr1(n) dist[i][c]= (i64) 1e16;

    dist[source][c]= 0;
    parent[source][c]= source;
    q.push(node(source,dist[source][c]));

    while(!q.empty()){
        i64 u= q.top().ver;
        q.pop();

        for(node nod: v[u][c]){
            i64 nd= nod.ver, cost= nod.cost;

            if(dist[u][c]+cost< dist[nd][c]){
                dist[nd][c]= dist[u][c] +cost;
                parent[nd][c]= u;

                q.push(node(nd,dist[nd][c]));

            }
        }
    }
}

void reset(){
    fr1(n) v[i][0].clear(), v[i][1].clear();
    edges.clear();
}

main(){
    int cas=1;
    int opt;
    si(opt);

    while(opt--) {
        i64 a, b, w;

        sll(n, m);
        sll(s, d);
        sl(p);

        fr(m) {
            slll(a, b, w);

            v[a][0].pb(node(b, w));
            v[b][1].pb(node(a, w));

            edges.pb(edge(a, b, w));
        }

        dijkstra(s, 0);
        dijkstra(d, 1);

        i64 maxi = -1;

        for (edge e: edges) {
            i64 a = e.a, b = e.b, w = e.w;

            if (dist[a][0] + w + dist[b][1] <= p) maxi = max(maxi, w);
        }

        printf("Case %d: %lld\n",cas++,maxi);

        reset();
    }
}
