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

int a[N], sz[N];
int col[N], n, k, L[N], dist[N], freq[N], T[N], ans[N], maxi= -1, distinct[N], P[N][22];
bool big[N];

vector<int> v[N], q[N];
vector<pii> query;
map<pii,int> answer;
map<int,int> occur[N];

int sub_dfs(int u, int p){
    sz[u]= 1;
    dist[u]= (p==-1) ? 0: dist[p]+1;

    for(int nd: v[u]){
        if(nd==p) continue;

        sz[u]+= sub_dfs(nd,u);
    }
    return sz[u];
}

void sub(int u, int p){
    int level= dist[u];
    freq[level]--;

    //printf("Ans for %d is %d\n",u,mx);
    for(int nd: v[u]){
        if(nd==p || big[nd])  continue;

        sub(nd,u);
    }
}

void add(int u, int p){
    int level= dist[u];
    freq[level]++;

    //printf("Ans for %d is %d\n",u,mx);

    for(int nd: v[u]){
        if(nd==p || big[nd])  continue;

        add(nd,u);
    }
}

void dfs(int u, int p, int keep){
    int bigchild= -1, mx= -1;

    for(int nd: v[u]){
        if(nd==p)  continue;

        if(sz[nd]>mx)  mx= sz[nd], bigchild= nd;
    }

    //printf("Bigchild of %d is %d\n",u,bigchild);

    for(int nd: v[u]){
        if(nd==p || nd==bigchild)  continue;

        dfs(nd,u,0);  //keep=0 means remove light edges calculations
    }

    if(bigchild!=-1)
        dfs(bigchild,u,1), big[bigchild]= 1;

    add(u,p);
    for(i64 qs: q[u]){
        answer[mp(u,qs)]= freq[dist[u]+ qs] - 1;

        //printf("Distince count for %d in depth %lld\n",u,qs);
        //outl(distinct[qs]);
    }
    /*
    printf("Colors with occurrence for Vertex %d:\n",u);
    fr1(5){
        outii(i,cnt[i]);
    }*/

    if(bigchild!=-1)  big[bigchild]= 0;
    if(!keep)  sub(u,p);
}

vector<int> parents;

void parent_dfs(int u, int p){
    T[u]= p;
    L[u]= (p>-1) ? L[p]+1 : 0;

    for(int s: v[u]){
        if(s==p) continue;

        parent_dfs(s,u);
    }
}

void init_LCA(int n){
    sets(P);

    fr1(n){
        P[i][0]= T[i];
    }

    for(int j=1; (1<<j)<n;j++){
        fr1(n){
            if(P[i][j-1]!=-1)
                P[i][j]= P[P[i][j-1]][j-1];
        }
    }
}

int getParent(int p, int no){
    no--;
    if(no==-1)  return p;

    int log = 1;
    while (1) {
        int next = log + 1;
        if ((1 << next) > L[p])break;
        log++;

    }

    for(int i=log;i>=0;i--){
        if((1<<i)<=no) {
            p = P[p][i];
            no-= (1<<i);
        }
    }

    return P[p][0];
}

main(){
    int x,y, opt;
    si(n);

    for(int x=1;x<=n; x++){
        si(y);

        if(y==0){
            parents.pb(x);
            continue;
        }

        v[x].pb(y);
        v[y].pb(x);
    }

    si(opt);

    fr(parents.size())
        parent_dfs(parents[i],-1);
    init_LCA(n);

    fr(opt){
        sii(x,y);
        if(L[x]<y){
            answer[mp(0,0)]= 0;
            x= 0, y= 0;
        }
        else{
            x= getParent(x,y);
        }

        q[x].pb(y);
        query.pb(mp(x,y));
    }

    fr(parents.size()) {
        int s = sub_dfs(parents[i], -1);
        dfs(parents[i], -1, 1);

        sub(parents[i], -1); //remove calculations for current connected graph
    }

    fr(opt){
        outis(answer[query[i]]);
    }
}
