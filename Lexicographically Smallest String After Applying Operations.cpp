class Solution {
public:

    void rotate(string &temp,int b){
        reverse(begin(temp),end(temp));
        reverse(begin(temp), begin(temp)+b);
        reverse(begin(temp)+b,end(temp));
    }

    string findLexSmallestString(string s, int a, int b) {
        string small = s;
        unordered_set<string> visited;
        queue<string> que;
        que.push(s);
        visited.insert(s);

        while(!que.empty()){
            string curr = que.front();
            que.pop();

            if(curr < small){
                small = curr;
            }

            // Add
            string temp = curr;
            for(int i=1;i<s.length();i+=2){
                temp[i] = ((temp[i] - '0' + a) % 10) + '0';
            }

            if(!visited.count(temp)){
                visited.insert(temp);
                que.push(temp);
            }

            //rotate
            rotate(temp,b);
            if(!visited.count(temp)){
                visited.insert(temp);
                que.push(temp);
            }
        }

        return small;
    }
};
