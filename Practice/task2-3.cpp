#include <iostream>
#include <cstdio>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n;
    cin >> n;

    long long a = 2; //лилави
    long long b; //жълти
    long long lastA = 2;
    long long lastB = 0;

    for(long long i=2; i<=n; i++) {
        a = (lastA + lastB)%1000000007;
        b = lastA%1000000007;
        lastA = a;
        lastB = b;
       // cout << "На ред " << i << " , л: " << a[i] << " ж: " << b[i] << " с: " << c[i] << endl;
    }

    cout << a%1000000007 << endl;

    return 0;
}
