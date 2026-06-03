class Solution {
public:
    string decodeString(string s) {
        stack<int> counts;
        stack<string> strings;
        string currentString = "";
        int k = 0;

        for (char c : s) {
            if (isdigit(c)) {
                k = k * 10 + (c - '0');
            } else if (c == '[') {
                counts.push(k);
                strings.push(currentString);
                k = 0;
                currentString = "";
            } else if (c == ']') {
                string decoded = strings.top();
                strings.pop();
                int count = counts.top();
                counts.pop();
                
                for (int i = 0; i < count; ++i) {
                    decoded += currentString;
                }
                currentString = decoded;
            } else {
                currentString += c;
            }
        }
        
        return currentString;
    }
};