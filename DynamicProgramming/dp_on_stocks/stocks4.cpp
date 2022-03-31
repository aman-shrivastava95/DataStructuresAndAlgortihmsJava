#include<bits/stdc++.h>
using namespace std ;

//another recursion n*2*k (bsbs will be 2*k ) and this can also be memoized and done.
int f(int ind, int transaction_num,vector<int> &prices, int n,int k ){
    if(ind==n || transaction_num ==2*k) return 0 ;
    
    if(transaction_num%2==0){
        //meaning can buy , that is one selling is done
        return max(-prices[ind] + f(ind+1,transaction_num+1, prices, n,k),0+f(ind+1,transaction_num,prices,n,k)) ;
    }
    return max(prices[ind] + f(ind+1,transaction_num+1, prices, n,k),0+f(ind+1,transaction_num,prices,n,k)) ;
}