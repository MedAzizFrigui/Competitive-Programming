#include <iostream>
#include <algorithm>
#include <iomanip>
#include <ios>
#include <cmath>

using namespace std;

#define FAST ios::sync_with_stdio(0), cin.tie(0)
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define endl '\n'

typedef long long int  ll;
typedef unsigned long long int ull;
const ll inf=1e18;
const ll N=207;
const ll mod=61;
const size_t MAXN=10007;
const double PI=3.141592653589793238;
const double eps=numeric_limits<double>::epsilon();





int main(void){
	FAST;
	
	int n; 
	while(cin>>n , n!=-1){
		int f[n+1];
		f[0]=1;
		f[1]=0;
		
		int g[n+1];
		g[0]=0;
		g[1]=1;
		
		for(int i=2;i<=n;i++){
			if( i&1 ){
				g[i]=f[i-1]+g[i-2];
				f[i]=0;
			}else{
				g[i]=0;
				f[i]=f[i-2]+2*g[i-1];
			}
		}
		
		cout<<f[n]<<endl;
	}
	
	return 0;
}