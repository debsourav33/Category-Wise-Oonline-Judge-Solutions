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
int col[N], n, k, odd[N], dist[N], freq[N], freq_sum[N], ans[N], maxi= -1, distinct[N];
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
    int level= dist[u], c= col[u];

    if(occur[level][c]==1){
        distinct[level]--;
    }

    occur[level][c]--;

    //printf("Ans for %d is %d\n",u,mx);

    for(int nd: v[u]){
        if(nd==p || big[nd])  continue;

        sub(nd,u);
    }
}

void add(int u, int p){
    int level= dist[u], c= col[u];

    if(occur[level].count(c)==0 || occur[level][c]==0){
        distinct[level]++;
        occur[level][c]= 0;
    }

    occur[level][c]++;

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
        answer[mp(u,qs)]= distinct[dist[u]+ qs];

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

string s[N];
vector<string> names, sorted_names;
vector<int> parents;

main(){
    fastIO();

    int x,y, opt;
    //sii(n,opt);
    cin>>n;

    for(int x=1;x<=n; x++){
        cin>>s[x]>>y;

        names.pb(s[x]);
        sorted_names.pb(s[x]);

        if(y==0){
            parents.pb(x);

            continue;
        }

        v[x].pb(y);
        v[y].pb(x);
    }

    sort(all(sorted_names));

    fr1(n){
        int c= lower_bound(all(sorted_names),names[i-1])- sorted_names.begin();
        col[i]= c;
        //outii(i,col[i]);
    }

    cin>>opt;

    fr(opt){
        cin>>x>>y;
        q[x].pb(y);

        query.pb(mp(x,y));
    }

    fr(parents.size()) {
        int s = sub_dfs(parents[i], -1);
        dfs(parents[i], -1, 1);

        sub(parents[i], -1); //remove calculations for current connected graph
    }

    fr(opt){
        cout<<answer[query[i]]<<endl;
    }

}

/*
 6
 bc 0
 ab 1
 ab 3
 ef 0
 de 4
 de 4
 2
 1 1
 4 1
 */

