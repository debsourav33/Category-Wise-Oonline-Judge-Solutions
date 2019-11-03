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

i64 m,n, a[152][152], sum[152][152];


i64 kadane(int m, int n){
    i64 maxi= -1e15;
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            i64 s= 0;
            for(int k=1;k<=m;k++){
                s+= sum[k][j]- sum[k][i-1];
                //cout<<k<<" "<<i<<" "<<j<<" "<<s<<endl;
                maxi= max(maxi,s);
                s= max(0,s);

            }

        }
    }

    return maxi;
}

int main(){
    sll(m,n);
    clr(sum);

    fr1(m){
        for(int j=1;j<=n;j++){
            sl(a[i][j]);
            sum[i][j]= sum[i][j-1]+ a[i][j];
        }
    }

    cout<<kadane(m,n)<<endl;

}

/*
3 3
-100 4 4
4 -10 4
4 4 1
int M[ROW][COL] = {{1, 2, -1, -4, -20},
                       {-8, -3, 4, 2, 1},
                       {3, 8, 10, 1, 3},
                       {-4, -1, 1, 7, -6}
                      };

 */
