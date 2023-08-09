#include<bits/stdc++.h>
using namespace std;

int binarySearch(int arr[], int n, int key) {
    int l=0;
    int r=n;
    while(l<=r) {
        int mid = (l+r) / 2;
        if(arr[mid]==key) {
            return mid;
        } else if(arr[mid]>key) {
            r = mid-1;
        } else {
            l = mid+1;
        }
    }
    return -1;
}

int main() {
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++) {
        cin>>arr[i];
    }

    int key;
    cin>>key;

    cout<<binarySearch(arr, n, key)<<endl;
}