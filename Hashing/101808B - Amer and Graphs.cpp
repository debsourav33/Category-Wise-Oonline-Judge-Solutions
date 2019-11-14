
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

const i64 N= 5005, m[]= {1000000007,1000000009}, p[]= {304933,4395853};

int n;
pii vp[N];
map<pii,int>  cnt;
i64 hashes[5005][2];

i64 exp(i64 b, i64 e, i64 M){
    i64 ans=1;

    while(e){
        if(e&1)  ans= (ans*b) % M;
        b= (b*b) % M;
        e/= 2;
    }

    return ans;
}

void precalc(){
    i64 h1= 1, h2= 1;

    fr(5005){
        hashes[i][0]= h1;
        hashes[i][1]= h2;

        h1*= p[0];
        h2*= p[1];

        h1%= m[0];
        h2%= m[1];

    }
}

i64 compute_hash(int pos, int k) {
    i64 hash_value = 0;

    hash_value+= hashes[vp[pos].ff][k] + hashes[vp[pos].ss][k];
    hash_value%= m[k];

    return hash_value;
}

main(){
    precalc();
    int a,b, opt;

    si(opt);

    while(opt--) {
        cnt.clear();

        si(n);
        fr(n) {
            sii(a, b);

            if (a > b) swap(a, b);

            vp[i]= (mp(a, b));
        }

        fr(n) {
            int sum1 = 0, sum2=0;
            for (int j = i; j < n; j++) {
                sum1 += compute_hash(j,0);
                sum1 %= m[0];

                sum2 += compute_hash(j,1);
                sum2 %= m[1];

                if (cnt.count(mp(sum1,sum2)) == 0) cnt[mp(sum1,sum2)] = 0;

                cnt[mp(sum1,sum2)]++;
            }
        }

        int ans = 0;
        fr(n) {
            int sum1 = 0, sum2=0;
            for (int j = i; j < n; j++) {
                sum1 += compute_hash(j,0);
                sum1 %= m[0];

                sum2 += compute_hash(j,1);
                sum2 %= m[1];

                //cout<<"Pair: "; outii(i,j);
                //outi(cnt[mp(sum1,sum2)]);

                ans += cnt[mp(sum1, sum2)] - 1;
                cnt[mp(sum1, sum2)]--;

            }
        }

        outi(ans);
    }
}
