#include<bits/stdc++.h>//
#define pb push_back
#define mp make_pair
#define MOD  100000007 
#define len(x) x.size()
#define min3(a,b,c),min(a, min(b,c))
#define max3(a,b,c), max(a, max(b,c))
#define all(v) v.begin(),v.end() 
#define alla(n) a,a + n
using namespace std ;

//if I need to have the change persisted , I need to pass that by reference.
void playWithPair(pair<float,float> &p){
    p.first+=10 ;
    p.second+=20 ;
}
//this is awesome
int main(int argc, char const *argv[])
{
    //modify this as pwer the 
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin) ;
    freopen("output.txt","w",stdout) ;
    #endif
    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ; cout.tie(NULL) ;

    string s = "thisIsAString" ;
    for(int i=0;i<s.length();i++){
        char currChar = s[i] ;
    }
    s.substr() ;
    //this is how we use iterator , whenever we required
    string::iterator itr = s.begin() ;
    while(itr!=s.end()){
        cout<<*itr<<endl ;
        itr++ ;
    }
    pair<float, float> complexNumber({4.00f,2.00f}) ;
    cout<<complexNumber.first<<endl ;
    cout<<complexNumber.second<<endl ;


    //cmparison with lambdas.
    auto cmp = [](int a, int b){return a > b ;};
    vector<int> v ;
    sort(v.begin(),v.end(),cmp) ;

    playWithPair(complexNumber) ;
    cout<<complexNumber.first<<endl ;
    cout<<complexNumber.second<<endl ;

    cout<<"let's tokenize some string using string stream." ;     
    vector<string> vv ;              
    string input ;
    getline(cin, input) ;
    stringstream ss(input) ;
    while(ss.good()){
        string temp ;
        ss>>temp ;
        vv.push_back(temp) ;
    }
    for(auto word:vv)
        cout<<word<<endl ;
}
