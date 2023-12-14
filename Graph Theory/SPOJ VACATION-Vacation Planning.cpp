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
const ll inf= 1e18;
const ll N=107;
const ll mod=1e9 + 7;
const int MAXN=207;
const double PI=3.141592653589793238;
//const double eps=numeric_limits<double>::epsilon();

int n,m,k,q;
int mat[MAXN][MAXN];
ll dist[MAXN][MAXN];

int main(void){
	cin>>n>>m>>k>>q;
	
	for(int i=0;i<n;++i){
		for(int j=0;j<n;++j){
			mat[i][j]=-1;
			dist[i][j]=inf;
			if(i==j) dist[i][i]=0ll;
		}
	}
	
	for(int i=0;i<m;++i){
		int a,b,w; cin>>a>>b>>w;
		--a;--b;
		mat[a][b]=w;
		dist[a][b]=min(dist[a][b],w*1ll);
	}
	
	for(int k=0;k<n;++k){
		for(int i=0;i<n;++i){
			for(int j=0;j<n;++j){
				dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
			}
		}
	}
	ll sum=0ll;
	int nb=0;
	while(q--){
		int a,b; cin>>a>>b;
		--a;--b;
		ll ans=inf;
		for(int i=0;i<k;++i){
			ans=min(ans,dist[a][i]+dist[i][b]);
		}
		if(ans!=inf){
			++nb;
			sum+=ans;
		}
	}
	cout<<nb<<endl;
	cout<<sum<<endl;
		
	return 0;
}