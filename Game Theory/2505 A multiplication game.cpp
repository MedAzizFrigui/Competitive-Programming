#include <iostream>
#include <algorithm>
#include <iomanip>
#include <ios>
#include <cmath>
#include <vector>
#include <set>
#include <bitset>
#include <map>

using namespace std;

#define FAST ios::sync_with_stdio(0), cin.tie(0)
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define endl '\n'

typedef long long int  ll;
typedef unsigned long long int ull;
const int inf= (int) 1e9 ;
const ll N=50;
const ll mod=1e9 + 7;
const int MAXN=2e5 + 7;
const double PI=3.141592653589793238;
//const double eps=numeric_limits<double>::epsilon();

ll n;

ll CalcMex(set<ll> s){
	ll val=0;
	set<ll>::iterator it=s.begin();
	while( it!= s.end()){
		if( *it != val ) return val;
		it++;
		val++;
	}
	return val;
}
map<ll,ll>G;
ll Grundy(ll v){
	// cout<<v<<endl;
	if( v>= n ) return 0ll;
	
	if(G[v]) return G[v];
	
	set<ll>sub_numbers;
	
	for(int i=2;i<=9;++i){
		ll x=Grundy(i*1LL*v);
		// cout<<x<<" ";
		sub_numbers.insert(x);
	}
	return G[v]=CalcMex(sub_numbers);
}

int main(void){
	
	while(cin>>n){
		G.clear();
		if(Grundy(1) == 0 ) cout<<"Ollie wins."<<endl;
		else cout<<"Stan wins."<<endl;
	}
	return 0;
}