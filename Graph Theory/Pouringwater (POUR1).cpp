#include <iostream>
#include <algorithm>
#include <map>
#include <queue>

using namespace std;

#define mp make_pair
#define f first
#define s second

const int inf=(int) 1e9;

int main(void){
	int t; cin>>t;
	while(t--){
		int a,b,c; cin>>a>>b>>c;
		
		queue<pair<int,int>>q;
		q.push(mp(0,0));
		
		map<pair<int,int>,int>m;
		m[mp(0,0)]=0;
		while(!q.empty()){
			pair<int,int>p=q.front();q.pop();
			
			int i=p.f;
			int j=p.s;
			// cout<<i<<" "<<j<<endl;
			// cout<<m[p]<<endl;
			if( m.find(mp(0,j)) != m.end() ){
				if( m[mp(0,j)] > m[p]+1 ){
					m[mp(0,j)]=m[p]+1;
					q.push(mp(0,j));
					
					if( c==j || c==0) break;
					
				}
			}else{
					m[mp(0,j)]=m[p]+1;
					q.push(mp(0,j));
					
					if( c==j || c==0) break;
			}
			
			if( m.find(mp(i,0)) != m.end() ){
				if( m[mp(i,0)] > m[p]+1 ){
					m[mp(i,0)]=m[p]+1;
					q.push(mp(i,0));
					
					if( c=i || c==0) break;
				}
			}else{
					m[mp(i,0)]=m[p]+1;
					q.push(mp(i,0));
					
					if( c==i || c==0) break;
			}
			
			if( m.find(mp(a,j)) != m.end() ){
				if( m[mp(a,j)] > m[p]+1 ){
					m[mp(a,j)]=m[p]+1;
					q.push(mp(a,j));
					
					if( c==j || c==a) break;
					
				}
			}else{
					m[mp(a,j)]=m[p]+1;
					q.push(mp(a,j));
					
					if( c==j || c==a) break;
			}
			
			if( m.find(mp(i,b)) != m.end() ){
				if( m[mp(i,b)] > m[p]+1 ){
					m[mp(i,b)]=m[p]+1;
					q.push(mp(i,b));
					if( c==b || c==i) break;
					
				}
			}else{
					m[mp(i,b)]=m[p]+1;
					q.push(mp(i,b));
					if( c==b || c==i) break;
					
			}
			
			if( m.find(mp(i-min(b-j,i),min(i+j,b))) != m.end() ){
				if( m[mp(i-min(b-j,i),min(i+j,b))] > m[p]+1 ){
					m[mp(i-min(b-j,i),min(i+j,b))]=m[p]+1;
					q.push(mp(i-min(b-j,i),min(i+j,b)));
					if( c==i-min(b-j,i) || c==min(i+j,b)) break;
					
				}
			}else{
					m[mp(i-min(b-j,i),min(i+j,b))]=m[p]+1;
					q.push(mp(i-min(b-j,i),min(i+j,b)));
					if( c==i-min(b-j,i) || c==min(i+j,b)) break;
			}
			
			if( m.find(mp(min(a,i+j),j-min(a-i,j))) != m.end() ){
				if( m[mp(min(a,i+j),j-min(a-i,j))] > m[p]+1 ){
					m[mp(min(a,i+j),j-min(a-i,j))]=m[p]+1;
					q.push(mp(min(a,i+j),j-min(a-i,j)));
					if( c==j-min(a-i,j) || c==min(a,i+j)) break;
				}
			}else{
					m[mp(min(a,i+j),j-min(a-i,j))]=m[p]+1;
					q.push(mp(min(a,i+j),j-min(a-i,j)));
					if( c==j-min(a-i,j) || c==min(a,i+j)) break;
			}
			
		}
		
		int ans=inf;
		
		for(auto u:m){
			if(u.f.f == c || u.f.s==c ){
				ans=min(ans,u.s);
			}
		}
		if(ans==inf){
			cout<<-1<<endl;
			continue;
		}
		cout<<ans<<endl;
		
	}
	return 0;
}