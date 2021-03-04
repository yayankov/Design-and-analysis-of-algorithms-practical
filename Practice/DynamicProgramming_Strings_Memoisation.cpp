#include <iostream>
using namespace std;

int n, m, dp[1000][1000];
string s1, s2;

void init() {
    for(int i=0; i<=n; i++) {
        for(int j=0; j<=m; j++) {
            dp[i][j] = -1;
        }
    }
}

int calc(int i, int j) {

    if(dp[i][j] != -1) {
        return dp[i][j];
    }
    if(i == 0) {
        return dp[i][j] = j;
    }
    if(j == 0) {
        return dp[i][j] = i;
    }


    if(s1[i-1] == s2[j-1]) {                // ab(c) ad(c)
        return dp[i][j] = calc(i-1, j-1);
    }

    cout << i-1 <<  " " << j-1 << " -> " << 1 << endl;

    return dp[i][j] = min(min(calc(i-1, j) + 1, calc(i, j-1) + 1), calc(i-1, j-1) + 1);
}

int main() {
    cin >> s1 >> s2;
    n = s1.length();
    m = s2.length();
    init();

    cout << calc(n, m) << endl;
}
