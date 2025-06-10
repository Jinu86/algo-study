#include <iostream>
#include <string>

using namespace std;

int main(void)
{
    int N, M;
    
    cin >> N >> M;

    char board[50][50];
    
    for (int i = 0; i < N; i++) 
    {
        string row;
        cin >> row;
        
        for (int j = 0; j < M; j++) 
            board[i][j] = row[j];
    }

    int answer = 64;

    for (int si = 0; si + 7 < N; si++) 
    {
        for (int sj = 0; sj + 7 < M; sj++) 
        {
            int cntWB = 0;
            int cntBW = 0;
            
            for (int x = 0; x < 8; x++) 
            {
                for (int y = 0; y < 8; y++) 
                {
                    char c = board[si + x][sj + y];
                    if ((x + y) % 2 == 0) 
                    {
                        if (c != 'W') cntWB++;
                        if (c != 'B') cntBW++;
                    } else {
                        if (c != 'B') cntWB++;
                        if (c != 'W') cntBW++;
                    }
                }
            }
            int cnt = cntWB < cntBW ? cntWB : cntBW;
            if (cnt < answer) answer = cnt;
        }
    }

    cout << answer << '\n';
    return 0;
}