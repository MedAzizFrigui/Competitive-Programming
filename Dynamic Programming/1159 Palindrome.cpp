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
const size_t tab=5000;

int dp[2*tab+4][2];

int main(void){
	
	int n;
	while(cin>>n){
		string s; cin>>s;
		
		for(int i=0;i<2*n;i++) dp[i][0]=0;
		
		
		for(int t=1;t<n;t++){
			for(int j=t,i=0;j<n;j++,i++){
				if(s[i]==s[j]){
					dp[j][1]=dp[j+(j-t)][0];
				}else{
					dp[j][1]=1+min(dp[j+j-t-1][0],dp[j+j-t+1][0]);
				}
			}
			
			for(int j=t;j<n;j++){
				dp[j+j-t][0]=dp[j][1];
			}
			
		}
		
		cout<<dp[n-1][0]<<endl;
		
	}

	return 0;
}