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
    int t;
    int c,pos,pos2,i;
    cin>>t;
    string s,a;
    while(t--)
    {
        c=0,pos=0,pos2=0;
        cin>>s;
        for(i=0; i<s.length(); i++)
        {
            if(s[i]=='1')
            {
                //a+='1';
                pos=i;
                break;
            }
        }
        for(i=s.length(); i>=pos; i--)
        {
            if(s[i]=='1')
            {
                pos2=i;
                break;
            }
        }
        for(i=pos; i<pos2; i++)
        {
            if(s[i]=='0')
                c++;
            else
                a+='1';
        }
        cout<<c<<endl;
    }
        //cout<<a<<endl;
    return 0 ;
}
