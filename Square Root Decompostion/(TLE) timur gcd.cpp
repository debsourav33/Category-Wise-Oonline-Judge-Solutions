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
const int sN= 325;

int n, m, k, Block, block_gcd[sN];
int cnt[N];
set<int> s;
map<int,int> block_of;
vector<int> block_ele[sN];

void add(int x){
    int no= block_of[x];
    int st= no*Block;

    int ind= lower_bound(all(block_ele[no]),x)- block_ele[no].begin();

    cnt[st+ind]+=1;

    int gcd= -1;

    fr(block_ele[no].size()){
        int k= block_ele[no][i];

        //outi(k+st);

        if(cnt[i+st]>0)
            gcd= (gcd==-1) ? k :__gcd(gcd,k);
    }

    block_gcd[no]= gcd;
}

void sub(int x){
    int no= block_of[x];
    int st= no*Block;

    int ind= lower_bound(all(block_ele[no]),x)- block_ele[no].begin();

    cnt[st+ind]-=1;

    int gcd= -1;

    fr(block_ele[no].size()){
        int k= block_ele[no][i];

        if(cnt[i+st]>0)
            gcd= (gcd==-1) ? k :__gcd(gcd,k);
    }

    block_gcd[no]= gcd;
}

void query(){
    int gcd= -1, no_of_blocks= cel(N,Block);

    for(int i=0;i<=no_of_blocks;i++){
        if(gcd==-1)  gcd= block_gcd[i];
        else if(block_gcd[i]!=-1)  gcd= __gcd(block_gcd[i], gcd);
    }

    if(gcd==-1)  puts("1");
    else  outi(gcd);
}

struct node{
    int x;
    char c;
} queries[100005];


main(){
    Block= 325;
    sets(block_gcd);

    char ss[2];

    int opt, x;
    si(opt);

    fr(opt){
        scanf("%s %d", ss, &x);

        queries[i].x = x;
        queries[i].c = ss[0];

        s.insert(x);
    }

    int cnt= 0;

    for(int i: s){
        int no= cnt/Block;

        block_ele[no].pb(i);
        block_of[i]= no;

        cnt++;
    }

    fr(opt){
        char c= queries[i].c;
        int x= queries[i].x;

        if(c=='+')  add(x);
        else sub(x);

        query();
    }
}
