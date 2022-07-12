#include "ExpressionCalculator.h"




bool IsNumber(char c) {
  return c >= '0' && c <= '9';
}

std::string ExpressionCalculator::ReadToken(const std::string &expression, int &pos) {
  if (expression[pos] == '(' || expression[pos] == ')' || expression[pos] == ',')
    return std::string(1, expression[pos]);
  if (expression[pos] == ' ')
    ++pos;
  std::string token;
  for (; pos < expression.length(); ++pos) {
    if (expression[pos] == '(' || expression[pos] == ')'  || expression[pos] == ',') {
      --pos;
      return token;
    } else if (expression[pos] == ' ')
      return token;
    else
      token.push_back(expression[pos]);
    if (token.length() == 1 && IsNumber(token[0]))
      return token;
  }
  return token;
}

ExpressionCalculator::TokenType ExpressionCalculator::GetTokenType(const std::string &token) {
  if (token == "max") {
    return kMax;
  } else if (token == "min") {
    return kMin;
  } else if (token == "(") {
    return kOpeningBracket;
  } else if (token == ")")
    return kCloseBracket;
  else if (token == ",")
    return kComma;
  else return kNumber;
}

std::queue<ExpressionCalculator::Token> ExpressionCalculator::ProcessExpression(const std::vector<Token> &tokens) {
  std::stack<Token> stack;
  std::queue<Token> out_string;
  for (int i = 0; i < tokens.size(); ++i) {
    Token t = tokens[i];
    if (t.type_ == kNumber) {
      out_string.push(t);
    } else if (t.type_ == kMin || t.type_ == kMax) {
      stack.push(t);
    } else if (t.type_ == kComma) {
      while (!stack.empty() && stack.top().type_ != kOpeningBracket) {
        PushStackTopToOutString(stack, out_string);
      }
    } else if (t.type_ == kOpeningBracket) {
      stack.push(t);
    } else if (t.type_ == kCloseBracket) {
      while (stack.top().type_ != kOpeningBracket) {
        PushStackTopToOutString(stack, out_string);
      }
      stack.pop();
      if (!stack.empty()) {
        if (stack.top().type_ == kMin || stack.top().type_ == kMax) {
          PushStackTopToOutString(stack, out_string);
        }
      }
    }
  }
  while (!stack.empty()) {
    PushStackTopToOutString(stack, out_string);
  }
  return out_string;
}

int ExpressionCalculator::CalculateExpression(std::queue<Token>& out_string) {
  std::stack<int> numbers_;
  while (!out_string.empty()) {
    if (out_string.front().type_ == kNumber) {
      numbers_.push(std::stoi(out_string.front().value));
      out_string.pop();
    } else if (out_string.front().type_ == kMin) {
      int a = numbers_.top(); numbers_.pop();
      int b = numbers_.top(); numbers_.pop();
      numbers_.push(std::min(a, b));
      out_string.pop();
    } else if (out_string.front().type_ == kMax) {
      int a = numbers_.top(); numbers_.pop();
      int b = numbers_.top(); numbers_.pop();
      numbers_.push(std::max(a, b));
      out_string.pop();
    }
  }
  return numbers_.top();
}
