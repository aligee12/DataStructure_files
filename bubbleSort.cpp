#include <iostream>
using namespace std;

void bubbleSort(int arr[],int n){
    for(int i=1; i<n; i++){
        for(int j=0; j<n-i-1; j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp; 
            }
        }
    }
}


int main(){
    return 0;
}