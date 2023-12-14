#include <bits/stdc++.h>
 
#define FAST ios::sync_with_stdio(0), cin.tie(0),cout.tie(0)
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define endl '\n'
using namespace std;
typedef long long int  ll;
const ll inf=1e18;
const ll N=1007;
const ll mod=1e9 +7;
const int MAXN = 1e6;
 
 
int parent[N];
int sz[N];
 
void make_set(int v){
		parent[v]=v;
		sz[v]=1;
}
 
int find_set(int v){
	if(v==parent[v]) return v;
	return parent[v]=find_set(parent[v]);
}
 
void union_set(int a, int b){
	a=find_set(a);
	b=find_set(b);
	if(a!=b){
		if(sz[a]<sz[b]) swap(a,b);
		parent[b]=a;
		sz[a]+=sz[b];
	}
	
}
 
int main(){
	
	int n; cin>>n;
	vector<pair<int,int>>ans;
	for(int i=1;i<=n;i++) parent[i]=i;
	for(int i=0;i<n-1;i++){
		int a,b; cin>>a>>b;
		int aa=find_set(a);
		int bb=find_set(b);
		
		if(aa==bb) ans.pb({a,b});
		
		else{
			union_set(a,b);
		}
	}
	vector<pair<int,int>>res;
	int x=find_set(1);
	for(int i=2;i<=n;i++){
		int y=find_set(i);
		if(x!=y){
			res.pb({1,i});
			union_set(1,i);
		}
	}
	
	cout<<ans.size()<<endl;
	for(int i=0;i<ans.size();i++){
		cout<<ans[i].f<<" "<<ans[i].s<<" "<<res[i].f<<" "<<res[i].s<<endl;
	}
	
}