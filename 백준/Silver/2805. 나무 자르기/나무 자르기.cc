#include <iostream>

using namespace std;

typedef long long ll;

int main(void)
{
    int n;
    ll m;
    cin >> n >> m;

    int trees[1000000];
    int max_height = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> trees[i];
        if (trees[i] > max_height)
            max_height = trees[i];
    }

    int low = 0;
    int high = max_height;
    int result = 0;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        ll total = 0;

        for (int i = 0; i < n; i++)
        {
            if (trees[i] > mid)
                total += trees[i] - mid;
        }

        if (total >= m)
        {
            result = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    cout << result << '\n';

    return 0;
}