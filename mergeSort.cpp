#include <iostream>
using namespace std;

void merge(int arr[], int l, int mid, int r){

}
void mergeSort(int arr[],int l,int r){
    if(l < r){
        int mid = (l+r)/2 ;
        mergeSort(arr,l,mid);        
        mergeSort(arr,mid+1,r);
    
        merge(arr,l,mid,r);
    }
}
void main(){
    return 0;
}