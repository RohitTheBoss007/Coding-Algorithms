/* Heavy light decomposition to -----
given a tree where each node has a value 
 then there are queries where we have two nodes A and B and
  have to answer sum of nodes in the path from A to B efficiently
 */
  
   
#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <cstring>
#include <cassert>
#include <utility>
#include <iomanip>
#define ll long long
#define int long long
#define mod 998244353
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
template<typename T> T sum(T &a, T b){ return (a+=b)%=mod; }
template<typename T> T sub(T &a, T b){ (a-=b); if(a<0) a+=mod; }
using namespace std;

const int MAXN = 105000,MAXNN=1000001;
int spf[MAXNN];
map<ll,ll> m[MAXN];
void sieve() 
{ 
    spf[1] = 1; 
    for (int i = 2; i < MAXNN; i++) 
  
        // marking smallest prime factor for every 
        // number to be itself. 
        spf[i] = i; 
  
    // separately marking spf for every even 
    // number as 2 
    for (int i = 4; i < MAXNN; i += 2) 
        spf[i] = 2; 
  
    for (int i = 3; i * i < MAXNN; i++) { 
  
        // checking if i is prime 
        if (spf[i] == i) { 
  
            // marking SPF for all numbers divisible by i 
            for (int j = i * i; j < MAXNN; j += i) 
  
                // marking spf[j] if it is not 
                // previously marked 
                if (spf[j] == j) 
                    spf[j] = i; 
        } 
    } 
}

struct SegmentTree {
    int * tree;
    int size;

    void init(int sz) {
        tree = new int[4 * sz];
        memset(tree, 0, 4 * sz * sizeof(int));
        size = sz;
    }

    int getSum(int v, int from, int to, int l, int r) {
        if (l > to || r < from)
            return 0;
        if (from == l && to == r)
            return tree[v];
        int mid = (from + to) / 2;
        int res = getSum(v * 2, from, mid, l, min(r, mid));
        sum(res, getSum(v * 2 + 1, mid + 1, to, max(l, mid + 1), r));
        return res;
    }

    int getSum(int l, int r) {
        return getSum(1, 1, size, l, r); 
    }

    void update(int v, int from, int to, int pos, int val) {
        if (pos > to || pos < from)
            return;
        if (from == pos && to == pos) {
            tree[v] = val;
            return;
        }
        int mid = (from + to) / 2;
        update(v * 2, from, mid, pos, val);
        update(v * 2 + 1, mid + 1,  to, pos, val);
        tree[v] = (tree[v * 2] + tree[v * 2 + 1]);
    }

    void update(int pos, int val) {
        update(1, 1, size, pos, val);
    }
};

int n, qn;
char q;
int a, b;
int timer;
int sz[MAXN];
int tin[MAXN], tout[MAXN];    
int val[MAXN];
vector <int> g[MAXN];
int p[MAXN];
int chain[MAXN], chainRoot[MAXN];
int chainSize[MAXN], chainPos[MAXN];
int chainNum;
SegmentTree tree[MAXN];

bool isHeavy(int from, int to) {
    return sz[to] * 2 >= sz[from];
}

void dfs(int v, int par = -1) {
    timer++;
    tin[v] = timer;
    p[v] = par;
    sz[v] = 1;

    for (int i = 0; i < (int) g[v].size(); i++) {
        int to = g[v][i];
        if (to == par)
            continue;
        dfs(to, v);
        sz[v] += sz[to];
    }

    timer++;
    tout[v] = timer;
}

int newChain(int root) {
    chainNum++;
    chainRoot[chainNum] = root;
    return chainNum;
}

void buildHLD(int v, int curChain) {
    chain[v] = curChain;
    chainSize[curChain]++;
    chainPos[v] = chainSize[curChain];

    for (int i = 0; i < g[v].size(); i++) {
        int to = g[v][i];
        if (p[v] == to)
            continue;
        if (isHeavy(v, to))
            buildHLD(to, curChain);
        else
            buildHLD(to, newChain(to));
    }   
}

bool isParent(int a, int b) {
    return tin[a] <= tin[b] && tout[a] >= tout[b];
}

int getSum(int a, int b) {
    int res = 0;
    while (true) {
        int curChain = chain[a];
        if (isParent(chainRoot[curChain], b))
            break;
        sum(res, tree[curChain].getSum(1, chainPos[a]));
        a = p[chainRoot[curChain]];
    }
    while (true) {
        int curChain = chain[b];
        if (isParent(chainRoot[curChain], a))
            break;                                          
        sum(res, tree[curChain].getSum(1, chainPos[b]));
        b = p[chainRoot[curChain]];
    }
    int from = chainPos[a], to = chainPos[b];
    if (from > to)
        swap(from, to);
    sum(res, tree[chain[a]].getSum(from, to));
    return res;
}


int32_t main() {
    //assert(freopen("input.txt","r",stdin));
    //assert(freopen("output.txt","w",stdout));
	int t;
	cin>>t;
	sieve();
	while(t--){
    scanf("%lld", &n);
    for (int i = 1; i < n; i++) {
        int from, to;
        scanf("%lld %lld", &from, &to);
        g[from].push_back(to);
        g[to].push_back(from);
    }

    dfs(1);
    buildHLD(1, newChain(1));

    for (int i = 1; i <= chainNum; i++) {
        tree[i].init(chainSize[i]); 
    }
	
	for(int a=1;a<=n;a++){
		int b;
		scanf("%lld",&b);
		// val[a] += b;
        tree[chain[a]].update(chainPos[a], b);
        
        
	}
	
    scanf("%lld\n", &qn);
    // trace(qn);
    for (int i = 1; i <= qn; i++) {
        scanf("%lld %lld\n",&a, &b);       
            printf("%lld\n", getSum(a, b));
        
    }  
    }  

    return 0;
}
