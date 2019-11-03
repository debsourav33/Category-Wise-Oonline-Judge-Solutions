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
int col[N], n, dist[N], occur[N], ans[N], maxi= -1, distinct= 0;
bool big[N];

vector<int> v[N], q[N];
vector<pii> query;
map<i64,i64> cost, freq;

int sub_dfs(int u, int p){
    sz[u]= 1;
    dist[u]= (p==-1) ? 1: dist[p]+1;

    for(int nd: v[u]){
        if(nd==p) continue;

        sz[u]+= sub_dfs(nd,u);
    }
    return sz[u];
}

set<int, greater<int> > s;

void sub(int u, int p, i64 neg){
    i64 c= col[u]+ neg;
    if(freq[c]==1){
        distinct--;
    }

    freq[c]--;

    //printf("Ans for %d is %d\n",u,mx);

    for(int nd: v[u]){
        if(nd==p || big[nd])  continue;

        sub(nd,u, neg+cost[nd]);
    }
}

void add(int u, int p, i64 neg){
    i64 c= col[u]+ neg;
    if(freq.count(c)==0 || freq[c]==0){
        freq[c]= 0;
        distinct++;
    }

    freq[c]++;

    //printf("Ans for %d is %d\n",u,mx);

    for(int nd: v[u]){
        if(nd==p || big[nd])  continue;

        add(nd,u, neg+cost[nd]);
    }
}

i64 dfs(int u, int p, int keep){
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

    i64 neg= 0;
    if(bigchild!=-1)
        neg= dfs(bigchild,u,1), big[bigchild]= 1;

    add(u,p, -1*neg);

    ans[u]= distinct;

    /*
    printf("Colors with occurrence for Vertex %d:\n",u);
    fr1(5){
        outii(i,cnt[i]);
    }*/

    if(bigchild!=-1)  big[bigchild]= 0;
    if(!keep)  sub(u,p, -1*neg);

    return neg+cost[u];
}

main(){
    int x,y, opt;
    si(n);

    fr1(n)  si(col[i]);

    int p= -1;

    fr1(n){
        si(y);

        if(y==0){
            p= i;
            continue;
        }

        v[i].pb(y);
        v[y].pb(i);
    }

    fr1(n){
        sl(x);

        cost[i]= x;
    }

    int s= sub_dfs(p,-1);

    i64 neg= dfs(p,-1,1);

    fr1(n)  outi(ans[i]);

}

/*
 5

7 3 2 5 1

0 1 1 3 3

0 4 1 0 14


4
7 7 5 9
4 4 2 0
4 2 2 0

 */