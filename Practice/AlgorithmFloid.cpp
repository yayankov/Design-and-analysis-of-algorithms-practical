#include <cstdio>
#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;

int n, m, dist[1000][1000];

 void init() {

    int from, to, weight;

    scanf("%d %d",&n,&m);

    for(int i=0; i<n; i++) {
        fill(dist[i], dist[i]+n, INT_MAX);
    }

    for(int i=0; i<m;i++) {
        scanf("%d %d %d",&from,&to,&weight);
        dist[from][to] = weight;
    }

    for(int i=0; i<n;i++) {
        dist[i][i] = 0;
    }
 }

 void floyd() {
    for(int k=0; k<n;k++) {
        for(int i=0; i<n;i++) {
            for(int j=0; j<n;j++) {

                if(dist[i][k] == INT_MAX || dist[k][j] == INT_MAX) {
                    continue;
                }
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
 }

 void print() {
    for(int i=0; i<n;i++) {
        for(int j=0; j<n;j++) {
            printf("dist from %d to %d is %d\n",i+1,j+1,dist[i][j]);
        }
    }
 }

 int main() {
    init();
    floyd();
    print();
 }
