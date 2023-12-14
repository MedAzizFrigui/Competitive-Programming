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
const int inf=  (int)1e9 ;
const ll N=50;
const ll mod=1e9 + 7;
const int MAXN=1007;
const double PI=3.141592653589793238;
//const double eps=numeric_limits<double>::epsilon();

vector<int>adj[MAXN];
vector<tuple<int,int,int>>edges;
int dist[MAXN];
set<int>start;
bool visited[MAXN];
set<int>ans;

void dfs(int s){
	if(visited[s]) return;
	visited[s]=true;
	ans.insert(s);
	for(auto u:adj[s]){
		dfs(u);
	}
	return ;
}

int main(void){
	int nb=1;
	int t; cin>>t;
	while(t--){
		int n,m; cin>>n>>m;
		for(int i=0;i<n;++i){
			adj[i].clear();
		}
		edges.clear();
		start.clear();
		ans.clear();
		for(int i=0;i<m;++i){
			int a,b,w; cin>>a>>b>>w;
			edges.pb({b,a,w});
			adj[b].pb(a);
		}
		fill_n(dist,sizeof(dist)/sizeof(int),inf);
		dist[0]=0;
		for(int i=0;i<n-1;++i){
			for(auto e:edges){
				int a,b,w;
				tie(a,b,w)=e;
				dist[b]=min(dist[b],dist[a]+w);
			}
		}
		for(auto e:edges){
			int a,b,w;
			tie(a,b,w)=e;
			if(dist[b]>dist[a]+w){
				 start.insert(b);
			}
		}
		
		fill_n(visited,sizeof(visited)/sizeof(bool),0);
		for(auto u:start){
			if(!visited[u]) dfs(u);
		}
		cout<<"Case "<<nb<<": ";
		if(ans.size()==0){
			cout<<"impossible"<<endl;
			nb++;
			continue;
		}
		
		for(auto it=ans.begin();it!=ans.end();++it){
			auto itt=it;
			itt++;
			itt==ans.end()?cout<<*it:cout<<*it<<" ";
		}
		cout<<endl;
		nb++;
	}
	return 0;
}