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
const ll N=507;
const ll mod=1e9 + 7;
const int MAXN=2e5 + 7;
const double PI=3.141592653589793238;
//const double eps=numeric_limits<double>::epsilon();

int a[N];
int b[N];
int dp[N][N];
int seq[N];

int main(void){
	int n;cin>>n;
	
	for(int i=0;i<n;++i) cin>>a[i];
	
	int m; cin>>m;
	
	for(int i=0;i<m;++i) cin>>b[i];
	
	fill_n(seq,sizeof(seq)/sizeof(int),-1);
	
	for(int j=0;j<m;++j){
		if(a[0]==b[j]){
			dp[0][j]=1;
		}else{
			dp[0][j]=0;
		}
	}
	
	for(int i=1;i<n;++i){
		for(int j=0;j<m;++j){
			if(a[i]==b[j]){
				int sum=0;
				
				for(int k=0;k<m;++k){
					if(b[k]<b[j]){
						if(dp[i][k] > sum ){
							sum=dp[i][k];
							seq[j]=k;
						}
					}
				}
				
				dp[i][j]=1+sum;
			}else{
				dp[i][j]=max(0,dp[i-1][j]);
			}
		}
	}
	
	vector<int>ans;
	int res=0;
	int index=-1;

	for(int i=0;i<m;++i){
		if(dp[n-1][i] > res ){
			res=dp[n-1][i];
			index=i;
		}
	}
	for(int i=index;i!=-1;i=seq[i]){
		ans.pb(b[i]);
	}
	
	
	
	cout<<res<<endl;
	
	for(int i=ans.size()-1;i>=0;--i){
		i==0? cout<<ans[i]<<endl : cout<<ans[i]<<" ";
	}
	
	return 0;
}
			
	