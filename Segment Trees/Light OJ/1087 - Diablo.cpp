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

const int maxn= 150005;

#define lefts 2*at
#define rights 2*at+1

int n, a[maxn], num[maxn], sum[maxn*4];

void build(int at, int L, int R){
    if(L==R){
        sum[at]= a[L];
        return;
    }

    int mid= (L+R)/2;

    build(lefts,L,mid);
    build(rights,mid+1,R);

    sum[at]= sum[lefts]+ sum[rights];
}

void update(int at, int L, int R, int pos, int val){
    if(L==R){
        sum[at]= val;
        return;
    }

    int mid= (L+R)/2;
    if(pos<=mid)
        update(lefts, L, mid, pos, val);
    else
        update(rights, mid+1, R, pos, val);

    sum[at]= sum[lefts]+ sum[rights];
}

int query(int at, int L, int R, int l, int r){

    if(r<L || l>R)  return 0;
    if(l<=L && r>=R)  return sum[at];

    int mid= (L+R)/2;

    int x= query(lefts, L, mid, l, r);
    int y= query(rights, mid+1, R, l, r);

    return x+y;
}

int main(){
    fastIO();
    int opt, cas= 1;
    cin>>opt;

    while(cas<=opt) {
        cout<<"Case "<<cas++<<":"<<endl;
        clr(a);

        int q, x, end;
        char c;
        cin >> n >> q;


        fr(n) {
            cin >> num[i];
            a[i] = 1;
        }

        end = n;

        build(1, 0, maxn - 1);

        fr(q) {
            cin >> c >> x;

            if (c == 'a') {
                num[end] = x;
                a[end] = 1;
                update(1, 0, maxn - 1, end, 1);
                end++;
            }
            if (c == 'c') {
                x--;
                int lo = 0, hi = end - 1, ans = -1;

                while (hi >= lo) {
                    int mid = (lo + hi) / 2;
                    int tmp = query(1, 0, maxn - 1, 0, mid);
                    tmp--;

                    //cout<<"mid "<<mid<<" "<<tmp<<endl;

                    if (tmp == x && a[mid] == 1) {
                        ans = mid;
                        break;
                    } else if (tmp < x)
                        lo = mid + 1;
                    else
                        hi = mid - 1;
                }

                if (ans == -1) {
                    cout << "none" << endl;
                    continue;
                }
                cout << num[ans] << endl;
                a[ans] = 0;
                update(1, 0, maxn - 1, ans, 0);

            }

        }
    }
}
