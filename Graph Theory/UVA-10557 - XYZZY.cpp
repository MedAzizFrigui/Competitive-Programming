#include <iostream>
#include <algorithm>
#include <iomanip>
#include <ios>
#include <cmath>
#include <vector>
#include <set>
#include <bitset>
#include <map>
#include <tuple>

using namespace std;

#define FAST ios::sync_with_stdio(0), cin.tie(0)
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define endl '\n'

typedef long long int  ll;
typedef unsigned long long int ull;
const int inf=(int) 1e8;
const ll N=107;
const ll mod=1e9 + 7;
const int MAXN=107;
const double PI=3.141592653589793238;
//const double eps=numeric_limits<double>::epsilon();

vector<tuple<int,int,int>>edges;
int dist[MAXN];
vector<int>adj[MAXN];
int n;
int val[MAXN];

int main(void){
	while(cin>>n,n!=-1){
		
		edges.clear();
		for(int i=0;i<n;++i) adj[i].clear();
		
		for(int i=0;i<n;++i){
			cin>>val[i];
			int m; cin>>m;
			for(int j=0;j<m;++j){
				int a; cin>>a;a--;
				adj[i].pb(a);
			}
		}
		
		for(int i=0;i<n;++i){
			for(auto u:adj[i]){
				edges.pb({i,u,-val[u]});
			}
		}
		fill_n(dist,sizeof(dist)/sizeof(int),inf);
		dist[0]=0;
		
		for(int i=0;i<n-1;++i){
			for(auto e:edges){
				int a,b;
				int w;
				tie(a,b,w)=e;
				if(dist[a]>=100) continue;
				dist[b]=min(dist[b],dist[a]+w);
			}
		}
				
		for(auto e:edges){
			int a,b;
			int w;
			tie(a,b,w)=e;
			if(dist[a]>=100) continue;
			if(dist[b] > dist[a]+w){
				edges.pb({0,b,-inf});
			}
		}

		for(int i=0;i<n-1;++i){
			for(auto e:edges){
				int a,b;
				int w;
				tie(a,b,w)=e;
				if(dist[a]>=100) continue;
				dist[b]=min(dist[b],dist[a]+w);
			}
		}

			
		if( dist[n-1]<100) cout<<"winnable"<<endl;
		else cout<<"hopeless"<<endl;
	}
	return 0;
}