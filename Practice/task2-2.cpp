#include <iostream>
#include <stdio.h>
#include <queue>
#include <vector>
#include <limits.h>
#include <list>
#include <algorithm>

using namespace std;

#define pi pair<int,int>

int A, B, P, Q, dist[int(1e6) + 8];

int rev(int n) {
    int reverseNum = 0;
    int curr;
    while(n) {
        curr = n%10;
        reverseNum = reverseNum*10 + curr;
        n /= 10;
    }
    return reverseNum;
}

void init() {
    cin >> A >> B >> P >> Q;
}

int BFS(int start) {
    bool visited[int(1e6)+8] = {false};
    list<int> toVisit;
    visited[start] = true;
    dist[start] = 1;
    toVisit.push_back(start);

    while(!toVisit.empty() && !visited[B]) {
        int node = toVisit.front();
        toVisit.pop_front();

        if(!visited[(node + P)%1000007]) {
            visited[(node + P)%1000007] = true;
            dist[(node + P)%1000007] = dist[node] + 1;
            toVisit.push_back((node + P)%1000007);
        }
        if(visited[B]) break;
        if(!visited[rev(node*Q)%1000007]) {
            visited[rev(node*Q)%1000007] = true;
            dist[rev(node*Q)%1000007] = dist[node] + 1;
            toVisit.push_back(rev(node*Q)%1000007);
        }
    }
    return dist[B];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    init();
    cout << BFS(A) << endl;

    return 0;
}

