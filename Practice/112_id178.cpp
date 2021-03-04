
#include <iostream>
#include <stdio.h>
#include <queue>
#include <vector>
#include <limits.h>
#include <list>
#include <algorithm>

using namespace std;

#define pi pair<int,int>

int n, m;
vector<int> gr[int(1e3) + 5];
vector<char> answer;
int visited[int(1e3) + 5];

void init() {
    int from, to;
    cin >> n >> m;

    for (int i=0; i<m; i++) {
        cin >> from >> to;
        gr[from].push_back(to);
        gr[to].push_back(from);
    }

}

void BFS(int start, int target) {
    for(int i=0; i<=n; i++) {
        visited[i] = 0;
    }
    queue<int> toVisit;
    visited[start] = 1;
    toVisit.push(start);
    int key = 0;
    while(!toVisit.empty()) {
        int node = toVisit.front();

        if(node == target) {
            answer.push_back('1');
            key = 1;
            break;
        }
        toVisit.pop();
        for(int neighbour : gr[node]) {

            if(!visited[neighbour]) {
                visited[neighbour] = 1;
                toVisit.push(neighbour);
            }
        }
    }
    if(key == 0) {
        answer.push_back('0');
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    init();
    int q;
    cin >> q;
    int start, target;

    for(int i=0; i<q; i++) {
        cin >> start >> target;
        BFS(start,target);
    }
    for(char j: answer) {
        cout << j;
    }
    cout << endl;

    return 0;
}
