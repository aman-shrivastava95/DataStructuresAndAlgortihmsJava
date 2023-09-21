#include<iostream>
#define pb push_back
#define mp make_pair
#define MOD  100000007 
#define len(x) x.size()
#define min3(a,b,c),min(a, min(b,c))
#define max3(a,b,c), max(a, max(b,c))
#define all(v) v.begin(),v.end() 
#define alla(n) a,a + n
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
    //logic used here is the sum of any two sides of triangle is greater than
    //or equal to any third side
    while(t--){
        long long a, b, c, d; 
        cin>>a>>b>>c>>d ;
        // a------b-------c--------d
        long long x = b ;
        long long y = c ;
        long long z = c ;
        cout<<x<<" "<<y<<" "<<z<<"\n" ;
    }
}