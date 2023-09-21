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
    int n ;
    cin>>n ;
    while(n--){
        string num ;
        cin>>num ;
        int zero= 0,sum = 0, even = 0 ;
        for(int i=0;i<num.length();i++){
            int digit =  num[i] - '0' ;
            if(digit == 0)
                zero++ ;
            if(digit%2 == 0)
                even++ ;
            sum += digit ;
        }
        if(sum%3==0 && zero > 0 && even>1) cout<<"red\n" ;
        else cout<<"cyan\n" ;
       
    }
}