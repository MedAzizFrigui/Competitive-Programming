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
	int n; 
	while(cin>>n){
		int Xsum=0;
		for(int i=0;i<n;++i){
			int a; cin>>a;
			Xsum^=a;
		}
		if(Xsum) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
	return 0;
}