#include <iostream>
#include <algorithm>
#define FAST ios::sync_with_stdio(0), cin.tie(0)
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define endl '\n'
using namespace std;
typedef long long int  ll;
typedef unsigned long long int ull;
const ll inf=1e18;
const ll N=1e6+7;
const ll mod=998244353;
const size_t MAXN=1e7;

int PrimePower(ll n,ll p){
	int pow=0;
	for(ll i=p;i<=n;i*=p){
		pow+=n/i;
	}
	return pow;
}
			
void solve(){
	ll n; cin>>n;
	cout<<PrimePower(n,5)<<endl;
}

			
				
	
 
int main(void){
    FAST;

	int t; cin>>t;
	while(t--){
		solve();
	}
	
	return 0;
}