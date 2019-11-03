#include<bits/stdc++.h>
using namespace std;

//{
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

typedef long l;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;
//}

ll n, dist[20][20], dp[1000000][25];

int setbit(int mask, int i){
    return mask|(1<<i);
}
int check(int mask, int i){

    return mask & (1<<i);
}
int reset(int mask, int i){
    return mask & ~(1<<i);
}

/*
4
0 6 2 5
6 0 9 3
2 9 0 4
5 3 4 0
*/

ll call(ll mask, ll at){
    ll &ret= dp[mask][at];
    if(ret!=-1)  return ret;
    if(mask==((1<<n)-1)) return 0;

    ll mini= INF;

    fr(n){
        if(!check(mask,i)){
            int set_mask= setbit(mask,i);
            mini= min(dist[at][i]+ call(set_mask,i), mini);
        }
    }

    return ret= mini;
}

main(){
    sets(dp);
    cin>>n;

    dist[0][0]= 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>dist[i][j];
        }
    }

    cout<<call(0,0)<<endl;
}
