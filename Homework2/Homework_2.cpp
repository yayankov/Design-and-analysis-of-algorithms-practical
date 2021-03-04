#include <iostream>
#include <stdio.h>
#include <queue>
#include <vector>
#include <limits.h>
#include <algorithm>

using namespace std;

#define triple pair<int,pair<int,int>>

int n, m, k;
int used[int(1e6) + 5], dist[int(1e6) + 5], levels[int(1e6) + 5];
vector<triple> gr[int(1e5) + 5];

void init() {
    int from, to, level, weight;
    cin >> n >> m >> k;

    for (int i=0; i<m; i++) {
        cin >> from >> to >> level >> weight;
        gr[from].push_back({to,{level,weight}});
        levels[i] = level;
    }

}

bool dijsktra(int maxLimit) {
    priority_queue< pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>> > toVisit;

    fill(dist,dist+n+1,INT_MAX/10);
    fill(used,used+n+1,0);

    dist[1] = 0;
    toVisit.push({0,1});

    while(!toVisit.empty()) {
        int node = toVisit.top().second;
        toVisit.pop();

        if(used[node]) continue;
        used[node] = 1;

        for(triple neighbour : gr[node]) {
            if(neighbour.second.first > maxLimit || dist[node] + neighbour.second.second >= dist[neighbour.first]) continue;

            dist[neighbour.first] = dist[node] + neighbour.second.second;
            toVisit.push({dist[neighbour.first],neighbour.first});
        }
    }
    if(dist[n] <= k ) {
     //   cout << maxLimit << ", " << dist[n] << endl;
        return true;
    } else {
     //   cout << maxLimit << ", , " << dist[n] << endl;
        return false;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    init();

    sort(levels, levels + m);

    int left = 0, right = m, mid, ans = -1;
    while(left <= right) {
        mid = (left + right)/2;
        if(dijsktra(levels[mid])) {
            ans = levels[mid];
            right = mid - 1;
        } else {

            left = mid + 1;
        }
    }
    cout << ans << endl;

    return 0;
}
