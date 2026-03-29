class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                for (int k1 = 0; k1 < 4; k1++) {
                    for (int k2 = 0; k2 < 4; k2++) {
                        if (s1 == s2)
                            return true;
                        if (k2 - k1 == 2) {
                            swap(s2[k2], s2[k1]);
                        }
                    }
                    cout << s2 << endl;
                }
                if (j - i == 2) {
                    swap(s2[i], s2[j]);
                }
            }
        }
        return false;
    }
};