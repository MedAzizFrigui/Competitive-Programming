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
const ll N=50;
const ll mod=1e9 + 7;
const int MAXN=10007;
const double PI=3.141592653589793238;
//const double eps=numeric_limits<double>::epsilon();

int n,l,r;
vector<int>a;
int dp[MAXN];

int dfs(int cur){
	if(dp[cur]!=inf) return dp[cur];
	
	int ret=inf;
	
	for(int i=cur+1;i<a.size();++i){
		if(a[i]-a[cur]>=l && a[i]-a[cur]<=r){
			ret=min(ret,a[cur]-dfs(i));
		}
	}
	
	if(ret==inf) ret=a[cur];
	
	return dp[cur]=ret;
}

int main(void){
	int t; cin>>t;
	while(t--){
		cin>>n>>l>>r;
		a.clear();
		for(int i=0;i<n;++i){
			int x; cin>>x;
			if(x>0){
				a.pb(x);
			}
		}
		
		sort(a.begin(),a.end());
		
		fill_n(dp,sizeof(dp)/sizeof(int),inf);
		
		int ans=-inf;
		
		for(int i=0;i<a.size();++i){
			if(a[i]>=l && a[i]<=r){
				ans=max(ans,dfs(i));
			}
		}
		if(ans==-inf) ans=0;
		cout<<ans<<endl;
		
	}
	return 0;
}