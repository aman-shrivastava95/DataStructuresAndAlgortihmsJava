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
    //logic is that if you try to divide k into n blocks ,, they will be minimal only if they all are equal 
    int t ;
    cin>>t ;
    ll n, k ;
    while(t--){
        cin>>n>>k ;
        if(k < n){ //to make it a multiple of the number
            int mul = ceil((1.0*n)/k) ;
            k*=mul ;
        }
        ll q = k/n ;
        ll r = k%n ;
        if(r>0)
            q++ ;
        cout<<q<<"\n" ;
       
    }
}