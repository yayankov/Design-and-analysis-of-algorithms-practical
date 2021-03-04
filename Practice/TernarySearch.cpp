#include<iostream>
#include<cstdio>
#include<math.h>
#include<iomanip>
using namespace std;

int n,x1,y1,x2,y2,v1,v2;

double func(int x1,int y1,int x2,int y2,int v1,int v2, int x) {
    double f1 = sqrt((x-x1)*(x-x1)+y1*y1)/v1;
    double f2 = sqrt((x-x2)*(x-x2)+y2*y2)/v2;
    return f1 + f2;
}

double ts(int left, int right, int x1,int y1,int x2,int y2,int v1,int v2) {

    double l = left;
    double r = right;

    for(int i=0; i<100; i++) {
        double l1 = (2*l+r)/3;
        double l2 = (l+2*r)/3;
        if(func(x1,y1,x2,y2,v1,v2,l1) < func(x1,y1,x2,y2,v1,v2,l2)) { //minimum
            r = l2;
        }
        else {
            l = l1;
        }
    }

    return func(x1,y1,x2,y2,v1,v2,l);
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    while(n--) {
        cin >> x1 >> y1 >> x2 >> y2 >> v1 >> v2;
        cout << setprecision(5) << fixed << ts(min(x1,x2), max(x1,x2),x1,y1,x2,y2,v1,v2) << endl;
    }


    return 0;
}
