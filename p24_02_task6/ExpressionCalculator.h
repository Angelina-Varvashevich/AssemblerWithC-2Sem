#ifndef P24_02_T6__EXPRESSIONCALCULATOR_H_
#define P24_02_T6__EXPRESSIONCALCULATOR_H_

#include <string>
#include <stack>
#include <iostream>
#include <queue>
#include <vector>


bool IsNumber(char c);

class ExpressionCalculator {
  enum TokenType {
    kMin, kMax, kNumber, kOpeningBracket, kCloseBracket, kComma
  };
  struct Token {
    std::string value;
    TokenType type_;
  };

  struct StackAndQueue {
    std::stack<Token> stack;
    std::queue<Token> out_string;
  };

 public:
  [[nodiscard]] static int Calculate(const std::string &expression) {
    std::vector<Token> tokens = SplitExpressionIntoTokens(expression);

    std::queue<Token> processionResult = ProcessExpression(tokens);
    return CalculateExpression(processionResult);
  };
 private:
  static std::vector<Token> SplitExpressionIntoTokens(const std::string& expression) {
    std::vector<Token> result;
    for (int i = 0; i < expression.length(); ++i) {
      std::string token = ReadToken(expression, i);
      result.push_back(Token{token, GetTokenType(token)});
    }
    return result;
  }
  static int CalculateExpression(std::queue<Token>& input);
  static std::queue<Token> ProcessExpression(const std::vector<Token> &tokens);
  static std::string ReadToken(const std::string &expression, int &pos);
  static TokenType GetTokenType(const std::string &token);
};

template<typename T>
void PushStackTopToOutString(std::stack<T>& stack, std::queue<T> queue) {
  queue.push(stack.top());
  stack.pop();
}

#endif //P24_02_T6__EXPRESSIONCALCULATOR_H_
