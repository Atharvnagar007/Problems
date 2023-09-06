#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=int(a);i<int(b);i++)
#define REP(i,b) FOR(i,0,b)
#define MP make_pair
#define PB push_back
#define ALL(x) x.begin(),x.end()
#define REACH cerr<<"reached line "<<__LINE__<<endl
#define DBG(x) cerr<<"line "<<__LINE__<<" "<<#x<<":"<<x<<endl

using uint=unsigned int;
using ll=long long;
using pii=pair<int,int>;
using vi=vector<int>;
using ld=long double;

template<class T,class U>
ostream& operator<<(ostream& os,const pair<T,U>& p){
	os<<"("<<p.first<<","<<p.second<<")";
	return os;
}

template<class T>
ostream& operator <<(ostream& os,const vector<T>& v){
	os<<"[";
	REP(i,(int)v.size()){
		if(i)os<<",";
		os<<v[i];
	}
	os<<"]";
	return os;
}

int read(){
	int i;
	scanf("%d",&i);
	return i;
}

ll readLL(){
	ll i;
	scanf("%lld",&i);
	return i;
}

string readString(){
	static char buf[3341919];
	scanf("%s",buf);
	return string(buf);
}

char* readCharArray(){
	static char buf[3341919];
	static int bufUsed=0;
	char* ret=buf+bufUsed;
	scanf("%s",ret);
	bufUsed+=strlen(ret)+1;
	return ret;
}

template<class T,class U>
void chmax(T& a,U b){
	if(a<b)
		a=b;
}

template<class T,class U>
void chmin(T& a,U b){
	if(a>b)
		a=b;
}

template<class T>
T Sq(const T& t){
	return t*t;
}

int main(){
	int n=read(),p=0;
	vi s;
	REP(i,n){
		int x=read();
		p^=x;
		s.PB(x^(x-1));
	}
	sort(ALL(s));
	reverse(ALL(s));
	int ans=0;
	for(auto v:s)if(p){
		if(__builtin_clz(p)==__builtin_clz(v)){
			p^=v;
			ans++;
		}
	}
	if(p==0)
		cout<<ans<<endl;
	else
		cout<<-1<<endl;
}
