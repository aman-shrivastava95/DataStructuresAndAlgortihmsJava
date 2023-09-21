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
    int n ;
    cin>>n ;
    bool takenFloor = false ;
    for(int i=0;i<n;i++){
        int rating  ;
        cin>>rating ;
        bool neg = rating < 0 ;
        if(rating%2){
            int r ; 
            if(takenFloor){
                 r = (rating+1)/2 ;
            }else{
                r = (rating-1)/2 ;
            }
            cout<<r<<"\n" ;
            takenFloor = !takenFloor;
        }else{
            cout<<rating/2<<"\n" ;
        }
    }
}