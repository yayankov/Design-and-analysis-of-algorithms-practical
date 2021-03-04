#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

long long fib(long long x) {
    int cnt = 1;
    int cnt2 =1;
    int sum = 0;
    for(int i=1; i<x; i++) {
        sum = cnt + cnt2;
        cnt = cnt2;
        cnt2 = sum;
    }
    return sum;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    string s;
    cin >> s;
    if(s.length() == 0) {
        cout << "0" << endl;
        return 0;
    }
    long long sumAll = 1;
    //long long sum = 1;
    for(long unsigned int i=0; i<s.length(); i++) {
        long long sum = 1;
        if(s[i] == 'm' || s[i] == 'w') {
            cout << "0" << endl;
            return 0;
        }
        if(s[i] == 'u') {
            i++;
            int cnt = 1;
            while(i < s.length() && s[i] == 'u') {
                if(s[i] == 'm' || s[i] == 'w') {
                    cout << "0" << endl;
                    return 0;
                }
                cnt++;
                sum = fib(cnt)%1000000007;
             //   cout << "sum: " << sum << endl;
                i++;
            }
            sumAll = sum*sumAll%1000000007;
            i--;
            continue;
        }

        if(s[i] == 'n') {
            i++;
            int cnt = 1;
            while(i < s.length() && s[i] == 'n') {
                if(s[i] == 'm' || s[i] == 'w') {
                    cout << "0" << endl;
                    return 0;
                }
                cnt++;
                sum = fib(cnt)%1000000007;
//                cout << " sum: " << sum << endl;
                i++;
            }
        //    cout << " sum: " << sum << " sumAll: " << sumAll << endl;

            sumAll = sum*sumAll%1000000007;
            i--;
            continue;
        }
    }
    cout << sumAll%1000000007 << endl;
    return 0;
}
