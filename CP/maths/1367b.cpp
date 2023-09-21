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
    int t; 
    cin>>t ;
    while(t--){
        int n ;
        cin>>n ;
        int oddCount =0,evenCount = 0 ;
        int nums[n] ;
        for(int i = 0;i<n;i++)
            cin>>nums[i] ;
        for(int i = 0;i<n;i++){
            if(i%2){
                if(nums[i]%2==0)
                    oddCount++ ;
            }else{
                if(nums[i]%2)
                    evenCount++ ;
            }
        }
        if(evenCount==oddCount)
            cout<<evenCount<<"\n" ;
        else
            cout<<-1<<"\n" ;
    }
}