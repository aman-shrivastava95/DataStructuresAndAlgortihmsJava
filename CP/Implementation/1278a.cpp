#include<iostream>
#define pb push_back
#define mp make_pair
#define MOD  100000007 
#define len(x) x.size()
#define min3(a,b,c),min(a, min(b,c))
#define max3(a,b,c), max(a, max(b,c))
#define all(v) v.begin(),v.end() 
#define alla(n) a,a + n
using namespace std ;


int main(int argc, char const *argv[])
{
    #ifndef ONLINE_JUDGE
    freopen("../input.txt","r",stdin) ;
    freopen("../output.txt","w",stdout) ;
    #endif
    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ; cout.tie(NULL) ;
    //SOLUTION
    int t ;
    cin>>t ;
    while(t--){
        int hash[26] ;
        memset(hash,0,sizeof(hash)) ;
        string p,h ;
        cin>>p>>h ;
        int np = p.length() ;
        int nh = h.length() ;
        bool found = false  ;
        for(int i=0;i<nh;i++){
            //process all the substring
            //Using alphabetic hash to check anagrams, sorting can 
            //also be used here
            string sub= h.substr(i,np) ;
            for(int i=0; i<sub.length(); i++){
                hash[sub[i]-'a']+=1 ;
            }
            for(int i =0; i<p.length(); i++){
                hash[p[i]-'a']-=1 ;
            }
            bool allzero = true ;
            for(int i=0; i<26; i++){
                if(hash[i]!=0){
                    allzero = false ;
                    break ;
                }
            }
            if(allzero){
                cout<<"YES\n" ;
                found = true ;
                break ;
            }
            memset(hash, 0, sizeof(hash));
        }
        if(!found){
            cout<<"NO\n" ;
        }
    }
}