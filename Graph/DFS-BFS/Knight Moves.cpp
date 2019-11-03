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
#define max(a,b) ((a)>(b)? (a):(b))
#define min(a,b) ((a)<(b)? (a):(b))
#define fr(n) for(int i=0;i<n;i++)
#define fr1(n) for(int i=1;i<=n;i++)
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

vector<int> v[100005];
int n, vis[10][10], level[10][10], edges, parent[10][10], m;

int dr[]= {1, 1, -1, -1, 2, 2, -2, -2};
int dc[]= {2, -2, 2, -2, 1, -1, 1, -1};

void reset(){
    clr(vis);
    clr(level);
    sets(parent);
}

bool isSafe(int row, int col){
    return !vis[row][col]  && row>0 && row<=8 && col>0 && col<=8;
}

void bfs(pii p){
    queue<pii> q;
    q.push(p);
    vis[p.ff][p.ss]= 1;

    while(!q.empty()){
        pii u= q.front();
        q.pop();

        fr(8){
            int row= u.ff+dr[i];
            int col= u.ss+dc[i];
            if (isSafe(row,col)) {

                vis[row][col] = 1;
                level[row][col] = level[u.ff][u.ss] + 1;

                q.push(pii(row,col));
            }

        }

    }

}

int main(){
    reset();
    int a, b;

    char t[3], s[3];
    while(scanf("%s",t)!=EOF) {
        reset();
        a= t[0]-'a'+1;
        b= t[1]-'0';

        bfs(pii(a, b));

        scanf("%s",s);
        a= s[0]-'a'+1;
        b= s[1]-'0';

        printf("To get from %s to %s takes %d knight moves.\n",t,s,level[a][b]);
    }
}
