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

string s ;
int nb, ns, nc ,pb, ps, pc ;
int cB = 0, cS = 0, cC = 0 ;
ll r ;
bool check(ll toMake){
    ll needB = max(toMake*cB - nb, (ll)0) ;
    ll needS = max(toMake*cS - ns, (ll)0) ;
    ll needC = max(toMake*cC - nc, (ll)0) ;
    return (needB*pb + needC*pc + needS*ps <= r) ;
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
   
    cin>>s>>nb>>ns>>nc>>pb>>ps>>pc>>r ;
    for(int i=0;i<s.length();i++){
        if(s[i]=='B')cB++ ;
        if(s[i]=='S')cS++ ;
        if(s[i]=='C')cC++ ;
    }

    //perform binary search
    //the search space is all the possible answers.
    ll L = 0 , R = 1e14 ;
    ll ans = 0 ;
    while(L <= R){
        ll mid = L + (R-L)/2 ;
        if(check(mid)){
            ans = mid ;
            L = mid + 1 ;
        }else
            R = mid -1 ;
    }
    cout<<ans ;
}