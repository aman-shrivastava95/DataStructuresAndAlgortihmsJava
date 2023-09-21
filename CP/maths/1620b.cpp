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
    cin>>t ;
    while(t--){
        ll w, h , ans = 0;
        cin>>w>>h ;
        for(int i=1;i<=4;i++){
            ll mul = i<=2 ? h : w ;//first two set of inputs for 'h',next two for 'w'
            ll x, y ;
            int n ;
            cin>>n ;
            cin>>x  ;
            n-- ;
            while(n--)
                cin>>y ;
            //already in ascending order , so no need to sort
            //maximize the ans
            ans = max(ans , abs(y-x)*mul) ;
        }
        cout<<ans<<"\n" ;
    }
}