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

const int N= 505;

struct node{
    i64 ver, cost;
    node(i64 v, i64 w){
        ver= v;
        cost= w;
    }
};

bool operator <(node a, node b){
    return a.cost>b.cost;
}

vector<node> v[N];
i64 n, vis[N], dist[N], edges, parent[N], cnt=0, t;
map<pll,i64> weight;

void dijakstra(i64 source){
    priority_queue <node> q;
    q.push(node(source,0));

    fr(n)
        dist[i]= 1e15;

    dist[source]= 0;
    vis[source]= 1;

    while(!q.empty()){
        cnt++;
        i64 u= q.top().ver;
        q.pop();

        fr(v[u].size()){
            i64 nd= v[u][i].ver;

            if(max(v[u][i].cost,dist[u]) < dist[nd]){

                vis[nd]= 1;
                dist[nd]= max(v[u][i].cost, dist[u]);
                parent[nd]= u;
                q.push(node(nd,dist[nd]));
            }

        }

    }

}


i64 solve(i64 nd){
    i64 maxi= 0;

    while(nd!=t){
        maxi= max(maxi,weight[mp(nd,parent[nd])]);
        nd= parent[nd];
    }

    return maxi;
}

void print_path(i64 node){
    if(parent[node]==-1){
        cout<<node;
        return;
    }

    print_path(parent[node]);
    printf(" %lld",node);
}

void reset(){
    fr(n)  v[i].clear();
    weight.clear();
    clr(vis);
    sets(parent);
}

main(){
    int opt;
    si(opt);

    frj1(opt) {
        reset();
        i64 a, b, w;

        sll(n, edges);

        fr1(edges) {
            slll(a, b, w);

            v[a].pb(node(b, w));
            v[b].pb(node(a, w));

            if (weight.count(mp(a, b)) == 0 || weight[mp(a, b)] > w) {
                weight[mp(a, b)] = w;
                weight[mp(b, a)] = w;
            }
        }

        sl(t);

        dijakstra(t);

        printf("Case %lld:\n",j);
        fr(n){
            if(dist[i]== 1e15)  puts("Impossible");
            else outl(solve(i));
        }
    }
}
