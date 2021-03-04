#include <iostream>
#include <stdio.h>
#include <queue>
#include <vector>
#include <limits.h>
#include <algorithm>

using namespace std;

struct Edge {
    int from, to, weight;
};
int dist[int(1e6)+5],n,m;
Edge edges[int(1e6)+5];

void init() {
    scanf("%d %d",&n,&m);

    for (int i=0; i<m; i++) {
        scanf("%d %d %d",&edges[i].from,&edges[i].to,&edges[i].weight);
    }
}

void bellmanFord(int start) {
    bool somethingChanged;

    fill(dist, dist+n, INT_MAX);
    dist[start] = 0;
    for(int i=0; i<n-1; i++) {
        somethingChanged = false;

        for(int j=0; j<m; j++) {
            Edge edge = edges[j];

            if(dist[edge.from] != INT_MAX && dist[edge.to] > dist[edge.from] + edge.weight) {
                dist[edge.to] = dist[edge.from] + edge.weight;
                somethingChanged = true;
            }
        }

        if(!somethingChanged)
            break;
    }

    somethingChanged = false;

     for(int j=0;j<m;j++) {
        Edge edge = edges[j];

        if(dist[edge.from] != INT_MAX && dist[edge.to] > dist[edge.from] + edge.weight) {
            dist[edge.to] = dist[edge.from] + edge.weight;
            somethingChanged = true;
        }
    }

    if(somethingChanged) {
        printf("Negative cycle!\n");
    }
    else {
        for(int i=0; i<n; i++) {
            printf("dist to %d is %d\n",i,dist[i]);
        }
    }
}


int main() {
    init();
    bellmanFord(4);
    return 0;
}
