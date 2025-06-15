#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    
    while (T--) 
    {
        int A, B;
        cin >> A >> B;

        static bool visited[10000];
        static int prevv[10000];
        static char op[10000];
        
        for (int i = 0; i < 10000; i++) visited[i] = false;

        queue<int> q;
        visited[A] = true;
        q.push(A);

        while (!q.empty()) 
        {
            int cur = q.front(); q.pop();
            if (cur == B) break;

            int nxt;

            nxt = (cur * 2) % 10000;
            if (!visited[nxt]) 
            {
                visited[nxt] = true;
                prevv[nxt] = cur;
                op[nxt] = 'D';
                q.push(nxt);
            }

            nxt = (cur == 0 ? 9999 : cur - 1);
            if (!visited[nxt]) 
            {
                visited[nxt] = true;
                prevv[nxt] = cur;
                op[nxt] = 'S';
                q.push(nxt);
            }

            nxt = (cur % 1000) * 10 + (cur / 1000);
            if (!visited[nxt]) 
            {
                visited[nxt] = true;
                prevv[nxt] = cur;
                op[nxt] = 'L';
                q.push(nxt);
            }

            nxt = (cur % 10) * 1000 + (cur / 10);
            if (!visited[nxt]) 
            {
                visited[nxt] = true;
                prevv[nxt] = cur;
                op[nxt] = 'R';
                q.push(nxt);
            }
        }

        string ans;
        int cur = B;
        
        while (cur != A) 
        {
            ans.push_back(op[cur]);
            cur = prevv[cur];
        }

        for (int i = (int)ans.size() - 1; i >= 0; i--)
            cout << ans[i];
        cout << '\n';
    }

    return 0;
}