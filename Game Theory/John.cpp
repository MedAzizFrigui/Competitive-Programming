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

int a[N];

int main(void){
	int t; cin>>t;
	while(t--){
		int n; cin>>n;
		bool test=true;
		int nb=0;
		int Xsum=0;
		
		for(int i=0;i<n;++i){
			cin>>a[i];
			if(a[i]>1) test=false;
			if(a[i]==1) ++nb;
			Xsum^=a[i];
		}
		
		if(test){
			if(nb&1) cout<<"Brother"<<endl;
			else cout<<"John"<<endl;
		}else{
			if(Xsum){
				cout<<"John"<<endl;
			}else{
				cout<<"Brother"<<endl;
			}
		}
	}
	return 0;
}
