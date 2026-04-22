class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        int n1 = queries.size();
        int n2 = dictionary.size();
    vector<string>ans;
        for(int i=0;i<n1;i++){
            string str1 = queries[i];
            for(int j=0;j<n2;j++){
                string str2 = dictionary[j];
                if(str1 == str2){
                    ans.push_back(str1);
                    break;
                }
                else{
                    if(str1.size()==str2.size()){
                        int c =0;
                        for(int k=0;k<str1.size();k++){
                            if(str1[k]!=str2[k]) c++;
                        }
                        if(c<=2){
                            ans.push_back(str1);
                            break;
                        }
                    }
                    else continue;
                
                }
            }
        }
        return ans;

    }
};