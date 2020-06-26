
// Problem : B. Kay and Snowflake
// Contest : Codeforces - Codeforces Round #359 (Div. 1)
// URL : https://codeforces.com/problemset/problem/685/B
// Memory Limit : 256 MB
// Time Limit : 3000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

//look at my code
//my code is amazing
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
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};

const int N=300003;
vll g[N];
ll sz[N],par[N],ans[N];


void dfs(ll a){
	sz[a]=1;
	pll big={0,0};
	for(auto b:g[a]){
		dfs(b);
		sz[a]+=sz[b];	
		big=max(big,{sz[b],b});	
	}
	
	if(2*big.x<=sz[a]){
		ans[a]=a;
	}
	else{
		ans[a]=ans[big.y];
		while((sz[a]-sz[ans[a]])*2>sz[a])
		ans[a]=par[ans[a]];		
	}
	
	
}


int32_t main()
{
    
	fast
	
	ll n,q;
	cin>>n>>q;
	f(i,n-1){
		ll p;
		cin>>p;
		par[2+i]=p;	
		g[p].pb(2+i);
	}
	
	dfs(1);
    f(i,q){
    	ll v;
    	cin>>v;
    	cout<<ans[v]<<nl;
    }

	return 0;
    
}
