class Fancy {
public:
    int MOD = 1e9 + 7;
    vector<long long> nums;
    long long  p = 1;
    long long a = 0;
    Fancy() {}

    long long power(long long a,long long b){
        if(b==0) return 1;
        long long half = power(a,b/2);
        long long result = (half * half) % MOD;
        if(b % 2 ==1) {
            result = (result *a) %MOD;
        }
        return result;
    }

    void append(int val) { 
       long long d = ((val - a) % MOD + MOD) % MOD;
    d = (d * power(p, MOD - 2)) % MOD;
    nums.push_back(d);
     }

    void addAll(int inc) { a = (a + inc) % MOD ; }

    void multAll(int m) {
        a = (a*m) % MOD;
        p = (p*m) % MOD;
    }

    int getIndex(int idx) {
        if (idx < 0 || idx >= nums.size())
            return -1;
        return (nums[idx] * p + a) % MOD;
    }
};

/**
 * Your Fancy object will be instantiated and called as such:
 * Fancy* obj = new Fancy();
 * obj->append(val);
 * obj->addAll(inc);
 * obj->multAll(m);
 * int param_4 = obj->getIndex(idx);
 */