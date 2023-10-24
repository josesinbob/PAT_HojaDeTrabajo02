#include "Ejercicio03.h"

int Ejercicio03::calculate(string s)
{
    if (s.empty()) {
        return 0;
    }

    stack<int> operandStack;
    char currentOperator = '+';

    for (size_t i = 0; i < s.length(); i++) {
        if (s[i] == ' ') {
            continue;
        } else if (isdigit(s[i])) {
            int number = extractNumber(s, i);
            performOperation(operandStack, currentOperator, number);
        } else {
            currentOperator = s[i];
        }
    }

    return calculateResult(operandStack);
}

int extractNumber(const string &s, size_t &i) {
    string numberStr = "";
    while (i < s.length() && isdigit(s[i])) {
        numberStr += s[i];
        i++;
    }
    i--;
    return stoi(numberStr);
}

void performOperation(stack<int> &operandStack, char currentOperator, int number) {
    if (currentOperator == '+') {
        operandStack.push(number);
    } else if (currentOperator == '-') {
        operandStack.push(-number);
    } else if (currentOperator == '*') {
        int previousOperand = operandStack.top();
        operandStack.pop();
        operandStack.push(previousOperand * number);
    } else if (currentOperator == '/') {
        int previousOperand = operandStack.top();
        operandStack.pop();
        operandStack.push(previousOperand / number);
    }
}

int calculateResult(stack<int> &operandStack) {
    int result = 0;
    while (!operandStack.empty()) {
        result += operandStack.top();
        operandStack.pop();
    }
    return result;
}

int main() {
    string s = "3 2 4 * +";
    cout << "Result: " << evaluateExpression(s) << endl;
    return 0;
}
