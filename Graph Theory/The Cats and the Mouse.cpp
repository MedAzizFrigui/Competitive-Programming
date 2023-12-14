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
int mat[107][107];
queue<pair<int,int>>q;
int dx[4]={-1,1,0,0};
int dy[4]={0,0,1,-1};



bool IsValid(int x,int y,int timer){
	if( x < 0 || y < 0 || x>=n || y>=m || mat[x][y]<=timer ) 
			return false;
	return true;
}

bool IsEscape(int x,int y,int timer){
	if(!IsValid(x,y,timer)) return false;
	
	if( x==0 || y==0 || x==n-1 || y==m-1 ) return true;
	
	return false;
	
}

void lavaFlow(){
	
	while(!q.empty()){
		int sx=q.front().f;
		int sy=q.front().s;
		q.pop();
		for(int i=0;i<4;++i){
			int tx=sx+dx[i];
			int ty=sy+dy[i];
			
			if(!IsValid(tx,ty,mat[sx][sy]+1)) continue;
			
			mat[tx][ty]=mat[sx][sy]+1;
			q.push(mp(tx,ty));
		}
	}
}

bool bfs(int i,int j){
	
	queue<pair<pair<int,int>,int>>qq;
	qq.push(mp(mp(i,j),0));
	
	while(!qq.empty()){
		int sx=qq.front().f.f;
		int sy=qq.front().f.s;
		int timer=qq.front().s;
		++timer;
		qq.pop();
		
		for(int i=0;i<4;++i){
			int tx=sx+dx[i];
			int ty=sy+dy[i];
			
			if(!IsValid(tx,ty,timer)) continue;
			
			if(IsEscape(tx,ty,timer)) return true;
			
			mat[tx][ty]=timer;
			qq.push(mp(mp(tx,ty),timer));
		}
		
	}
	
	return false;
	
	
}


int main(void){
	cin>>n>>m;
	
	int t; cin>>t;
	
	while(t--){
		for(int i=0;i<n;++i){
			for(int j=0;j<m;++j){
				mat[i][j]=100000000;
			}
		}
		
		pair<int,int>mouse;
		cin>>mouse.f;
		mouse.f--;
		
		cin>>mouse.s;
		mouse.s--;
		
		for(int i=0;i<2;++i){
			int a,b; cin>>a>>b;
			--a;--b;
			mat[a][b]=0;
			q.push(mp(a,b));
		}
		
		if(IsEscape(mouse.f,mouse.s,0)){
			cout<<"YES"<<endl;
			continue;
		}
		
		lavaFlow();
			
		bool ans=bfs(mouse.f,mouse.s);	
		
		if(ans) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
}