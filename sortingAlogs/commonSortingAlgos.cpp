#include<bits/stdc++.h>
using namespace std ;

void selectionSort(int arr[],int n){
    //find the minimum in each iteratin and keep putting it at the beginning of the array.
    for(int i=0;i<n;i++){
        int mini = i ;
        for(int j=i;j<n;j++){
            if(arr[j] < arr[mini])
                mini = j ;
        }
        swap(arr[i],arr[mini]) ;
    }
}

void bubbleSort(int arr[],int n){
    for(int i=n-1;i>0;i--){
        for(int j =0;j<i;j++ ){
            if(arr[j] > arr[j+1] ){
                swap(arr[j],arr[j+1]) ;
            }
        }
    }
}


int main(int argc, char const *argv[])
{
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr)/sizeof(arr[0]);
    bubbleSort(arr, n);
    for(int i=0;i<6;i++){
        cout<<arr[i]<<" " ;
    }
    cout<<endl ;

    return 0;
}
