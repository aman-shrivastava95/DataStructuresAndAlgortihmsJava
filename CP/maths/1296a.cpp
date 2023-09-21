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
        string ans="NO" ;
        int oddCount = 0 , evenCount = 0 ;
        while(n--){
            int num ;
            cin>>num ;
            if(num%2)
                oddCount+=1 ;
            else 
                evenCount+=1 ;
        }
        if(oddCount%2){
            ans = "YES";
        }else{
            ans = (evenCount > 0 && oddCount!=0) ? "YES": "NO" ;
        }
        cout<<ans<<"\n" ;
    }
}