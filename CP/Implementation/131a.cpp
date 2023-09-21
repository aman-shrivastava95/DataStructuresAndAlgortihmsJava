#include<iostream>//
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
    string word ;
    cin>>word ;
    bool allUpper  = true ;
    for(int i=1;i<word.length();i++){
        allUpper = allUpper && isupper(word[i]) ;
    }
    if(allUpper){
        for(int i = 0;i<word.length();i++){
            char u = word[i] ;
            if(islower(u)){
                u  = toupper(u) ;
            }else{
                u = tolower(u) ;
            }
            cout<<u ;
        }
    }
    else 
        cout<<word ;
}
