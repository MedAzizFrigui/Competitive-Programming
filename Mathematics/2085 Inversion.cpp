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

int solve(int a, int b){
	double n= a * 1.0;
	double c= b * 1.0;
	
	double delta=1.0 + 4 * c ;
	
	double x= ( 1.0 + sqrt(delta) ) / 2.0;
	
	return (int) floor (x) ;
}

int main(void){
	int n,m; cin>>n>>m;
	while(n!=-1 || m!=-1){
		int x=solve(n,2*m);
		
		int rest= m - ( (x * (x-1) )  / 2 ) ;
		int cnt;
		
		if(rest){
			cnt=n- ( x + 1 );
		}else{
			cnt=n-x;
		}
		int i;
		for(i=1;i<=cnt;++i) cout<<i<<" ";
		
		if(rest==0){
			for(int k=n;k>i;--k) cout<<k<<" ";
			cout<<i<<endl;
			cin>>n>>m;
			continue;
		}
		
		int k=i+rest;
		cout<<k<<" ";
		for(int j=n;j>=i;--j){
			if(j!=k) cout<<j<<" ";
		}
		cout<<endl;
		cin>>n>>m;
			
		
	}
	return 0;
}