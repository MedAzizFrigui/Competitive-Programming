#include <iostream>
#include <algorithm>
#include <iomanip>
#include <ios>
#include <cmath>
#include <vector>
#include <set>
#include <bitset>
#include <map>

using namespace std;

#define FAST ios::sync_with_stdio(0), cin.tie(0)
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define endl '\n'

typedef long long int  ll;
typedef unsigned long long int ull;
const int inf= (int) 1e9 ;
const ll N=107;
const ll mod=1e9 + 7;
const int MAXN=2e5 + 7;
const double PI=3.141592653589793238;
//const double eps=numeric_limits<double>::epsilon();

int mat[N][N];
int dp[N][N];

int main(void){
	int n; cin>>n;
	
	for(int i=0;i<n;++i){
		for(int j=0;j<n;++j){
			cin>>mat[i][j];
		}
	}
	
	for(int i=0;i<n+1;++i){
		for(int j=0;j<n;j++) dp[i][j]=0;
	}
	
	
	for(int i=1;i<n+1;++i){
		for(int j=0;j<n;++j){
			dp[i][j]=dp[i-1][j]+mat[i-1][j];
		}
	}
	
	int ans=-inf;
	
	for(int i=1;i<n+1;++i){
		for(int j=0;j<i;++j){
			int sum=dp[i][0]-dp[j][0];
			int mx=sum;
			for(int k=1;k<n;++k){
				sum=max(sum+dp[i][k]-dp[j][k],dp[i][k]-dp[j][k]);
				mx=max(mx,sum);
			}
			ans=max(ans,mx);
		}
	}
	cout<<ans<<endl;

	return 0;
}
		
	
	
	