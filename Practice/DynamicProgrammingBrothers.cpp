#include <iostream>
#include <cstdio>
using namespace std;

int dp[int(1e6)+5], sum, cash[int(1e3)+5], n;

void init() {
    cin >> n;
    for (int i=0; i<n; i++) {
        scanf("%d",&cash[i]);
        sum += cash[i];
    }
}

void dpCash() {

    dp[0] = 1;
    for(int i=0; i<n;i++) {
        for(int j=sum/2; j-cash[i]>=0; j--) {
            if(dp[j] == 1) continue;

            dp[j] = dp[j-cash[i]];
        }
    }
}

void split() {
    for(int i=sum/2; i>=0; i--) {
        if(dp[i]) {
            cout << sum - 2*i << endl;
            return;
        }
    }
}

int main() {
    init();
    dpCash();
    split();
}
