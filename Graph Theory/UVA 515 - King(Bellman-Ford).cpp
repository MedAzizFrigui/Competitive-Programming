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
const ll N=207;
const ll mod=1e9 + 7;
const int MAXN=107;
const double PI=3.141592653589793238;
//const double eps=numeric_limits<double>::epsilon();

vector<tuple<int,int,ll>>edges;
ll dist[MAXN];
int n,m;

int main(void){
	
	while(cin>>n,cin>>m){
		edges.clear();
		
		for(int i=1;i<=n;++i){
			edges.pb({105,i,0});
		}
		
		for(int i=0;i<m;++i){
			int a,b; cin>>a>>b;
			string s; cin>>s;
			int c; cin>>c;
			if(s=="gt"){
				edges.pb({a+b,a-1,-c-1});
			}else{
				edges.pb({a-1,a+b,c-1});
			}
		}
		fill_n(dist,sizeof(dist)/sizeof(ll),inf);
		dist[105]=0;
		
		for(int i=0;i<n;++i){
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
		if(ans) cout<<"lamentable kingdom"<<endl;
		else cout<<"successful conspiracy"<<endl;
	}	
	return 0;
}