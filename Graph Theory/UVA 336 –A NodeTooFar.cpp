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
const int inf=(int) 1e8;
const ll N=107;
const ll mod=1e9 + 7;
const int MAXN=37;
const double PI=3.141592653589793238;
//const double eps=numeric_limits<double>::epsilon();

vector<int>adj[MAXN];
bool visited[MAXN];
int dist[MAXN];
map<int,int>label;
int cnt;
int nb=1;

void bfs(int s,int ttl){
	queue<int>q;
	q.push(s);
	dist[s]=0;
	while(!q.empty()){
		int a=q.front();q.pop();
		if(visited[a]) continue;
		visited[a]=true;
		for(auto u:adj[a]){
			if(dist[a]+1>ttl) continue;
			if(dist[u]>dist[a]+1){
				dist[u]=dist[a]+1;
				q.push(u);
			}
		}	
	}
}

int main(void){
	int m;
	while(cin>>m){
		label.clear();
		for(int i=0;i<32;++i) adj[i].clear();
		cnt=0;
		for(int i=0;i<m;++i){
			int a,b; cin>>a>>b;
			if(label.find(a)==label.end()) label[a]=cnt++;
			if(label.find(b)==label.end()) label[b]=cnt++;
			adj[label[a]].pb(label[b]);
			adj[label[b]].pb(label[a]);
		}
		int start,ttl;
		while(cin>>start,cin>>ttl,start!=0 || ttl !=0 ){
			if(label.find(start)==label.end()) label[start]=cnt++;
			for(int i=0;i<cnt;++i){
				dist[i]=inf;
				visited[i]=0;
			}
			
			bfs(label[start],ttl);
			int ans=0;
			for(int i=0;i<cnt;++i) if(dist[i]>ttl) ans++;
			cout<<"Case "<<nb<<": "<<ans<<" nodes not reachable from node "<<start<<" with TTL = "<<ttl<<"."<<endl;
			nb++;
		}
		
	}
	return 0;
}