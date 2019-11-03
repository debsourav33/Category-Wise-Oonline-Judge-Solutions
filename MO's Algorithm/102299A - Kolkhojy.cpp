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
const int sN= 1e5+5;

int n, m, k, Block, cnt[230][230][230], a[N], Cnt[N], answer= 0, ans[N];

struct node {
    int L, R, m, d, i;
}q[N];

bool cmp(node x, node y) {
    if(x.L/Block != y.L/Block) {
        return x.L/Block < y.L/Block;
    }
    return x.R < y.R;
}

void add(int position) {
    Cnt[a[position]]++;
}

void remove(int position) {
    Cnt[a[position]]--;
}

int currentL=0, currentR= 0;

void query2(int i){
    int L = q[i].L, R = q[i].R;
    int m= q[i].m, d= q[i].d;

    while(currentL > L) {
        add(currentL-1);
        currentL--;
    }

    while(currentR <= R) {
        add(currentR);
        currentR++;
    }

    while(currentL < L) {
        remove(currentL);
        currentL++;
    }

    while(currentR > R+1) {
        remove(currentR-1);
        currentR--;
    }

    answer= 0;

    for(int j=m;j<N;j+=d){
        answer+= Cnt[j];
    }

    ans[q[i].i] = answer;
}

void process_block(int no){
    int st= no*Block, endi= (no+1)*Block;
    endi= min(n,endi);

    for(int i=st;i<endi;i++){
        frj1(227){
            int mod= a[i]%j;

            cnt[no][j][mod]++;
        }
    }
}

void preprocess(){
    int no_of_blocks= cel(n,Block);

    fr(no_of_blocks)  process_block(i);
}

void query1(int no){
    int x= q[no].L, y= q[no].R, m= q[no].m, d= q[no].d;

    int st_block= x/Block, end_block= y/Block, answer= 0;

    for(int i=st_block; i<=end_block; i++){
        answer+= cnt[i][d][m];
    }

    int st= st_block*Block, endi= (end_block+1)*Block;
    endi= min(n,endi);

    //outii(st,endi);
    //outi(ans);

    for(int i=st; i<x;i++){
        if(a[i]%d==m)  answer--;
    }

    for(int i=y+1; i<endi;i++){
        if(a[i]%d==m)  answer--;
    }

    ans[q[no].i]= answer;
}

main(){
    int x,y,m,d, opt;
    sii(n,opt);

    Block= (int) sqrt(n)+1;

    fr(n)  si(a[i]);

    preprocess();

    fr(opt){
        sii(x,y);
        sii(m,d);
        --x, --y;

        q[i].L= x, q[i].R= y, q[i].d= d, q[i].m= m, q[i].i= i;
    }

    sort(q,q+opt,cmp);

    fr(opt){
        if(q[i].d<Block)  query1(i);
        else  query2(i);
    }

    fr(opt){
        outi(ans[i]);
    }
}

/*
 3 4
 1 2 3
 1 3 1 2
 2 3 1 2
 1 3 0 2
 1 3 0 1
 */
