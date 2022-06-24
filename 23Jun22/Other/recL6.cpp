
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

vector<vector<ll>> AllSubSqn;
void getAll(vector<ll> &v, ll i, vector<ll> &ss){
	ll n = v.size();
	if(i>=n or i<0) {
		AllSubSqn.push_back(ss);
		return;
	}
	//2 possibility take v[i] or ignore v[i]
	//ignore
	getAll(v,i+1,ss);
	//take
	ss.push_back(v[i]); // do the task
	getAll(v,i+1,ss);
	ss.pop_back(); //undo the taks
	/*
	do and undo the task is important because
	we are passing the same vector(ss) to all the functional calls
	if not done then it will been overWritten all the times
	*/
}

ll gi = 0;
void print_ss_whose_sum_is_k(ll k , vector<ll> &v , vector<ll> &ds, ll i){
	ll n = v.size();
	ll sm;
	if(i<0 or i>=n){
		sm = 0;
		sm = accumulate(ds.bg,ds.ed,sm);
		if(sm == k) { cout << ++gi<< "# "; cout << ds << br;}
		return;
	}
	// not take (ignore)
	print_ss_whose_sum_is_k(k,v,ds,i+1);
	// take it
	ds.push_back(v[i]);
	print_ss_whose_sum_is_k(k,v,ds,i+1);
	ds.pop_back();
	// if all are +ve the we can go back if sm + v[i] > k
}
bool print_OnlyOne_ss_whose_sum_is_k(ll k , vector<ll> &v , vector<ll> &ds, ll i){
	ll n = v.size();
	ll sm;
	if(i<0 or i>=n){
		sm = 0;
		sm = accumulate(ds.bg,ds.ed,sm);
		// if the conditon match then return true
		if(sm == k) { cout << ++gi<< "# "; cout << ds << br; return true;}
		// if the condition doesnot match then return false
		return false;
	}
	// not take (ignore)
	bool f;
	f = print_OnlyOne_ss_whose_sum_is_k(k,v,ds,i+1);
	if (f) return true; // we found the sub sqn

	// if f is 0 : then do below
	// take it
	ds.push_back(v[i]);
	f = print_OnlyOne_ss_whose_sum_is_k(k,v,ds,i+1);
	ds.pop_back();
	if (f) return true; // did not go into further more depht
	// if all are +ve the we can go back if sm + v[i] > k

	// if both are not trur then go in depth
	return false;
}

ll count_the_ss_whose_sum_is_k(ll k, vector<ll> &v, vector<ll> &ds, ll i){
	ll n = v.size(),sm;

	if(i<0 or i>=n){
		sm = 0;
		sm = accumulate(ds.bg,ds.ed,sm);
		if (sm == k) return 1; // found one ss
		else return 0; // not found
	}
	ll ifIgnore, ifTake;
	// ignore v[i] and count ss's
	ifIgnore = count_the_ss_whose_sum_is_k(k,v,ds,i+1);
	// take  v[i] and count ss's
	ds.push_back(v[i]);
	ifTake = count_the_ss_whose_sum_is_k(k,v,ds,i+1);
	ds.pop_back();

	return ifTake + ifIgnore;
}


void solve(){

	// complexity
	// TC : O(2^n)
	// SC : O(2^n)
	ll n,i,k;
	cin >> n >> k;
	vector<ll> v(n);
	cin >> v;
	vector<ll> emptyDataStructure;
	// //**********print all the sub sqn 
	// getAll(v,0,emptyDataStructure);
	// i =1;
	// for(auto e : AllSubSqn){
	// 	cout << i++ << "# ";
	// 	cout << e << br;
	// }

	// // *********all the ss's whose sum is k
	// print_ss_whose_sum_is_k(k,v,emptyDataStructure,0); 
	
	// //********** one ss's
	// bool b = print_OnlyOne_ss_whose_sum_is_k(k,v,emptyDataStructure,0);
	
	// //********** count of ss's

	ll count = count_the_ss_whose_sum_is_k(k,v,emptyDataStructure,0);
	cout << count << br;

	
}

int main(){
	#ifndef ONLINE_JUDGE 
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif

	Fast_N_Last
	int testCase=1;
	// cin >> testCase;

	int google=1;
	yeKarloPehle();

	while(testCase--){
		// cout << "Case #"<< google++ <<": ";
		solve();
	}
}
//multiple recursion calls
//Fibonacci : f(n) -> f(n-2)+f(n-1) [2 multiple calls]
//print all the subsqns

//NOTE :-
//subsqn is used when we need to make combination from given array
//with limited supply of member of array
//what if we have unlimited supply the the combination is infinite
//with unlimited supply made the target we need some other implementation
// counting the ways can be done by dp
// but printing the ways is been different
