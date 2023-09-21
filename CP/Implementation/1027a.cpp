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
        int n ;
        cin>>n ;
        string s;
        cin>>s ;
        int left = 0, right= n-1 ;
        string palindromic  = "YES" ;
        while(left<=right){
            char leftChar = s[left];
            char rightChar = s[right] ;
            if(leftChar == rightChar ||
                (leftChar=='a' && rightChar=='c')||
                (leftChar=='c' && rightChar=='a')||
                (leftChar=='z' && rightChar=='x')||
                (leftChar=='x' && rightChar=='z')){
                left++ ;
                right-- ;
                continue; 
            }else{
                if(abs(leftChar-rightChar) != 2){
                    palindromic = "NO" ;
                    break ;
                }
            }
            left++ ;
            right-- ;
        }
        cout<<palindromic<<"\n" ;
    }
}