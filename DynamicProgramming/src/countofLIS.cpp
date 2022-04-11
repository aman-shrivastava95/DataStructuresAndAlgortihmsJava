#include<bits/stdc++.h>
using namespace std ;

int countList(vector<int> &arr){
    int n =  arr.size() ;
    vector<int> lis(n,1) ;
    vector<int> count(n,1) ;
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(arr[i] > arr[j]){
                if(lis[j]+1 > lis[i]){
                    lis[i] = lis[j]+1 ;
                    count[i] = count[j] ;
                }
                else if(lis[j] + 1 == lis[i]){
                    count[i] +=count[j] ;
                }
            }
        }
    }
    int maxCount = 0 ;
    for(auto i:count)
        maxCount = max(maxCount,i) ;
    return maxCount ;
}