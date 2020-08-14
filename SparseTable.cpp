


const int N=6e5+5;
 
const int maxn=N;
const int max_logn=20;
template<typename T>
struct SparseTable{
	int log[maxn];
	T dp[max_logn][maxn];
	T combine(T a,T b){
		return min(a,b);
	}
	SparseTable(){
		log[1] = 0;
		for (int i = 2; i < maxn; i++)
			log[i] = log[i/2] + 1;
	}
	void build(vector<T> b)
	{
		int n=b.size();
		for (int i = 0; i < n; ++i){
			dp[0][i]=b[i];
		}
		for (int j = 1; j < max_logn; j++)
			for (int i = 0; i + (1 << j) < maxn; i++)
				dp[j][i] = combine(dp[j - 1][i], dp[j - 1][i + (1 << (j - 1))]);
	}
	T qry(int l,int r)
	{
		int j=log[r-l+1];
		return combine(dp[j][l],dp[j][r-(1<<j)+1]);
	}
};
SparseTable<int> sp;


//usage 

//create vector v(say)
//call sp.build(v) -> init
//sp.qry(l,r) ->inclusive

//change combine to any other idempotent operation for O(1)
//ex max,min,OR,AND,gcd,lcm
