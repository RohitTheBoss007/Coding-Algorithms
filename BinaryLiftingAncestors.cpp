
#include<bits/stdc++.h>
using namespace std;
#define ll int
// #define int long long
#define mod 1000000007
#define fast  ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define f(i,n) for(ll i=0;i<n;i++)
#define trace(x) cerr<<#x<<": "<<x<<" "<<endl
#define trace2(x, y) cerr<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl
#define trace3(x, y, z) cerr<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl
#define trace4(a, b, c, d) cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl
#define cout1(a) cout<<a<<endl
#define cout2(a,b) cout<<a<<" "<<b<<endl
#define cout3(a,b,c) cout<<a<<" "<<b<<" "<<c<<endl
#define cout4(a,b,c,d) cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl
#define vcout(v,i) cout<<v[i].fi<<" "<<v[i].se<<endl
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
#define nl "\n"
#define inf 1e18
#define cases ll T;cin>>T;while(T--)
#define BLOCK 500
const double PI = 3.141592653589793238460;
template<typename T> bool mmax(T &m, const T q) { if (m < q) {m = q; return true;} else return false; }
template<typename T> bool mmin(T &m, const T q) { if (m > q) {m = q; return true;} else return false; }
typedef std::complex<double> Complex;
typedef std::valarray<Complex> CArray;
 
using namespace std;

// the total number of nodes in the tree
#define N 7

// log(N)
#define LG 5
//adjacency list to store the graph
vector<int> graph[N]; 
int parent[N], level[N], visited[N], dp[N][LG]; //make global

//Find out the parent and level of each node using a depth first search
void dfs(int s,int &depth){
    
    visited[s] = 1;
    
    level[s] = depth;
    
    for(int i = 0; i < graph[s].size(); i++){
        if(!visited[graph[s][i]]){
            
            //going one level deeper
            depth++;
            
            dfs(graph[s][i],depth);
            
            parent[graph[s][i]]=s;
            
            //backtracking to the parent node
            depth--;
        }
    }
}

void findKth(int a, int k){
    
    int c = a;
    
    int cur_level = k;
    
    for(int i = LG; i >= 0; i--){
        if(dp[c][i] != -1 && (1 << i) <= cur_level){
            c = dp[c][i];
            cur_level = cur_level - (1 << i);
        }
    }
    
    cout << "The " << k << "nd ancestor of " << a << " is " << c << '\n';
    
}

void lca(int a, int b){
    
    int lg;
    
    if(level[a]<level[b])
        swap(a,b);
    
    //calculate the maximum value of height we might need
    for(lg =0 ; (1<<lg) <= level[a]; lg++);
    
    
    // find the ancestor of a at the same level of b
    for(int i = lg - 1; i >= 0; i--)
        if((level[a] - (1<<i)) >= level[b]){
            a = dp[a][i];
        }
        
    if(a == b){
        cout << "The lowest common ancestor of a and b is " << a << '\n';
        return;
    }
    
    // find the lowest ancestors of a and b which are not equal
    for(int i = lg; i >= 0; i--){
        if(dp[a][i] != dp[b][i]){
            a = dp[a][i];
            b = dp[b][i];
        }
    }
    cout << "The lowest common ancestor of a and b is " << parent[a] << '\n';
}

void precalculate(int dp[N][LG], int parent[]){

    
    
    //initialize 2^0 th ancestor as parent
    for(int i = 0; i < N; i++)
        dp[i][0] = parent[i];
    
    for(int h = 1; h < LG; h++){
        for(int i = 0; i < N; i++){
            if(dp[i][h-1] != -1)
                dp[i][h] = dp[dp[i][h-1]][h-1];
        }
    }
    
}
int main(){
    
    fast

    
    //initialize dp table with -1(which denotes unreachable ancestor)
    memset(dp, -1, sizeof(dp));
    
    /* create an undirected graph of the structure:
            0
          /   \
         1     2
        / \   / \
       3   4 5   6
    */
    
    
    graph[0].push_back(1);
    graph[1].push_back(0);
    graph[0].push_back(2);
    graph[2].push_back(0);
    graph[1].push_back(3);
    graph[3].push_back(1);
    graph[1].push_back(4);
    graph[4].push_back(1);
    graph[2].push_back(5);
    graph[5].push_back(2);
    graph[2].push_back(6);
    graph[6].push_back(2);
    
    
    int depth=0;
    dfs(0,depth);
    
    precalculate(dp, parent);
    
    //find out the 2nd ancestor of node 3
    findKth(3, 2);
    
    //find LCA of 5 and 6
    lca(5, 6);
    
    
}
