/*
Май месец е (добре де, поне беше когато писах задачата), дните са
дълги, нощите - топли и ароматни. Като всяка млада влюбена двойка,
Наня и приятелят й Бибо прекарват часове наред заедно… играейки
Worms. Макар и любовта да е силна (а жаждата за победа – още
повече), двамата влюбени имат сериозен проблем – докато Наня живее
в студ ентски град, Бибо е в съвсем другия край на града (ако изобщо се
счита в града) – в О!Беля.
За всяка своя среща един от двамата трябва да прекоси необятните
разстояния, които ги разделят. Те, разбира се, се опитват да намалят до
минимум времето, отделено за пътуване. Това означава, че ако има
поредица от автобусни линии, за която пътят от студ ентски град до О!Беля
бива изминат за минимално време, то те биха избрали нея. Двамата
имат карти за всички линии на градския транспорт, за това броят
сменени превозни средства не ги интересува. За сметка на това на
всяка спирка автобусите минават всеки Ki минути (броено от нулевата),
така че това е възможно да ги забави известно време. Можете ли да
помогнете на младата двойка, като намерите път с минимална (по
време) дължина между тях?
Схемата на града ще е дадена под формата на граф с N върха (всички
спирки) и M насочени ребра (F, T, P) - маршрут на превозно средство от
връх F до връх T за време P. За начална спирка ще се счита спирка с
номер 0, а за крайна – тази с номер N-1.
*/

#include <iostream>
#include <cstdio>
#include <stdio.h>
#include <queue>
#include <vector>
#include <limits.h>
#include <algorithm>

using namespace std;
#define pi pair<long long,long long>
#define ll long long

ll n, m, parent[int(1e4)*5+5];
queue<ll> path;
ll used[int(1e4)*5 + 5], dist[int(1e4)*5 + 5];
vector<pi> gr[int(1e5) + 5];

void init() {
    ll from, to, weight;
    scanf("%lld %lld",&n,&m);

    ll curr;
    ll waiting[int(1e3) + 5];
    for(ll i=0; i<n; i++) {
        scanf("%lld",&curr);
        waiting[i] = curr;
    }

    for (ll i=0; i<m; i++) {
        scanf("%lld %lld %lld",&from,&to,&weight);
        gr[from].push_back({to,weight});
    }
}

void dijkstra() {
    priority_queue< pi,vector<pi>, greater<pi> > toVisit; //{dist,node}

    fill(dist,dist+n+1,LONG_MAX/10);
    fill(used,used+n+1,0);

    dist[0] = 0;

    toVisit.push({0,0});

    while(!toVisit.empty()) {
        ll node = toVisit.top().second;
        toVisit.pop();

        if(used[node]) continue;
        used[node] = 1;

        for(pi neighbour : gr[node]) {
            if(node == n-1) {
                if(dist[node] + neighbour.second >= dist[neighbour.first]) continue;

                dist[neighbour.first] = dist[node] + neighbour.second;
                toVisit.push({dist[neighbour.first],neighbour.first});
            }
            else {
                ll time = neighbour.second + (waiting[node] - (neighbour.second % waiting[node]));

                if(dist[node] + time >= dist[neighbour.first]) continue;

                dist[neighbour.first] = dist[node] + time;
                toVisit.push({dist[neighbour.first],neighbour.first});
            }
        }
    }
    if(dist[n-1] == LONG_MAX/10) {
        printf("-1");
        exit(0);
    }
    else {
        cout << dist[n-1] << endl;
    }
}
/*
void print() {
    for(int i=0; i<n; i++) {
        cout << "dist to " << i << " is " << dist[i] << endl;
    }
}
*/

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    init();

    dijkstra();

    return 0;
}
