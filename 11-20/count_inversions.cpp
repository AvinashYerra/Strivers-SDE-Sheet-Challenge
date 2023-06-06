#include <bits/stdc++.h> 

long long merge(long long*arr,int l,int mid,int r){
    long long inv=0;
    int n1=mid-l+1;
    int n2=r-mid;
    int a[n1];
    int b[n2];
    for(int i=0;i<n1;i++){
        a[i]=arr[l+i];
    }
    for(int i=0;i<n2;i++){
        b[i]=arr[mid+i+1];
    }
    int i=0,j=0,k=l;
    while(i<n1 && j<n2){
        if(a[i]<=b[j]){
            arr[k]=a[i];
            i++;
            k++;
        }else {
            inv+=n1-i;
            arr[k]=b[j];
            j++;
            k++;
        }
    }
    while(i<n1){
        arr[k]=a[i];
        i++;
        k++;
    }
    while(j<n2){
        arr[k]=b[j];
        j++;
        k++;
    }
    return inv;

}
long long mergesort(long long*arr,int l, int r){
    long long inv=0;
    if (l < r) {
      int mid = (l + r) / 2;
      inv += mergesort(arr, l, mid);
      inv += mergesort(arr, mid + 1, r);
      inv += merge(arr, l, mid, r);
    }
    return inv;
}
long long getInversions(long long *arr, int n){
    // Write your code here.
    return mergesort(arr,0,n-1);
}