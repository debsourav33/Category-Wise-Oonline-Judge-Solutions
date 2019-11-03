#include<bits/stdc++.h>
using namespace std;

//{
#define si(a) scanf("%d",&a)
#define sii(a,b) scanf("%d %d",&a,&b);
#define siii(a,b,c) scanf("%d %d %d",&a,&b,&c);

#define sl(a) scanf("%lld",&a)
#define sll(a,b) scanf("%lld %lld",&a,&b);
#define slll(a,b,c) scanf("%lld %lld %lld",&a,&b,&c);

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

int a, b, k;
vector<int> beg, endi;
int dp[105][105][12][2][2];

int call(int m1, int m2, int pos, int f1, int f2){
    if(pos==endi.size())  return (!m1 && !m2);

    //int &ret= dp[m1][m2][pos][f1][f2];
    if(dp[m1][m2][pos][f1][f2]!=-1)  return dp[m1][m2][pos][f1][f2];

    int st, lim;

    if(!f1)  st= beg[pos];
    else  st= 0;
    if(!f2)  lim= endi[pos];
    else lim= 9;

    int cnt= 0;
    for(int i=st;i<=lim;i++){
        int tmp1= (m1+i)%k, tmp2= (m2*10+i)%k;
        cnt+= call(tmp1,tmp2,pos+1,(f1||i>beg[pos]),(f2||i<endi[pos]));
    }

    return dp[m1][m2][pos][f1][f2]= cnt;
}


int solve(int a, int b){
    sets(dp);
    beg.clear();
    endi.clear();

    while(a){
        beg.pb(a%10);
        a/=10;
    }

    while(b){
        endi.pb(b%10);
        b/=10;
    }

    while(beg.size()<endi.size())
        beg.pb(0);


    reverse(all(beg));
    reverse(all(endi));

    int ans= call(0,0,0,0,0);
    return ans;
}

int main(){
    int opt, cas= 1;
    si(opt);

    while(cas<=opt) {
        siii(a, b, k);

        if(k>=100)  printf("Case %d: 0\n",cas++);
        else  printf("Case %d: %d\n",cas++,solve(a, b));
    }
}
