#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define MOD  100000007 
#define len(x) x.size()
#define min3(a,b,c),min(a, min(b,c))
#define max3(a,b,c), max(a, max(b,c))
#define all(v) v.begin(),v.end() 
#define alla(n) a,a + n
using namespace std ;
//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
void solve(int k){
    cout<<"solving for k: "<<k<<endl ;
    for(int i=0;i<k;i++){
        cout<<(i+1)*k<<" " ;
    }
    cout<<endl;
}

//code for monotonic stack , next greater element.
vector<int> nextGreaterElement(vector<int> &nums){
    int n  = nums.size();
    vector<int> nge(n,0) ;
    stack<int> st ;
    for(int i=0;i<n;i++){
        while(!st.empty() && nums[st.top()] < nums[i]){
            nge[st.top()] = nums[i] ;
            st.pop() ;
        }
        st.push(i) ;
    } 
    return nge ;
}
//this is awesome
int main(int argc, char const *argv[])
{
    //this basic structre is what is required for most of the time while dealing with competatitve code   
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin) ;
    freopen("output.txt","w",stdout) ;
    #endif
    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ; cout.tie(NULL) ; 
    int t ;
    cin>>t ;
    while(t--){
        int k ;
        cin>>k ;
        solve(k) ;
    }

}
 