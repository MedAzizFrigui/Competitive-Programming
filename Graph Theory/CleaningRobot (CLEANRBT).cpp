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
const int MAXN=50007;
const double PI=3.141592653589793238;
//const double eps=numeric_limits<double>::epsilon();

char mat[22][22];
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};

// map<pair<pair<int,int>,pair<int,int>>,int>dist;
int dist[22][22][22][22];


int m,n;
bool IsValid(int x,int y){
	if( x<0 || y<0 || x>=n || y>=m || mat[x][y]=='x' ) return false;
	return true;
}
pair<int,int>robot;
// set<pair<int,int>>adj[20][20];
vector<pair<int,int>>dirty;
int dr;
int dp[11][1<<11];

int solve(int mask,int pos){
	
	if( dp[pos][mask]!=inf) return dp[pos][mask] ;
	bool test=true;
	int res=inf;
	for(int i=0;i<dr;++i){
		if( ( mask & (1<<i) ) == 0 ){
			test=false;
			res=min(res,solve( ( mask | (1<<i) ), i) + dist[dirty[pos].f][dirty[pos].s][dirty[i].f][dirty[i].s]) ;
		}
		
	}
	if(test) res=0;
	return dp[pos][mask]=res;
}
			
bool verif(int x, int y, int l, int r){
	if ( !IsValid(x,y) || !IsValid(l,r) ) return false;
	if( y==r && ( x==l-1 || x== l+1 ) ) return true;
	if( x==l && ( y==r-1 || y== r+1 ) ) return true;

	return false;
}
int distanc[22][22];
bool visited[22][22];
void dijk(int i,int j){
	priority_queue<pair<int,pair<int,int>> , vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
	
	for(int i=0;i<22;++i){
		for(int j=0;j<22;++j){
			visited[i][j]=0;
			distanc[i][j]=inf;
		}
	}
	
	
	distanc[i][j]=0;
	pq.push(mp(0,mp(i,j)));
	
	while(!pq.empty()){
		int sx=pq.top().s.f;
		int sy=pq.top().s.s;
		pq.pop();
		
		if(visited[sx][sy]) continue;
		visited[sx][sy]=true;
		
		for(int i=0;i<4;++i){
			int tx=sx+dx[i];
			int ty=sy+dy[i];
			if( !IsValid(tx,ty) ) continue;
			if(distanc[tx][ty] > distanc[sx][sy]+1){
				distanc[tx][ty]=distanc[sx][sy]+1;
				pq.push(mp(distanc[tx][ty],mp(tx,ty)));
			}
		}
	}
}

int main(void){
	 
	while( cin>>m,cin>>n,n!=0,m!=0 ){
		
		dirty.clear();
		
		
		for(int i=0;i<n;++i){
			string s; cin>>s;
			for(int j=0;j<m;++j){
				mat[i][j]=s[j];
				if(s[j]=='*') dirty.pb({i,j});
				else if( s[j]=='o' ) robot=mp(i,j);
			}
		}
		
		
				
		
		for(int ix=0;ix<n;++ix){
			for(int iy=0;iy<m;++iy){
				for(int jx=0;jx<n;++jx){
					for(int jy=0;jy<m;++jy){
						if( ix==jx && iy==jy  && mat[ix][iy]!='X') dist[ix][iy][jx][jy] =0;
						else if( verif(ix,iy,jx,jy) ){
							dist[ix][iy][jx][jy] =1;
						}else dist[ix][iy][jx][jy] =inf;
						
						// cout<<dist[{ {ix,iy}, {jx,jy} } ]<<" ";
					}
				}
			}
		}
		
		dr=dirty.size();
		
		dijk(robot.f,robot.s);
		
		for(int i=0;i<dr;++i){
			dist[robot.f][robot.s][dirty[i].f][dirty[i].s]=distanc[dirty[i].f][dirty[i].s];
			dist[dirty[i].f][dirty[i].s][robot.f][robot.s]=distanc[dirty[i].f][dirty[i].s];
		}
		
		for(int i=0;i<dr;++i){
			dijk(dirty[i].f,dirty[i].s);
			for(int j=i+1;j<dr;++j){
				dist[dirty[i].f][dirty[i].s][dirty[j].f][dirty[j].s]=distanc[dirty[j].f][dirty[j].s];
				dist[dirty[j].f][dirty[j].s][dirty[i].f][dirty[i].s]=distanc[dirty[j].f][dirty[j].s];
			}
		}
				
		
		// for(int kx=0;kx<n;++kx){
			// for(int ky=0;ky<m;ky++){
				// if(mat[kx][ky]=='x') continue;
				// for(int ix=0;ix<n;++ix){
					// for(int iy=0;iy<m;++iy){
						// if(mat[ix][iy]=='x') continue;
						// for(int jx=0;jx<n;++jx){
							// for(int jy=0;jy<m;++jy){
								// if(mat[jx][jy]=='x') continue;
								// dist[ix][iy][jx][jy]=min(dist[ix][iy][jx][jy], dist[ix][iy][kx][ky] + dist[kx][ky][jx][jy] );
								 // cout<<dist[ix][iy][jx][jy]<<endl;
							// }
						// }
					// }
				// }
			// }
		// }
		
		
		for(int i=0;i<11;++i){
			for(int j=0;j< (1<<11) ;++j) dp[i][j]=inf;
		}
		
		
		int ans=inf;
		
		for(int i=0;i<dr;++i){
			
			ans=min(ans,solve( (0|(1<<i) ),i) + dist[robot.f][robot.s][dirty[i].f][dirty[i].s]);
		}
		if(ans==inf) ans=-1;
		cout<<ans<<endl;
								
		
	}
	
	
	return 0;
}