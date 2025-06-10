#include <iostream>
#include <cmath>

using namespace std;

int main(void) 
{
    int N;
    cin >> N;

    long long sum = 0;
    int freq[8001] = {0};
    int minV = 4001, maxV = -4001;
    for (int i = 0, x; i < N; i++) {
        cin >> x;
        sum += x;
        freq[x + 4000]++;
        if (x < minV) minV = x;
        if (x > maxV) maxV = x;
    }

    int mean = (int)round((double)sum / N);

    int median = 0;
    int cnt = 0;
    int target = (N + 1) / 2;
    for (int i = 0; i < 8001; i++) {
        cnt += freq[i];
        if (cnt >= target) {
            median = i - 4000;
            break;
        }
    }

    int maxCount = 0;
    for (int i = 0; i < 8001; i++) {
        if (freq[i] > maxCount) maxCount = freq[i];
    }

    int mode = 0;
    int modeCnt = 0;
    for (int i = 0; i < 8001; i++) {
        if (freq[i] == maxCount) {
            mode = i - 4000;
            modeCnt++;
            if (modeCnt == 2) break;
        }
    }

    int range = maxV - minV;

    cout << mean << '\n'
         << median << '\n'
         << mode << '\n'
         << range << '\n';

    return 0;
}