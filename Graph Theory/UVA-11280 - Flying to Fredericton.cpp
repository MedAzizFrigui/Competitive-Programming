#include <iostream>
#include <algorithm>
#include <iomanip>
#include <ios>
#include <cmath>
#include <vector>
#include <set>
#include <bitset>
#include <map>
#include <queue>
using namespace std;

#define FAST ios::sync_with_stdio(0), cin.tie(0)
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define endl '\n'

typedef long long int  ll;
typedef unsigned long long int ull;
const int inf=  (int)1e9 ;
const ll N=50;
const ll mod=1e9 + 7;
const int MAXN=10007;
const double PI=3.141592653589793238;
//const double eps=numeric_limits<double>::epsilon();


int main(void){
	int t; cin>>t;
	int nb=1;
	while(t--){
		int n; cin>>n;
		map<string,int>label;
		for(int i=0;i<n;++i){
			string s; cin>>s;
			label[s]=i;
		}
		int m; cin>>m;
		int cost[n][n];
		for(int i=0;i<n;++i){
			for(int j=0;j<n;++j){
				cost[i][j]=inf;
			}
		}
		for(int i=0;i<m;++i){
			string s1,s2; cin>>s1>>s2;
			int w; cin>>w;
			cost[label[s1]][label[s2]]=min(cost[label[s1]][label[s2]],w);
		}
		
		int dp[n][n]; // dp[i][j]: minimal cost to travel to the city i after going through j cities
		for(int i=0;i<n;++i){
			for(int j=0;j<n;++j){
				dp[i][j]=inf;
			}
		}
		dp[0][0]=0;
		for(int i=0;i<n-1;++i){
			for(int k=0;k<n-1;++k){
				for(int u=i+1;u<n;++u){
					if(dp[i][k]!=inf && cost[i][u]!=inf)
					dp[u][k+1]=min(dp[u][k+1],dp[i][k]+cost[i][u]);
				}
			}
		}
		int ans[n];
		for(int i=0;i<n;++i) ans[i]=inf;
		for(int i=1;i<n;i++){
			ans[i]=min(ans[i-1],dp[n-1][i]);
		}
		cout<<"Scenario #"<<nb<<endl;
		int q; cin>>q;
		while(q--){
			int cur; cin>>cur;
			cur++;
			if(cur>=n) cur=n-1;
			if(ans[cur]==inf){
				cout<<"No satisfactory flights"<<endl;
			}else{
				cout<<"Total cost of flight(s) is $"<<ans[cur]<<endl;
			}
		}
		if(t!=0)cout<<endl;
		++nb;
	}
	return 0;
}