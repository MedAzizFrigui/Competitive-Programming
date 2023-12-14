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
const ll N=20007;
const ll mod=1e9 + 7;
const int MAXN=2e5 + 7;
const double PI=3.141592653589793238;
//const double eps=numeric_limits<double>::epsilon();

vector<int>adj[N];
int root;
int subsz[N];
pair<int,int>ans;

void dfssz(int v, int p){
	subsz[v]=1;
	
	for(int j=0;j<adj[v].size();++j){
		int i=adj[v][j];
		if(i==p) continue;
		dfssz(i,v);
		subsz[v]+=subsz[i];
	}

}

void dfscal(int v, int p){
	int mx=subsz[root]-subsz[v];
	
	for(int j=0;j<adj[v].size();++j){
		int u=adj[v][j];
		if(u==p) continue;
		mx=max(mx,subsz[u]);
	}
	
	if(ans.f > mx){
		ans=mp(mx,v);
	}
	
	for(int j=0;j<adj[v].size();++j){
		int u=adj[v][j];
		if(u==p) continue;
		dfscal(u,v);
	}
}

int main(void){
	
	int t; cin>>t;
	while(t--){
		int n; cin>>n;
		for(int i=1;i<=n;++i) adj[i].clear();
		
		int a,b; cin>>a>>b;
		root=a;
		adj[a].pb(b);
		adj[b].pb(a);
		for(int i=1;i<n-1;++i){
			int a,b; cin>>a>>b;
			adj[a].pb(b);
			adj[b].pb(a);
		}
		
		dfssz(root , -1);
		ans=mp(1000000000,-1);
		dfscal(root,-1);
		
		cout<<ans.s<<" "<<ans.f<<endl;
			
	}
	return 0;
}