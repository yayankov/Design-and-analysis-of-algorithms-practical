
#include<iostream>
#include <math.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long double N, F;
    cin >> N >> F;
    long double res = ceil(N/F);
    cout << res << endl;

    return 0;
}
