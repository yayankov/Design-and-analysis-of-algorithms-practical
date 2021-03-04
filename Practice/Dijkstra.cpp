#include <iostream>
#include <stdio.h>
#include <queue>
#include <vector>
#include <limits.h>
#include <algorithm>

using namespace std;

#define pi pair<int,int>

int n, m;
int used[int(1e6) + 5], dist[int(1e6) + 5];
vector<pi> gr[int(1e5) + 5];

void init() {
    int from, to, weight;
    cin >> n >> m;

    for (int i=0; i<m; i++) {
        cin >> from >> to >> weight;
        gr[from].push_back({to,weight});
        gr[to].push_back({from,weight});
    }

}

void dijkstra(int start) {
    priority_queue< pi,vector<pi>, greater<pi> > toVisit; //{dist,node}

    fill(dist,dist+n+1,INT_MAX/10);
    //fill(used,used+n+1,0);
    dist[start] = 0;
    toVisit.push({0,start});

    while(!toVisit.empty()) {
        int node = toVisit.top().second;
        toVisit.pop();

        if(used[node]) continue;
        used[node] = 1;

        for(pi neighbour : gr[node]) {
            if(dist[node] + neighbour.second >= dist[neighbour.first]) continue;

            dist[neighbour.first] = dist[node] + neighbour.second;
            toVisit.push({dist[neighbour.first],neighbour.first});
        }
    }
}

void print() {
    for(int i=0; i<n; i++) {
        cout << "dist to " << i << " is " << dist[i] << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    init();
    dijkstra(2);
    print();

    return 0;
}
