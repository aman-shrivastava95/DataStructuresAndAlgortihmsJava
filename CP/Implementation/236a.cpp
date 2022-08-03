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
    string s ;
    cin>>s ;
    int n = s.size();
    vector<int> mp(26,0) ;
    for(int i=0;i<n;i++){
        mp[s[i]-'a']++ ;
    }
    int count = 0 ;
    for(auto freq:mp){
        if(freq!=0)count++ ;
    }
    if(count%2==1)cout<<"IGNORE HIM!" ;
    else cout<<"CHAT WITH HER!" ;
    return 0 ;
}
