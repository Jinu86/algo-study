#include <iostream>
using namespace std;

struct Point {
    double x, y;
};

double cross(Point a, Point b, Point c) {
    return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

Point intersect(Point a, Point b, Point c, Point d) {
    double A1 = b.y - a.y, B1 = a.x - b.x, C1 = A1 * a.x + B1 * a.y;
    double A2 = d.y - c.y, B2 = c.x - d.x, C2 = A2 * c.x + B2 * c.y;
    double det = A1 * B2 - A2 * B1;
    Point p;
    p.x = (B2 * C1 - B1 * C2) / det;
    p.y = (A1 * C2 - A2 * C1) / det;
    return p;
}

int clip(Point *src, int n, Point a, Point b, Point *dst) {
    int m = 0;
    for (int i = 0; i < n; i++) {
        Point c = src[i], d = src[(i + 1) % n];
        double c1 = cross(a, b, c), c2 = cross(a, b, d);
        if (c1 >= 0) dst[m++] = c;
        if (c1 * c2 < 0) dst[m++] = intersect(a, b, c, d);
    }
    return m;
}

double area(Point *p, int n) {
    double s = 0;
    for (int i = 0; i < n; i++)
        s += p[i].x * p[(i + 1) % n].y - p[i].y * p[(i + 1) % n].x;
    if (s < 0) s = -s;
    return s / 2.0;
}

int main(void) 
{
    int N, M;
    cin >> N >> M;
    Point A[200], B[200], tmp1[200], tmp2[200];
    
    for (int i = 0; i < N; i++) cin >> A[i].x >> A[i].y;
    for (int i = 0; i < M; i++) cin >> B[i].x >> B[i].y;
    
    int n = N;
    
    for (int i = 0; i < N; i++) tmp1[i] = A[i];
    for (int i = 0; i < M; i++) {
        n = clip(tmp1, n, B[i], B[(i + 1) % M], tmp2);
        for (int j = 0; j < n; j++) tmp1[j] = tmp2[j];
        if (n == 0) break;
    }
    
    if (n == 0) cout << 0.0;
    else {
        cout.setf(ios::fixed);
        cout.precision(15);
        cout << area(tmp1, n);
    }
}