// https://codeforces.com/contest/1155/problem/D

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fast  ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define f(i,n) for(ll i=0;i<n;i++)
#define mp make_pair
#define pb push_back
#define mem(v) memset((v),0,sizeof(v));
#define pll pair<ll,ll>
#define mll map<ll,ll>
#define sll set<ll>
#define vll vector<ll>
#define maxi(a,b,c) max(a,max(b,c))
#define maxii(a,b,c,d) max(max(a,b),max(c,d))
#define mini(a,b,c) min(a,min(b,c))
#define md(a,b)  ((a%mod)*(b%mod)+mod)%mod 
#define ad(a,b)  (a%mod+b%mod+mod)%mod
#define nl endl
#define inf 1e18
#define cases ll t;cin>>t;while(t--)

const ll N=3e5+5;

ll n,x;
ll a[N];
ll dp[N][3][3];


int main()
{
    fast
    cin>>n>>x;
    for(ll i=0;i<n;i++)
    {
        cin>>a[i];
    }
    f(i,n+1)f(j,3)f(k,3)
    dp[i][j][k]=-inf;

    dp[0][0][0]=0;
    
    f(i,n+1)
    f(j,3)
    f(k,3)
    {
        if(j<2)
        {
            dp[i][j+1][k]=max(dp[i][j+1][k],dp[i][j][k]);
        }
        if(k<2)
        {
            dp[i][j][k+1]=max(dp[i][j][k+1],dp[i][j][k]);
        }
        if(i<n)
        {
            dp[i+1][j][k]=max(dp[i+1][j][k],dp[i][j][k]+((j==1)?a[i]:0)*((k==1)?x:1));
        }
    }
    cout<<dp[n][2][2];
    
    

    return 0;
}
