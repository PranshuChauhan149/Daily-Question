class Solution {
public:
    bool judgeCircle(string moves) {
        int countL = 0;
        int countR = 0;
        int countU = 0;
        int countD = 0;
        for (auto c : moves) {
            if (c == 'U') {
                countU++;
            } else if (c == 'D') {
                countD++;
            } else if (c == 'R') {
                countR++;
            } else {
                countL++;
            }
        }
        return (countL == countR && countU == countD);
    }
};