#include <iostream>
using namespace std;

int partition(int arr[], int l, int r){
    int pivot = arr[r];
    int i = l-1;

    for (int j=l; j< r; j++){
        if(arr[j] < pivot){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    
    swap(arr[i+1],arr[r]);

    return (i+1);
}

void quickSort(int arr[],int l, int r){
    if(l < r){
        int pivotIndex = partition(arr,l,r);

        quickSort(arr, l, pivotIndex-1);
        quickSort(arr,pivotIndex+1,r);
    }
    
}
int main(){
    int array[] = {5,4,3,2,1};    
    quickSort(array,0,4);       //left and right indices of array
    cout << "\nSorted array elements: ";
    for(int i =0; i<5; i++){        
        cout << array[i] << " ";
    }
    cout << endl;
    return 0;
}