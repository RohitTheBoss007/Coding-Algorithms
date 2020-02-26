#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector< pii > vii;
#define INF 0x3f3f3f3f
vii *G;    // Graph
vi D;      // distance vector for storing min distance from the source.
/*=======================================*/
void dijkstra(int source, int N) {
    priority_queue<pii, vector<pii>, greater<pii> > Q;   // min heap
    D.assign(N,INF);
    D[source] = 0;
    Q.push({0,source});
    while(!Q.empty()){
        int u = Q.top().second;
        Q.pop();
        for(auto &c : G[u]){
            int v = c.second;
            int w = c.first;
            if(D[v] > D[u]+w){
                D[v] = D[u]+w;
                Q.push({D[v],v});
            }
        }
    }
}
/*==========================================*/
int main(){
    int N,M,k,u,v,w;
    cin >> N >> M >> k; 
//Input the number of nodes(0 based), number of edges and the source vertex.
    G = new vii[N];
    for(int i=0;i<M;i++){
        cin >> u >> v >> w; 
        u--;v--;
//Input the starting vertex of the edge, the ending vertex and the cost of the edge.
        G[u].push_back({w,v});
        G[v].push_back({w,u});
    }
    dijkstra(0, N); 
 
    cout<<D[N-1];
    cout<<endl;
}
