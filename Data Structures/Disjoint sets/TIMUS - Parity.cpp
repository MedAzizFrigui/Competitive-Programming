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
	pair<size_t,int> *parent= new pair<size_t,int>[MAXN];
	size_t *sz=new size_t[MAXN];
	size_t nbr;
public:
	disjointSets(size_t n):nbr(n){
		for(size_t i=0u;i<n;i++){
			parent[i]={i,0};
			sz[i]=1u;
		}
	}

	pair<size_t,int> find_set(size_t v){
		if(parent[v].f==v) return parent[v];
		
		int tmp=parent[v].s;
		parent[v]=find_set(parent[v].f);
		parent[v].s=(parent[v].s+tmp)%2;
		
		return parent[v];
	
	}

	bool union_sets(size_t a, size_t b, int parity){
		
	
		size_t Pa=find_set(a).f;
		size_t Pb=find_set(b).f;

		if(Pa!=Pb){
			if(sz[Pa]>sz[Pb]) swap(Pa,Pb);
			parent[Pa].f=Pb;
			parent[Pa].s=((parent[a].s+parity)%2+parent[b].s)%2;
			
			sz[Pb]+=sz[Pa];
			sz[Pa]=0u;
			--nbr;
			return true;
		}
		return false;
	}

	int getParity(size_t v){
		return find_set(v).s;
	}
	
	size_t sizeOfSets(size_t v){
		return sz[find_set(v).f];
	}

	bool sameSet(size_t a, size_t b){
		return find_set(a).f==find_set(b).f;
	}

	size_t nbrOfSets(){
		return nbr;
	}
};


int main(void){
	
	int n;
	while(cin>>n,n!=-1){
		int q; cin>>q;
		map<int,int>label;
		int cnt=0;
		pair<pair<int,int>,string>query[q];
		
		for(int i=0;i<q;i++){
			int l,r; cin>>l>>r;
			string parity ; cin>>parity;
			
			l--;
			
			if(label.find(l)==label.end()){
				label[l]=cnt;
				cnt++;
			}
			
			if(label.find(r)==label.end()){
				label[r]=cnt;
				cnt++;
			}
			
			query[i]={{label[l],label[r]},parity};
		}
		
		int ans=q;
		disjointSets ds(cnt);
		for(int i=0;i<q;i++){
			int l=query[i].f.f;
			int r=query[i].f.s;
			string parity=query[i].s;
			int p;
			parity=="even"?p=0:p=1;
			
			
			if(ds.sameSet(l,r) && ((ds.getParity(l)+ds.getParity(r))%2 + p )%2 == 1 ){
				ans=i;
			
				break;
			}else if(!ds.sameSet(l,r)){
			
				ds.union_sets(l,r,p);
		
			}
		}
		
		cout<<ans<<endl;
	}
		
		
	return 0;
}