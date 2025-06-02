using namespace std;

#include <iostream>
#include <string>
#include <vector>

template<typename T>
T mymin(T a, T b)
{
    return (a < b) ? a : b;
}

struct seg_tree
{
    struct tree_node
    {
        int sum0, sum1, opt;
        
        tree_node() { sum0 = sum1 = opt = 0; }
        
        tree_node(int x)
        {
            sum0 = (x == 0);
            sum1 = (x == 1);
            opt = 0;
        }
        
        tree_node operator+(const tree_node &nd) const
        {
            tree_node ret;
            ret.sum0 = sum0 + nd.sum0;
            ret.sum1 = sum1 + nd.sum1;
            ret.opt = mymin(opt + nd.sum0, sum1 + nd.opt);
            return ret;
        }
    };

    int limit;
    vector<tree_node> tree;

    void init(vector<int> &a)
    {
        for (limit = 1; limit <= (int)a.size(); limit <<= 1);
            tree.resize(2 * limit);

        for (int i = 0; i < (int)a.size(); i++)
            tree[i + limit] = tree_node(a[i]);

        for (int i = limit - 1; i; i--)
            tree[i] = tree[2 * i] + tree[2 * i + 1];
    }

    void edit(int x, int v)
    {
        x += limit;
        tree[x] = tree_node(v);
        while (x > 1)
        {
            x >>= 1;
            tree[x] = tree[2 * x] + tree[2 * x + 1];
        }
    }
} seg[25];

int len;

int init(string s)
{
    len = (int)s.size();
    int ret = 0;

    for (int i = 0; i < 25; i++)
    {
        vector<int> seq(len);
        for (int j = 0; j < len; j++)
            seq[j] = (s[j] > i + 'a');

        seg[i].init(seq);
        ret += seg[i].tree[1].opt;
    }

    return ret;
}

int change_char(int idx, char c)
{
    int ret = 0;

    for (int i = 0; i < 25; i++)
    {
        seg[i].edit(idx, c > i + 'a');
        ret += seg[i].tree[1].opt;
    }

    return ret;
}

int main(void)
{
    string s;
    cin >> s;

    cout << init(s) << "\n";

    int n;
    cin >> n;

    while (n--)
    {
        int idx;
        string v;
        cin >> idx >> v;

        cout << change_char(idx - 1, v[0]) << "\n";
    }

    return 0;
}
