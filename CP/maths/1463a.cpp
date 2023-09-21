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
        ll a, b, c ;
        cin>>a>>b>>c ;
        ll sum = a + b + c ;
        //the logic is that each 7th hit reduces the total by 9
        ll times = sum/9 ;
        if(sum%9==0 && a>=times && b>=times && c>=times)
            cout<<"YES\n" ;
        else
            cout<<"NO\n" ;
    }
}