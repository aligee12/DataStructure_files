#include <iostream>
using namespace std;

void selectionSort(int arr[],int n){
    for(int i=0; i<n-1; i++){
        int minIndex = i;
        for(int j=i+1; i<n; i++){
            if(arr[j] < arr[minIndex]){
                minIndex = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}


int main(){
    return 0;
}