string makeFancyString(string s) {
        int n = s.length();

        string result = "";

        for(int i=1;i<n-1;i++){
            if(s[i] == s[i-1] && s[i] == s[i+1]){
                s[i-1] = '@';
            }
        }

        for(int i=0;i<n;i++){
            if(s[i] != '@'){
                result += s[i];
            }
        }

        return result;
    }
