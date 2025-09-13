class Solution {
public:

    bool isVowel(char ch){
        return ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u';
    }

    int maxFreqSum(string s) {
        int n = s.size();
        vector<int> freq(26,0);
        int vowel_freq = 0;
        int consonant_freq = 0;

        for(int i=0;i<n;i++){
            freq[s[i]-'a']++;
        }

        for(int i=0;i<26;i++){
            char ch = i + 'a';
            if(isVowel(ch)) {
                vowel_freq = max(vowel_freq,freq[i]);
            }else {
                consonant_freq = max(consonant_freq,freq[i]);
            }
        }

        return vowel_freq + consonant_freq;
        
    }
};
