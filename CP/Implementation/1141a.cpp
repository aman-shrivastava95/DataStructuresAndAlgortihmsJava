#include<iostream>//
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
    long long source,target, ans = 0 ;
    cin>>source>>target ;
    
    if(target == source){
        cout<< 0 ;
    }
    else if(target % source != 0){
        cout<< -1 ;
    }
    else {
        long long d = target/source ;
        while(d%2 == 0){
            d = d/2 ;
            ans++ ;
        }

        while(d%3 == 0){
            d = d/3 ;
            ans++ ;
        }
        if(d != 1)
            ans = -1 ;
        
        cout<<ans ;
    }
}
