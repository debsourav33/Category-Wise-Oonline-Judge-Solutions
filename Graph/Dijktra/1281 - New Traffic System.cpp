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
    i64 ver, cost, used;
    node(i64 v, i64 w, i64 u){
        ver= v;
        cost= w;
        used= u;
    }
};

vector<node> v[N];
i64 n, dist[N][12], edges, k, d;

bool operator <(node a, node b){
    return a.cost>b.cost;
}

void reset(){
    fr(n)  v[i].clear();
}

void dijakstra(i64 source){
    priority_queue <node> q;
    q.push(node(source,0,0));

    fr(n)
        frj(12)
            dist[i][j]= (i64) 1e17;

    dist[source][0]= 0;

    while(!q.empty()){
        i64 u= q.top().ver, u_used= q.top().used;

        q.pop();

        fr(v[u].size()){
            i64 nd= v[u][i].ver, weight= v[u][i].cost, used= v[u][i].used;

            //if(u==0 && v[u][i].ver==n-1)  outii(u_used,used);

            if(u_used+used>d)  continue;

            if(dist[u][u_used]+ weight < dist[nd][u_used+used]){
                dist[nd][u_used+used]= dist[u][u_used]+ weight;
                q.push(node(nd,dist[nd][u_used+used],u_used+used));
            }
        }

    }

}

main(){
    int opt, cas=1;
    si(opt);

    while(opt--) {
        i64 a, b, w;

        sll(n, edges);
        sll(k, d);

        fr1(edges) {
            slll(a, b, w);

            v[a].pb(node(b, w, 0));
        }

        fr1(k) {
            slll(a, b, w);

            v[a].pb(node(b, w, 1));
        }


        dijakstra(0);

        i64 mini = 1e17;
        fr(d + 1) {
            mini = min(mini, dist[n - 1][i]);
        }

        if(mini==1e17)  printf("Case %d: Impossible\n",cas++);
        else  printf("Case %d: %lld\n",cas++,mini);

        reset();
    }
}
