#include <iostream>
#include <string>

using namespace std;

int main(void) 
{
    int a, b, c;
    
    cin >> a >> b >> c;

    int result = a * b * c;
    int count[10] = {0};

    string s = to_string(result);
    
    for (char ch : s) count[ch - '0']++;

    for (int i = 0; i < 10; i++) cout << count[i] << '\n';

    return 0;
}