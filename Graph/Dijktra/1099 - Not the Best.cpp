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

const int N= 5e3+5;

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

vector<node> v[2][N];
i64 n, m, dist[N][2], parent[N][2], cnt=0, s, t, p;
vector<edge> edges;

bool operator <(node a, node b){
    return a.cost>b.cost;
}

void dijakstra(i64 source, int c){
    priority_queue <node> q;
    q.push(node(source,0));

    fr1(n)
        dist[i][c]= (i64) 10e15;

    dist[source][c]= 0;
    parent[source][c]= source;

    while(!q.empty())
    {
        cnt++;
        i64 u= q.top().ver;
        q.pop();

        fr(v[c][u].size()){
            i64 nd= v[c][u][i].ver;

            if(dist[u][c]+ v[c][u][i].cost < dist[nd][c])
            {
                dist[nd][c]= dist[u][c]+ v[c][u][i].cost;
                parent[nd][c]= u;
                q.push(node(nd,dist[nd][c]));
            }
        }
    }
}

i64 mini;

void solve(i64 j){
    for(edge e: edges){
        i64 a=e.a, b=e.b, w=e.w;
        i64 new_dist;

        new_dist= min(dist[a][0]+w+dist[b][1], dist[a][1]+w+dist[b][0]);

        if(new_dist== dist[t][0])  new_dist+= 2*w;
        mini= min(new_dist,mini);
    }

    printf("Case %lld: %lld\n",j,mini);
}

void reset(){
    edges.clear();
    fr1(n)  frj(2) v[j][i].clear();
    sets(parent);
}

main(){
    int opt;
    si(opt);

    frj1(opt) {
        mini= (i64) 1e18;
        i64 a, b, w;

        sll(n, m);

        fr(m) {
            slll(a, b, w);

            v[0][a].pb(node(b, w));
            v[0][b].pb(node(a, w));

            v[1][a].pb(node(b, w));
            v[1][b].pb(node(a, w));

            edges.pb(edge(a, b, w));
        }

        s= 1;
        t= n;

        dijakstra(s, 0);
        dijakstra(t, 1);

        solve(j);
        reset();
    }
}
