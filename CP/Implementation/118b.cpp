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
    int n ;
    cin>> n ;
    //upward triangle
    for(int i=0;i<=n;i++){
        //print spaces
        for(int j=0;j<n-i;j++){
            cout<<"  " ;
        }
        int k ;
        for(k=0;k<=i;k++){
            cout<<k ;
            if(i!=0)
                cout<<" " ;
        }
        k-=2 ;
        for(;k>=0;k--){
            cout<<k ;
            if(k>0)
                cout<<" " ;
        }
        cout<<endl ;
    }
    //downward triangle
    for(int i=n-1;i>=0;i--){
        //print spaces
        for(int j=0;j<n-i;j++){
            cout<<"  " ;
        }
        int k ;
        for(k=0;k<=i;k++){
            cout<<k ;
            if(i!=0)
                cout<<" " ;
        }
        k-=2 ;
        for(;k>=0;k--){
            cout<<k;
            if(k > 0)
                cout<<" ";
        }

         cout<<endl ;
    }

}
