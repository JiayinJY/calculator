#include <string>
#include <stack>

#include "eval.h"

bool isNumOrDot(std::string_view str, std::size_t index) {
    return (index < str.size() and (('0' <= str[index] and str[index] <= '9') or str[index] == '.'));
}


double getNum(std::string_view str, std::size_t& index) {
    double num = 0;
    std::string str2;
    while (isNumOrDot(str, index)){
        str2.push_back(str[index]);
        ++index;
    }
    num = std::stod(str2);
    return num;
}

char ordertable[7][7] = {
           //'#' '(' ')' '+' '-' '*' '/'
    /*'#'*/ {'e','l','l','l','l','l','l'},
    /*'('*/ {'e','l','e','l','l','l','l'},
    /*')'*/ {'e','e','e','l','l','l','l'},
    /*'+'*/ {'g','l','g','g','g','l','l'},
    /*'-'*/ {'g','l','g','g','g','l','l'},
    /*'*'*/ {'g','l','g','g','g','g','g'},
    /*'/'*/ {'g','l','g','g','g','g','g'}
};

std::int32_t charactor2Number(char c) {
    switch (c) {
        case '#': return 0; break;
        case '(': return 1; break;
        case ')': return 2; break;
        case '+': return 3; break;
        case '-': return 4; break;
        case '*': return 5; break;
        case '/': return 6; break;
        default: break;
    }
    return -1;
}

std::int32_t checkOrder(char instack, char outstack) {
    int a = charactor2Number(instack);
    int b = charactor2Number(outstack);
    return ordertable[a][b];
}

double compute(double num1, char op, double num2) {
    switch (op) {
        case '+': return num2 + num1; break;
        case '-': return num2 - num1; break;
        case '*': return num2 * num1; break;
        case '/': return num2 / num1; break;
        default: break;
    }
    return 0;
}

double Eval(std::string str) {
    std::stack<char> ops;
    std::stack<double> nums;

    ops.push('#');
    str.push_back('#');

    char ch{};
    std::size_t index = 0;
    while (!ops.empty()) {
        if (index < str.size()) ch = str[index];

        if ('0' <= ch && ch <= '9') {
            nums.push(getNum(str, index));
        }
        else switch (ch) {
            case '/': [[fallthrough]];
            case '(': [[fallthrough]];
            case ')': [[fallthrough]];
            case '+': [[fallthrough]];
            case '-': [[fallthrough]];
            case '*': [[fallthrough]];
            case '#':
                switch (checkOrder(ops.top(), ch)) {
                    case 'l': ops.push(ch); ++index; break;
                    case 'e': ops.pop();    ++index; break;
                    case 'g':{
                        double lhs = nums.top(); nums.pop();
                        double rhs = nums.top(); nums.pop();
                        char    op  = ops.top();  ops.pop();
                        nums.push(compute(lhs, op, rhs));
                        break;
                    }
                    default: break;
                }
                break;
            default: ++index; break;
        }
    }
    return nums.top();
}
