class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
         if (hand.size() % groupSize != 0) return false;
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 0; i < hand.size(); i++) {
            pq.push(hand[i]);
        }
        while (!pq.empty()) {
            vector<int> a;
            int i = 0;
            int temp = pq.top();
            pq.pop();
            int count = 1;
            while (count< groupSize) {
                if(pq.empty()) return false;
                int t = pq.top();
                pq.pop();
                if (temp == t) {
                    a.push_back(t);
                } else if(t==temp+1) {
                    temp = t;
                    count++;
                }
                else{
                    return false;
                }
                    temp = t;
            }
            for (int i = 0; i < a.size(); i++) {
                pq.push(a[i]);
            }
        
        }
        return true;
    }
};