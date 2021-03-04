#include <iostream>
#include <cstdio>
#include <limits.h>
using namespace std;

int mat[int(1e3)][int(1e3)], currLvl[int(1e3)][int(1e3)], prvLvl[int(1e3)][int(1e3)] = {INT_MIN};
int n, k, ans = INT_MIN;

void init() {
    cin >> n >> k;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin >> mat[i][j];
        }
    }
}

int getStateValue(int i, int j, int k) {
    if(i < 0 || j < 0 || i >= n || j >= n) return INT_MIN;

    return k == 0 ? currLvl[i][j] : prvLvl[i][j];
}

void dp() {

    prvLvl[0][0] = mat[0][0];

    for (int i=1; i<n; i++) {
        prvLvl[i][0] = mat[i][0] + prvLvl[i-1][0];
        prvLvl[0][i] = mat[0][i] + prvLvl[0][i-1];
    }

    for (int i=1; i<n; i++) {
        for (int j=1; j<n; j++) {
            prvLvl[i][j] = max(prvLvl[i-1][j], prvLvl[i][j-1]) + mat[i][j];
        }
    }

    ans = prvLvl[n-1][n-1];

    for(int p=k; p>0; p--) {
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                currLvl[i][j] = max(getStateValue(i-1,j,0), getStateValue(i,j-1,0));
                currLvl[i][j] = max(currLvl[i][j], getStateValue(i+1,j,1));
                currLvl[i][j] = max(currLvl[i][j], getStateValue(i,j+1,1));

                currLvl[i][j] += mat[i][j];
            }
        }

        ans = max(ans, currLvl[n-1][n-1]);

        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                prvLvl[i][j] = currLvl[i][j];
            }
        }

    }

}

int main() {
    init();
    dp();
    cout << ans << endl;
}
