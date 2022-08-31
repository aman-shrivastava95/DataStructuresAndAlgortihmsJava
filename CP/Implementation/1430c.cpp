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
     long t; scanf("%ld", &t);
    while(t--){
        long n; scanf("%ld", &n);
        puts("2");
        long cur(n);
        for(long p = n - 1; p >= 1; p--){
            printf("%ld %ld\n", p, cur);
            cur = (cur + p + 1) / 2;
        }
    }

    return 0;
    
}
