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
    ll n ;
    cin>>n ;
    if(n <=2){
        cout<<"No" ;
    }else{
        cout<<"Yes\n" ;
        cout<<n-1<<" " ;
        for(int i=1 ; i<=n-1;i++){
            cout<<i<<" " ;
        }
        cout<<"\n" ;
        cout<<1<<" "<<n ;
    }
}
//another better intuitive way
//sum of all the natural number is given by n(n+1)/2 ;
//one of n/2 or (n+1)/2 will have to be integer and both of them will be between 1 and n
//sum can be then written as k*m (k can be n/2 or (n+1)/2)
//that means sum is a multiple of k 
//take  k out in one set, and remaining in other set.
void solution(int n){
    int k  = n%2 ?(n+1)/2 : n/2 ;
    cout<<1<<" "<<k<<"\n" ;
    cout<<n-1<<" " ;
    for(int i=1;i<k;i++) cout<<i<<" " ;
    for(int i=k+1; i<=n;i++) cout<<i<<" " ;

}