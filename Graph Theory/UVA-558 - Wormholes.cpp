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
const ll inf=1e18;
const ll N=1007;
const ll mod=1e9 + 7;
const int MAXN=1007;
const double PI=3.141592653589793238;
//const double eps=numeric_limits<double>::epsilon();

vector<tuple<int,int,ll>>edges;
ll dist[MAXN];
int n,m;

int main(void){
	int t; cin>>t;
	while(t--){
		cin>>n>>m;
		edges.clear();
		
		for(int i=0;i<m;++i){
			int a,b,c; cin>>a>>b>>c;
			edges.pb({a,b,c*1ll});
		}
		fill_n(dist,sizeof(dist)/sizeof(ll),inf);
		dist[0]=0;
		
		for(int i=0;i<n-1;++i){
			for(auto e:edges){
				int a,b;
				ll w;
				tie(a,b,w)=e;
				dist[b]=min(dist[b],dist[a]+w);
			}
		}
		
		bool ans=true;
		
		for(auto e:edges){
			int a,b;
			ll w;
			tie(a,b,w)=e;
			if(dist[b] > dist[a]+w){
				ans=false;
				break;
			}
		}
		if(ans) cout<<"not possible"<<endl;
		else cout<<"possible"<<endl;
	}
	
	
	
	return 0;
}