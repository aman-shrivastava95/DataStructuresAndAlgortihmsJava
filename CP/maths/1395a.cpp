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
    //good question
    //number of odds will determine if palindrom can 
    //for palindrom only one should be odd , or 0 should be odd
    // and for odd =3, and odd 4 [ see if they can be converted to 1 odd setting.]
    int t ;
    cin>>t ;
    ll r,g,b,w ;
    while(t--){
        cin>>r>>g>>b>>w ;
        ll odd =  0;
        if(r%2) odd++ ;
        if(g%2) odd++ ;
        if(b%2) odd++ ;
        if(w%2) odd++ ;
        if(odd==2 || odd>=3 && (r==0 || g==0 || b==0))
            cout<<"NO\n" ;
        else
            cout<<"YES\n" ;
    }
}