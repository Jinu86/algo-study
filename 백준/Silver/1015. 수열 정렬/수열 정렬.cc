#include <iostream>
using namespace std;

int main(void) 
{
    int N;
    if (!(cin >> N)) return 0;

    int A[50];
    int sortedA[50];

    for (int i = 0; i < N; i++) {
        cin >> A[i];
        sortedA[i] = A[i];
    }

    for (int i = 1; i < N; i++) {
        int key = sortedA[i];
        int j = i - 1;
        while (j >= 0 && sortedA[j] > key) {
            sortedA[j + 1] = sortedA[j];
            j--;
        }
        sortedA[j + 1] = key;
    }

    int used[1001];
    int nextpos[1001];
    for (int v = 0; v <= 1000; v++) {
        used[v] = 0;
        nextpos[v] = 0;
    }

    for (int j = 0; j < N; j++) {
        int v = sortedA[j];
        if (!used[v]) {
            used[v] = 1;
            nextpos[v] = j;
        }
    }

    int P[50];
    for (int i = 0; i < N; i++) {
        int v = A[i];
        P[i] = nextpos[v];
        nextpos[v]++;
    }

    for (int i = 0; i < N; i++) {
        if (i) cout << ' ';
        cout << P[i];
    }
    cout << '\n';

    return 0;
}