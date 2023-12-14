#include <bits/stdc++.h>
 
#define FAST ios::sync_with_stdio(false), cin.tie(nullptr)
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define endl '\n'
using namespace std;
typedef long long int  ll;
typedef unsigned long long int ull;
const ll inf=1e18;
const ll N=2e4+7;
const ll mod=998244353;
const size_t MAXN=1<<18;
 
 class disjointSets{
	 size_t *parent=new size_t [MAXN];
	 size_t *sz=new size_t [MAXN];
	 size_t nbr;
public:
	 disjointSets(size_t n):nbr(n){
		 for(size_t i=0u;i<nbr;i++){
			 parent[i]=i;
			 sz[i]=1u;
		 }
	 }
	 
	 void setParent(int v, int p){
		 parent[v]=p;
	 }
	 size_t getParent(int v){
		 return parent[v];
	 }
	 size_t find_set(size_t v){
		 return parent[v]==v?v:parent[v]=find_set(parent[v]);
	 }
	 
	 bool union_sets(size_t a, size_t b){
		 a=find_set(a);
		 b=find_set(b);
		 if(a==b){
			 return false;
		 }
		 if(sz[a]>sz[b]){
			 swap(a,b);
		 }
		 
		 parent[a]=b;
		 sz[b]+=sz[a];
		 sz[a]=0u;
		 nbr--;
		 return true;
	 }

	 bool sameSet(size_t a, size_t b){
		 return find_set(a)==find_set(b);
	 }
	 
	 size_t nbrOfSets(){
		 return nbr;
	 }
	 
	size_t sizeOfSets(size_t v){
			return sz[find_set(v)];
	}	 
 };
 

 void solve(){
	int n,m; cin>>n>>m;
	disjointSets ds(n);
	
	pair<int,int>edges[m];
	
	for(int i=0;i<m;i++){
		int a,b; cin>>a>>b;a--;b--;
		edges[i]=mp(a,b);
	}
	
	int q; cin>>q;
	
	int query[q];
	set<int>s;
	for(int i=0;i<q;i++){
		int a; cin>>a;a--;
		query[i]=a;
		s.insert(a);
	}
	
	for(int i=0;i<m;i++){
		if(s.find(i)==s.end()){
			ds.union_sets(edges[i].f,edges[i].s);
		}
	}
	
	vector<int>ans;
	ans.pb(ds.nbrOfSets());
	
	for(int i=q-1;i>0;i--){
		ds.union_sets(edges[query[i]].f,edges[query[i]].s);
		ans.pb(ds.nbrOfSets());
	}
	
	for(int i=ans.size()-1;i>=0;i--){
		cout<<ans[i]<<" ";
	}
		
	
 }
 

int main(void){
	FAST;
	int t=1;
	// cin>>t;
	int nb=1;
	while(t--){
		// cout<<"Case "<<nb<<":"<<endl;
		solve();
		nb++;
	}
	return 0;
}