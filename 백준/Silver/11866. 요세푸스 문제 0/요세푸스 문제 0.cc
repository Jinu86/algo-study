#include <iostream>
#include <queue>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;

    queue<int> q;
    for (int i = 1; i <= N; i++) q.push(i);

    int ans[1000], p = 0;
    while (!q.empty()) {
        for (int i = 1; i < K; i++) {
            q.push(q.front());
            q.pop();
        }
        ans[p++] = q.front();
        q.pop();
    }

    cout << '<';
    for (int i = 0; i < p; i++) {
        cout << ans[i];
        if (i + 1 < p) cout << ", ";
    }
    cout << '>' << '\n';

    return 0;
}