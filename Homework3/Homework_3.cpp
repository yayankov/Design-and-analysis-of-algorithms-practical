/*
Подземие
Поради наближаващата сесия Мими започна да играе нова игра,
за да отлага ученето. Част от играта се нарича Подземието. То се
състои от Лагери, изградени от играчите, и пещери, които ги
свързват. Във всяка пещера има чудовище, което е на определено
ниво, и за да може играч да премине през пещерата, то неговият
герой трябва да бъде на ниво поне колкото чудовището (може и повисоко).
При влизане в подземието, играча си избира лагер, в който
да започне героят му, и целта е да обикаля по другите лагери, за
да намери по-добра екипировка и да се среща с други играчи.
Придвижването става както човек би очаквал. От един лагер играчът
може да премести своя герой до някой от другите лагери, с които
той е свързан, стига да може да премине през свързващата пещера.
Има само едно ограничение - чудовищата се нуждаят от поне 1 ход да
се възстановят, за това една пещера не може да бъде използвана 2
пъти последователно, тоест ако героят е започнал от лагер 1, след
това отиде в лагер 2, то не може веднага да се върне в лагер 1.(да
отбележим, че ако героят се озове в лагер 2 на по-късен етап, той
може да се върне. Например 1->2->3->4->2->1 е валиден път)
Сега Мими се е фокусирала върху едно от предизвикателствата в
играта - да направи "кръг" в подземието. Това означава да започне
от един лагер и да успее да се върне пак до него, следвайки
правилата за движение. На пръв поглед това звучи лесно, но все пак
сесията наближава и поне малко време трябва да бъде отделено за
учене. По тази причина Мими се интересува от минималното ниво,
което трябва да бъде нейният герой, за да може да изпълни
предизвикателството, за да не прекали с играенеето.
Забележки: пещерите са двупосочни и е гарантирано, че винаги ще
има поне един "кръг" в подземието. Лагерите са номерирани с
числата от 0 до n-1.

Вход:
На първия ред се въвеждат 2 числа: n - броят на лагерите и m -
броят на пещерите.
На следващите m реда се въвеждат по 3 числа: from,to,level. Те
означават, че, съответно, лагер from е свързан с лагер to и
чудовището в пещерата е ниво level.

Изход:
Изведете минималното ниво, което трябва да е героят на Мими, за да
може да направи "кръг" в подземието.

Ограничения:
1<=n<=105
1<=m<=106
1<=level<=1000
*/

#include <iostream>
#include <stdio.h>
#include <queue>
#include <vector>
#include <limits.h>
#include <algorithm>

using namespace std;

#define pi pair<int,int>

int n, m;
int dist[int(1e5) + 5], levels[int(1e6) + 5];
vector<pi> gr[int(1e5) + 5];

void init() {
    int from, to, weight;
    cin >> n >> m;

    for (int i=0; i<m; i++) {
        cin >> from >> to >> weight;
        gr[from].push_back({to,weight});
        gr[to].push_back({from,weight});
        levels[i] = weight;
    }
}

bool dijkstra(int maxLimit) {
    priority_queue< pi,vector<pi>, greater<pi> > toVisit; //{dist,node}

    fill(dist,dist+n+1,INT_MAX/10);
    //fill(used,used+n+1,0);
    int last = -1;
    int isStart = false;
    dist[1] = 0;
    toVisit.push({0,1});
    cout << endl << " Limit: " << maxLimit << endl;
    while(!toVisit.empty()) {
        int node = toVisit.top().second;
        toVisit.pop();

        cout << endl << node << endl;
        for(pi neighbour : gr[node]) {
           cout << "Pass, neighbour: " << neighbour.first << " edge: " << neighbour.second << endl;
            if(neighbour.first == last ) continue;
            if(isStart == true && neighbour.first == 1 && neighbour.second <= maxLimit) {
                return true;
            }

            if(neighbour.second > maxLimit || dist[node] + neighbour.second >= dist[neighbour.first]) continue;
            cout << "neighbour: " << neighbour.first << endl;
            dist[neighbour.first] = dist[node] + neighbour.second;

            toVisit.push({dist[neighbour.first],neighbour.first});
        }
        if(node == 1) {
            isStart = true;
        }
        last = node;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    init();

    sort(levels, levels + m);

    int left = 0, right = m, mid, ans = -1;
    while(left <= right) {
        mid = (left + right)/2;
        if(dijkstra(levels[mid])) {
            ans = levels[mid];
            right = mid - 1;
        } else {

            left = mid + 1;
        }
    }
    cout << ans << endl;

    return 0;
}




























