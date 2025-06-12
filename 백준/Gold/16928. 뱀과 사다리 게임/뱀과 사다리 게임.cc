#include <iostream>
#include <queue>

using namespace std;

int main(void)
{
    int N, M;
    cin >> N >> M;

    int move[101];
    
    for (int i = 1; i <= 100; i++) move[i] = i;
    
    for (int i = 0, x, y; i < N + M; i++)
    {
        cin >> x >> y;
        move[x] = y;
    }

    int dist[101];
    
    for (int i = 1; i <= 100; i++) dist[i] = -1;
    
    queue<int> q;
    dist[1] = 0;
    
    q.push(1);

    while (!q.empty()) 
    {
        int cur = q.front(); q.pop();
        
        if (cur == 100) break;
        
        for (int d = 1; d <= 6; d++) 
        {
            int nxt = cur + d;
            
            if (nxt > 100) continue;
            
            nxt = move[nxt];
            
            if (dist[nxt] == -1) 
            {
                dist[nxt] = dist[cur] + 1;
                q.push(nxt);
            }
        }
    }

    cout << dist[100] << '\n';
    
    return 0;
}