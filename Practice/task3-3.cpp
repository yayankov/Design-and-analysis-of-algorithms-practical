#include<iostream>
#include<cmath>
using namespace std;

long long sum(long long n) {
    long long sum = 0;
    for(long  long i=1; i<=n; i++)
        sum += i%1000000007;

    return sum%1000000007;
}

int main() {
    long long n;
    cin >> n;
    long long A = 1;
    long long lastA = 0;
    long long sumAll = 1;
    for(long long i=2; i<=n; i++) {
        long long s = sum(i);
        A += (long  long)(pow(i,i-1)*(s)+(2*i-1)*lastA);

        lastA = A%1000000007;
        sumAll = A%1000000007;
    }
    cout << sumAll%1000000007 << endl;
    return 0;
}
