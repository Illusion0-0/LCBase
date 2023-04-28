class UnionFind {
    vector<int> p;
    vector<int> size;
public:
    UnionFind(int n) : p(n), size(n, 1) {
        iota(p.begin(), p.end(), 0);
    }

    int Find(int i) {
        while (p[i] != i) i = p[i] = p[p[i]];
        return i;
    }

    bool Union(int i, int j) {
        i = Find(i), j = Find(j);
        if (i == j) return false;
        
        if (size[i] < size[j]) swap(i, j);
        size[i] += size[j];
        p[j] = i;
        return true;
    }
};

class Solution {
    bool areSimilar(const string& a, const string& b) {
        int miss = 0;
        for (size_t i = 0; i < a.size(); ++i)
            if (a[i] != b[i] && ++miss > 2) return false;
        return true;
    }

public:
    int numSimilarGroups(const vector<string>& strs) {
        UnionFind uf(strs.size());
        int groups = strs.size();
        
        for (int i = 0; i < strs.size(); ++i)
            for (int j = i+1; j < strs.size(); ++j)
                if (areSimilar(strs[i], strs[j]) && uf.Union(i, j))
                    --groups;
        return groups;
    }
};