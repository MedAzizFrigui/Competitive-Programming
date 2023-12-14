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
const int MAXN=100007;
const double PI=3.141592653589793238;
//const double eps=numeric_limits<double>::epsilon();

vector<pair<int,int>>adj[MAXN];
ll dist[MAXN];
bool visited[MAXN];

int main(void){
	
	int t; cin>>t;
	while(t--){
		int n,m; cin>>n>>m;
		int start,end;
		cin>>start>>end;
		start--;
		end--;
		for(int i=0;i<n;++i) adj[i].clear();
		for(int i=0;i<m;++i){
			int a,b,c; cin>>a>>b>>c;
			--a;--b;
			adj[a].pb(mp(b,c));
			adj[b].pb(mp(a,c));
		}
		
		for(int i=0;i<n;++i) dist[i]=inf,visited[i]=0;
	
		
		priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>>pq;
		
		dist[start]=0ll;
		pq.push(mp(0ll,start));
		
		while(!pq.empty()){
			int a=pq.top().s;pq.pop();
			if(visited[a]) continue;
			
			visited[a]=true;
			
			for(auto u:adj[a]){
				int b=u.f;
				int w=u.s;
				if(dist[b] > dist[a]+w*1ll){
					dist[b]=dist[a]+w*1ll;
					pq.push(mp(dist[b],b));
				}
			}
		}
		
		if(dist[end]==inf){
			cout<<"NONE"<<endl;
			continue;
		}
		cout<<dist[end]<<endl;
		
	}
	
	return 0;
}