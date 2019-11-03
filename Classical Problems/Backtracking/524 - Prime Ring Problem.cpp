#include<bits/stdc++.h>
using namespace std;
//{
#define sets(a) memset(a, -1, sizeof(a))
#define clr(a) memset(a, 0, sizeof(a))
#define max(a,b) ((a)>(b)? (a):(b))
#define min(a,b) ((a)<(b)? (a):(b))
#define fr(n) for(int i=0;i<n;i++)
#define ull unsigned long long
#define ll long long
#define pb push_back
#define INF 10000007
#define all(v) v.begin(),v.end()
//}

int mark[100];
void sieve(int n){
    int limit= sqrt(n)+2;
    mark[0]= mark[1]= 1;

    for(int i=4; i<n; i+=2)
        mark[i]= 1;

    for(int i=3; i<n; i+=2){
        if(mark[i])
            continue;

        if(i<limit){
            for(int j=i*i; j<n; j+=i*2){
                mark[j]=1;
            }
        }
    }
}

int n, a[100], taken[100];

void call(int cnt){
    if(cnt==n){
        cout<<"1";
        for(int i=1;i<n;i++)
            cout<<" "<<a[i];
        puts("");
        return;
    }

    for(int i=2;i<=n;i++){
        int nxt= (cnt+1) %n;
        int prev= cnt-1;

        if(!taken[i] && !mark[i+a[prev]] && (!mark[i+a[nxt]] || !a[nxt])){

            taken[i]= 1;
            a[cnt]= i;
            call(cnt+1);
            a[cnt]= 0;
            taken[i]= 0;
        }
    }
}

main(){
    int i= 0;
    clr(mark);
    sieve(32);

    while (scanf("%d", &n) != EOF){
        if(i++)  puts("");

        clr(a);
        clr(taken);

        cout<<"Case "<<i<<":"<<endl;
        a[0]= 1;
        call(1);

    }
}
