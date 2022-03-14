#include<bits/stdc++.h>
using namespace std ;
//0-based example of max-heap
//TODO: insertion and deletion from the heap

void max_heapify(int arr[],int node,int n){
    int left = 2*node + 1 ;
    int right = 2*node  + 2 ;

    int largest = node ;
    if(left < n && arr[left] > arr[largest]){
        largest = left ;
    }
    if(right < n && arr[right] > arr[largest]){
        largest = right ;
    }
    if(largest!=node){
        swap(arr[node],arr[largest]) ;
        max_heapify(arr,largest,n);
    }
}

void build_maxHeap(int arr[],int n){
    for(int i = n/2;i>=0;i--){
        max_heapify(arr, i,n) ;
    }
}
void heapSort(int arr[],int n){
    int heap_size = n ;
    build_maxHeap(arr, n) ;
    for(int i=n-1;i>0;i--){
        swap(arr[i],arr[0]) ;
        heap_size-- ;
        max_heapify(arr,0,heap_size) ;
    }
}
int main(int argc, char const *argv[])
{
    // int arr[] = {1,4,3,7,8,9,10} ;
    // int n = sizeof(arr)/sizeof(arr[0]) ;
    // build_maxHeap(arr, n) ;

    // cout<<"max heap of the given array:"<<endl ;
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    cout<<"after heap sort:"<<endl ;
    int n = sizeof(arr)/sizeof(arr[0]);
    heapSort(arr, n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" " ;
    }
    return 0;
}
