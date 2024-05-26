#include <iostream>
#include <algorithm>

using namespace std;

#define MOD 1000000007
#define INF 5e18
typedef long long ll;

bool isPossible(int t, int n, int x, int y) {
    if (t < min(x, y)) {
        return false;
    }

    int cnt = 1;
    t -= min(x, y);
    cnt += t / x + t / y;

    return cnt >= n;
}

int main() {
    int n, x, y;
    cin >> n >> x >> y;

    int left = 0;
    int right = max(x, y) * n;
    int mid;

    while (left + 1 < right) {
        mid = left + (right - left) / 2;
        if (isPossible(mid, n, x, y)) {
            right = mid;
        }
        else {
            left = mid;
        }
    }
    
    cout << right << '\n';
}
