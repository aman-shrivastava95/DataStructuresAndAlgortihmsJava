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

ll __gcd(ll a, ll b) { 
    if (b == 0) { 
        return a; 
    } 
    return __gcd(b, a % b); 
}

int main(int argc, char const *argv[])
{
    #ifndef ONLINE_JUDGE
    freopen("../input.txt","r",stdin) ;
    freopen("../output.txt","w",stdout) ;
    #endif
    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ; cout.tie(NULL) ;
    //SOLUTION
    int t ;
    cin>>t ;
    while(t--){
        string s1, s2 ;
        cin>>s1>>s2 ;
        ll n1 = s1.length(), n2 = s2.length() ;
        ll lcm = __gcd(n1,n2) ;
        for(int i=0;i<lcm/n1;i++)s1+=s1 ;
        for(int i=0;i<lcm/n2;i++)s2+=s2 ;
        if(s1==s2) cout<<s1<<"\n" ;
        else cout<<-1<<"\n" ;
        
    }
}