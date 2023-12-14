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
const ll inf=  1e18 ;
const ll N=50;
const ll mod=1e9 + 7;
const int MAXN=10007;
const double PI=3.141592653589793238;
//const double eps=numeric_limits<double>::epsilon();



int main(void){
	int t; cin>>t;
	while(t--){
		int n; cin>>n;
		
		for(int i=0;i<31;++i){
			if( (n-(1<<i) ) % ( 1 << (i+1) ) == 0 ){
				cout<< n - ( ( 1 << i ) -1 ) <<" "<<n + ( ( 1 << i ) -1 )<<endl;
				break;
			}
		}
	}
	return 0;
}