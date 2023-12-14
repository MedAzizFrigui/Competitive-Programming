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
const int inf= (int) 1e9 ;
const ll N=150;
const ll mod=1e9 + 7;
const int MAXN=150;
const double PI=3.141592653589793238;
// const double eps=numeric_limits<double>::epsilon();

int n,m;
vector<int>adj[MAXN];
int parent[MAXN];
int cap[MAXN][MAXN];

int bfs(int s,int t){
	for(int i=0;i<MAXN;++i) parent[i]=-1;
	parent[s]=-2;
	queue<pair<int,int>>q;
	q.push(mp(s,inf));
	while(!q.empty()){
		int cur=q.front().f;
		int f=q.front().s;
		q.pop();
		for(auto next:adj[cur]){
			if(parent[next]==-1 && cap[cur][next]){
				parent[next]=cur;
				int newflow=min(f,cap[cur][next]);
				if(next==t){
					return newflow;
				}
				q.push(mp(next,newflow));
			}
		}
	}
	return 0;
}

int ford(){
	int f=0;
	int newflow;
	while(newflow=bfs(0,n-1)){
		f+=newflow;
		int cur=n-1;
		while(cur!=0){
			int prev=parent[cur];
			cap[cur][prev]+=newflow;
			cap[prev][cur]-=newflow;
			cur=prev;
		}
	}
	return f;
}

void solve(){
	for(int i=0;i<MAXN;++i) adj[i].clear();
	for(int i=0;i<MAXN;i++){
		for(int j=0;j<MAXN;++j){
			cap[i][j]=0;
		}
	}
	
	for(int i=0;i<n;++i){
		adj[i].pb(i+n);
		adj[i+n].pb(i);
	}
	cap[0][n]=inf;
	cap[n-1][2*n-1]=inf;
	
	for(int i=0;i<n-2;++i){
		int v,c; cin>>v>>c;
		--v;
		cap[v][v+n]=c;
		
	}
	for(int i=0;i<m;++i){
		int u,v,w; cin>>u>>v>>w;
		--u;--v;
		adj[u+n].pb(v);
		adj[v+n].pb(u);
		adj[v].pb(u+n);
		adj[u].pb(v+n);
		cap[u+n][v]=w;
		cap[v+n][u]=w;
	}
	
	cout<<ford()<<endl;
	
}

int main(void){
	// freopen("in.txt","r",stdin);
	// freopen("out.txt","w",stdout);
	
	while(cin>>n>>m && (n!=0 || m!=0 )){
		solve();
	}
	
	return 0;
}