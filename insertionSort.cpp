#include <iostream>
using namespace std;

void insertionSort(int arr[],int n){
    for(int i=1; i<n; i++){
        int current = arr[i];
        int prevIndex = i-1;
        while((arr[prevIndex] > current) && prevIndex>=0){
            arr[prevIndex +1] = arr[prevIndex];         // moving elements one step ahead
            prevIndex--;            
        }
        arr[prevIndex+1] = current;
    }
}


int main(){
    return 0;
}