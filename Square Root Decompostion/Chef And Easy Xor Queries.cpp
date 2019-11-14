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
const int sN= 330;
const int Block= 330;

int n, m, k, xor_of_block[sN], a[N];
vector<int> block_xors[sN];

void process_block(int no){
    int st= no*Block, endi= (no+1)*Block;
    endi= min(n,endi);

    xor_of_block[no]= 0;

    for(int i=st;i<endi;i++){
        xor_of_block[no]^= a[i];

        block_xors[no].pb(xor_of_block[no]);
    }

    sort(all(block_xors[no]));
}

void preprocess(){
    int no_of_blocks= cel(n,Block);

    fr(no_of_blocks)  process_block(i);
}

void update_block(int ind, int k){
    a[ind]= k;
    int no= ind/Block;

    int st= no*Block, endi= (no+1)*Block;
    endi= min(n,endi);

    xor_of_block[no]= 0;

    block_xors[no].clear();

    for(int i=st;i<endi;i++){
        xor_of_block[no]^= a[i];

        block_xors[no].pb(xor_of_block[no]);
    }

    sort(all(block_xors[no]));
}

void query(int x, int k){
    int st_block= 0, end_block= x/Block, ans= 0;

    int curr=0, need;

    for(int i=st_block; i<end_block; i++){
        need= curr^k;
        ans+= upper_bound(all(block_xors[i]),need)- lower_bound(all(block_xors[i]),need);

        curr^= xor_of_block[i];
    }

    int st= end_block*Block, endi= x+1;

    for(int i=st;i<=x;i++) {
        curr^= a[i];

        if(curr==k)  ans++;
    }

    outi(ans);
}


main(){
    int opt,x,y,z;
    sii(n,opt);
    fr(n)  si(a[i]);

    preprocess();

    while(opt--){
        si(x);

        if(x==1){
            sii(x,y);
            --x;
            update_block(x,y);
        }
        else{
            sii(x,y);
            --x;
            query(x,y);
        }
    }
}
