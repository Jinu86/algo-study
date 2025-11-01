#include <iostream>
using namespace std;

long long cnt[10];

void calc(long long n, long long digit) 
{
    while (n > 0) {
        cnt[n % 10] += digit;
        n /= 10;
    }
}

int main(void) 
{
    long long n;
    cin >> n;

    long long start = 1, end = n;
    long long digit = 1;

    while (start <= end) 
    {
        while (end % 10 != 9 && start <= end) {
            calc(end, digit);
            end--;
        }
        while (start % 10 != 0 && start <= end) {
            calc(start, digit);
            start++;
        }

        if (start > end) break;

        long long num = (end / 10 - start / 10 + 1);
        
        for (int i = 0; i < 10; i++)
            cnt[i] += num * digit;

        start /= 10;
        end /= 10;
        digit *= 10;
    }

    for (int i = 0; i < 10; i++){
        cout << cnt[i];
        if (i < 9) cout << ' ';
    }
    
    return 0;
}