#include <iostream>
#include <string>

using namespace std;

int main(void) 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;
    string S;
    cin >> S;

    int ans = 0, cnt = 0;
    
    for (int i = 0; i + 2 < M; ) 
    {
        if (S[i] == 'I' && S[i+1] == 'O' && S[i+2] == 'I') 
        {
            cnt++;
            
            if (cnt >= N) ans++;
            
            i += 2;
        } else {
            cnt = 0;
            i++;
        }
    }

    cout << ans << '\n';
    return 0;
}