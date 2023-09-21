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
    ll n , m , k , max1 = -1 , max2=-1;
    cin>>n>>m>>k ;
    //finding first and second largest element
    while(n--){
        ll cur ;
        cin>>cur ;
        if(cur >= max1){
            max2  =  max1 ;
            max1 = cur;
        }else{
            if(max2 < cur){
                max2 = cur ;
            }
        }
    }
    
    ll r = m%(k+1) , q = m/(k+1) ;
    ll total = q* (k*max1 + max2) + r*max1 ;
    cout<<total ;
}