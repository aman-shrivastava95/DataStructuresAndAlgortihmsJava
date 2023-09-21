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
    int n,x ;
    cin>>n ;
    ll k ;
    while(n--){
        cin>>k>>x ;
        //pattern anaysis to see the observer the pattern
        //write the digitla sum from 1 to 9
        //then 10 to 18
        //then 19 to 27
        //you will find the pattern.
        cout<<(k-1)*9 + x<<"\n" ;
    }
}