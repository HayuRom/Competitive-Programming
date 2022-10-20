class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int K) {
        int n = points.size();
        if (n <= K)
            return points;
        vector<int> dist(n);
        vector<int> indices(n);
        for (int i = 0; i < n; ++i) {
            int x = points[i][0], y = points[i][1];
            dist[i] = x * x + y * y;
            indices[i] = i;
        }
        auto comp = [&dist](int i, int j) {
            return dist[i] < dist[j];
        };

        nth_element(indices.begin(), indices.begin() + K, indices.end(), comp);
        vector<vector<int>> res(K);
        for (int i = 0; i < K; ++i)
            res[i] = points[indices[i]];
        return res;
    }
};
