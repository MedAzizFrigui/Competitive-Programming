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
const ll inf=  1e18 ;
const ll N=50;
const ll mod=1e9 + 7;
const int MAXN=10007;
const double PI=3.141592653589793238;
//const double eps=numeric_limits<double>::epsilon();


int n;
vector<int>adj[10007];
int node;
int ans;
void dfs(int s,int p,int d){
	
	if(d>ans){
		ans=d;
		node=s;
	}
	
	for(auto u:adj[s]){
		if(u==p) continue;
		dfs(u,s,d+1);
	}
	
}

int main(void){
	
	cin>>n;
	for(int i=0;i<n-1;++i){
		int a,b; cin>>a>>b;
		--a;--b;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	
	ans=-1;
	
	dfs(0,-1,0);

	ans=-1;
	
	dfs(node,-1,0);
	
	cout<<ans<<endl;
	
	return 0;
}