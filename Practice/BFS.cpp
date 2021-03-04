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
vector<pi> gr[int(1e5) + 5];

void init() {
    int from, to, weight;
    cin >> n >> m;

    for (int i=0; i<m; i++) {
        cin >> from >> to >> weight;
        gr[from].push_back({to,weight});
    }

}

void BFS(int start) {
    bool *visited = new bool[m];

    fill(visited,visited+m+1,false);
    list<int> toVisit;
    visited[start] = true;
    toVisit.push_back(start);

    while(!toVisit.empty()) {
        int node = toVisit.front();
        cout << node << " ";
        toVisit.pop_front();

        for(pi neighbour : gr[node]) {

            if(!visited[neighbour.first]) {
                visited[neighbour.first] = true;
                toVisit.push_back(neighbour.first);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    init();
    BFS(2);

    return 0;
}

