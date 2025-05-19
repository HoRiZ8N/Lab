#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <unordered_map>
#include <cctype>
#include <stdexcept>

std::unordered_map<std::string, int> PRIORITY = {
    {"!", 5},
    {"<", 4}, {">", 4}, {"<=", 4}, {">=", 4}, {"==", 4}, {"!=", 4},
    {"&&", 3},
    {"||", 2},
    {"(", 1}
};

std::vector<std::string> tokenize(const std::string& expr) {
    std::vector<std::string> tokens;
    for (size_t i = 0; i < expr.size();) {
        if (isspace(expr[i])) { 
            i++; 
            continue; 
        }

        // Многосимвольные операторы
        if (i + 1 < expr.size()) {
            std::string op2 = std::string(1, expr[i]) + expr[i+1];
            if (op2 == "&&" || op2 == "||" || op2 == "==" || op2 == "!=" || op2 == "<=" || op2 == ">=") {
                tokens.push_back(op2);
                i += 2;
                continue;
            }
        }

        // Одиночные символы
        std::string op1(1, expr[i]);
        if (op1 == "(" || op1 == ")" || op1 == "!" || op1 == "<" || op1 == ">") {
            tokens.push_back(op1);
            i++;
            continue;
        }

        // Числа (включая отрицательные)
        if (isdigit(expr[i]) || (expr[i] == '-' && (i == 0 || expr[i-1] == '('))) {
            std::string num;
            if (expr[i] == '-') {
                num += '-';
                i++;
            }
            while (i < expr.size() && isdigit(expr[i])) {
                num += expr[i];
                i++;
            }
            tokens.push_back(num);
            continue;
        }

        // Булевы константы
        if (expr.substr(i, 4) == "true") {
            tokens.push_back("true");
            i += 4;
            continue;
        } else if (expr.substr(i, 5) == "false") {
            tokens.push_back("false");
            i += 5;
            continue;
        }

        throw std::invalid_argument("Неизвестный символ: " + std::string(1, expr[i]));
    }
    return tokens;
}

// Преобразование в ОПН
std::vector<std::string> converToRpn(const std::vector<std::string>& tokens) {
    std::vector<std::string> output;
    std::stack<std::string> opStack;

    for (const std::string& token : tokens) {
        if (token == "true" || token == "false" || isdigit(token[0]) || (token.size() > 1 && isdigit(token[1]))) {
            output.push_back(token);
        } else if (token == "(") {
            opStack.push(token);
        } else if (token == ")") {
            while (!opStack.empty() && opStack.top() != "(") {
                output.push_back(opStack.top());
                opStack.pop();
            }
            if (opStack.empty()) throw std::logic_error("Несбалансированные скобки");
            opStack.pop(); // Удалить '('
        } else {
            while (!opStack.empty() && 
                   PRIORITY[opStack.top()] >= PRIORITY[token]) {
                output.push_back(opStack.top());
                opStack.pop();
            }
            opStack.push(token);
        }
    }

    while (!opStack.empty()) {
        if (opStack.top() == "(") throw std::logic_error("Несбалансированные скобки");
        output.push_back(opStack.top());
        opStack.pop();
    }

    return output;
}

// Вычисление ОПН
bool evaluate_rpn(const std::vector<std::string>& rpn) {
    std::stack<bool> val_stack;
    std::stack<int> nums;

    for (const auto& token : rpn) {
        if (token == "true") {
            val_stack.push(true);
        } else if (token == "false") {
            val_stack.push(false);
        } else if (isdigit(token[0]) || (token[0] == '-' && isdigit(token[1]))) {
            nums.push(stoi(token));
        } else {
            // Обработка операций сравнения
            if (token == "<" || token == ">" || token == "<=" || 
                token == ">=" || token == "==" || token == "!=") {
                if (nums.size() < 2) throw std::logic_error("Недостаточно операндов");
                int b = nums.top(); nums.pop();
                int a = nums.top(); nums.pop();
                
                if (token == "<") val_stack.push(a < b);
                else if (token == ">") val_stack.push(a > b);
                else if (token == "<=") val_stack.push(a <= b);
                else if (token == ">=") val_stack.push(a >= b);
                else if (token == "==") val_stack.push(a == b);
                else if (token == "!=") val_stack.push(a != b);
            } 
            // Логические операции
            else {
                if (token == "!") {
                    if (val_stack.empty()) throw std::logic_error("Недостаточно операндов");
                    bool a = val_stack.top(); val_stack.pop();
                    val_stack.push(!a);
                } else {
                    if (val_stack.size() < 2) throw std::logic_error("Недостаточно операндов");
                    bool b = val_stack.top(); val_stack.pop();
                    bool a = val_stack.top(); val_stack.pop();
                    if (token == "&&") val_stack.push(a && b);
                    else if (token == "||") val_stack.push(a || b);
                }
            }
        }
    }

    if (val_stack.size() != 1 || !nums.empty()) 
        throw std::logic_error("Ошибка в выражении");
    return val_stack.top();
}

int main() {
    try {
        std::string expr = "!(5 > 3) && (true || false)";
        std::vector<std::string> tokens = tokenize(expr);
        std::vector<std::string> rpn = converToRpn(tokens);
        bool result = evaluate_rpn(rpn);
        std::cout << std::boolalpha << result << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return 0;
}