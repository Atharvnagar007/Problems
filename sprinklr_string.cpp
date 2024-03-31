#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
#define for0(i,n) for(ll i=0;i<n;i++)
#define for1(i,n) for(ll i=1;i<=n;i++)

signed main(){
 int n;
 cin>>n;
 string s;
 cin>>s;
 bool ok=true;
 for(int i=0;ok && i<n;i++){
     if(s[i]=='S'){
      if(i>0 && s[i-1]=='C')continue;
      else{
        bool f=false;
        for(int j=min(s[i]+1,n-1);!f &&j>=max(i-1,0);j--){
            if(s[j]=='.'){
              s[j]='C';f=true;
            }
        }
        if(!f) ok=false;
      }
     }
 }
 if(ok){
  int cnt=0;
  for(int i=0;i<n;i++){
    cnt+=(s[i]=='C');
  }
  cout<<cnt<<endl;
 }
 else cout<<-1<<endl;
}
// for test_cas .S.S answer is 1
