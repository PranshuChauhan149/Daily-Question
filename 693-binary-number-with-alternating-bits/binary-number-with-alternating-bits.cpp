class Solution {
public:
    bool hasAlternatingBits(int n) {
        int flag = -1;
        while(n!=0){
            if(n&1){
                if(flag==-1){
                    flag=1;
                }
                else{
                    if(flag==1){
                        return false;
                    }
                    else{
                        flag = 1;
                    }
                }
            
                
            }else{
                if(flag==-1){
                    flag=0;
                }
                else{
                    if(flag==0){
                        return false;
                    }
                    else{
                        flag = 0;
                    }
                }
                cout<<(n&1);
            }
            n = n>>1;
        }
        return true;
    }
};