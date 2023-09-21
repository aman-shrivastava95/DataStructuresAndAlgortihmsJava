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
    int n ;
    cin>>n ;
    while(n--){
        ll c, sum  ;
        cin>>c>>sum ;
        if(c >= sum){
            cout<<sum<<"\n" ;
        }else{
            //good question
            //divide equally, that will be optimal,square bumps up the value
            ll q = sum/c ;
            ll extra = sum%c ;
            ll ans = 0 ;
            if(q==0){
                ans = c*q*q ;
            }else{
                ans = (c-extra)*q*q + extra*(q+1)*(q+1) ;
                cout<<ans<<"\n" ;
            }
        }

    }
}