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
#define null NULL

typedef long l;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;
//}

struct node{
    node* child[2];
    node(){
        fr(2)
            child[i]= null;
    }
};

struct Trie{
    node* root= new node();

    ll resetbit(ll a, ll i){
        return a & ~(1LL<<i);
    }

    ll setbit(ll a, ll i){
        return a | (1LL<<i);
    }

    bool check(ll mask, ll i){
        return mask & (1LL<<i);
    }

    void insert(ll num, ll i, node* root){
        if(i==-1)  return;
        ll id= check(num,i);
        if(root->child[id]==null){
            node* t= new node();
            root->child[id]= t;
        }

        insert(num,i-1,root->child[id]);
    }

    ll query(ll num, ll i, node* root){
        if(i==-1)  return num;

        ll id= 1-check(num,i);

        if(root->child[id]==null){
            id= 1-id;
            num= resetbit(num,i);
        }
        else
            num= setbit(num,i);

        query(num,i-1,root->child[id]);
    }

    void init(){
        insert(0,63,root);
    }
};

main(){
    int opt;
    cin>>opt;

    for(int o=0;o<opt;o++){
        ll n, a[100005], pre=0, ans=0;
        Trie T;

        cin>>n;
        T.init();

        fr(n){
            cin>>a[i];

            pre= pre ^ a[i];
            T.insert(pre,63,T.root);
            ans= max(ans,T.query(pre,63,T.root));
        }

        cout<<ans<<endl;
    }
}

/*

2
5
3 7 7 7 0
5
3 8 2 6 4

*/
