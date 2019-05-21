/*
Nama    : Cryssa Aprilia Ermiyanda Piter
NPM     : 140810170063
Program : Merge Sort
*/

#include <iostream>

using namespace std;

void merge (int A[], int p, int q, int r){
    int i,j,k;
    int n1 = q-p+1;
    int n2 = r-q;

    //arrays
    int L[n1], R[n2];

    for (i=1; i<n1; i++){
        L[i]=A[p+i-1];
    }
    for (j=1; j<n2; j++){
        R[j]=A[q+j];
    }

    L[n1+1]
    i=1; j=1;

    for (k=p; k<r; k++){
        if (L[i] <= R[j]){
            A[k] = L[i];
            i = i+1;
        }
        else{
            A[k] = R[j];
            j = j+1;
        }
    }
}

void mergesort (int A[], int p, int r){
    if (l < r) 
    { 
        int m = p+(r-p)/2; 

        mergeSort(arr, p, m); 
        mergeSort(arr, m+1, r); 

        merge(arr, p, m, r); 
    } 
}