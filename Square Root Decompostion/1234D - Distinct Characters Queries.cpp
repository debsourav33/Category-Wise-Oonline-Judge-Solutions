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
const int sN= 320;

int n, m, k, Block, cnt[sN][26], a[N];

void process_block(int no){
    int st= no*Block, endi= (no+1)*Block;
    endi= min(n,endi);

    for(int i=st;i<endi;i++){
        cnt[no][a[i]]++;
    }
}

void preprocess(){
    int no_of_blocks= cel(n,Block);

    fr(no_of_blocks)  process_block(i);
}

void query1(int x, int y){
    int st_block= x/Block, end_block= y/Block, ans= 0;
    int curr[26];

    clr(curr);

    for(int i=st_block; i<=end_block; i++){
        frj(26) {
            int c = cnt[i][j];
            curr[j]+= c;
        }
    }

    int st= st_block*Block, endi= (end_block+1)*Block;
    endi= min(n,endi);

    for(int i=st; i<x;i++){
        curr[a[i]]--;
    }

    for(int i=y+1; i<endi;i++){
        curr[a[i]]--;
    }

    fr(26)  if(curr[i])  ans++;
    outi(ans);
}

char s[N];

main(){
    int x,y,m,q, opt;

    scanf("%s",s);
    n= strlen(s);
    Block= (int) sqrt(n)+1;

    fr(n)  a[i]= s[i]-'a';

    preprocess();

    si(opt);
    fr(opt){
        si(q);

        if(q==2) {
            sii(x, y);
            --x, --y;

            query1(x, y);
        }
        else{
            si(x);
            scanf("%s",s);

            y=s[0]-'a';

            x--;
            int st= x/Block;

            cnt[st][a[x]]--;
            a[x]= y;
            cnt[st][a[x]]++;
        }
    }
}

