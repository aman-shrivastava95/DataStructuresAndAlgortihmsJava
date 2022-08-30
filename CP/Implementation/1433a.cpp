#include<bits/stdc++.h>//
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
    int counts[]  = {1,3,6,10} ;
    int t ;
    cin>>t ;
    while(t--){
        string picked  ;
        cin>>picked ;
        int apNO = picked.size() ;
        int currNum = picked[0] - '0' ;
        int ans = (currNum-1)*10 + counts[apNO-1] ;
        cout<<ans<<'\n';
    }
    return 0 ;
}
