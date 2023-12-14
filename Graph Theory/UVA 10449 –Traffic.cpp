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
const int inf=numeric_limits<int>::max();
const ll N=107;
const ll mod=1e9 + 7;
const int MAXN=207;
const double PI=3.141592653589793238;
//const double eps=numeric_limits<double>::epsilon();

int val[MAXN];
int dist[MAXN];
vector<pair<ll,pair<int,int>>>edges;
bool visit[MAXN];
set<int>s;
int main(void){
	int n;
	int nb=1;
	while(cin>>n){	
		edges.clear();
		s.clear();
		for(int i=0;i<n;++i) cin>>val[i];
		int m; cin>>m;
		for(int i=0;i<m;++i){
			int a,b; cin>>a>>b;
			--a;--b;
			edges.pb(mp(pow(val[b]-val[a],3),mp(a,b)));
		}
		fill_n(dist,sizeof(dist)/sizeof(int),inf);

		dist[0]=0;
		
		for(int i=0;i<n-1;++i){
			for(auto e:edges){
				int a,b;
				int w;
				w=e.f;
				a=e.s.f;
				b=e.s.s;
				if(dist[a]==inf) continue;

				dist[b]=min(dist[b],dist[a]+w);
			}
		}
		
		for(int i=0;i<n-1;++i){
			for(auto e:edges){
				int a,b;
				int w;
				w=e.f;
				a=e.s.f;
				b=e.s.s;
				if(dist[a]==inf) continue;

				if(dist[b]>dist[a]+w){
					dist[b]=dist[a]+w;
					s.insert(b);
				}
			}
		}
		
		
		int q; cin>>q;
		cout<<"Set #"<<nb<<endl;
		nb++;
		while(q--){
			int x; cin>>x;--x;
			
			if(dist[x]<3 || dist[x]==inf || s.find(x)!=s.end()) cout<<'?'<<endl;
			else cout<<dist[x]<<endl;
		}
		
	}
	
	return 0;
}