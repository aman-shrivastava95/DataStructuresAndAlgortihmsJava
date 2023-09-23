#include<bits/stdc++.h>
#define mp make_pair
#define MOD  100000007 
#define len(x) x.size()
#define min3(a,b,c),min(a, min(b,c))
#define max3(a,b,c), max(a, max(b,c))
#define all(v) v.begin(),v.end() 
#define alla(n) a,a + n
#define ll long long
using namespace std ;

int countDigits(ll num){
    int cnt = 0  ;
    while(num != 0){
        num/=10 ;
        cnt++ ;
    }
    return cnt ;
}
int main(int argc, char const *argv[])
{
    #ifndef ONLINE_JUDGE
    freopen("../input.txt","r",stdin) ;
    freopen("../output.txt","w",stdout) ;
    #endif
    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ; cout.tie(NULL) ;
   //SOLUTION 
   //the concept is that any number s a product of the power of its prime factors
    int t ;
    cin>>t ;
    ll n, k ;
    while(t--){
        int a, b, c ;
        cin>>a>>b>>c ;
        //let's fix a number z of length c, let's take the prime number 2
        ll z = 1 ;
        while(countDigits(z)!=c){
            z*=2 ;
        }
        ll x = z , y = z ;
        while(countDigits(x)!=a){
            x*=3 ;//multiplying by power of prime 3
        }
        while(countDigits(y)!=b){
            y*=5 ; //mulitplying by power of prime 5
        }
        cout<<x<<" "<<y<<"\n" ;
    }
}