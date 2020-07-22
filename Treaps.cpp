

// Problem : C1. Prefix Flip (Easy Version)
// Contest : Codeforces - Codeforces Round #658 (Div. 2)
// URL : https://codeforces.com/contest/1382/problem/C1
// Memory Limit : 256 MB
// Time Limit : 1000 ms
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
#define st first
#define nd second
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
#define FOR(i,b,e) for(int i=(b); i <= (e); ++i)
#define FORD(i,b,e) for(int i=(b); i >= (e); --i)
#define SIZE(c) (int) (c).size()
#define FORE(i,c) FOR(i,0,SIZE(c)-1)
#define FORDE(i,c) FORD(i,SIZE(c)-1,0)
typedef pair <int,int> pii;

typedef vector <int> VI;
typedef vector <bool> VB;
typedef vector <pii> VP;
typedef vector <ll> VL;
typedef vector <pll> VPL;
 
typedef vector <VI> VVI;
typedef vector <VL> VVL;
typedef vector <VB> VVB;
typedef vector <VP> VVP;

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

// const int N=;

struct Treap {
    int n;
    VI L, R, par, cnt, rv, prio;
 
    Treap(int n): n(n), L(n,-1), R(n,-1), par(n,-1), cnt(n,1), rv(n,0) {
        srand(time(0));
        FOR(i,0,n-1) prio.pb(rand());
    }
 
    void rev(int x) { rv[x] ^= 1; }
 
    int detach(int v, VI &T) {
        int temp = T[v];
        if (temp != -1) {
            cnt[v] -= cnt[temp];
            par[temp] = -1;
            T[v] = -1;
        }
 
        return temp;
    }
 
    void attach(int v, VI &T, int x) {
        cnt[v] += cnt[x];
        par[x] = v;
        T[v] = x;
    }
 
    int getRoot(int v) {
        return par[v] == -1 ? v : getRoot(par[v]);
    }
 
    void push(int v) {
        if (rv[v]) {
            rv[v] = 0;
            if (L[v] != -1) rev(L[v]);
            if (R[v] != -1) rev(R[v]);
 
            swap(L[v], R[v]);
        }
    }
 
    int deepest(int v, VI &T) {
        push(v);
 
        if (T[v] == -1) return v;
        else return deepest(T[v], T);
    }
 
    int first(int v) { return deepest(v, L); }
    int last(int v) { return deepest(v, R); }
 
    int join(int x, int y) {
        if (min(x,y) == -1) return max(x, y);
 
        push(x); push(y);
        if (prio[x] > prio[y]) {
            attach(x, R, join(detach(x, R), y));
            return x;
        } else {
            attach(y, L, join(x, detach(y, L)));
            return y;
        }
    }
 
    pii split(int x, int k) {
        if (x == -1) return {-1, -1};
 
        push(x);
        int left = (L[x] == -1 ? 0 : cnt[L[x]]);
 
        if (k > left) {
            pii right = split(detach(x, R), k - left - 1);
            return {join(x, right.st) , right.nd};
        } else {
            pii left = split(detach(x, L), k);
            return {left.st, join(left.nd, x)};
        }
    }
};

int32_t main()
{
    
	fast	
	cout << fixed << setprecision(12);
	
	cases{
		
		ll n;
		cin>>n;
	
	
		
		
		string s1,s2;
		
		cin>>s1>>s2;
		
		int root = 0;
		Treap treap(n);
		FOR(i,1,n-1) {
		    root = treap.join(root, i);
		}
		
		VI a(n),b(n);
		
		FOR(i,0,n-1) {
		   a[i]=(s1[i]=='1');
		   b[i]=(s2[i]=='1');
		}
		
		
		
		
		vll ans;
		
		ll f=0;
		
		for(ll i=n-1;i>=0;i--){
			
			int left, mid, right;
	        tie(left, mid) = treap.split(root, i);
	        tie(mid, right) = treap.split(mid, 1);
	        
	        root = treap.join(left, treap.join(mid, right));
	        ll now=a[mid]^f;
	        if(now==b[i]) continue;
	        
	      	//what is at a[1]
	        tie(left, mid) = treap.split(root, 0);
	        tie(mid, right) = treap.split(mid, 1);
	        
	        root = treap.join(left, treap.join(mid, right));
	        
	        if((a[mid]^f)!=now){
	        	ans.pb(0);	
	        	if(i==0) break;        	
	        }
	       
	        
	        int l=0,r=i;
	        tie(left, mid) = treap.split(root, l);
        	tie(mid, right) = treap.split(mid, r - l + 1);
        	treap.rev(mid);
        	
        	root = treap.join(left, treap.join(mid, right));
        	
        	f^=1;
        	
        	ans.pb(i);
		}
		
		cout<<ans.size()<<" ";
		for(auto i:ans) cout<<i+1<<" ";
		cout<<nl;
		
	}
	



    

	return 0;
    
}
