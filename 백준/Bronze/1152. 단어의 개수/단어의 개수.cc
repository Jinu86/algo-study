#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main(void) 
{
    string line;
    getline(cin, line);

    stringstream ss(line);
    
    string word;
    int n = 0;

    while (ss >> word) n++;

    cout << n << '\n';
    
    return 0;
}
