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

#define lefts 2*at
#define rights 2*at+1

const int N= 1e4+5;

int n, T[N], P[N][22], L[N], subTree[N];
int chainHead[N], chain[N], chainSize[N], chainPos[N], no;
int BaseTree[N], posInBase[N], maxi[4*N], baseIndex;

vector<int> v[N], costs[N];
vector<pii> edges;

void dfs(int u, int p){
    T[u]= p;
    L[u]= (p>-1) ? L[p]+1 : 0;
    subTree[u]= 1;

    for(int nd: v[u]){
        if(nd==p)  continue;
        dfs(nd,u);
        subTree[u]+= subTree[nd];
    }
}

void hld(int u, int p, int c){
    if(chainHead[no]==-1)  chainHead[no]= u;
    chain[u]= no;
    chainSize[no]++;
    chainPos[u]= chainSize[no]-1;

    posInBase[u]= baseIndex;
    BaseTree[baseIndex++]=  c;

    int ind= -1, sz= -1;
    fr(v[u].size()) {
        int nd= v[u][i];
        if(nd==p) continue;

        if (subTree[nd]>sz)  ind= i, sz= subTree[nd];
    }

    if(ind!=-1)  hld(v[u][ind],u,costs[u][ind]);

    fr(v[u].size()){
        if(v[u][i]==p) continue;

        if(i!=ind){
            no++;
            hld(v[u][i],u,costs[u][i]);
        }
    }
}

void init_LCA(int n){
    sets(P);

    fr(n){
        P[i][0]= T[i];
    }

    for(int j=1; (1<<j)<n;j++){
        fr(n){
            if(P[i][j-1]!=-1)
                P[i][j]= P[P[i][j-1]][j-1];
        }

    }
}

int lca_query(int p, int q) {
    int tmp, log, i;

    if (L[p] < L[q])
        tmp = p, p = q, q = tmp;

    log = 1;
    while (1) {
        int next = log + 1;
        if ((1 << next) > L[p])break;
        log++;

    }

    for (i = log; i >= 0; i--)
        if (L[p] - (1 << i) >= L[q])
            p = P[p][i];

    if (p == q)
        return p;

    for (i = log; i >= 0; i--)
        if (P[p][i] != -1 && P[p][i] != P[q][i])
            p = P[p][i], q = P[q][i];

    return T[p];
}

void merge(int at){
    maxi[at]= max(maxi[lefts], maxi[rights]);
}

void build(int at, int L, int R){
    if(L==R){
        maxi[at]= BaseTree[L];
        return;
    }

    int mid= (L+R)/2;

    build(lefts,L,mid);
    build(rights,mid+1,R);

    merge(at);
}

int query(int at, int L, int R, int l, int r){
    if(l>r)  return 0;
    if(r<L || l>R)  return 0;
    if(l<=L && r>=R)  return maxi[at];

    int mid= (L+R)/2;

    int x= query(lefts, L, mid, l, r);
    int y= query(rights, mid+1, R, l, r);

    return max(x,y);
}

void update(int at, int L, int R, int pos, int val){
    if(L==R){
        BaseTree[L]= val;
        maxi[at]= val;
        return;
    }

    int mid= (L+R)/2;

    if(pos<=mid)  update(lefts,L,mid,pos,val);
    else  update(rights,mid+1,R,pos,val);

    merge(at);
}

int queryUp(int u, int v){
    if(u==v)  return 0;
    int uchain= chain[u], vchain, ans= 0;

    while(1){
        vchain= chain[v];

        if(uchain==vchain){
            int tmp= query(1,0,n-1, posInBase[u]+1,posInBase[v]);
            ans= max(tmp,ans);
            break;
        }

        int head= chainHead[vchain];
        ans= max(ans, query(1,0,n-1, posInBase[head]+1,posInBase[v]));  //maximum in v's chain
        ans= max(ans, BaseTree[posInBase[head]]); //chain change, so check chainhead's edge cost

        v= T[head]; //change chain
    }

    return ans;
}

int ansQuery(int u, int v){
    int lca= lca_query(u,v);

    int ans= max(queryUp(lca,u),queryUp(lca,v));
    return ans;
}

void reset(int n){
    fr(n)  v[i].clear(), costs[i].clear();
    edges.clear();
    sets(chainHead);
    clr(chainSize);  clr(chain);
    no= baseIndex= 0;
}

main(){
    fastIO();
    baseIndex= no= 0;
    int opt;
    cin>>opt;

    while(opt--) {

        int a, b, c;

        cin >> n;

        fr(n - 1) {
            cin >> a >> b >> c;
            --a, --b;

            v[a].pb(b);
            v[b].pb(a);
            costs[a].pb(c);
            costs[b].pb(c);

            edges.pb(mp(a, b));
        }
        sets(chainHead);

        dfs(0, -1);
        hld(0, -1, -1);
        init_LCA(n);
        build(1, 0, n - 1);

        string opt;
        while (1) {
            cin >> opt;

            if (opt == "QUERY") {
                cin >> a >> b;
                --a, --b;

                int ans = ansQuery(a, b);
                cout << ans << endl;
            } else if (opt == "CHANGE") {
                cin >> a >> c;
                --a;

                int x = edges[a].ff, y = edges[a].ss;

                if (T[x] == y) swap(x, y);

                update(1, 0, n - 1, posInBase[y], c);
            } else {
                break;
            }
        }

        reset(n);
    }
}

/*
 11
 0 1 5
 0 2 7
 1 3 3
 1 4 2
 4 7 9
 7 9 4
 7 10 6
 2 5 11
 2 6 2
 5 8 6

 */
