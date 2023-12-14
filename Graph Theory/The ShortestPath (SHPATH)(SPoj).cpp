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
const int inf=  (int) 1e9 ;
const ll N=50;
const ll mod=1e9 + 7;
const int MAXN=100007;
const double PI=3.141592653589793238;
//const double eps=numeric_limits<double>::epsilon();

vector<pair<int,int>>adj[MAXN];
ll dist[MAXN];
bool visited[MAXN];
map<string,int>m;
int n;

int dijk(int start, int end){
	for(int i=0;i<n;++i) dist[i]=inf,visited[i]=0;
	
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
	dist[start]=0;
	pq.push(mp(0,start));
	while(!pq.empty()){
		int a=pq.top().s;pq.pop();
		if(visited[a]) continue;
		visited[a]=true;
		
		for(auto u:adj[a]){
			int b=u.f;
			int w=u.s;
			if(dist[b] > dist[a]+w){
				dist[b]=dist[a]+w;
				pq.push(mp(dist[b],b));
			}
		}
	}
	return dist[end];
}

int main(void){
	
	int t; cin>>t;
	while(t--){
		cin>>n;
		for(int i=0;i<n;++i) adj[i].clear();
		for(int i=0;i<n;++i){
			string s; cin>>s;
			m[s]=i;
			int m; cin>>m;
			for(int j=0;j<m;++j){
				int a,b; cin>>a>>b;
				--a;
				adj[i].pb(mp(a,b));
			}
		}
		
		int q; cin>>q;
		while(q--){
			string a,b; cin>>a>>b;
			cout<<dijk(m[a],m[b])<<endl;
		}
		
	}
	
	return 0;
}