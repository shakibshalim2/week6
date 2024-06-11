#include<bits/stdc++.h>
using namespace std;
bool canDistribute(int n, int a, int b, int x){
    int piecesA = a / x;
    int piecesB = b / x;
    return (piecesA + piecesB) >= n;
}

int main(){
    int n, a, b;
    cin >> n >> a >> b;

    int l = 1, r = min(a, b), ans = 0;
    while (l <= r){
        int mid = (l + r) / 2;
        if (canDistribute(n, a, b, mid))
        {
            ans = mid;
            l = mid + 1;
        }
        else{
            r = mid - 1;
        }
    }

    cout << ans << endl;
}
