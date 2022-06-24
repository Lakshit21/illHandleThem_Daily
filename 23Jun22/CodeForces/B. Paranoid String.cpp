
#include <bits/stdc++.h>
#define MOD 1000000007
typedef long l;
typedef long long ll;
using namespace std;

template<class A,class B>ostream&operator<<(ostream&out,const pair<A,B>&a){return out<<"("<<a.first<<","<<a.second<<")";}
template<class A>ostream&operator<<(ostream&out,const vector<A>&a){for(const A &it:a)out<<it<<" ";return out;}
template<class A,class B>istream&operator>>(istream&in,pair<A,B>&a){return in>>a.first>>a.second;}
template<class A>istream&operator>>(istream&in,vector<A>&a){for(A &i:a)in>>i;return in;}

//************************** Define'S
#define Fast_N_Last ios_base::sync_with_stdio(0); cin.tie(0);
#define stringMax string::npos
#define bg begin()
#define ed end()
#define br "\n"
#define inc(i,low,up) for(i=low;i<up;i++)
#define minHp priority_queue<ll,vector<ll>,greater<ll>>
#define maxHp priority_queue<ll,vector<ll>>

//************************** Arithmatic
int poww(const int &a,int b,const int &m=MOD){if(b==0)return 1;int x=poww(a,b/2,m);x=x*x%m;if(b&1)x=x*a%m;return x;}
ll cel(ll x, ll y){return (x+y-1)/y;}
ll gcd(ll a, ll b){return b == 0 ? a : gcd(b, a % b);}
ll lcm(ll a,ll b){return (a*b)/gcd(a,b);}
void sieve(ll size,vector<bool> &isPrime){
	isPrime.resize(size+1,1);
	isPrime[0] = isPrime[1] = false;
	for(int i=2;i<=size;i++){
		if (isPrime[i]){
			for(int j=2*i;j<=size;j+=i) isPrime[j] = false;
		}
	}
}

//************************** letsGO!

/*----------------------------CODE STARTS------------------------*/

//------------------"DSU area"--------------------- START

struct dsu{
	vector<ll> parent,sz;
	ll n;
	dsu(ll len){
		n = len;
		parent.resize(n);
		sz.resize(n);
		ll i;
		inc(i,0,n){
			parent[i] = i;
			sz[i] = 1;
		}
	}
	ll find(ll v){
		//find parent of vertex v
		if (parent[v]==v) return v;
		else {
			while(parent[v] != v){
				parent[v] = parent[parent[v]];
				v = parent[v];
			}
			return parent[v];
		}
	}
	void merge(ll u, ll v){
		ll pu = find(u);
		ll pv = find(v);
		if (pu!=pv)  {
		//if not already connected
			if (sz[pu] < sz[pv]) swap(pu,pv);
			//pu is larger tree and pv is smaller tree : pv -> pu
			sz[pu] += sz[pv];sz[pv]=0;
			parent[pv] = pu;
		}
	}
	ll getsz(ll v) {return sz[v];}
};

//------------------"DSU area"--------------------- END


// -----------------"ye karlo pehle area"----- START


void yeKarloPehle(){
	return;
}


// -----------------"ye karlo pehle area"----- END


void solve(){
	ll n,m,i,j,k,sm;
	string s;
	cin >> n;
	cin >> s;

	// the last index who eat the whole string
	// if i and i-1 are same then the string want be eaten
	sm = n; // why this ???
	// ans :- here l=r is also one case
	// and each character is itself a paranoid string hence count those also
	inc(i,1,n){
		if(s[i] != s[i-1]) {
			// 0,i 1,i 2,i 3,i 4,i .. i-1,i
			// every true index i will generate new i index
			sm += i;
		}
	}
	cout << sm << br;

}


void run(){
	#ifndef ONLINE_JUDGE 
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	Fast_N_Last
	// cout << fixed << setprecision(10);
}

int main(){
	run();
	int testCase=1;
	cin >> testCase;

	int google=1;
	yeKarloPehle();

	while(testCase--){
		// cout << "Case #"<< google++ <<": ";
		solve();
	}
}
