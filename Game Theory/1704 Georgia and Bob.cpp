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
const int MAXN=1007;
const double PI=3.141592653589793238;
//const double eps=numeric_limits<double>::epsilon();

int a[MAXN];

int main(void){
	int t; cin>>t;
	while(t--){
		int n; cin>>n;
		for(int i=0;i<n;++i) cin>>a[i];
		
		sort(a,a+n);
		int Xsum=0;
		
		for(int i=n-1;i>0;i-=2){
			Xsum^=(a[i]-a[i-1]-1);
		}
		
		if(n&1) Xsum^=a[0]-1;
			
		if(Xsum){
			cout<<"Georgia will win"<<endl;
		}else{
			cout<<"Bob will win"<<endl;
		}
	}
	return 0;
}