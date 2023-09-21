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


//this can be done with recursion, exploring all possibilities,
//but will give TLE
/*
the optimal way is the fact that each number can be made with sum of 2 and 1, 
because they are either even or odd
in even case start with all 2 steps
in odd case start with all 2 steps + 1 step
and keep on moving up, and checking which is divisible by m
*/

int main(int argc, char const *argv[])
{
    
    #ifndef ONLINE_JUDGE
    freopen("../input.txt","r",stdin) ;
    freopen("../output.txt","w",stdout) ;
    #endif
    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ; cout.tie(NULL) ;
    int n ,m ;
    cin>>n>>m ;
    int res = 0 ;
    if(m > n){
        res = -1 ;
    }
    else{
        if(n%2==0){
            res = n/2 ;
        }else{
            res = n/2 + 1 ;
        }
        while(res%m){
            res++ ;
        }
    }
    cout<<res ;
}
