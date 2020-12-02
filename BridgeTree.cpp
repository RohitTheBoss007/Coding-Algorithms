
// Problem : E. We Need More Bosses
// Contest : Codeforces - Educational Codeforces Round 46 (Rated for Div. 2)
// URL : https://codeforces.com/problemset/problem/1000/E
// Memory Limit : 256 MB
// Time Limit : 2000 ms

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

const int N=5e5+5;
ll p[N],rnk[N];

int get(int x)
{
 	return (p[x] == x ? x : p[x] = get(p[x]));
}

void link(int x, int y)
{
 	x = get(x);
 	y = get(y);
 	if(x == y) return;
 	if(rnk[x] > rnk[y])
 		swap(x, y);
 	p[x] = y;
 	rnk[y] += rnk[x];	
}

vll ar[N],t[N]; //t stores the bridge tree of graph ar
ll in[N],low[N],vis[N];
ll timer;
vpll bridges;

ll root;

void dfs(ll u,ll par)
{
	vis[u]=1;
	in[u]=low[u]=timer;
	timer++;
	for(auto i:ar[u])
	{
		if(i==par)
		continue;
		
		if(vis[i])
		{
			//back edge
			low[u]=min(low[u],in[i]);			
		}
		else{
			
			dfs(i,u);
			if(low[i]>in[u])
			{
				
				bridges.pb({u,i});
				
			}
			else
			link(u,i);
			
			low[u]=min(low[u],low[i]);
						
		}
	}
}

void build(){
	for(auto i:bridges){
		ll u=i.x;
		ll v=i.y;
		
		u=get(u);
		v=get(v);
		
		root=u;
		
		t[u].pb(v);
		t[v].pb(u);
	}
}

pair<int, int> dfs2(int v, int par = -1, int dist = 0) {
    p[v] = par;
    pair<int, int> res = make_pair(dist, v);
    for (auto to : t[v]) {
        if (to == par) continue;
        res = max(res, dfs2(to, v, dist + 1));
    }
    return res;
}

int32_t main()
{
    
	fast	
	cout << fixed << setprecision(12);
	ll n,m;
	cin>>n>>m;
	
	f(i,n)p[i]=i,rnk[i]=1;
	
	f(i,m){
		ll x,y;
		cin>>x>>y;
		x--;y--;
		ar[x].pb(y);
		ar[y].pb(x);
	}
	
	dfs(0,-1);
	
	build();
	
	auto da=dfs2(root);
    auto db = dfs2(da.y);
	
	cout<<db.x;

	return 0;
    
}
