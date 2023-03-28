#include "Header.h"

bool Bool_logics(bool p, bool q, bool r, string expression) {
        vector<bool> values = { p, q, r };

        for (int i = 0; i < expression.length(); i++) {
            if (expression[i] == 'p') {
                expression.replace(i, 1, values[0] ? "1" : "0");
            }
            else if (expression[i] == 'q') {
                expression.replace(i, 1, values[1] ? "1" : "0");
            }
            else if (expression[i] == 'r') {
                expression.replace(i, 1, values[2] ? "1" : "0");
            }
        }

        // Обработка выражений в скобках
        int openBracketIndex = expression.find('(');
        int closeBracketIndex = expression.find(')');

        if (openBracketIndex != string::npos && closeBracketIndex != string::npos) {
            string insideBrackets = expression.substr(openBracketIndex + 1, closeBracketIndex - openBracketIndex - 1);
            bool result = Bool_logics(p, q, r, insideBrackets);

            expression.replace(openBracketIndex, closeBracketIndex - openBracketIndex + 1, result ? "1" : "0");
        }

        // Обработка логических операторов
        string operators = "!^v>=";
        int operatorIndex;

        while ((operatorIndex = expression.find_first_of(operators)) != string::npos) {
            bool result;
            switch (expression[operatorIndex]) {
            case '!':
                result = (expression[operatorIndex + 1] == '0');
                expression.replace(operatorIndex, 2, result ? "1" : "0");
                break;
            case '^':
                result = (expression[operatorIndex - 1] == '1' || expression[operatorIndex + 1] == '1');
                expression.replace(operatorIndex - 1, 3, result ? "1" : "0");
                break;
            case 'v':
                result = (expression[operatorIndex - 1] == '1' && expression[operatorIndex + 1] == '1');
                expression.replace(operatorIndex - 1, 3, result ? "1" : "0");
                break;
            case '>':
                result = (expression[operatorIndex - 1] == '0' || expression[operatorIndex + 1] == '1');
                expression.replace(operatorIndex - 1, 3, result ? "1" : "0");
                break;
            case '=':
                result = (expression[operatorIndex - 1] == expression[operatorIndex + 1]);
                expression.replace(operatorIndex - 1, 3, result ? "1" : "0");
                break;
            }
        }

        return (expression == "1");
    }

