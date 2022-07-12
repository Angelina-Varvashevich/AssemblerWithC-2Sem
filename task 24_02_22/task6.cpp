#include "task6.h"
#include "StackOnList.h"

Calculate::TypeOfToken Calculate::GetTokenType(const std::string &token) {
    if (token == "max") return Calculate::TypeOfToken::MAX;
    else if (token == "min") return Calculate::TypeOfToken::MIN;
    else if (token == "(") return Calculate::TypeOfToken::OPENBR;
    else if (token == ")") return Calculate::TypeOfToken::CLOSEBR;
    else if (token == ",") return Calculate::TypeOfToken::COMMA;
    else return Calculate::TypeOfToken::NUMBER;
}

std::vector<Calculate::Token>
Calculate::TransformToTokens(const std::string &expression) {
    std::vector<Calculate::Token> string_to_tokens;
    std::stringstream read(expression);
    std::string item;
    while (read >> item) {
        Calculate::TypeOfToken type = Calculate::GetTokenType(item);
        Calculate::Token tk(type, item);
        string_to_tokens.push_back(tk);
    }
    return string_to_tokens;
}

std::queue<Calculate::Token> Calculate::TransformExpression(const std::vector<Calculate::Token> &string_to_tokens) {
   StackOnList<Calculate::Token> op_stack;
    std::queue<Calculate::Token> output_string;
    for (int i = 0; i < string_to_tokens.size(); ++i) {
        Calculate::Token tk(string_to_tokens[i]);
        if (tk.type == Calculate::NUMBER) output_string.push(tk);
        else if (tk.type == Calculate::MAX || tk.type == Calculate::MIN) op_stack.Push(tk);
        else if (tk.type == Calculate::COMMA) {
            while (!op_stack.Empty() && op_stack.Top().type != Calculate::OPENBR) {
                output_string.push(op_stack.Top());
                op_stack.Pop();
            }
        } else if (tk.type == Calculate::OPENBR) op_stack.Push(tk);
        else if (tk.type == Calculate::CLOSEBR) {
            while (!op_stack.Empty() && op_stack.Top().type != Calculate::OPENBR) {
                output_string.push(op_stack.Top());
                op_stack.Pop();
            }
            op_stack.Pop();
            if (!op_stack.Empty()) {
                if (op_stack.Top().type == Calculate::MIN || op_stack.Top().type == Calculate::MAX) {
                    output_string.push(op_stack.Top());
                    op_stack.Pop();
                }
            }
        }
    }
    while (!op_stack.Empty()) {
        output_string.push(op_stack.Top());
        op_stack.Pop();
    }
    return output_string;
}

int Calculate::Result(std::queue<Calculate::Token> &output_string) {
    std::stack<int> result;
    while (!output_string.empty()) {
        if (output_string.front().type == Calculate::NUMBER) result.push(std::stoi(output_string.front().value));
        else if (output_string.front().type == Calculate::MIN) {
            int a = result.top();
            result.pop();
            int b = result.top();
            result.pop();
            result.push(std::min(a, b));
        } else if (output_string.front().type == Calculate::MAX) {
            int a = result.top();
            result.pop();
            int b = result.top();
            result.pop();
            result.push(std::max(a, b));
        }
        output_string.pop();
    }
    return result.top();
}
