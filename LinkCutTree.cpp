
// Problem: E. Holes
// Contest: Codeforces - Codeforces Beta Round #13
// URL: https://codeforces.com/contest/13/problem/E
// Memory Limit: 64 MB
// Time Limit: 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

// 私に忍び寄るのをやめてください、ありがとう

#include<bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
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
#define x first
#define y second
#define vc vector
#define pb push_back
#define ar array
#define all(a) (a).begin(), (a).end()
#define rall(x) (x).rbegin(), (x).rend()
#define ms(v,n,x) fill(v,v+n,x);
#define init(c,a) memset(c,a,sizeof(c))
#define pll pair<ll,ll>
#define mll map<ll,ll>
#define sll set<ll>
#define vll vector<ll>
#define vpll vector<pll>
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

mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

const int N=1<<18;


int tt[1 + N][2], pp[1 + N], sz[1 + N];
 
int dir(int i) {
	return tt[pp[i]][0] == i ? 0 : 1;
}
 
int is_root(int i) {
	return tt[pp[i]][0] != i && tt[pp[i]][1] != i;
}
 
void pul(int i) {
	sz[i] = 1 + sz[tt[i][0]] + sz[tt[i][1]];
}
 
void attach(int p, int u, int d) {
	if (p)
		tt[p][d] = u, pul(p);
	if (u)
		pp[u] = p;
}
 
void rotate(int u) {
	int v = pp[u], w = pp[v], du = dir(u), dv = dir(v);
 
	if (is_root(v))
		pp[u] = w;
	else
		attach(w, u, dv);
	attach(v, tt[u][du ^ 1], du);
	attach(u, v, du ^ 1);
}
 
void splay(int u) {
	while (!is_root(u)) {
		int v = pp[u];
 
		if (!is_root(v))
			rotate(dir(u) == dir(v) ? v : u);
		rotate(u);
	}
}
 
int first(int u) {
	while (tt[u][0])
		u = tt[u][0];
	splay(u);
	return u;
}

// just call this before query on node u
int expose(int u) {
	int v, w;
 
	for (v = u, w = 0; v; w = v, v = pp[v])
		splay(v), attach(v, w, 1);
	splay(u);
	return u;
}

// set parent of u as v
 
void link(int u, int v) {
	expose(u), expose(v);
	attach(v, u, 1);
}
 
void cut(int u) {
	expose(u);
	pp[tt[u][0]] = 0;
	attach(u, 0, 0);
}

int32_t main()
{
    
	fast	
	cout << fixed << setprecision(12);
	ll n,m;
	cin>>n>>m;
	
	
	vll par(N+1);
	
	vll a(n+1);
	
	fore(i,1,n)sz[i]=1;
	
	fore(i,1,n){
		cin>>a[i];
		par[i]=i+a[i];
		if(par[i]<=n){
			link(i,par[i]);
		}
	}
	
	
	
	f(i,m){
		ll t;
		cin>>t;
		ll a,b;
		if(t==0){
			cin>>a>>b;
			if(par[a]<=n)
			cut(a); //disconnect i from parent
			
			par[a]=a+b;
			
			if(par[a]<=n)
			link(a,par[a]);	
		}
		
		else{
			cin>>a;
			expose(a);
			ll path=sz[a]; //length of path to root from a 
			ll root=first(a); //root of the tree a is a part of
			
			cout<<root<<" "<<path<<nl;
		}
		
	}

    

	return 0;
    
}
