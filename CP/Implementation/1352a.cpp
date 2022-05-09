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
    long long n,t,i,a,b,r;
    cin>>t ;
    while(t--){
        vector<int>v;
        r=1;
        cin>>n;
        while(n!=0)
        {
            r=r*10;
            a=n%r;
            n=n-a;
            if(a!=0)
                v.push_back(a);
        }
        cout<<v.size()<<endl;
        for(i=0; i<v.size(); i++)
        {
            cout<<v[i]<<" ";
        }
        cout<<endl;
    }
}
