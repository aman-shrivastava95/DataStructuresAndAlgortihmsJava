#include<iostream>
#define mp make_pair
#define MOD  100000007 
#define len(x) x.size()
#define min3(a,b,c),min(a, min(b,c))
#define max3(a,b,c), max(a, max(b,c))
#define all(v) v.begin(),v.end() 
#define alla(n) a,a + n
#define ll long long
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
    cin>>t;
    while(t--){
        long long a,b,c, n ;
        string ans ;
        cin>>a>>b>>c>>n ;
        long long maxi = max(a, max(b, c)) ;
        long long extra =  0 ;
        extra+=(maxi - a) ;
        extra+=(maxi - b) ;
        extra+=(maxi - c) ;
        if(n < extra){
            ans =  "NO" ;
        }else{
            if((n-extra)%3) ans = "NO" ;
            else ans = "YES" ;
        }
        cout<<ans<<"\n" ;
    }
}