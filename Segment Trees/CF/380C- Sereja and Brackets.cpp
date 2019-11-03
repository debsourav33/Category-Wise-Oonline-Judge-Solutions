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

int t[4000006],  o[4000006], c[4000006];
char s[1000006];

struct node{
    int t, o, c;

    node(int _t, int _o, int _c){
        t= _t;
        o= _o;
        c= _c;
    }
};

void marge(int at){
    int temp= min(o[2*at],c[2*at+1]);
    t[at]= t[2*at]+ t[2*at+1]+ temp;
    o[at]= o[2*at]+ o[2*at+1]- temp;
    c[at]= c[2*at]+ c[2*at+1]- temp;
}

void build(int at, int l, int r){
    if(l==r){
        t[at]= 0;
        if(s[l]=='(')
            o[at]= 1;
        else
            c[at]= 1;

        return;
    }

    int mid= (l+r)/2;

    build(2*at,l,mid);
    build(2*at+1,mid+1,r);
    marge(at);
}

node query(int x, int y, int at, int l, int r){
    if(l>y || r<x)  return node(0,0,0);
    if(l>=x && r<=y)  return node(t[at],o[at],c[at]);

    int mid= (l+r)/2;

    node a= query(x,y,2*at,l,mid);
    node b= query(x,y,2*at+1,mid+1,r);

    int temp= min(a.o, b.c);
    int tt= a.t+ b.t + temp;
    int oo= a.o+ b.o - temp;
    int cc= a.c+ b.c - temp;

    return node(tt,oo,cc);
}

main(){
    char c;
    int len=1;

    while(1){
        scanf("%c",&c);

        if(c=='\n')
            break;

        s[len++]= c;
    }

    int q, x, y;
    cin>>q;

    build(1,1,len-1);

    while(q--){
        cin>>x>>y;

        node ans= query(x, y, 1, 1, len-1);
        cout<<ans.t*2<<endl;
    }

}
