#include <iostream>
#include <cstring>
using namespace std;

int enemy[20005];
int cache[10005][4][4];

int mymin(int a, int b) { return a < b ? a : b; }

int operation(int idx, int prev, int last, int n, int w) 
{
    int &unit = cache[idx][prev][last];
    if (unit) return unit;

    bool is_inner = (enemy[idx] + enemy[idx ? idx - 1 : n - 1] <= w);
    bool is_outer = (enemy[idx + n] + enemy[idx ? idx - 1 + n : 2 * n - 1] <= w);
    bool is_inner_outer = (enemy[idx] + enemy[idx + n] <= w);

    if (idx == n - 1) 
    {
        if (idx == 0) return is_inner_outer ? 1 : 2;

        unit = 2;
        bool can_inner = is_inner && !(prev & 1);
        bool can_outer = is_outer && prev < 2;

        if (last == 0) 
        {
            if (is_inner && is_outer && prev == 0) unit = 0;
            
            else if (can_inner || can_outer || is_inner_outer) unit = 1;
        } else if (last == 1 && can_outer) unit = 1;
        
        else if (last == 2 && can_inner) unit = 1;

        return unit;
    }

    unit = 2 + operation(idx + 1, 0, idx ? last : 0, n, w);
    
    if (is_inner && !(prev & 1))
        unit = mymin(unit, 1 + operation(idx + 1, 1, idx ? last : 1, n, w));
    
    if (is_outer && prev < 2)
        unit = mymin(unit, 1 + operation(idx + 1, 2, idx ? last : 2, n, w));
    
    if (is_inner && is_outer && prev == 0)
        unit = mymin(unit, operation(idx + 1, 3, idx ? last : 3, n, w));
    
    if (is_inner_outer)
        unit = mymin(unit, 1 + operation(idx + 1, 3, idx ? last : 0, n, w));

    return unit;
}

int main(void)
{
    int t;
    cin >> t;
    
    while (t--) 
    {
        memset(cache, 0, sizeof(cache));
        int n, w;
        cin >> n >> w;
        for (int i = 0; i < 2 * n; i++) cin >> enemy[i];
        cout << operation(0, 0, 0, n, w) << '\n';
    }
    
    return 0;
}
