#include <iostream>
#include <stdio.h>
#include <queue>
#include <vector>
#include <limits.h>
#include <list>
#include <algorithm>

using namespace std;

#define pi pair<int,int>
int n, m , k;
int dist[2005][2005];
int visited[2005][2005];
vector<pi> obstacles;
vector<pi> horses;
int cntHorses = 0;

void init() {

    cin >> n >> m >> k;

    int x, y;

    for(int i=0; i<m; i++) {
        cin >> x >> y;
        obstacles.push_back({x,y});
    }

    for(int i=0; i<k; i++) {
        cin >> x >> y;
        horses.push_back({x,y});
    }
}

int BFS(pi start) {

    for(int i=0; i<n; i++) {
        fill(visited[i],visited[i] + n, 0);
    }
    for(pi ob : obstacles) {
        visited[ob.first][ob.second] = 1;
    }
    for(pi horse : horses) {
        visited[horse.first][horse.second] = 2;
    }

    list<pi> toVisit;
    visited[start.first][start.second] = 1;
    dist[start.first][start.second] = 0;

    toVisit.push_back(start);
    int maxX, maxY;

    while(!toVisit.empty()) {
        pi node = toVisit.front();
        toVisit.pop_front();

        int x[] = {-2,-2,-1,-1,1,1,2,2};
        int y[] = {-1,1,-2,2,-2,2,-1,1};

        for(int i=0; i<8; i++) {
            int xi = node.first + x[i];
            int yi = node.second + y[i];

            if(xi>=0 && xi<n && yi>=0 && yi<n && visited[xi][yi] == 0) {
                visited[xi][yi] = 1;
                dist[xi][yi] = dist[node.first][node.second] + 1;
                toVisit.push_back({xi,yi});
            }
            if(xi>=0 && xi<n && yi>=0 && yi<n && visited[xi][yi] == 2) {
                cntHorses++;
                visited[xi][yi] = 1;
             //   cout << " horse: [" << xi << "][" << yi << "]" << endl;
                dist[xi][yi] = dist[node.first][node.second] + 1;
                maxX = xi;
                maxY = yi;

            }
        }

    }
    return dist[maxX][maxY];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    init();
    int x, y;
    cin >> x >> y;
    pi target = {x, y};
  //  cout << x << " " << y << endl;
    int maxDist = BFS(target);
    cout << cntHorses << " " << maxDist << endl;
    return 0;
}


