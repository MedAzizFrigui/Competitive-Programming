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
 
int rep[100007];
int child[100007]; 
int ans[100007];
 void solve(){
	int n,q; cin>>n>>q;
	disjointSets ds(2*n);
	
	int a[n];
	fill_n(rep,sizeof(rep)/sizeof(int),-1);
	fill_n(child,sizeof(child)/sizeof(int),-1);
	
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(rep[a[i]]!=-1){
			ds.union_sets(i,rep[a[i]]);
		}else{
			rep[a[i]]=i;
		}
	}
	
	for(int i=1;i<=100000;i++){
		if(rep[i]!=-1){
			child[i]=ds.find_set(rep[i]);
			ans[ds.find_set(rep[i])]=i;
		}
	}
	
	
	while(q--){
		int t; cin>>t;
		if(t==2){
			int idx; cin>>idx;
			cout<<ans[ds.find_set(idx-1)]<<endl;
		}
		else{
			int x,y; cin>>x>>y;
			if(x==y) continue;
			int Xc=child[x];
			int Xy=child[y];
			if(Xc==-1) continue;
			if (Xy==-1 && Xc!=-1) Xy=Xc;
			
			ds.union_sets(Xc,Xy);
			child[y]=ds.find_set(Xc);
			child[x]=-1;
			ans[ds.find_set(Xc)]=y;


		}
	}		
 }
 

int main(void){
	FAST;
	int t=1;
	cin>>t;
	int nb=1;
	while(t--){
		cout<<"Case "<<nb<<":"<<endl;
		solve();
		nb++;
	}
	return 0;
}