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

int alpha[30];
int cost[30][30];
ll dp[30][12];
pair<int,int> getans[30][12];

int main(void){
	FAST;
	int t; cin>>t;
	while(t--){
		int m;
		cin>>m;
		fill_n(alpha,sizeof(alpha)/sizeof(int),0);
		
		while(m--){
			string s; cin>>s;
			for(int i=0;i<s.size();++i){
				if(s[i]=='+') alpha[26]++;
				else if(s[i]=='*') alpha[27]++;
				else if( s[i]=='/') alpha[28]++;
				else if( s[i]=='?') alpha[29]++;
				else alpha[s[i]-'a']++;
			}
		}
		
		for(int i=0;i<30;++i){
			cost[i][i]=alpha[i];
		}
		
		for(int i=0;i<30;++i){
			for(int j=i+1;j<30;++j){
				cost[i][j]=cost[i][j-1]+alpha[j]*(j-i+1);
			}
		}
		
		
		
		
		for(int i=0;i<30;++i){
			
			for(int j=0;j<12;++j) dp[i][j]=inf,getans[i][j]=mp(-1,-1);
		}
		
		for(int i=1;i<30;++i){
			dp[i][1]=(cost[0][i-1]+cost[i][29])*1LL;
		}
		
		for(int j=2;j<12;++j){
			for(int i=j;i<30;++i){
				
				for(int k=j-1;k<i;k++){
					
					if( dp[k][j-1]-cost[k][29]*1LL+cost[k][i-1]*1LL+cost[i][29]*1LL < dp[i][j] ){
						dp[i][j]=dp[k][j-1]-cost[k][29]*1LL+cost[k][i-1]*1LL+cost[i][29]*1LL;
						getans[i][j]=mp(k,j-1);
					}
				}
			}
		}
		
		ll ans=inf;
		pair<int,int> index;
		
		
		
		
		
		for(int i=11;i<30;++i){
			if(ans > dp[i][11] ) {
				ans=dp[i][11];
				index=mp(i,11);
			}
		}
		
		string res="";
		
		while(index.f!=-1){
			if(index.f==26) res+='+';
			else if(index.f==27) res+='*';
			else if( index.f==28) res+='/';
			else if( index.f==29) res+='?';
			else res+= 'a' + index.f;
			
			index=getans[index.f][index.s];
		}
		
		for(int i=res.size()-1;i>=0;--i) cout<<res[i];
		cout<<endl;
	
	}
	
	return 0;
}