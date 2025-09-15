class Solution {
public:

    int canBeTypedWords(string text, string brokenLetters) {
        unordered_set<char> broken(brokenLetters.begin(), brokenLetters.end());
        int count = 0;
        string word = "";

        for (int i = 0; i <= text.size(); i++) {
            if (i == text.size() || text[i] == ' ') { // end of a word
                if (!word.empty()) {
                    bool bad = false;
                    for (char c : word) {
                        if (broken.count(c)) {
                            bad = true;
                            break;
                        }
                    }
                    if (!bad) count++;
                    word.clear();
                }
            } else {
                word += text[i];
            }
        }
        return count;
    }
};
