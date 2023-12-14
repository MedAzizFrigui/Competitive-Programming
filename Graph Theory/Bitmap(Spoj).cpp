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
const int MAXN=10007;
const double PI=3.141592653589793238;
//const double eps=numeric_limits<double>::epsilon();

int n,m;
char mat[183][183];
int dist[183][183];
int ans[183][183];
bool visited[183][183];

vector<pair<int,int>> mv={ {1,0},{-1,0},{0,1},{0,-1} };

int mn;

bool IsValid(int x,int y){
	if( x < 0 || y < 0 ) return false;
	if( x >=n || y>= m ) return false;
	
	return true;
}

queue<pair<int,int>>q;

void bfs(){
	

	while (!q.empty()) {
		pair<int,int> s = q.front(); q.pop();
		
		for (auto u : mv) {
			int vx=s.f+u.f;
			int vy=s.s+u.s;
			if (!IsValid(vx,vy) || visited[vx][vy]) continue;
			
			if(dist[vx][vy] > dist[s.f][s.s] ){
			
				visited[vx][vy] = true;
				
				dist[vx][vy] = dist[s.f][s.s]+1;
				q.push({vx,vy});
			}
		}
	}

}

int main(void){
	FAST;
	int t; cin>>t;
	while(t--){
		cin>>n>>m;
		
		for(int i=0;i<n;++i){
			for(int j=0;j<m;++j){
				visited[i][j]=0;
				dist[i][j]=1000000000;
			}
		}
		
		
		for(int i=0;i<n;++i){
			string s; cin>>s;
			for(int j=0;j<m;++j){
				mat[i][j]=s[j];
				if(s[j]=='1'){
					q.push(mp(i,j));
					dist[i][j]=0;
				}
			}
		}
		
		
		
		bfs();
		
		for(int i=0;i<n;++i){
			for(int j=0;j<m;++j){
				cout<<dist[i][j]<<" ";
			}
			cout<<endl;
		}
		
		
	}
		
	return 0;
}