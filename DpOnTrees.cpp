/*
find the maximum sum of points in a tree if we cant take adjacent nodes
*/
 
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
#define mod 1000000007 //998244353
#define fast  ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define f(i,n) for(ll i=0;i<n;i++)
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
#define mp make_pair
#define pb push_back
#define all(a) (a).begin(), (a).end()
#define ms(v,n) memset((v),n,sizeof(v));
#define pll pair<ll,ll>
#define mll map<ll,ll>
#define sll set<ll>
#define vll vector<ll>
#define vpll vector<pll>
#define maxi(a,b,c) max(a,max(b,c))
#define maxii(a,b,c,d) max(max(a,b),max(c,d))
#define mini(a,b,c) min(a,min(b,c))
#define md(a,b)  ((a%mod)*(b%mod)+mod)%mod 
#define ad(a,b)  (a%mod+b%mod+mod)%mod
#define inf 1e18
#define cases ll T;cin>>T;while(T--)
#define BLOCK 500
//const double PI = 3.141592653589793238460;
template<typename T> bool mmax(T &m, const T q) { if (m < q) {m = q; return true;} else return false; }
template<typename T> bool mmin(T &m, const T q) { if (m > q) {m = q; return true;} else return false; }
typedef std::complex<double> Complex;
typedef std::valarray<Complex> CArray;
#define MAX 100005

ll p[MAX];
vll adj[MAX];
ll incDP[MAX],exDP[MAX];

void dfs(ll u,ll par=-1)
{
	incDP[u]=p[u];
	
	for(auto v:adj[u])
	{
		if(v==par)continue;
		dfs(v,u);
		incDP[u]+=exDP[v];
		exDP[u]+=max(incDP[v],exDP[v]);
		
	}
	

}

int32_t main()
{
    
	fast
	
	ll n;
	cin>>n;
	
	f(i,n)
	{
		cin>>p[i+1];
	}
// 	
// 	
	f(i,n-1)
	{
		ll u,v;
		cin>>u>>v;
		adj[u].pb(v);
		adj[v].pb(u);
		
	}
	
	dfs(1);
	
	cout<<max(incDP[1],exDP[1]);
	
	
	
	





    

	return 0;
    
}
