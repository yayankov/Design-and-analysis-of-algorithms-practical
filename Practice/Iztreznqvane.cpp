// Task id=179
/*  След множеството купони и голямото количество изпита ракия за една вечер
група студентите от ФМИ решили да отидат да изпият по една студена бира за
изтрезняване. Освен това искали да стигнат възможно най-бързо до магазина
тъй като нямали никакво желание за разходки след тежката вечер.
Допълнително групата решила да мине през баничарницата, за да се подкрепи
с по една баница. Като най-съобразителна Ели решила да изготви план за достигане до
магазина, но липсата на сън не и давала никаква възможност да се справи.
Можете ли да й помогнете?

Вход
 На първия ред на стандартния вход са зададени пет числа:
- n – броя на обектите от плана, покрай които е възможно групата да
премине – всеки обект е означен с индекс от 1 до n
- m – броя на директните пътища между два обекта
- x – индекса на блока, в който се намират студентите
- y – индекса на баничарницата (y ≠ x)
- z – индекса на магазина (z ≠ x, z ≠ x)
 На всеки от следващите m реда стоят по три числа – индексите на двата
различни обекта, между които има директен път и дължината на този път –
цяло положително число не по-голямо от 10000. Всеки път е зададен само по
веднъж.

Изход
 На първия ред от стандартния изход стои дължината на търсения минимален
път до магазина. На втория ред на стандартния изход стоят, разделени с
интервал, индексите на обектите, през които трябва да преминат студентите в
същата поредност. При наличие на няколко възможни варианта за минимален
път – изведете произволен.
 Ако няма път между блока на студентите и магазина изведете на единствен
ред -1.
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

ll n, m, first, station, last, parent[int(1e4)*5+5];
queue<ll> path;
ll used[int(1e4)*5 + 5], dist[int(1e4)*5 + 5];
vector<pi> gr[int(1e5) + 5];

void init() {
    ll from, to, weight;
    scanf("%lld %lld %lld %lld %lld",&n,&m,&first,&station,&last);

    for (ll i=0; i<m; i++) {
        scanf("%lld %lld %lld",&from,&to,&weight);
        gr[from].push_back({to,weight});
        gr[to].push_back({from,weight});
    }
    path.push(first);
}

void printPath(ll parent[], ll j)
{
    // Base Case : If j is source
    if (parent[j] == - 1)
        return;

    printPath(parent, parent[j]);

    path.push(j);
}

void dijkstra(ll start, ll target) {
    priority_queue< pi,vector<pi>, greater<pi> > toVisit; //{dist,node}

    fill(dist,dist+n+1,LONG_MAX/10);
    fill(used,used+n+1,0);
    parent[start] = -1;
    dist[start] = 0;
    toVisit.push({0,start});

    while(!toVisit.empty()) {
        ll node = toVisit.top().second;
        toVisit.pop();

        if(used[node]) continue;
        used[node] = 1;

        for(pi neighbour : gr[node]) {
            if(dist[node] + neighbour.second >= dist[neighbour.first]) continue;

            parent[neighbour.first] = node;
            dist[neighbour.first] = dist[node] + neighbour.second;
            toVisit.push({dist[neighbour.first],neighbour.first});
        }
    }
    if(dist[target] == LONG_MAX/10) {
        printf("-1");
        exit(0);
    }
    printPath(parent, target);
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

    dijkstra(first, station);
    ll startToStation = dist[station];

    dijkstra(station, last);
    ll stationToLast = dist[last];

    ll ans = startToStation + stationToLast;
    if(startToStation == LONG_MAX/10 && stationToLast == LONG_MAX/10) {
        printf("-1");

    } else {
        // cout << ans << endl;
        printf("%lld\n",ans);
        while(!path.empty()) {
            //cout << path.front() << " ";
            printf("%lld ",path.front());
            path.pop();
        }
    }

    printf("\n");

    return 0;
}
