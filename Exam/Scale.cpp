#include <cmath>
#include <cstdio>
#include <vector>
#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
using namespace std;


int N, Q;
vector<tuple<int,int,string>> students;
vector<int> questions;

void init() {
    cin >> N >> Q;
    string a1;
    int a2, a3;
    for(int i=0; i<N; i++) {
        cin >> a1 >> a2 >> a3;
        students.push_back(make_tuple(a3,a2,a1));
    }
    int b1;
    for(int i=0; i<Q; i++) {
        cin >> b1;
        questions.push_back(b1);
    }
}

void binarySearch(int min) {
    long long left = 0;
    long long right = N-1;
    long long mid;
    long long res = 0;
    while(left <= right) {
        mid = (right + left)/2;
        if(min <= get<0>(students[mid])) {
           // cout << "q: " << min << " points: " << get<0>(students[mid]) << " res: " << res << endl;
            res = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    cout << get<2>(students[res]) << " " << get<1>(students[res]) << endl;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    init();
    sort(students.begin(), students.end());
    for(int minimum : questions) {

        binarySearch(minimum);
    }

    /*    for (int i = 0; i < N; i++)
        cout << get<0>(students[i]) << " "
             << get<1>(students[i]) << " "
             << get<2>(students[i]) << "\n";*/
    return 0;
}
