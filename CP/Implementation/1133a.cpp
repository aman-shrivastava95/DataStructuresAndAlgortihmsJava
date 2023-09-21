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
    int h1,h2,m1,m2 ;
    char c ;
    cin>>h1>>c>>m1 ;
    cin>>h2>>c>>m2 ;
    int time1 = h1*60 + m1 ;
    int time2 = h2*60 + m2 ;
    int resTime = (time2+time1)/2 ;
    int h =resTime/60 ;
    int m = resTime%60 ;
    if(h>9 && m > 9){
        cout<<h<<":"<<m ;
    }else{
        if(h<10)
            cout<<0 ;
        cout<<h<<":" ;
        if(m < 10)
            cout<<0 ;
        cout<<m ;
    }
}   