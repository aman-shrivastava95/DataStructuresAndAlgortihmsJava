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

//this is awesome
int main(int argc, char const *argv[])
{
    //modify this as pwer the 
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin) ;
    freopen("output.txt","w",stdout) ;
    #endif
    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ; cout.tie(NULL) ;
    
    //simple vector
    vector<int> v {1,2,3,4} ;//this is also right
    vector<int> v1 = {2,3,4,5,6,7,8} ;//this is also right
    int t ;
    cin>>t ;
    while(t--){
        int x ;
        cin>>x ;
        v.push_back(x) ;
    }

    for(auto num:v){
        cout<<num<<" " ;
    }
    cout<<endl ;
    for(auto num:v1){
        cout<<num<<" " ;
    }
    cout<<endl;
    //2 dimensinal vector of given sizes
    int R=3, C=3 ;
    vector<vector<int>> mat(R,vector<int>(C, 80)) ;
    for(auto r:mat){
        for(auto c: r){
            cout<<c<< " " ;
        }
        cout<<endl ;
    }
    return 0 ;
}
