
#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<tuple<int, int, int> > v;
    v.push_back(make_tuple(10, 5, 30));
    v.push_back(make_tuple(10, 20, 25));
    v.push_back(make_tuple(3, 2, 1));

    // Using sort() function to sort by 1st
    // element of tuple
    sort(v.begin(), v.end());
    cout << "Sorted Vector of Tuple on basis"
           " of first element of tuple:\n";
    for (int i = 0; i < v.size(); i++)
        cout << get<0>(v[i]) << " "
             << get<1>(v[i]) << " "
             << get<2>(v[i]) << "\n";

    return 0;
}


/* #include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;

long long n, l, d, x, a, b, arr[int(1e5) + 5];

void init() {
    cin >> n >> l >> d;
    cin >> x >> a >> b;
    arr[0] = x;
    for(long long i=1; i<n; i++) {
        arr[i] = (x*a+b)%(l+1);
        x = arr[i];
    }
}

bool check(long long x) {
    int arr2[int(1e5) + 5];
    copy(arr,arr+x+1,arr2);
    sort(arr2,arr2+x+1);
    int leftLimit = 0;
    for(long long j=0; j<=x; j++) {
        if(arr2[j] - leftLimit > d) {
            return false;
        }
        leftLimit = arr2[j];
    }
    if(l - arr2[x] > d) {
        return false;
    }
    return true;
}

int binarySearch() {
    long long left = 0;
    long long right = n-1;
    long long mid;
    long long res = -1;
    while(left <= right) {
        mid = (right + left)/2;
        if(check(mid)) {
            res = mid + 1;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    init();
    cout << binarySearch() << endl;
}
*/
