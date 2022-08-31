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
    int t ;
    cin>>t ;
    while(t--){
        vector<int> skills ;
        int n ;
        cin>>n ;
        for(int i = 0;i<2*n;i++){
            int skill; 
            cin>>skill ;
            skills.push_back(skill) ;
        }
        sort(skills.begin(),skills.end()) ;
        
        cout<<abs(skills[n]-skills[n-1])<<"\n" ;
    }
    return 0; 
}
