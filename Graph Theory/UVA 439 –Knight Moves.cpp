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
const int MAXN=107;
const double PI=3.141592653589793238;
//const double eps=numeric_limits<double>::epsilon();

int dx[8]={-1,-1,1,1,-2,-2,2,2};
int dy[8]={2, -2,2,-2,1,-1,1,-1};

int dist[8][8];
bool visited[8][8];

bool Is_Valid(int x,int y){
	if( x<0 || y<0 || x>=8 || y>=8 ) return false;
	return true;
}

void bfs(int i,int j){
	queue<pair<int,int>>q;
	q.push(mp(i,j));
	dist[i][j]=0;
	while(!q.empty()){
		int sx=q.front().f;
		int sy=q.front().s;
		q.pop();
		if(visited[sx][sy]) continue;
		visited[sx][sy]=true;
		for(int i=0;i<8;++i){
			int tx=sx+dx[i];
			int ty=sy+dy[i];
			if(!Is_Valid(tx,ty)) continue;
			if(dist[sx][sy]+1<dist[tx][ty]){
				dist[tx][ty]=dist[sx][sy]+1;
				q.push({tx,ty});
			}
		}
	}
	
}

int main(void){
	string s1,s2;
	while(cin>>s1>>s2){
		for(int i=0;i<8;++i){
			for(int j=0;j<8;++j){
				dist[i][j]=inf;
				visited[i][j]=0;
			}
		}
		
		pair<int,int>start=mp(s1[0]-'a',s1[1]-'1');
		pair<int,int>finish=mp(s2[0]-'a',s2[1]-'1');
		
		bfs(start.f,start.s);
		
		cout<<"To get from "<<s1<<" to "<<s2<<" takes "<<dist[finish.f][finish.s]<<" knight moves."<<endl;
		
	}
	
	
	return 0;
}