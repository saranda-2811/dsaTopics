#include<bits/stdc++.h>
using namespace std;


int partition( vector<int>&arr, int s, int e) {

    int pivot = arr[s];

    int cnt = 0;
    for(int i = s+1; i<=e; i++) {     // number of elemeents less than pivot
        if(arr[i] <=pivot) {
            cnt++;
        }
    }

    //place pivot at the correct position
    int pivotIndex = s + cnt;
    swap(arr[pivotIndex], arr[s]);

    //left and right part
    int i = s, j = e;

    while(i < pivotIndex && j > pivotIndex) {

        if(arr[i] <= pivot) 
        {
            i++;
        }

        if(arr[j] > pivot) {
            j--;
        }

        else if(i < pivotIndex && j > pivotIndex) {
            swap(arr[i++], arr[j--]);
        }

    }

    return pivotIndex;

}

void quickSort(vector<int>&arr, int s, int e) {

    //base case
    if(s >= e) 
        return ;

    //find partition point
    int p = partition(arr, s, e);

    //left part sort
    quickSort(arr, s, p-1);

    //right part sort
    quickSort(arr, p+1, e);

}

int main() {

    vector<int>arr = {50,30,90,40,80,70};
    int n = arr.size();

    quickSort(arr, 0, n-1);

    for(int i=0; i<n; i++) 
    {
        cout << arr[i] <<" ";
    } 
    cout << endl;


    return 0;
}
