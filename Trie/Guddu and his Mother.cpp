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
#define fr(n) for(i64 i=0;i<n;i++)
#define fr1(n) for(i64 i=1;i<=n;i++)
#define frj(n) for(i64 j=0;j<n;j++)
#define frj1(n) for(i64 j=1;j<=n;j++)
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

struct node{
    node* child[2];
    pll leaf;

    node(){
        leaf.ff= 0;
        leaf.ss= 0;
        fr(2)
            child[i]= NULL;
    }
};

struct Trie{
    node* root= new node();

    i64 resetbit(i64 a, i64 i){
        return a & ~(1LL<<i);
    }
    i64 setbit(i64 a, i64 i){
        return a | (1LL<<i);
    }
    bool check(i64 mask, i64 i){
        return mask & (1LL<<i);
    }

    void insert(i64 num, i64 i, node* root, i64 pos){
        if(i==-1) {
            root->leaf.ff= root->leaf.ff+ (pos+ 1);
            root->leaf.ss++;

            return;
        }

        i64 id= check(num,i);
        if(root->child[id]==NULL){
            node* t= new node();
            root->child[id]= t;
        }

        insert(num,i-1,root->child[id], pos);
    }

    pll query(i64 num, i64 i, node* root){
        if(i==-1)  return root->leaf;

        i64 id= check(num,i);

        if(root->child[id]==NULL)
            return mp(0,0);

        query(num,i-1,root->child[id]);
    }

    void init(){
        insert(0,63,root,-1);
    }
};

main(){
    int opt;
    si(opt);

    while(opt--){
        i64 n, a[100005], pre=0, ans=0, endi;
        Trie T;

        cin>>n;

        fr(n)  sl(a[i]);
        T.init();

        for(i64 i=0;i<n;i++){
            pre= pre ^ a[i];

            pll p= T.query(pre,63,T.root);
            if(p.ss!=0) {
                ans+= (i*p.ss);
                ans-= p.ff;
            }

            T.insert(pre,63,T.root,i);
        }

        printf("%lld\n", ans);
    }
}

/*
 4
 12
 1 7 8 3 4 5 1 2 7 5 9 9
 3
 3 3 3
 15
 9 6 7 12 8 16 12 6 6 6 9 4 9 4 5
 7
 1 9 6 5 3 8 2


 */
