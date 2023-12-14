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
const int MAXN=57;
const double PI=3.141592653589793238;
//const double eps=numeric_limits<double>::epsilon();

int n,m,k,q;
ll dist[MAXN][MAXN];

int main(void){
	int nb=1;
	int t; cin>>t;
	while(t--){
	
		cin>>n;
		
		for(int i=0;i<n;++i){
			for(int j=0;j<n;++j){
				dist[i][j]=inf;
				if(i==j) dist[i][i]=0ll;
			}
		}
		
		for(int i=0;i<n;++i){
			for(int j=0;j<n;++j){
				int w;cin>>w;
				dist[i][j]=w*1ll;
			}
		}
		
		for(int k=0;k<n;++k){
			for(int i=0;i<n;++i){
				for(int j=0;j<n;++j){
					dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
				}
			}
		}
		int q; cin>>q;
		ll sum=0ll;
		while(q--){
			int a,b; cin>>a>>b;
			--a;--b;
			sum+=dist[a][b];
		}
		cout<<"Case #"<<nb<<": "<<sum<<endl;
		++nb;
	}
	return 0;
}