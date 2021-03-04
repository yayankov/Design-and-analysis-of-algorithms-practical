#include <iostream>
#include <cstdio>

using namespace std;

int main() {

    long long a[int(1e5)+5];
    long long b[int(1e5)+5];
    long long n, k;

    cin >> n >> k;

    b[1] = 1;
    a[1] = k-1;

    for(int i=2; i<=n; i++) {
        a[i] = (a[i-1]*(k-1) + b[i-1]*(k-1))%1000000007;
        b[i] = a[i-1];
    }

    cout << (a[n]+b[n])%1000000007 << endl;

    return 0;
}
