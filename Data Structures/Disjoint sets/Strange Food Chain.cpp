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
const ll N=2e5+7;
const ll mod=998244353;
const size_t MAXN=1<<18;
 
 
class disjointSets{
	size_t *parent= new size_t[MAXN];
	size_t *sz=new size_t[MAXN];
	size_t nbr;
public:
	disjointSets(size_t n):nbr(n){
		for(size_t i=0u;i<n;i++){
			parent[i]=i;
			sz[i]=1u;
		}
	}
 
	size_t find_set(size_t v){
		return parent[v]==v?v:parent[v]=find_set(parent[v]);
	}
 
	bool union_sets(size_t a, size_t b){
 
		a=find_set(a);
		b=find_set(b);
 
		if(a!=b){
			if(sz[a]>sz[b]) swap(a,b);
			parent[a]=b;
			sz[b]+=sz[a];
			sz[a]=0u;
			--nbr;
			return true;
		}
		return false;
	}
 
	size_t sizeOfSets(size_t v){
		return sz[find_set(v)];
	}
 
	bool sameSet(size_t a, size_t b){
		return find_set(a)==find_set(b);
	}
 
	size_t nbrOfSets(){
		return nbr;
	}
};
 
void solve(){
	int n,k; cin>>n>>k;
	disjointSets ds(n*3+10);
	int ans=0;
	while(k--){
		int t,a,b; cin>>t>>a>>b;
		
		if(a>n || b>n){
			ans++;
			continue;
		}
		
		if(t==1){
			if(ds.sameSet(a+n,b) || ds.sameSet(a,b+n)){
				ans++;
				continue;
			}
			ds.union_sets(a,b);
			ds.union_sets(a+n,b+n);
			ds.union_sets(a+2*n,b+2*n);
		}
		else{
				
			if(ds.sameSet(a,b) || ds.sameSet(b+n,a)){
				ans++; 
				continue;
			}
			ds.union_sets(a+n,b);
			ds.union_sets(a+2*n,b+n);
			ds.union_sets(a,b+2*n);
		}
	}
	cout<<ans<<endl;
		
	
}
 
int main(void){
	FAST;
	int t; cin>>t;
	while(t--){
		solve();
	}
	return 0;
} 