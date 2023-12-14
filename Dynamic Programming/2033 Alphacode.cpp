#include <iostream>
#include <algorithm>
#include <iomanip>
#include <ios>
#include <cmath>
#include <vector>
#include <set>
#include <bitset>
#include <map>
#include <string>

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
const ll mod=1e9 + 7;
const int MAXN=2e5 + 7;
const double PI=3.141592653589793238;
//const double eps=numeric_limits<double>::epsilon();
const size_t tab=1e8;

ll dp[tab];
ll cur[tab];

int main(void){
	string s; 
	while(cin>>s,s[0]!='0'){
		int n=s.size();
		
		dp[0]=1ll;
		cur[0]=1ll;
	
		for(int i=1;i<n;i++){
			int x=( s[i-1]-'0') * 10;
			x+= ( s[i]-'0');
			
			if(x<=26 && s[i]!='0'&& s[i-1]!='0' && (i+1>=n || s[i+1]!='0')){
				dp[i]=dp[i-1]+cur[i-1];
			}else{
				dp[i]=dp[i-1];
			}
			
			cur[i]=dp[i-1];
		}
		cout<< dp[n-1] <<endl;
	}

	return 0;
}