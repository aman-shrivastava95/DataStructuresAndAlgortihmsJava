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

//the idea is to find the frequency of the character, and at every part of k strings, how many times that cahracter has to be there.
int main(int argc, char const *argv[])
{
    
    #ifndef ONLINE_JUDGE
    freopen("../input.txt","r",stdin) ;
    freopen("../output.txt","w",stdout) ;
    #endif
    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ; cout.tie(NULL) ;
    int n ;
    cin>>n ;
    string s ;
    cin>>s ;
    vector<int> freq(26,0) ;
    for(int i=0;i<s.size();i++){
        freq[s[i]-'a'] +=1 ;
    }
    for(int i=0;i<26;i++){
        
        if(freq[i]!=0 && freq[i]%n!=0){
            cout<<-1 ;
            return 0;
        }
    }
    string temp = "" ;
    for(int i=0;i<26;i++){
        if(freq[i] > 0){
            for(int j=0;j<(freq[i]/n);j++)
            temp+=(char)(i+'a');
        }
    }
    string ans="" ;
    for(int i=0;i<n;i++){
        ans+=temp ;
    }
    
    cout<<ans ;
    return 0;
    
}
