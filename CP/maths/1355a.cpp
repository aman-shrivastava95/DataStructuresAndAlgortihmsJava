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

ll findNextTerm(ll a){
    int minDigit = 10 , maxDigit = -1 ;
    ll temp  = a ;
    while(temp){
        int digit = temp%10 ;
        temp = temp/10 ;
        minDigit = min(minDigit, digit) ;
        maxDigit = max(maxDigit, digit) ;
    }
    return a + minDigit*maxDigit ;
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
    // the sequence will converge, if one of the mindigit becomes zero
    //all the elements in sequence after that will be same
    //why ther will be zero ? see the mathematical proof of it.
    int t  ; 
    ll a, K ;
    cin>>t ;
    while(t--){
        cin>>a>>K ;
        ll aprev = a ;
        for(int i=1;i<K;i++){
            a = findNextTerm(aprev) ;
            if(a == aprev)
                break ;
            aprev =  a ;
        }
        cout<<a<<"\n" ;
    }
}