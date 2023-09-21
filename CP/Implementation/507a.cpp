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
    //SOLUTION
    int n, k ;
    cin>>n>>k ;
    vector<pair<int, int>> v ;
    for(int i=0;i<n;i++){
        int days ;
        cin>>days ;
        v.push_back({days,i+1}) ;
    }
    sort(v.begin(), v.end()) ;
    int i = 0;
    int count = 0 ;
    string res = "" ;
    while(i<n && k>0){
        if(v[i].first <= k){
            count+=1 ;
            k = k-v[i].first ;
            res = res + to_string(v[i].second) + " " ;
        }
        i++ ;
    }
    cout<<count ;
    if(count!=0){
        cout<<"\n" ;
        cout<<res ;
    }
}