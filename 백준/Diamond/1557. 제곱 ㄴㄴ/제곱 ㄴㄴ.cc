#include <iostream>

using namespace std;

const int MAX_SQRT_N = 45000;
int mu[MAX_SQRT_N + 1];
bool is_composite[MAX_SQRT_N + 1];

void precomputeMu() {
    mu[1] = 1;
    for (int i = 2; i <= MAX_SQRT_N; i++) {
        mu[i] = 1;
    }

    for (int i = 2; i <= MAX_SQRT_N; i++) {
        if (is_composite[i]) continue;

        mu[i] = -1;

        for (long long j = 2LL * i; j <= MAX_SQRT_N; j += i) {
            is_composite[j] = true;
            if ((j / i) % i == 0) {
                mu[j] = 0;
            } else {
                if (mu[j] != 0) {
                    mu[j] *= -1;
                }
            }
        }
    }
}

long long countSquareFree(long long N) {
    long long count = 0;
    
    for (long long i = 1; i * i <= N; i++) {
        count += (long long)mu[i] * (N / (i * i));
    }
    return count;
}

int main(void)
{
    precomputeMu();

    long long K;
    cin >> K;

    long long low = 1;
    long long high = K * 2;
    long long ans = high;

    while (low <= high) {
        long long mid = low + (high - low) / 2;
        
        long long count = countSquareFree(mid);

        if (count >= K) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    cout << ans << "\n";

    return 0;
}