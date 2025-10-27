class Solution {
public:

    int stSum(string &laser) {
        
        int total = 0;

        for(char ch: laser) {
            total += (ch - '0');
        }

        return total;

    }

    int numberOfBeams(vector<string>& bank) {
        int n = bank.size();
        vector<int> temp(n);

        for(int i=0;i<n;i++){
            string curr = bank[i];
            int sum = stSum(curr);

            temp[i] = sum;
        }

        int beam = 0;
        int prevBeam = temp[0];

        for(int i=1;i<n;i++){
            if(temp[i] == 0) continue;
            beam += (prevBeam * temp[i]);
            prevBeam = temp[i];
        }

        return beam;
        
    }
};
