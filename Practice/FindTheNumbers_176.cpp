#include<iostream>
using namespace std;

int n, arr[100000], m;

void init() {
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    cin >> m;
}

int minBinarySearch(int target) {

        int left = 0;
        int right = n-1;
        int mid;
        int index = -1;
        while(left <= right) {
            mid = (right + left)/2;
            if(arr[mid] >= target) {
                index = mid;
                right = mid-1;
            } else {
                left = mid+1;
            }
        }
        return index;
}

int maxBinarySearch(int target) {

        int left = 0;
        int right = n-1;
        int mid;
        int index = n;
        while(left <= right) {
            mid = (right + left)/2;
            if(arr[mid] <= target) {
                index = mid;
                left = mid+1;
            } else {
                right = mid-1;
            }
        }
        return index;
}

void check() {

    for(int j=0; j<m; j++) {
        int first, last;
        cin >> first >> last;

        if( maxBinarySearch(last) == n || minBinarySearch(first) == -1) {
            cout << "0" << endl;
            continue;
        }

        cout << maxBinarySearch(last) - minBinarySearch(first) + 1 << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    init();
    check();

    return 0;
}
