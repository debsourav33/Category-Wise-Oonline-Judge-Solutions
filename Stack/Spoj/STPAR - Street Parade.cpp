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

int n, a, now;

main(){
    while(1){
        now= 1;
        si(n);

        if(n==0)  return 0;

        queue<int> q;
        stack<int> st;

        fr(n){
            si(a);
            q.push(a);
        }

        while(!q.empty()){
            if(q.front()==now){
                now++;
                q.pop();
            }
            else if(!st.empty() && st.top()==now){
                now++;
                st.pop();
            }
            else{
                st.push(q.front());
                q.pop();
            }


        }

        int fl= 1;
        while(!st.empty()){
            if(st.top()==now++)
                st.pop();
            else{
                fl= 0;
                break;
            }
        }

        if(fl)  puts("yes");
        else puts("no");
    }
}
