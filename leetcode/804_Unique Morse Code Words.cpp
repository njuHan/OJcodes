string dict[] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        unordered_set<string> st;
        for (string& str : words)
        {
            string morse = "";
            for (char& ch : str)
            {
                morse += dict[ch-'a'];
            }
            st.insert(morse);
        }
        return st.size();
    }
};