#include <iostream>
#include <vector>
#include <map>

using namespace std;

vector<long long> getSubarraySums(const vector<int>& arr)
{
    vector<long long> result;
    int n = arr.size();

    for (int i = 0; i < n; i++)
    {
        long long sum = 0;
        
        for (int j = i; j < n; j++)
        {
            sum += arr[j];
            result.push_back(sum);
        }
    }

    return result;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    long long T;
    int n, m;

    cin >> T;
    cin >> n;

    vector<int> A(n);
    
    for (int i = 0; i < n; i++)
        cin >> A[i];
    
    cin >> m;

    vector<int> B(m);
    
    for (int i = 0; i < m; i++)
        cin >> B[i];

    vector<long long> aSums = getSubarraySums(A);
    vector<long long> bSums = getSubarraySums(B);

    map<long long, int> bCount;
    
    for (long long b : bSums)
    {
        bCount[b]++;
    }

    long long result = 0;
    for (long long a : aSums)
        result += bCount[T - a];

    cout << result << '\n';

    return 0;
}