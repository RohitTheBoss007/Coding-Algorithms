
// Problem : Vertex Add Subtree Sum
// Contest : Library Checker
// URL : https://judge.yosupo.jp/problem/vertex_add_subtree_sum
// Memory Limit : 1024 MB
// Time Limit : 5000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

// author - chick_magnet® 

#include<bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define ll long long
#define int long long
#define mod 1000000007 //998244353
#define fast  ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define f(i,n) for(ll i=0;i<n;i++)
#define fore(i, a, b) for (ll i = (ll)(a); i <= (ll)(b); ++i)
#define nl "\n"
#define trace(x) cerr<<#x<<": "<<x<<" "<<endl
#define trace2(x, y) cerr<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl
#define trace3(x, y, z) cerr<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl
#define trace4(a, b, c, d) cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl
#define cout1(a) cout<<a<<nl
#define cout2(a,b) cout<<a<<" "<<b<<nl
#define cout3(a,b,c) cout<<a<<" "<<b<<" "<<c<<nl
#define cout4(a,b,c,d) cout<<a<<" "<<b<<" "<<c<<" "<<d<<nl
#define vcout(v,i) cout<<v[i].fi<<" "<<v[i].se<<nl
#define x first
#define y second
#define vc vector
#define pb push_back
#define ar array
#define all(a) (a).begin(), (a).end()
#define ms(v,n,x) fill(v,v+n,x);
#define init(c,a) memset(c,a,sizeof(c))
#define pll pair<ll,ll>
#define mll map<ll,ll>
#define sll set<ll>
#define vll vector<ll>
#define vpll vector<pll>
#define maxi(a,b,c) max(a,max(b,c))
#define maxii(a,b,c,d) max(max(a,b),max(c,d))
#define mini(a,b,c) min(a,min(b,c))
#define md(a,b)  ((a%mod)*(b%mod)+mod)%mod 
#define inf 9e18
#define cases ll T;cin>>T;while(T--)
#define BLOCK 500
//const double PI = 3.141592653589793238460;
template<typename T> bool mmax(T &m, const T q) { if (m < q) {m = q; return true;} else return false; }
template<typename T> bool mmin(T &m, const T q) { if (m > q) {m = q; return true;} else return false; }
typedef std::complex<double> Complex;
typedef std::valarray<Complex> CArray;
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
// void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int N=500001;
vll g[N];
ll n,q,t,a[N],bit[N],lord[N],rord[N];



inline void upd(int i, int val) {
	for ( ; i < N; i |= i + 1)
		bit[i] += val;
}

inline int get(int i) {
	int ans = 0;
	for ( ; i >= 0; i = (i & (i + 1)) - 1)
		ans += bit[i];
	return ans;
}


void dfs(ll u){
	
	lord[u]=t++;
	
	for(auto v:g[u])
	dfs(v);
	
	rord[u]=t;
}

ll sum(ll a,ll b){
	
	return get(b-1)-get(a-1);
}


int32_t main()
{
 	   
	fast	
	cout << fixed << setprecision(12);
	cin>>n>>q;

	f(i,n)cin>>a[i];
	
	f(i,n-1){
		ll p;
		cin>>p;
		g[p].pb(i+1);
	}
	
	dfs(0);
	
	
	
	f(i,n){
		// cout<<lord[i];
		upd(lord[i],a[i]);
	}
	

	
	
	
	f(i,q){
		ll c;
		cin>>c;
		if(c==0){
			ll u,x;
			cin>>u>>x;
			upd(lord[u],x);	
		}
		else{
			ll u;
			cin>>u;
			cout<<sum(lord[u],rord[u])<<nl;
			
		}
		
	}

	



    

	return 0;
    
}
