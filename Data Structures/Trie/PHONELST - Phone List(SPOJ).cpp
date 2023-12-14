#include <iostream>
#include <algorithm>
#include <iomanip>
#include <ios>
#include <cmath>
#include <vector>
#include <set>
#include <bitset>
#include <map>
#include <queue>
#include <cstring>
 
using namespace std;
 
void dbg_out() { cerr << endl; }
template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T) {
    cerr << ' ' << H;
    dbg_out(T...);
}
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#define FAST ios::sync_with_stdio(0), cin.tie(0)
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define endl '\n'
 
typedef long long int  ll;
typedef unsigned long long int ull;
const int inf=  (int) 1e9;
const int N=26;
const ll mod=1e9 + 7;
const int MAXN=200007;
const double PI=3.141592653589793238;
//const double eps=numeric_limits<double>::epsilon();
struct node;
 
typedef node* pnode;
 
struct node{
	int nbOfMatches;
	int isEnd;
	vector<pair<char,pnode>>child;
	node(){
		nbOfMatches = isEnd = 0;
		child.clear();
	}
};
 
int get(char c){
    if (c >= 'a')
        return c - 'a';
    return 26 + c - 'A';
}
 
class Trie{
public:
	pnode head;
	void init(){
		head = new node();
	}
	
	void addElement(string const& s){
		pnode it = head;
		it -> nbOfMatches++;
		for(char c:s){
			int let = get(c);
			bool ok = false;
			for(int i=0;i<it->child.size();++i){
				if(it->child[i].first == let){
					ok = true;
					it = it->child[i].second;
					break;
				}
			}
			if(!ok){
				it->child.push_back(make_pair(let,new node()));
				it = it->child.back().second;
			}
			it->nbOfMatches++;
		}
		it->isEnd++;
	}
	
	int findElement(string const& s){
		pnode it = head;
		for(char c:s){
			int let = get(c);
			bool ok=false;
			for(int i=0;i<it->child.size();++i){
				if(it->child[i].first == let){
					ok=true;
					it = it->child[i].second;
					break;
				}
			}
			if(!ok){
				return 0;
			}
		}
		return it->isEnd;
	}
	
	int isMatch(string const& s){
		pnode it = head;
		for(char c:s){
			int let = get(c);
			bool ok=false;
			for(int i=0;i<it->child.size();++i){
				if(it->child[i].first == let){
					ok=true;
					it = it->child[i].second;
					break;
				}
			}
			if(!ok){
				return 0;
			}
		}
		return it->nbOfMatches;
	}
	
	void delete_(pnode it){
        for (int i = 0; i < it->child.size(); ++i){
            if (it->child[i].second == NULL)
                continue;
            delete_(it->child[i].second);
        }
        it->child.clear();
        free(it);
        it = NULL;
    }
};
 
Trie trie;
void solve(){
    int n; cin>>n;
    trie.init();
    bool ans=true;
    string a[n];
    for(int i=0;i<n;++i){
        string s; cin>>s;
        trie.addElement(s);
        a[i]=s;
    }
    for(int i=0;i<n;++i){
        int cnt = trie.isMatch(a[i]);
        ans&=!(cnt > 1);
    }
    if(ans) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    
}
 
int main(void){
    FAST;
    int t=1; 
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
} 