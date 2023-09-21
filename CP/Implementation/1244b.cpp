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
    while(t--){
        int n  ;
        string s ;
        int from_left = INT_MIN ;
        int from_right = INT_MIN ;
        cin>>n>>s ;
        for(int i=0; i<n; i++){
            if(s[i]=='1'){
                from_left = max(from_left, i) ;
                from_right = max(from_right,n-i-1) ;
            }
        }
        if(from_left!=INT_MIN){
            cout<<max((from_left+1)*2,(from_right+1)*2)<<endl ;
        }else{
            cout<<n<<endl ;
        }
    }
}