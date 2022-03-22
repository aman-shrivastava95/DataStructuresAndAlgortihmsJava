#include<bits/stdc++.h>
using namespace std ;


int longestConsecutive(vector<int>& nums) {
    unordered_set<int> s ;
    for(int num : nums){
        s.insert(num) ;
    }
    int longest = 0 ;
    for(int num:nums){
        //this is the first element of any sequence
        if(s.find(num-1)==s.end()){
            int start = num ;
            int tempLength =0 ;
            while(s.find(start)!=s.end()){
                tempLength++ ;
                start++ ;
            }
            longest = max(longest,tempLength) ;
        }
    }
    return longest ;
}

