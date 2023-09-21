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
    int n ;
    string s ;
    cin>>n>>s ;
    for(int i=0; i< n-1 ;i++){
        if(s[i]!=s[i+1]){
            cout<<"YES"<<endl<<s[i]<<s[i+1] ;
            return  0 ;
        }
    }
    cout<<"NO" ;
    return 0 ;
}