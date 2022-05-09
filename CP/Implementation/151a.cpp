#include<bits/stdc++.h>//
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
    int n, k,l,c,d,p,nl,np ;
    cin>>n>>k>>l>>c>>d>>p>>nl>>np ;
    int total_ml = k*l ;
    int pegs = total_ml/nl ;
    int total_slices = c*d ;
    int total_salt = p/np ;
    cout<<min(min(pegs/n,total_slices/n),total_salt/n) ;
    return 0 ;

}
