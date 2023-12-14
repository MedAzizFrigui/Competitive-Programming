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
 
	size_t sizeOfSet(size_t v){
		return sz[find_set(v)];
	}
 
	bool sameSet(size_t a, size_t b){
		return find_set(a)==find_set(b);
	}
 
	size_t nbrOfSets(){
		return nbr;
	}
};
 
int freq[2*N+7];
int nb;
 
void solve(){
	int n; cin>>n;
	disjointSets ds(2*N+7);
	fill_n(freq,N,0);
	vector<pair<int,int>>v;
	
	for(int i=0;i<n;i++){
		int a,b; cin>>a>>b;
		v.pb({a,b});
		freq[a]++;
		freq[b]++;
	}
	
	priority_queue<pair<int,pair<int,int>>>pq;
	
	for(auto u:v){
		if(freq[u.f]>freq[u.s]){
			pq.push({freq[u.f],{u.f,u.s}});
		}else if(freq[u.f]==freq[u.s]){
			pq.push({freq[u.f],{max(u.f,u.s),min(u.f,u.s)}});
		}
		else{
			pq.push({freq[u.s],{u.s,u.f}});
		}
	}
	
	while(!pq.empty()){
		pair<int,pair<int,int>> u=pq.top();
		pq.pop();
		int a=u.s.f;
		int b=u.s.s;
		 // cout<<a<<" "<<b<<" "<<u.f<<endl;
		if(ds.sameSet(a,2*N+1)){
			ds.union_sets(b,2*N+2);
		}
		else if(ds.sameSet(a,2*N+2)){
			ds.union_sets(b,2*N+1);
		}
		else if(ds.sameSet(b,2*N+1)){
			ds.union_sets(a,2*N+2);
		}
		else if(ds.sameSet(b,2*N+2)){
			ds.union_sets(a,2*N+1);
		}
		else{
			if(freq[a]>=freq[b]){
				ds.union_sets(a,2*N+2);
				ds.union_sets(b,2*N+1);
			}else{
				ds.union_sets(b,2*N+2);
				ds.union_sets(a,2*N+1);
			}
		}
	}
	
	cout<<"Case "<<nb<<": "<<max(ds.sizeOfSet(2*N+1)-1,ds.sizeOfSet(2*N+2)-1)<<endl;
			
	
}
int main(void){
	FAST;
	int t; cin>>t;
	nb=1;
	while(t--){
		solve();
		nb++;
	}
	
	return 0;
}