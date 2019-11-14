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

const int N= 1e5+5, m= 1e9+9, p= 31;

#define lefts 2*at
#define rights 2*at+1

int n, a[N];

char s[N];
i64 pre_hash[N], pow_p[N], mod_inv_p[N];
int k;
map<pll,int> cnt;

struct node{
    i64 h1,h2,c;

    node(){

    }
}hashes[4*N], hashes_rev[4*N];

i64 exp(i64 b, i64 e, i64 M){
    i64 ans=1;

    while(e){
        if(e&1)  ans= (ans*b) % M;
        b= (b*b) % M;
        e/= 2;
    }

    return ans;
}

void pre_calc(){
    i64 curr_pow = 1;
    pow_p[0]= 1;

    fr1(n){
        curr_pow= (curr_pow*p)%m;
        pow_p[i]=  curr_pow;
    }

    fr(n+1){
        mod_inv_p[i]= exp(pow_p[i],m-2,m);
    }
}

void merge(int at){
    node p1= hashes[lefts];
    node p2= hashes[rights];

    i64 hash_val= p1.h1+ p2.h1*pow_p[p1.c];
    i64 hash_rev_val= p1.h2* pow_p[p2.c]+ p2.h2;

    node nd;
    nd.h1= hash_val, nd.h2= hash_rev_val, nd.c=p1.c+p2.c;

    hashes[at]= nd;
}

void build(int at, int L, int R){
    if(L==R){
        node nd;
        nd.h1= s[L]-'a'+1, nd.h2= s[L]-'a'+1, nd.c=1;
        hashes[at]= nd;
        return;
    }

    int mid= (L+R)/2;

    build(lefts,L,mid);
    build(rights,mid+1,R);

    merge(at);
}

void update(int at, int L, int R, int pos, char c){
    if(L==R){
        node nd;
        s[L]= c;
        nd.h1= s[L]-'a'+1, nd.h2= s[L]-'a'+1, nd.c=1;
        hashes[at]= nd;
        return;
    }

    int mid= (L+R)/2;
    if(pos<=mid)
        update(lefts, L, mid, pos, c);
    else
        update(rights, mid+1, R, pos, c);

    merge(at);
}

void del(int at, int L, int R, int pos){
    if(L==R){
        node nd;
        nd.h1= 0, nd.h2= 0, nd.c=0;
        hashes[at]= nd;
        return;
    }

    int mid= (L+R)/2;
    if(pos<=mid)
        del(lefts, L, mid, pos);
    else
        del(rights, mid+1, R, pos);

    merge(at);
}

node query(int at, int L, int R, int l, int r){
    if(r<L || l>R){
        node nd;
        nd.h1= 0, nd.h2= 0, nd.c=0;
        return nd;
    }

    if(l<=L && r>=R)  return hashes[at];

    int mid= (L+R)/2;

    node p1= query(lefts, L, mid, l, r);
    node p2= query(rights, mid+1, R, l, r);

    i64 hash_val= p1.h1+ p2.h1*pow_p[p1.c];
    i64 hash_rev_val= p1.h2* pow_p[p2.c]+ p2.h2;

    node nd;
    nd.h1= hash_val, nd.h2= hash_rev_val, nd.c=p1.c+p2.c;

    return nd;
}

main(){
    int opt;
    scanf("%s", s);
    n = strlen(s);
    pre_calc();
    build(1,0,n-1);

    si(opt);

    int l,r;

    while(opt--) {
        sii(l, r);

        int mid= (r-l+1)/2;

        i64 hash1= query(1,0,n-1, l, l+mid-1).h1;
        i64 hash2= query(1,0,n-1, r-mid+1, r).h2;

        outll(hash1,hash2);
        if(hash1==hash2)  puts("YES");
        else  puts("NO");

    }
}
