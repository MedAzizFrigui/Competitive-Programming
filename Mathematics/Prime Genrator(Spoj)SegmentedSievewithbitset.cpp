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
const ll N=1000000000;
const ll mod=998244353;
const size_t MAXN=1<<18;
 
set<int>Primes;
bitset<31622>Sieve;
void find_primes(){
	Sieve.set();
	Sieve[0]=Sieve[1]=0;
	ll nsqrt=sqrt(N)+1;
	for(int i=2;i*i<=nsqrt;i++){
		if(Sieve[i]){
			for(int j=i*i;j<=nsqrt;j+=i){
				Sieve[j]=0;
			}
		}
	}
	
	for(int i=2;i<=nsqrt;i++) if(Sieve[i]) Primes.insert(i);
}
 
bitset<100007>SegSieve; 
 
void solve(){
	int n,m; cin>>n>>m;
	SegSieve.set();
	
	for(auto u:Primes){
		int x=n/u;
		if(u*x<n)x++;
		if(x==1)x++;
		while(u*x<=m){
			SegSieve[u*x-n]=0;
			x++;
		}
	}
	
	for(int i=0;i<=m-n;i++){
		if(SegSieve[i]==1){
			if(i+n!=1) cout<<i+n<<endl;
		}
	}
		
	
}
 
int main(void){
	FAST;
	find_primes();
	int t; cin>>t;
	while(t--){
		solve();
	}
	return 0;
}