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
const int inf=(int) 1e9;
const ll N=207;
const ll mod=1e9 + 7;
const int MAXN=2e5 + 7;
const double PI=3.141592653589793238;
//const double eps=numeric_limits<double>::epsilon();

struct Cow{
	int x,y;
}cow[1001];
	

int n,K,b;
int dp[1001][1001][5];

bool cmp(Cow a,Cow b){
	return a.x<b.x;
}

int main(void){
		
	while(cin>>n>>K>>b){
		
		for(int i=1;i<=n;++i){
			int x,y; cin>>y>>x;
			cow[i].x=x;
			cow[i].y=y;
		}
		
		sort(cow+1,cow+n+1,cmp);
		
		

		int cnt=0;
		
		for(int i=1;i<=n;++i){
			if(cow[i].x==cow[i-1].x){
				cow[cnt].y=3;
			}else{
				++cnt;
				cow[cnt]=cow[i];
			}
		}
		cow[0].x=cow[1].x;
				
		for(int i=0;i<=cnt;++i){
			for(int j=0;j<=K;++j){
				for(int l=0;l<5;++l){
					dp[i][j][l]=inf;
				}
			}
		}
		
		
		dp[0][1][1]=dp[0][1][2]=1;
		dp[0][1][3]=dp[0][2][4]=2;
		
		for(int i=1;i<=cnt;++i){
			for(int j=1;j<=K;++j){
				if(cow[i].y==1){
					int tmp=min(dp[i-1][j-1][1],min(dp[i-1][j-1][2],min(dp[i-1][j-1][3],dp[i-1][j-1][4])));
					dp[i][j][1]=min(dp[i][j][1],tmp+1);
					dp[i][j][1]=min(dp[i][j][1],dp[i-1][j][1]+cow[i].x-cow[i-1].x);
					dp[i][j][1]=min(dp[i][j][1],dp[i-1][j][4]+cow[i].x-cow[i-1].x);
					dp[i][j][3]=min(dp[i][j][3],tmp+2);
					dp[i][j][3]=min(dp[i][j][3],dp[i-1][j][3]+2*(cow[i].x-cow[i-1].x) );
					dp[i][j][3]=min(dp[i][j][3],dp[i-1][j][4]+2*(cow[i].x-cow[i-1].x) );
					
					dp[i][j][4]=min(dp[i][j][4],dp[i-1][j][4]+2*(cow[i].x-cow[i-1].x));
					
					dp[i][j][4]=min(dp[i][j][4],dp[i-1][j-1][1]+(cow[i].x-cow[i-1].x)+1);
					dp[i][j][4]=min(dp[i][j][4],dp[i-1][j-1][2]+(cow[i].x-cow[i-1].x)+1);
				}else if(cow[i].y==2){
					int tmp=min(dp[i-1][j-1][1],min(dp[i-1][j-1][2],min(dp[i-1][j-1][3],dp[i-1][j-1][4])));
					dp[i][j][2]=min(dp[i][j][2],tmp+1);
					dp[i][j][2]=min(dp[i][j][2],dp[i-1][j][2]+cow[i].x-cow[i-1].x);
					dp[i][j][2]=min(dp[i][j][2],dp[i-1][j][4]+cow[i].x-cow[i-1].x);
					dp[i][j][3]=min(dp[i][j][3],tmp+2);
					dp[i][j][3]=min(dp[i][j][3],dp[i-1][j][3]+2*(cow[i].x-cow[i-1].x));
					dp[i][j][3]=min(dp[i][j][3],dp[i-1][j][4]+2*(cow[i].x-cow[i-1].x));
					
					dp[i][j][4]=min(dp[i][j][4],dp[i-1][j][4]+2*(cow[i].x-cow[i-1].x));
					
					dp[i][j][4]=min(dp[i][j][4],dp[i-1][j-1][1]+(cow[i].x-cow[i-1].x)+1);
					dp[i][j][4]=min(dp[i][j][4],dp[i-1][j-1][2]+(cow[i].x-cow[i-1].x)+1);
				}else{
					int tmp=min(dp[i-1][j-1][1],min(dp[i-1][j-1][2],min(dp[i-1][j-1][3],dp[i-1][j-1][4])));
					dp[i][j][3]=min(dp[i][j][3],tmp+2);
					dp[i][j][3]=min(dp[i][j][3],dp[i-1][j][3]+2*(cow[i].x-cow[i-1].x));
					if(j>1) dp[i][j][4]=min(dp[i][j][4],min(dp[i-1][j-2][1]+2,min(dp[i-1][j-2][2]+2,min(dp[i-1][j-2][3]+2,dp[i-1][j-2][4]+2))));
					dp[i][j][4]=min(dp[i][j][4],dp[i-1][j][4]+2*(cow[i].x-cow[i-1].x));
					dp[i][j][4]=min(dp[i][j][4],dp[i-1][j-1][1]+(cow[i].x-cow[i-1].x)+1);
					dp[i][j][4]=min(dp[i][j][4],dp[i-1][j-1][2]+(cow[i].x-cow[i-1].x)+1);
				}
			}
		}
		
		int ans=inf;
		for(int i=1;i<=4;++i){
			ans=min(ans,dp[cnt][K][i]);
		}
		cout<<ans<<endl;
	}
	
	return 0;
}