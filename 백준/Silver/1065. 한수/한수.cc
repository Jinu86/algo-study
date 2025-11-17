#include <iostream>
using namespace std;

int main(void)
{
    int N;
    cin >> N;

    int count = 0;

    for (int x = 1; x <= N; x++) {
        if (x < 100) {
            count++;
        } else if (x < 1000) {
            int a = x / 100;
            int b = (x / 10) % 10;
            int c = x % 10;
            if (a - b == b - c) 
                count++;
        }
    }

    cout << count;
    return 0;
}