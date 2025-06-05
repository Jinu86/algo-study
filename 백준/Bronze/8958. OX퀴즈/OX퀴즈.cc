#include <iostream>
#include <string>

using namespace std;

int main(void) 
{
    int t;
    cin >> t;

    while (t--) 
    {
        string s;
        cin >> s;

        int score = 0, streak = 0;

        for (char c : s) 
        {
            if (c == 'O') score += ++streak;
            else streak = 0;
        }

        cout << score << '\n';
    }

    return 0;
}