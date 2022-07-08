#include<bits/stdc++.h>
using namespace std ;

void testBinarySearch(){
    int arr[]{1,2,3,4,5,6,7,8,9,10} ;
    int n = sizeof(arr)/sizeof(arr[0]) ;
    vector<int> v = {1,2,3,4,5,6,7,8,9} ;
    //this basically needs a forward iterator, backward iterator and the target value.
    cout<<binary_search(arr,arr+n,11)<<endl ;
    cout<<binary_search(v.begin(),v.end(),15)<<endl ;
}

void testBounds(){
    vector<int> v{1,2,3,4,5,6,7,7,7,15} ;
    cout<<*(upper_bound(v.begin(),v.end(),7))<<endl ;
    cout<<*(lower_bound(v.begin(),v.end(),7))<<endl ;
}

int main(int argc, char const *argv[])
{
    cout<<"testing binary search methods from the stl\n" ;
    testBounds() ;
}
