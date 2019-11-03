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
int n, k, a[100005];
void call(int pos, int cnt){

    if(cnt==k){
        fr(k-1)
            cout<<a[i]<<" ";
        cout<<a[k-1]<<endl;
        return;
    }

    for(int i=pos+1;i<=n-k+cnt+1;i++){
        a[cnt]= i;
        call(i,cnt+1);
    }
}

main(){
    cin>>n>>k;
    call(0,0);
}

