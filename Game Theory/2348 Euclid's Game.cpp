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
const int MAXN=10007;
const double PI=3.141592653589793238;
//const double eps=numeric_limits<double>::epsilon();


int main(void){
	
	int n,m; cin>>n>>m; 
	while(n!=0 || m!=0){
		int player=0;
		if(n<m) swap(n,m);
		if(m==0){
			cout<<"Ollie wins"<<endl;
			cin>>n>>m;
			continue;
		}
		while(n%m!=0 && n/m==1){
			 n=n-m;
			swap(n,m);
			player^=1;
		}
		
		if(player==0){
			cout<<"Stan wins"<<endl;
		}else{
			cout<<"Ollie wins"<<endl;
		}
		cin>>n>>m;
	}
	
	return 0;
}