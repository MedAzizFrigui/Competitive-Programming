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
	 disjointSets left(n+1);
	 disjointSets right(n+1);
	
	fill_n(infected,sizeof(infected)/sizeof(bool),0);
	
	int q; cin>>q;
	int qq=q;
	vector<pair<int,int>>query;
	while(qq--){
		int t,pos; cin>>t>>pos;
		query.pb({t,pos});
		if(t==2) infected[pos]=1;
	}
	
	for(int i=0;i<n-1;i++){
		if(infected[i]) continue;
		if(s[i]==s[i+1] && !infected[i+1]){
			right.setParent(i,i+1);
		}
	}
	
	for(int i=n-1;i>0;i--){
		if(infected[i]) continue;
		if(s[i]==s[i-1] && !infected[i-1]){
			left.setParent(i,i-1);
		}
	}
	reverse(query.begin(),query.end());
	
	vector<int>ans;
	
	for(auto u:query){
		
		int t=u.f;
		int pos=u.s;
		if(t==1){
			int l=left.find_set(pos);
			int r=right.find_set(pos);
			ans.pb(r-l+1);
		}else{
			infected[pos]=0;
			if(pos+1<n){
				if(s[pos+1]==s[pos] && !infected[pos+1]){
					right.setParent(pos,pos+1);
					left.setParent(pos+1,pos);
				}
			}
			if(pos-1>=0){
				if(s[pos-1]==s[pos] && !infected[pos-1]){
					left.setParent(pos,pos-1);
					right.setParent(pos-1,pos);
				}
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