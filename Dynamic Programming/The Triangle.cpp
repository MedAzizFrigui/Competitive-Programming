#include <iostream>
#include <algorithm>
#include <iomanip>
#include <ios>
#include <cmath>

using namespace std;

#define FAST ios::sync_with_stdio(0), cin.tie(0)
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define endl '\n'

typedef long long int  ll;
typedef unsigned long long int ull;
const ll inf=1e18;
const ll N=207;
const ll mod=61;
const size_t MAXN=10007;
const double PI=3.141592653589793238;
const double eps=numeric_limits<double>::epsilon();





int main(void){
	FAST;
	int n; cin>>n;
	int dp[n][n];
	int mat[n][n];
	
	int k=0;
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			mat[i][j]=dp[i][j]=0;
		}
	}
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>mat[i][j];
			if(j==k){
				k++;
				break;
			}
		}
	}
	
	dp[0][0]=mat[0][0];
	
	for(int i=1;i<n;i++){
		for(int j=0;j<n;j++){
				dp[i][j]=max(dp[i][j],dp[i-1][j]+mat[i][j]);
				
				if(j-1>=0){
					dp[i][j]=max(dp[i][j],dp[i-1][j-1]+mat[i][j]);
				}
		}
	}
	
	int ans=-1;
	
	for(int i=0;i<n;i++) ans=max(ans,dp[n-1][i]);
	
	cout<<ans<<endl;
	
	
	return 0;
}