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

#define outlflf(a,b) printf("%llf %llf\n",a,b);

string teams[18];
double p[18][18], dp[18][10];
int pow_of_2[10];

void calc(){
    pow_of_2[0]=1;

    fr1(8)  pow_of_2[i]= pow_of_2[i-1]*2;
}


void solve(){
    calc();
    fr(16)
        dp[i][0]= 1;

    for(int match= 1;match<=4;match++){
        for(int team=0;team<16;team++) {
            int block_size = pow_of_2[match], own_block_size = pow_of_2[match - 1];
            int curr_block = team / block_size;
            int own_block = team / own_block_size;

            int st = curr_block * block_size, endi = (curr_block + 1) * block_size;

            double pr = 0;

            for (int i=st;i<endi;i++) {
                int this_block = i/pow_of_2[match - 1];

                if (this_block == own_block) continue;

                pr+= dp[i][match-1] * (p[team][i]/100.0);
            }

            dp[team][match] = dp[team][match - 1] * pr;
        }
    }

}

main(){
    fr(16)  cin>>teams[i];

    fr(16)
        frj(16)
            cin>>p[i][j];

    solve();

    fr(16){
        double pr= dp[i][4]*100.0;

        frj(11) {
            if(j>=teams[i].length())  printf(" ");
            else  printf("%c",teams[i][j]);
        }

        printf("p=%.2lf%%\n",pr);
    }
}
