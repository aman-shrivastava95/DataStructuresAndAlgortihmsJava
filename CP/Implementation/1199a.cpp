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
    long n,x,y ;
    cin>>n>>x>>y ;
    long arr[n] ;
    for(int i=0;i<n;i++){
        cin>>arr[i] ;
    }
    //check for everye element if it is the one we are looking for
    for(long i = 0; i<n ;i++){
        bool check = true ;
        long cur = arr[i] ;
        
        //check left
        long left =  i-1;
        int count = 0 ;
        while(left >=0 && count !=x ){
            if(arr[left] <= cur){
                check = false ;
                break ;
            }
            count++ ;
            left-- ;
        }
        if(!check)
            continue; 
        
        //check right
        long  right = i+1 ;
        count = 0 ;
        while(right < n && count!=y){
            if(arr[right] <= cur){
                check=false ;
                break ;
            }
            count++ ;
            right++ ;
        }
        if(check){
            cout<<i+1 ;
            break ;
        }
    }

}