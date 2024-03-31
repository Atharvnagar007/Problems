#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
#define for0(i,n) for(ll i=0;i<n;i++)
#define for1(i,n) for(ll i=1;i<=n;i++)
struct Node{
    Node *links[26];
    ll freq=0;
    ll wfreq=0;
    bool containsKey(char ch){
        return (links[ch-'a']!=NULL);
    }
    void put(char ch,Node *node){
        links[ch-'a']=node;
    }
    Node *get(char ch){
        return links[ch-'a'];
    }
    

};
class Trie{
    private:Node *root;
    public:
    Trie(){
        root =new Node();
    }
    void insert(string &s, ll freq){
        Node* node=root;
        for(ll i=0;i<s.length();i++){
            node->freq+=freq;
            if(!node->containsKey(s[i])){
            node->put(s[i],new Node());
            }
            node=node->get(s[i]);
        }
        node->freq+=freq;
        node->wfreq=freq;
    }
    ll query(string &s){
        Node* node=root;
        for(int i=0;i<s.length();i++){
           if(!node->containsKey(s[i])){
            return 0;
           }
           else node=node->get(s[i]);
        }
        return node->freq;
    }
    ll wquery(string &s){
        Node*node=root;
        for(int i=0;i<s.length();i++){
            if(!node->containsKey(s[i])){
               return 0;
            }
            node=node->get(s[i]);
        }
        return node->wfreq;
    }
    void update(string &s,ll freq){
      Node*node=root;
      ll ofreq=wquery(s);
      for(int i=0;i<s.length();i++){
        node->freq+=(freq-ofreq);
        if(!node->containsKey(s[i])){
            return;
        }
        node=node->get(s[i]);
      }
     node->freq+=(freq-ofreq);
    }
};
signed main(){
 ll n;
 cin>>n;
 Trie trie;
 for(ll i=0;i<n;i++){
     string op;
     cin>>op;
     if(op=="I"){
        string s;
        ll f;
        cin>>s>>f;
        trie.insert(s,f);
     }
     else if(op=="U"){
        string s;
        ll f;
        cin>>s>>f;
        trie.update(s,f);
     }
     else{
        string s;
        cin>>s;
        cout<<trie.query(s)<<endl;
     }
 }
}
//INPUT
// 6
// I apple 2
// I google 1
// I sprinklr 10    
// I spring 2
// Q apple
// Q spr
//OUTPUT
//2
//12