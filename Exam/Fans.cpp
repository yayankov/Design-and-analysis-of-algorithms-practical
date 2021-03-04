#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long

bool check(ll* hut, ll mid, ll size, ll  k)
{
    ll  pos = hut[0];
    ll  tempCows = 1;
    for (unsigned int i=1; i<size; i++)
    {
        if (hut[i] - pos >= mid)
        {
            pos = hut[i];
            tempCows++;

            if (tempCows == k)
              return true;
        }
    }
    return 0;
}

ll largestMinDist(ll* hut, ll  n,  ll k)
{
     ll tempLen = -1;
     ll start = hut[0];
     ll end = hut[n-1];
    while (start < end)
    {
        ll middle = (start + end)/2;
        if (check(hut, middle, n, k))
        {
            if(tempLen < middle)
            {
                tempLen = middle;
            }
            start = middle + 1;
        } else {
            end = middle;
        }
    }
    return tempLen;
}


int main() {
     ll N, K;
    cin >> N >> K;
     ll hut[N];
    for(unsigned int i=0; i<N; i++)
    {
        cin >> hut[i];
    }
    sort(hut, hut + N);
    cout << largestMinDist(hut, N, K);
    return 0;
}
