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
    ll x, y, z ;
    cin>>x>>y>>z ;
    ll ans = x/z ;
    ll rem1 = x%z ;
    ans+=y/z ;
    ll rem2 = y%z;
    ll give = 0 ;
    if(rem1 + rem2 >= z){
       give = z - max(rem1, rem2) ;
    }
    if(give>0)
     ans++ ;
    cout<<ans<<" "<<give ; 

}