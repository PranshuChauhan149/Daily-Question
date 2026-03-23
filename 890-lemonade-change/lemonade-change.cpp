class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        vector<int> a;
        vector<int> b;
        for (int i = 0; i < bills.size(); i++) {
            if (bills[i] == 5) {
                a.push_back(bills[i]);
            } else if (bills[i] == 10) {
                if (a.size() == 0)
                    return false;
                else {
                    a.pop_back();
                    b.push_back(bills[i]);
                }
                
            }
            else {
                int s = 0;
                if(b.size() > 0){
                    s = 10;
                    b.pop_back();
                }
                while(s!=15 && a.size() >0){
                    s+=a[0];
                    a.pop_back();
                }
                if(s!=15) return false;
            }
        }
        return true;
    }
};