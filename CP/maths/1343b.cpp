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
        int n ;
        cin>>n ;
        string ans ;
        if((n/2)%2){
            cout<<"NO"<<"\n" ;
        }else{
            cout<<"YES"<<"\n" ;
            long long  sumE = 0 ; //these both have to be long long 
            long long sumO = 0 ;
            
            for(int i=2; i<= n ;i+=2){
                cout<<i<<" " ;
                sumE += i ;
            }
            for(int i=2; i<= (n-2) ;i+=2){
                cout<<i-1<<" " ;
                sumO += (i-1) ;
            }
            cout<<sumE - sumO<<"\n" ; 
        }
    }
}