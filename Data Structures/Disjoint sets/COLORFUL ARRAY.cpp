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
	 
	 size_t find_set(size_t v){
		 return parent[v]==v?v:parent[v]=find_set(parent[v]);
	 }
	 
	 bool union_sets(size_t a, size_t b){
		 a=find_set(a);
		 b=find_set(b);
		 if(a==b){
			 return false;
		 }
		 
		 if(sz[a]<sz[b]){
			 swap(a,b);
		 }
		 
		 parent[b]=a;
		 sz[a]+=sz[b];
		 sz[b]=0u;
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
 
int ans[200007]; 
 
 void solve(){
	 int n,q; cin>>n>>q;
	 pair<pair<int,int>,int>query[q];
	 
	 for(int i=0;i<q;i++){
		 int a,b,c; cin>>a>>b>>c;
		 query[i]={{a,b},c};
	 }
	 
	 disjointSets ds(n+2);
	 
	 for(int i=q-1;i>=0;i--){
		pair<pair<int,int>,int> u=query[i];
		int l=u.f.f;
		int r=u.f.s;
		int c=u.s;
		
		for(int v=ds.find_set(l);v<=r;v=ds.find_set(v)){
			ans[v]=c;
			ds.setParent(v,v+1);
		}
	 }
	 
	 for(int i=1;i<=n;i++) cout<<ans[i]<<endl;
		
 }
 
 
int main(void){
	
	int t=1;
	// cin>>t;
	while(t--){
		solve();
	}
	return 0;
} 