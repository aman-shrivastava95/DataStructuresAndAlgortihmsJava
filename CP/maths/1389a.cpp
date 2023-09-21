#include<iostream>
#define pb push_back
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
    
    int t ;
    cin>>t ;
    while(t--){
        ll a, b ;
        cin>>a>>b ;
        ll ans1 = 0, ans2 = 0 ;
        if(a*2 <= b){
            ans1 = a ;
            ans2 = a*2 ;
        }else{
            ans1 = -1 ;
            ans2 = -1 ;
        }
        cout<<ans1<<" "<<ans2<<"\n" ;
    }
}