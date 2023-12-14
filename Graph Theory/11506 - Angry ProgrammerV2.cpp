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
const int inf= (int) 1e6 ;
const ll N=107;
const ll mod=1e9 + 7;
const int MAXN=5000;
const double PI=3.141592653589793238;
// const double eps=numeric_limits<double>::epsilon();

struct Node{
	int to,nextEdge;
	int cap;
}edge[MAXN];

class MinCut{

	int le[N],k,parent[N],record[N];
	int n;
	
public:
	
	MinCut(int x):n(x){
		for(int i=0;i<n;++i) le[i]=-1;
		k=0;
	}
	
	void addEdge(int u,int v,int cap){
		edge[k].to=v,edge[k].cap=cap,edge[k].nextEdge=le[u],le[u]=k++;
		
		edge[k].to=u,edge[k].cap=0,edge[k].nextEdge=le[v],le[v]=k++;
	}
	
	int mincut(int s,int t){
		int f=0;
		int newflow;
		while(1){
			newflow=inf;
			for(int i=0;i<n;++i) parent[i]=-1;
			parent[s]=-2;
			queue<pair<int,int>>q;
			q.push({s,inf});
			bool found=false;
			while(!q.empty()){
				int cur=q.front().f;
				int curf=q.front().s;
				q.pop();
				for(int id=le[cur];id!=-1;id=edge[id].nextEdge){
					
					if(parent[edge[id].to]==-1 && edge[id].cap){
						
						parent[edge[id].to]=cur;
						record[edge[id].to]=id;
						int nf=min(curf,edge[id].cap);
						if(edge[id].to == t){
							newflow=nf;
							found=true;
							break;
						}
						q.push({edge[id].to,nf});
					}
				}
				if(found)break;
			}
			if(!found){
				break;
			}
			
			f+=newflow;
			
			int cur=t;
			while(cur!=s){
				int ri=record[cur];
				edge[ri].cap-=newflow;
				edge[ri^1].cap+=newflow;
				cur=parent[cur];
			}
			
		}
		return f;
	}
		
};

int n,m;




int main(void){
	// freopen("in.txt","r",stdin);
	// freopen("out.txt","w",stdout);
	while(cin>>n>>m && (n!=0 || m!=0)){
		MinCut mc(2*n);
		mc.addEdge(0,n,inf);
		mc.addEdge(n-1,2*n-1,inf);
		for(int i=0;i<n-2;++i){
			int v,cap; cin>>v>>cap;
			v--;
			mc.addEdge(v,v+n,cap);
		}
		
		for(int i=0;i<m;++i){
			int u,v,w; cin>>u>>v>>w;
			--u;--v;
			mc.addEdge(u+n,v,w);
			mc.addEdge(v+n,u,w);
		}
		
		cout<<mc.mincut(0,2*n-1)<<endl;
	}
	return 0;
}