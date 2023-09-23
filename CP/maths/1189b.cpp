#include<bits/stdc++.h>
#define pb push_back
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
    ll arr[n] ;
    for(int i = 0; i< n; i++){
        cin>>arr[i] ;
    }
    sort(arr, arr+n) ;
    if(arr[n-2] + arr[n-3] <= arr[n-1])
        cout<<"NO\n" ;
    else{
        cout<<"YES\n" ;
        cout<<arr[n-1]<<" " ;
        for(int i = n-3;  i>=0  ; i--){
            cout<<arr[i]<<" " ;
        }
        cout<<arr[n-2] ; 
    }
}