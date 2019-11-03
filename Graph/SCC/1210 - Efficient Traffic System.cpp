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

const int maxn= 2e4+5;

vector<int> t[maxn], v[maxn],  gr[maxn], comp_v[maxn], comp_t[maxn];
int vis[maxn], g_par[maxn], n, m, group=0, missing_in= 0, missing_out= 0;
stack<int> st;

void reset(){
    fr(maxn){
        v[i].clear();
        t[i].clear();
        comp_v[i].clear();
        comp_t[i].clear();
        gr[i].clear();
    }

    clr(vis);
    //sets(g_par);

    group= 0;
    missing_in= 0;
    missing_out= 0;
}

void dfs(int u, int p){
    vis[u]= 1;

    fr(v[u].size()){
        int nd= v[u][i];
        if(nd==p) continue;

        if(!vis[nd])
            dfs(nd,u);
    }

    st.push(u);
}

void scc(int u, int p){
    vis[u]= 1;
    gr[group].pb(u);
    g_par[u]= group;

    fr(t[u].size()){
        int nd= t[u][i];
        if(nd==p) continue;

        if(!vis[nd])
            scc(nd,u);
    }

}

void comp_dfs(int u, int p){
    vis[u]= 1;

    for(int nd: v[u]){
        if(nd==p) continue;

        int g1= g_par[u], g2= g_par[nd];

        if(g1!=g2){
            comp_v[g1].pb(g2);
            comp_t[g2].pb(g1);
        }

        if(!vis[nd])
            comp_dfs(nd,u);
    }
}

main(){
    int opt, cas=1;
    si(opt);

    while(opt--) {
        int a, b;

        sii(n, m);

        fr(m) {
            sii(a, b);

            v[a].push_back(b);
            t[b].push_back(a);
        }

        //fr1(n)  outi(t[i].size());
        clr(vis);

        fr1(n) {
            if (!vis[i])
                dfs(i, -1);
        }

        clr(vis);

        while (!st.empty()) {
            int i = st.top();
            st.pop();

            if (!vis[i]) {
                scc(i, -1);
                group++;
            }
        }

        clr(vis);
        fr1(n) {
            if(!vis[i])
                comp_dfs(i, -1);
        }


        fr(group) {
            if (comp_v[i].empty()) missing_out++;
            if (comp_t[i].empty()) missing_in++;
        }

        printf("Case %d: ",cas++);
        if(group==1)  puts("0");
        else  outi(max(missing_out, missing_in));

        reset();
    }
}

/*
8 14
1 2 2 3 3 4 4 3
5 1 5 6 2 5
6 7 7 6
7 8 8 8
3 7 4 8
2 6
*/
