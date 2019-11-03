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

const int maxn= 1e5+5;
int isBlack= 1;

int powOf2(int q){
    int ans= 0;

    while(q/2){
        ans++;
        q/=2;
    }

    return ans;
}

int lca_query(int p, int q, int typed)
{

    int odd= (powOf2(q)+1)%2;

    int tmp, log, i;

    if (p > q)
        tmp = p, p = q, q = tmp;

    int length= 1;

    while(powOf2(p)<powOf2(q))
        length++, q/=2;

    while(p!=q)
        length+= 2, p/=2, q/=2;

    int ifBlack= (isBlack==odd);

    if((length%2) && ifBlack==typed)
        return cel(length,2);
    return length/2;
}

main(){
    int a,b, opt;
    string s;
    cin>>opt;

    while(opt--) {
        cin>>s;

        if(s=="Qi")  isBlack= 1-isBlack;
        else{
            cin>>a>>b;

            if(s=="Qb")
                cout<<lca_query(a,b,1)<<endl;
            else
                cout<<lca_query(a,b,0)<<endl;
        }

    }
}

/*
11
1 2 1 3
2 4 2 5 2 6
4 7 4 8
6 9
3 10 3 11

 */