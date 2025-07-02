#include <iostream>

using namespace std;

const int MAX = 101;

int graph[MAX][MAX];
int dist[MAX];
int queue[MAX];
int front, rear;

int main(void)
{
    int N, M;
    cin >> N >> M;

    for (int i = 0; i < M; i++)
    {
        int A, B;
        cin >> A >> B;
        graph[A][B] = 1;
        graph[B][A] = 1;
    }

    int answer = 0;
    int min_sum = 1e9;

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
            dist[j] = -1;
        
        front = rear = 0;
        dist[i] = 0;
        queue[rear++] = i;

        while (front < rear)
        {
            int cur = queue[front++];

            for (int j = 1; j <= N; j++)
            {
                if (graph[cur][j] == 1 && dist[j] == -1)
                {
                    dist[j] = dist[cur] + 1;
                    queue[rear++] = j;
                }
            }
        }

        int sum = 0;
        for (int j = 1; j <= N; j++)
        {
            sum += dist[j];
        }

        if (sum < min_sum)
        {
            min_sum = sum;
            answer = i;
        }
    }

    cout << answer << '\n';

    return 0;
}