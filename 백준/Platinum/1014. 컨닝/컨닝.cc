#include <iostream>
using namespace std;

int main(void) 
{
    int C;
    cin >> C;
    
    while (C--){
        int N, M;
        cin >> N >> M;
        char room[10][11];
        for (int i = 0; i < N; i++) cin >> room[i];

        int avail[10] = {0};
        for (int i = 0; i < N; i++) {
            int mask = 0;
            
            for (int j = 0; j < M; j++)
                if (room[i][j] == '.') mask |= (1 << j);
            
            avail[i] = mask;
        }

        int max_state = 1 << M;
        int valid[1024], vcnt = 0, bits[1024];
        
        for (int s = 0; s < max_state; s++) {
            if ((s & (s << 1)) == 0) {
                valid[vcnt] = s;
                int cnt = 0;
                
                for (int k = 0; k < M; k++) if (s & (1 << k)) cnt++;
                bits[vcnt++] = cnt;
            }
        }

        int dp[2][1024] = {0};
        int cur = 0, prev = 1;

        for (int i = 0; i < vcnt; i++) {
            int s = valid[i];
            if ((s & avail[0]) == s) dp[cur][i] = bits[i];
        }

        for (int r = 1; r < N; r++) {
            cur ^= 1; prev ^= 1;
            for (int i = 0; i < vcnt; i++) dp[cur][i] = 0;
            
            for (int i = 0; i < vcnt; i++) {
                int s = valid[i];
                if ((s & avail[r]) != s) continue;
                for (int j = 0; j < vcnt; j++) {
                    int ps = valid[j];
                    
                    if ((ps & avail[r-1]) != ps) continue;
                    if ((s & (ps << 1)) || (s & (ps >> 1))) continue;
                    
                    int val = dp[prev][j] + bits[i];
                    
                    if (val > dp[cur][i]) dp[cur][i] = val;
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < vcnt; i++)
            if (dp[cur][i] > ans)
                ans = dp[cur][i];

        cout << ans << '\n';
    }
}