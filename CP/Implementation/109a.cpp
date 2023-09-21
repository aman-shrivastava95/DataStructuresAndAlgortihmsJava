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

/*
GOOD LOGIC ON NUMBERS
the number will be of the form a*4 + b*7 ;
let's take number 28 for example
28 = 4 4 4 4 4 4 4 
28 = 7 7 7 7
smaller will be 7, so if any numer is entirely 7 or 4, we need to take for 7
so reduce 4 , till the number is not divisibe by 7, and if it becomes divisible by 7 reduce 7
*/
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
    string s ;
    while(n>0 && n%7!=0){
        n = n-4 ;
        s.push_back('4') ;
    }
    while(n>0 && n%7==0){
        n = n-7 ;
        s.push_back('7') ;
    }
    if(n==0){
        cout<<s ;
    }else{
        cout<<-1 ;
    }
}