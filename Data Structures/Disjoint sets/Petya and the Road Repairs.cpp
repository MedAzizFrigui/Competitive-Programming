#include <bits/stdc++.h>

#define FAST ios::sync_with_stdio(false), cin.tie(nullptr)
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define endl '\n'
using namespace std;
typedef long long int  ll;
const ll inf=1e18;
const ll N=1e5 +7;
const ll mod=1e9 +7;


const size_t MAXN =1<<24;

class disjointSets{
	vector<size_t>parent;
	vector<size_t>sz;
	size_t nbr;
public:
	disjointSets(size_t n):nbr(n){
		parent.reserve(nbr);
		sz.reserve(nbr);
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


bool a[N];

int main(void){
	int t; cin>>t;
	while(t--){
		int n,m; cin>>n>>m;

		priority_queue<pair<int,pair<int,int>>,
					   vector<pair<int,pair<int,int>>>,
					   greater<pair<int,pair<int,int>>>>q;


		for(int i=0;i<n;i++){
			 cin>>a[i];
			 if(a[i]){
				 q.push({0,{i,n}});
			 }
		}

		for(int i=0;i<m;i++){
			int x,y,c; cin>>x>>y>>c;
			x--;y--;
			q.push({c,{x,y}});
		}

		disjointSets ds(n+1);

		ll ans=0ll;

		while(!q.empty()){
			pair<int,pair<int,int>> s=q.top(); q.pop();

			int cost=s.f;
			if(ds.union_sets(s.s.f,s.s.s)){
				ans+= cost * 1ll;
			}
		}

		if(ds.nbrOfSets()==1){

			cout<<ans<<endl;
		}else{
			cout<<"impossible"<<endl;
		}
	}
	return 0;
}
