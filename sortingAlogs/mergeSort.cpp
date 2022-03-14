#include<bits/stdc++.h>
using namespace std ;


void merge(int arr[],int left, int mid, int right){
    int subArr1 =mid-left+1 ;
    int subArr2 = right -mid ;
     //create temp array
    int* leftArray = new int[subArr1] ;
    int* rightArray = new int[subArr1] ;
    
    //copy data from left and right part
    for(int i=0;i<subArr1;i++)leftArray[i] = arr[left+i] ;
    for(int i=0;i<subArr2;i++)rightArray[i] = arr[mid+1+i] ;
    int i=0,j=0,k=left ;
    //merge temp array back into arr[left..right]
    while(i < subArr1 && j < subArr2){
        if(leftArray[i] < rightArray[j]){
            arr[k] = leftArray[i] ;
            i++ ;
        }else{
            arr[k] = rightArray[j] ;
            j++ ;
        }
        k++ ;
    }
    //left over in left array
    while(i<subArr1){
        arr[k] = leftArray[i] ;
        i++ ;
        k++ ;
    }
    //left over in right array
    while(j<subArr2){
        arr[k] = rightArray[j] ;
        j++ ;
        k++ ;
    }
}

void mergeSortUtil(int arr[],int start, int end, int n){
    
    if(start<end){
        int mid = (start+end)/2 ;
        mergeSortUtil(arr, start, mid,n) ;
        mergeSortUtil(arr, mid+1, end,n) ;
        merge(arr,start, mid ,end) ;
       
    }
}
void mergeSort(int arr[],int n){
   mergeSortUtil(arr, 0,n-1,n) ;
}

int main(int argc, char const *argv[])
{
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr)/sizeof(arr[0]);
    mergeSort(arr, n);
    for(int i=0;i<6;i++){
        cout<<arr[i]<<" " ;
    }
    cout<<endl ;
    return 0;
}
