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

const int N= 1e5+5;

i64 s[N*4], m[N*4], sm[N*4], ms[N*4], sms[N*4];
char str[N];

#define lefts 2*at
#define rights 2*at+1

struct node{
    i64 s, m, sm, ms, sms;

    node(i64 _s, i64 _m, i64 _sm, i64 _ms, i64 _sms){
        s= _s;
        m= _m;
        sm= _sm;
        ms= _ms;
        sms= _sms;
    }
};

void marge(i64 at){
    s[at]= s[lefts]+ s[rights];
    m[at]= m[lefts]+ m[rights];
    sm[at]= sm[lefts]+ sm[rights]+ s[lefts]*m[rights];
    ms[at]= ms[lefts]+ ms[rights]+ m[lefts]*s[rights];
    sms[at]= sms[lefts]+ sms[rights]+ s[lefts]*ms[rights]+ sm[lefts]*s[rights];
}

void build(i64 at, i64 l, i64 r){
    if(l==r){
        if(str[l]=='s')
            s[at]= 1;
        else if(str[l]=='m')
            m[at]= 1;

        return;
    }

    i64 mid= (l+r)/2;

    build(2*at,l,mid);
    build(2*at+1,mid+1,r);
    marge(at);
}

node query(i64 x, i64 y, i64 at, i64 l, i64 r){
    if(l>y || r<x)  return node(0,0,0,0,0);
    if(l>=x && r<=y)  return node(s[at],m[at],sm[at],ms[at],sms[at]);

    i64 mid= (l+r)/2;

    node a= query(x,y,2*at,l,mid);
    node b= query(x,y,2*at+1,mid+1,r);

    i64 cs= a.s+b.s;
    i64 cm= a.m+b.m;
    i64 csm= a.sm+b.sm+a.s*b.m;
    i64 cms= a.ms+b.ms+a.m*b.s;
    i64 csms= a.sms+b.sms+a.sm*b.s+a.s*b.ms;

    return node(cs,cm,csm,cms,csms);
}

main(){
    char c;


    scanf("%s",str);
    i64 len= strlen(str);

    i64 q, x, y;
    sl(q);

    build(1,0,len-1);

    while(q--){
        cin>>x>>y;
        --x, --y;

        node ans= query(x, y, 1, 0, len-1);
        outl(ans.sms);
    }
}
