#include<iostream>
#include<vector>
using namespace std;

int n, k;
int arr[1000000];
void init()
{
    cin >> n >> k;
    for(int i=0; i<n; i++)
    {
        cin >> arr[i];
    }
}

bool check(int mid) {
    bool isTrue = true;
    for(int i=0; i<n-k; i++) {
        isTrue = true;
        if(arr[i] >= mid) {

       //     cout << endl<<" i="<<i << " Tuk e: " << arr[i] << endl;
            for(int j=i+1; j<i+k; j++) {
                if(arr[j] < mid) {
               //         cout << "WTF";
                    isTrue = false;
                    i = j;
                    break;
                }
            }
            if (isTrue) {
                return true;
            }
        }
    }
    return false;
}

long long binarySearch() {
    int left = 0, right = 2000000, mid, ans = -1;
    while(left <= right) {
        mid = (left + right)/2;
        if(check(mid)) {
            ans = mid;
            left = mid + 1;
        } else {
        //    cout << " Fail " << mid <<endl;
            right = mid - 1;
        }
    }
    return ans;
}

int main()
{

/*    cout << check(1);
    cout << check(2);
    cout << check(3);
    cout << check(4);
    cout << check(5);
    cout << check(6);
    cout << check(7);
    cout << check(8);
    cout << check(9);*/
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    init();
    cout << binarySearch();


    return 0;
}
