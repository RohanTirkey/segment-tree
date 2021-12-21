
 
#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned long long
#define lld long double
#define fo(i,s,n) for(ll i=s;i<=n;i++)
#define fr(i,n,s) for(ll i=n;i>=s;i--)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define trav(x) for(auto &it:x)
#define mod 1000000000+7
#define mod1 998244353
#define pi 3.141592653589793238462643383279
typedef pair<ll,ll> pii;
#define ub upper_bound
#define lb lower_bound
typedef vector<ll> vi;
typedef vector<vector<ll>> vvi;
typedef vector<pair<ll, ll>> vpii;
#define all(x) (x).begin(), (x).end()
#define BOOST ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
#define inf 1e18
#define min(a, b)       ((a) < (b) ? (a) : (b))
#define max(a, b)       ((a) < (b) ? (b) : (a))
#define debug(x)        cout << '>' << #x << ':' << x << endl;
#define debug2(x, y)    cout << '>' << #x << ':' << x << " | " << #y << ':' << y << "\n";
#define debug3(x, y, z) cout << '>' << #x << ':' << x << " | " << #y << ':' << y << " | " << #z << ':' << z << "\n";
#define debug4(x, y, z, w) cout << '>' << #x << ':' << x << " | " << #y << ':' << y << " | " << #z << ':' << z << " | " << #w << ':' << w << "\n";

void swap(ll &x, ll &y) {ll temp = x; x = y; y = temp;}
void google(ll t) {cout << "Case #" << t << ": ";}
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll expom(ll x,ll y,ll m){if(y == 0) return 1;x=x%m;if(y%2==0) return expom(x*x , y/2,m)%m;  return (x*expom(x*x,y/2,m))%m;}
inline ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
inline ll lcm(ll a, ll b) { return a * b / gcd(a, b); }
inline ll ceil(ll a, ll b){  return (a%b==0) ? a/b : a/b +1 ;}
#define onebits(x)      __builtin_popcountll(x)
#define zerobits(x)      __builtin_ctzll(x)

void pr_vi(vi arr , ll i , ll n){
      cout<<": "; for( ; i<=n ;i++) cout<<arr[i]<<" "; cout<<"\n";
}

vi pri(1000000+1);
void prime_factorization(){
      fo(i,2,1000000) pri[i] = -1;
      pri[1] = 1;
      fo(i,2,1000000){
            if(pri[i] == -1){
                  for(ll j = i ; j<= 1000000 ; j+=i){
                        if(pri[j] == -1){
                              pri[j] = i;
                        }
                  }
            }
      }
}

vi pfactors(ll n){
      vi res;
      while(pri[n]!=1){
            res.pb(pri[n]);
            n = n/pri[n];
      }
      return res;
}
// ---------------------------------------*******************--------------------------------------//


ll N = 200000+10; 
vi seg(4*N+1);
vi arr(N+1);

ll merge(ll a , ll b ) {
      return a+b;
}

void build(ll ind , ll low , ll high){
      if(low == high){
            seg[ind] = arr[low];
            return;
      }
      ll mid = (low + high)>>1;
      build(2*ind+1 , low , mid);
      build(2*ind+2 , mid+1 , high);
      seg[ind] = merge(seg[2*ind+1] , seg[2*ind+2]);
}

ll query(ll ind , ll low , ll high , ll l, ll r){
      if(low >= l && high <= r) return seg[ind];
      if(high < l || low > r) return 0;
      ll mid = (low + high)>>1;
      ll left = query(2*ind+1 , low , mid , l , r);
      ll right = query(2*ind+2 , mid+1 , high , l , r);
      return merge(left , right);
}

void point_update(ll ind , ll low , ll high , ll node , ll val){
      if(low == high){
            seg[ind] = val;
            arr[node] = val;
            return;
      }
      else{
            ll mid = (low + high)>>1;
            if(node<=mid){
                  point_update(2*ind+1 , low , mid , node , val);
            }
            else point_update(2*ind+2 , mid+1 , high , node , val);
            seg[ind] = merge(seg[2*ind+1] , seg[2*ind+2]);
      }
}
void spidy(){
      ll n; cin>>n;
      fo(i,0,n-1) cin>>arr[i];
      build(0,0,n-1);
      ll q; cin>>q;
      while(q--){
            ll a; cin>>a;
            if(a == 1){
                  ll node , val;
                  cin>>node>>val;
                  --node;
                  point_update(0,0,n-1,node,val);
            }
            else{
                  ll l,r; cin>>l>>r;
                  --l,--r;
                  cout<<query(0,0,n-1,l,r)<<"\n";
            }
      }

}
 
// ---------------------------------------*******************--------------------------------------//
 
 
signed main()
{
      BOOST
      //prime_factorization();
      ll t=1;
      cin>>t;
      while(t--){
            spidy();
      }
      return 0;
}



