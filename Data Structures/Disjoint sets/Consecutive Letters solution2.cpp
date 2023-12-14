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
	 void display(){
		 for(int i=0;i<12;i++){
			 cout<<parent[i]<<" ";
		 }
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
 
bool infected[200007];
 
 void solve(){
	
	string s; cin>>s;
	int n=s.size();
	
	int q; cin>>q;
	
	vector<pair<int,int>>query;
	
	for(int i=0;i<q;i++){
		int t,pos; cin>>t>>pos;
		if(t==2) infected[pos]=true;
		
		query.pb({t,pos});
	}
	
	reverse(query.begin(),query.end());
	
	disjointSets ds(n);
	
	for(int i=0;i<n-1;i++){
		if(infected[i]) continue;
		if(s[i]==s[i+1] && !infected[i+1]){
			
		ds.union_sets(i,i+1);
		}
	}
	
	vector<int>ans;
	
	for(int i=0;i<q;i++){
		int t=query[i].f;
		int pos=query[i].s;
		
		if(t==1){
			ans.pb(ds.sizeOfSets(pos));
		}else{
			infected[pos]=0;
			if(pos+1<n && s[pos]==s[pos+1] && !infected[pos+1]){
				ds.union_sets(pos,pos+1);
			}
			if(pos-1>=0 && s[pos-1]==s[pos] && !infected[pos-1]){
				ds.union_sets(pos,pos-1);
			}
		}
	}
	
	reverse(ans.begin(),ans.end());
	
	for(auto u:ans){
		cout<<u<<endl;
	}
	
				
			
	
 }
 
 
int main(void){
	FAST;
	int t;
	cin>>t;
	int nb=1;
	while(t--){
		cout<<"Case "<<nb<<":"<<endl;
		solve();
		nb++;
	}
	return 0;
} 