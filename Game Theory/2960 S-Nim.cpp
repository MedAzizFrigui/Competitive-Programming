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





int CalcMex(set<int>s){
	int val=0;
	set<int>::iterator it=s.begin();
	while(it!=s.end()){
		if(*it != val ) return val;
		it++;val++;
	}
	return val;
}


set<int>s;
int grundy[MAXN];
int a[107];

int CalcGrundy(int n){
		
	if(n==0) return 0;
	
	if(grundy[n]!=-1) return grundy[n];
	bitset<10010>check;
	check.reset();
	
	for(set<int>::iterator it=s.begin();it!=s.end();it++){
		if( (*it) > n ) break;
		check[CalcGrundy(n-(*it))]=1;
		
	}
	
	for(int i=0;;++i) if(!check[i]) return grundy[n]=i;
}


int main(void){
	int k;
	while(cin>>k,k!=0){
		s.clear();
		fill_n(grundy,sizeof(grundy)/sizeof(int),-1);
		string ans="";
		for(int i=0;i<k;++i){
			int a; cin>>a;
			s.insert(a);
		}
		int t; cin>>t;
		
		while(t--){
			int n; cin>>n;
			for(int i=0;i<n;++i) cin>>a[i];
			
			int Xsum=0;
			
			for(int i=0;i<n;++i){
				Xsum^=CalcGrundy(a[i]);
			}
			
			if(Xsum){
				ans+='W';
			}else{
				ans+='L';
			}
		}
		
		cout<<ans<<endl;
		
	}
	return 0;
}