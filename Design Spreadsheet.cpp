class Spreadsheet {
public:
    vector<vector<int>> spreadsheet;
    Spreadsheet(int rows) {
        spreadsheet = vector<vector<int>>(rows, vector<int>(26, 0));
    }

    void setCell(string cell, int value) {
        int col = cell[0] - 'A';
        int row = stoi(cell.substr(1));
        spreadsheet[row-1][col] = value;
    }

    void resetCell(string cell) {
        int col = cell[0] - 'A';
        int row = stoi(cell.substr(1));

        spreadsheet[row-1][col] = 0;
    }

    int getValue(string formula) {
            
        if (!formula.empty() && formula[0] == '=')
            formula = formula.substr(1); // remove '='

        string op1, op2;
        char op = '+';

        // parse op1, op, op2
        size_t i = 0;
        while (i < formula.size() && isalnum(formula[i])) op1 += formula[i++];
        if (i < formula.size()) op = formula[i++];
        while (i < formula.size()) op2 += formula[i++];

        // evaluate first operand (cell or number)
        int first;
        if (isalpha(op1[0])) {
            int col1 = op1[0] - 'A';
            int row1 = stoi(op1.substr(1));
            first = spreadsheet[row1 - 1][col1];
        } else {
            first = stoi(op1);
        }

        // evaluate second operand (cell or number)
        int second;
        if (isalpha(op2[0])) {
            int col2 = op2[0] - 'A';
            int row2 = stoi(op2.substr(1));
            second = spreadsheet[row2 - 1][col2];
        } else {
            second = stoi(op2);
        }

        
        return first + second;
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */
