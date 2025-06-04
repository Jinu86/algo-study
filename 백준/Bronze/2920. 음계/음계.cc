#include <iostream>

using namespace std;

int main(void) 
{
    int a[8];
    
    for (int i = 0; i < 8; i++) cin >> a[i];

    bool asc = true, desc = true;
    
    for (int i = 0; i < 7; i++) 
    {
        if (a[i] < a[i + 1]) desc = false;
        if (a[i] > a[i + 1]) asc = false;
    }

    if (asc) cout << "ascending\n";
    else if (desc) cout << "descending\n";
    else cout << "mixed\n";

    return 0;
}