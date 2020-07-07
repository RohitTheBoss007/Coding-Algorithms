
// Problem : E - Who Says a Pun?
// Contest : AtCoder - AtCoder Beginner Contest 141
// URL : https://atcoder.jp/contests/abc141/tasks/abc141_e
// Memory Limit : 1024 MB
// Time Limit : 2000 ms
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

// const int N=;
struct HashData {
	int h1, h2;
	bool operator==(const HashData& rhs) const {
		return h1 == rhs.h1 && h2 == rhs.h2;
	}
	bool operator!=(const HashData& rhs) const { return !(*this == rhs); }
};
class RollingHash {
	template<int B, int M>
	class RollingHashPart {
	private:
		size_t len;
		std::vector<int> pow_b, hash;
	public:
		RollingHashPart() {}
		template<typename T>
		RollingHashPart(const T& s) : len(s.size()), pow_b(s.size() + 1), hash(s.size() + 1) {
			pow_b[0] = 1;
			hash[0] = 0;
			for (int i = 0; i < len; i++) {
				pow_b[i + 1] = (ll)pow_b[i] * B % M;
				hash[i + 1] = ((ll)hash[i] * B + s[i]) % M;
			}
		}
		// [l, r)
		int get(int l, int r) const {
			int res = (hash[r] - (ll)hash[l] * pow_b[r - l]) % M;
			if (res < 0) res += M;
			return res;
		}
	};
public:
	RollingHashPart<1033, 1000000007> rh1;
	RollingHashPart<6037, 999999937> rh2;
 
	RollingHash() {}
	template<typename T> RollingHash(const T & s) : rh1(s), rh2(s) {}
	// [l, r)
	HashData get(int l, int r) const {
		return HashData{ rh1.get(l, r), rh2.get(l, r) };
	}
	// [l1, r1), [l2, r2)
	int lcp(const RollingHash & rhs, int l1, int r1, int l2, int r2) const {
		int lb = 0, ub = std::min(r1 - l1, r2 - l2) + 1;
		while (ub - lb > 1) {
			int md = (lb + ub) >> 1;
			(get(l1, l1 + md) == rhs.get(l2, l2 + md) ? lb : ub) = md;
		}
		return lb;
	}
};


int32_t main()
{
    
	fast
	
	ll n;
	string s;
	cin>>n>>s;
	RollingHash rh(s);
	
	auto ok=[&](int d){
		for(ll i=0;i<n;i++){
			for(ll j=i+d;j<n-d+1;j++){
				if(s[i]!=s[j]) continue;
				if(rh.get(i,i+d)==rh.get(j,j+d))
				return true;
			}
			
		}
		
		return false;
		
	};
	
	ll l=0,h=n/2,ans=0;
	while(l<=h){
		ll m=(l+h)>>1;
		if(ok(m)){
			ans=m;
			l=m+1;
		}
		else
		h=m-1;
	}


	cout<<ans;
	



    

	return 0;
    
}
