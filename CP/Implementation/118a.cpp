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
bool isVowel(char ch){
     ch = tolower(ch) ;
    return (ch=='a' || ch=='e'|| ch=='i'||ch=='o'||ch=='u'||ch=='y') ;
}

int main(int argc, char const *argv[])
{
    
    #ifndef ONLINE_JUDGE
    freopen("../input.txt","r",stdin) ;
    freopen("../output.txt","w",stdout) ;
    #endif
    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ; cout.tie(NULL) ;
    string s,ans ;
    cin>>s ;
    for(int i=0;i<s.size();i++){
        if(!isVowel(s[i])){
            char a = tolower(s[i]) ;
            ans=ans+'.' ;
            ans=ans+a ;
        }
    }
    cout<<ans ;
    return 0 ;
}
