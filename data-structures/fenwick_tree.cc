/*
 * Fenwick Tree
 */

#include <vector>

using namespace std;

class FenwickTree {
private:
    vector<int> tree;
public:
    FenwickTree(int n) : tree(n + 1) {}

    int range_sum(int pos) {
        ++pos;
        int ret = 0;
        while (pos > 0) {
            ret += tree[pos];
            pos &= (pos - 1);
        }
        return ret;
    }

    void update(int pos, int val) {
        ++pos;
        while (pos < tree.size()) {
            tree[pos] += val;
            pos += (pos & -pos);
        }
    }
};
