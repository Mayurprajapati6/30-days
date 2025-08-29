class Solution {
public:
    long long flowerGame(int n, int m) {
        

        long long  n_odd_count = 0;
        long long n_even_count = 0;

        for(int i=1;i<=n;i++){
            i%2 == 0 ? n_even_count++ : n_odd_count++;
        }

        long long m_odd_count = 0;
        long long m_even_count = 0;

        for(int i=1;i<=m;i++){
            i%2 == 0 ? m_even_count++ : m_odd_count++;
        }

        long long first = (n_even_count * m_odd_count);
        long long second = (n_odd_count * m_even_count);

        long long result = first + second;

        return result;
        
    }
};
