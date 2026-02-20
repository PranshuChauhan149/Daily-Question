class Solution {
public:
    string makeLargestSpecial(string s) {
        // Base case: empty string returns itself
        if (s.empty()) {
            return s;
        }
      
        // Store all special substrings at the current level
        vector<string> specialSubstrings;
      
        // Track balance of 1s and 0s (1 adds +1, 0 adds -1)
        int balance = 0;
      
        // Start position of current special substring
        int startPos = 0;
      
        // Iterate through the string to find special substrings
        for (int currentPos = 0; currentPos < s.size(); ++currentPos) {
            // Update balance: increment for '1', decrement for '0'
            balance += (s[currentPos] == '1') ? 1 : -1;
          
            // When balance returns to 0, we found a complete special substring
            if (balance == 0) {
                // Recursively process the inner part (excluding outer 1 and 0)
                // and wrap it with "1" prefix and "0" suffix
                string innerPart = s.substr(startPos + 1, currentPos - startPos - 1);
                string processedSpecial = "1" + makeLargestSpecial(innerPart) + "0";
                specialSubstrings.push_back(processedSpecial);
              
                // Move start position to the next character
                startPos = currentPos + 1;
            }
        }
      
        // Sort special substrings in descending order (lexicographically largest first)
        sort(specialSubstrings.begin(), specialSubstrings.end(), greater<string>());
      
        // Concatenate all sorted special substrings to form the result
        string result = "";
        for (const string& substring : specialSubstrings) {
            result += substring;
        }
      
        return result;
    }
};