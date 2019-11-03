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
int cnt[4*N], gcd[4*N];
set<int> s;
map<int,int> index_of;

#define lefts 2*at
#define rights 2*at+1

void merge(int at){
    if(gcd[lefts]==-1)  gcd[at]= gcd[rights];
    else if(gcd[rights]==-1)  gcd[at]= gcd[lefts];
    else  gcd[at]= __gcd(gcd[lefts],gcd[rights]);
}

void build(int at, int L, int R){
    if(L==R){
        gcd[at]= -1;
        return;
    }

    int mid= (L+R)/2;

    build(lefts,L,mid);
    build(rights,mid+1,R);

    merge(at);
}

void update(int at, int L, int R, int pos, int val){
    if(L==R){
        if(val==-1){
            cnt[at]--;
            if(cnt[at]==0)  gcd[at]= -1;
        }
        else{
            cnt[at]++;
            gcd[at]= val;
        }

        return;
    }

    int mid= (L+R)/2;
    if(pos<=mid)  update(lefts, L, mid, pos, val);
    else  update(rights, mid+1, R, pos, val);

    merge(at);
}

int query(int at, int L, int R, int l, int r){

    if(r<L || l>R)  return -1;
    if(l<=L && r>=R)  return gcd[at];

    int mid= (L+R)/2;

    int x= query(lefts, L, mid, l, r);
    int y= query(rights, mid+1, R, l, r);

    if(x==-1)  return y;
    else if(y==-1)  return x;
    else return __gcd(x,y);
}

struct node{
    int x;
    char c;
} queries[100005];


main(){
    char op[2];
    int opt, x;
    si(opt);

    fr(opt){
        scanf("%s %d", op, &x);

        queries[i].x = x;
        queries[i].c = op[0];

        s.insert(x);
    }

    int cnt= 0;

    for(int i: s){
        index_of[i]= cnt;

        cnt++;
    }

    build(1,0,N-1);


    fr(opt){
        char c= queries[i].c;
        int x= queries[i].x;

        if(c=='+')  update(1,0,N-1,index_of[x],x);
        else update(1,0,N-1,index_of[x],-1);;

        int tmp= query(1,0,N-1,0,N-1);

        if(tmp==-1)  puts("1");
        else  outi(tmp);
    }
}
