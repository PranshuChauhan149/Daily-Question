class NumArray {
public:
    vector<int> seg;
    int n;

    void make(int idx, vector<int>& nums, int l, int h) {
        if (l == h) {
            seg[idx] = nums[l];
            return;
        }
        int mid = (l + h) / 2;
        make(idx * 2 + 1, nums, l, mid);
        make(idx * 2 + 2, nums, mid + 1, h);

        seg[idx] = seg[idx * 2 + 1] + seg[idx * 2 + 2];
    }

    int sum(int idx, int l, int h, int r1, int r2) {

        if (r2 < l || r1 > h)
            return 0;


        if (r1 <= l && h <= r2)
            return seg[idx];

        int mid = (l + h) / 2;

        return sum(idx * 2 + 1, l, mid, r1, r2) +
               sum(idx * 2 + 2, mid + 1, h, r1, r2);
    }

    void updates(int i, int index, int val, int l, int h) {
        if (l == h) {
            seg[i] = val;
            return;
        }
        int mid = (l + h) / 2;

        if (index <= mid)
            updates(i * 2 + 1, index, val, l, mid);
        else
            updates(i * 2 + 2, index, val, mid + 1, h);

        seg[i] = seg[i * 2 + 1] + seg[i * 2 + 2];
    }

    NumArray(vector<int>& nums) {
        n = nums.size();
        seg.resize(n * 4);
        make(0, nums, 0, n - 1);
    }

    void update(int index, int val) {
        updates(0, index, val, 0, n - 1);
    }

    int sumRange(int left, int right) {
        return sum(0, 0, n - 1, left, right);
    }
};
