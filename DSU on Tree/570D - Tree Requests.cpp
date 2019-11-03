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

const int N= 5e5+5;

int a[N], sz[N];
i64 col[N], n, k, odd[N], dist[N], occur[N][30], freq[N], freq_sum[N], ans[N], maxi= -1;
bool big[N];

vector<int> v[N], q[N];
vector<pii> query;
map<pii,i64> answer;

int sub_dfs(int u, int p){
    sz[u]= 1;
    dist[u]= (p==-1) ? 1: dist[p]+1;

    for(int nd: v[u]){
        if(nd==p) continue;

        sz[u]+= sub_dfs(nd,u);
    }
    return sz[u];
}

void sub(int u, int p){
    i64 level= dist[u];
    i64 o= occur[level][col[u]];

    if(o%2==0)  odd[level]++;
    else  odd[level]--;

    occur[level][col[u]]--;

    //printf("Ans for %d is %d\n",u,mx);

    for(int nd: v[u]){
        if(nd==p || big[nd])  continue;

        sub(nd,u);
    }
}

void add(int u, int p){
    i64 level= dist[u];
    i64 o= occur[level][col[u]];

    if(o%2==0)  odd[level]++;
    else  odd[level]--;

    occur[level][col[u]]++;

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
    for(int qs: q[u]){
        //printf("Odd count for %d in depth %d\n",u,qs);
        //outl(odd[qs]);

        if(odd[qs]<2)  answer[mp(u,qs)]= 1;
        else answer[mp(u,qs)]= 0;
    }
    /*
    printf("Colors with occurrence for Vertex %d:\n",u);
    fr1(5){
        outii(i,cnt[i]);
    }*/

    if(bigchild!=-1)  big[bigchild]= 0;
    if(!keep)  sub(u,p);
}

char s[N];

main(){
    clr(freq_sum);
    int x,y, opt;
    sii(n,opt);

    for(int x=2;x<=n; x++){
        si(y);

        v[x].pb(y);
        v[y].pb(x);
    }

    scanf("%s",s);
    fr1(n){
        col[i]= s[i-1] - 'a';
    }

    fr(opt){
        sii(x,y);
        q[x].pb(y);

        query.pb(mp(x,y));
    }

    int s= sub_dfs(1,-1);

    dfs(1,-1,1);

    fr(opt){
        if(answer[query[i]])  puts("Yes");
        else puts("No");
    }

}

/*
 7 6
1 1 1 3 3 3
zacdcdc
1 1
3 7
3 3
4 1
6 1
1 2
 */
