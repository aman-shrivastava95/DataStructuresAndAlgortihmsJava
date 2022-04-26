#include<bits/stdc++.h>
using namespace std ;
//number of subsequences of the form aibjck where i>0, b>0,c>0
//this can be converted to the bottom up dp also.
int  fun(int ind, int prev, string &s, int n, string currString,vector<vector<int>> &dp)
{
    if (ind == n)
    {
        if(prev==3){//we need to have atleast one of each a, b, and c
            cout << currString << endl;
            return 1;
        }
        return 0 ;
    }
    if(dp[ind][prev]!=-1)return dp[ind][prev] ;
    
    int ways = 0 ;
    if (s[ind] == 'a' && (prev == 0 || prev == 1)) ways+=fun(ind + 1, 1, s, n, currString + 'a',dp);
    if (s[ind] == 'b' && (prev == 1 || prev == 2)) ways+=fun(ind + 1, 2, s, n, currString + 'b',dp);
    if (s[ind] == 'c' && (prev == 2 || prev == 3)) ways+=fun(ind + 1, 3, s, n, currString + 'c',dp);

    // not pick cases
    ways+=fun(ind + 1, prev, s, n, currString,dp);
    return dp[ind][prev]=ways ;
}
int main(int argc, char const *argv[])
{
    string s = "abcabc" ;
    int n = s.size() ;
    vector<vector<int>> dp(n+1,vector<int>(4,-1)) ;
    int ans = fun(0,0, s ,s.size(),"",dp) ;
    cout<<ans ;
    return 0;
}
