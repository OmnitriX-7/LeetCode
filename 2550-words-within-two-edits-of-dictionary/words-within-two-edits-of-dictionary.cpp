class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string>ans;
        int q=queries.size();
        int d=dictionary.size();
        for(int i=0;i<q;i++){
            string s=queries[i];
            for(int j=0;j<d;j++){
                string t=dictionary[j];
                int edit=0;
                bool flag=1;
                for(int k=0;k<s.length();k++){
                    if(s[k]!=t[k] && edit<=2){
                        edit++;
                    }
                    else if(edit>2) {flag=0;break;}
                }
                if(edit<=2){
                    ans.push_back(s);
                    break;
                    }
            }
        }
        return ans;
    }
};