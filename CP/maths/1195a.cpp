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
    int arr[k+1] ;
    memset(arr, 0, sizeof(arr)) ;
    for(int i = 0; i< n; i++){
        int cur  ;
        cin>>cur;
        arr[cur]+=1 ;
    }
    // the trick is to satify even number of choices children first
    // 1 peti se 2 satisfy ho jayein that is optimal
    int cap = ceil(n/2.0) ;
    int even =0, odd= 0;
    for(int i=1;i<k+1;i++){
        if(arr[i]%2){
            even+=(arr[i]-1) ;
            odd++ ;
        }else{
            even+=arr[i] ;
        }
    }
    int res = 0 ;
    res+= 2*min(even/2, cap) ;
    cap-= min(even/2, cap) ;
    res+=cap ;
    cout<<res ;
}