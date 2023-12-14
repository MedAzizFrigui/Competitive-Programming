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
const ll inf=1e18;
const ll N=207;
const ll mod=1e9 + 7;
const int MAXN=2e5 + 7;
const double PI=3.141592653589793238;
//const double eps=numeric_limits<double>::epsilon();
int a[307];
int cost[307][307];
int dp[307][37];

int main(void){
	int n,m; 
	while(cin>>n,cin>>m){
		
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		
		
		
		for(int i=0;i<n;i++){
			for(int j=i;j<n;j++){
				cost[i][j]=0;
				for(int k=i;k<j;k++){
					cost[i][j]+=min(abs(a[i]-a[k]),abs(a[j]-a[k]));
				}
			}
		}
		
		
		
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				dp[i][j]=1000000000;
			}
		}
		
		for(int i=0;i<n;i++){
			dp[i][0]=0;
			for(int j=0;j<=i;j++){
				dp[i][0]+=abs(a[i]-a[j]);
			}
		}
		
		
		for(int i=1;i<n;i++){
			for(int j=1;j<m;j++){
				for(int k=0;k<=i;k++){
					dp[i][j]=min(dp[i][j],dp[k][j-1]+cost[k][i]);
				}
			}
		}
		
		int ans=1000000000;
		
		
		
		for(int i=0;i<n;i++){
			int cur=dp[i][m-1];
			for(int j=i+1;j<n;j++){
				cur+=abs(a[i]-a[j]);
			}
			ans=min(ans,cur);
		}
		
		cout<<ans<<endl;
		
	}
	return 0;
}