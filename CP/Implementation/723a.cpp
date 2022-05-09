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
    vector<int> v ;
    for(int i=0;i<3;i++){
        int x ;
        cin>>x ;
        v.push_back(x) ;
    }
    sort(v.begin(),v.end()) ;
    cout<<abs(v[1]-v[0]) + abs(v[1]-v[2]) ;
    return  0  ;
}
//aleternate solutoin, distance between max and min
int newYear(){
    int a,b,c ;
    cin>>a>>b>>c ;
    return abs(max(max(a,b),c) - min(min(a,b),c)) ;
}