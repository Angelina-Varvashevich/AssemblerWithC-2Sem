#ifndef TASK_24_02_22_TASK6_H
#define TASK_24_02_22_TASK6_H

#include <iostream>
#include <vector>
#include <queue>
#include <sstream>
#include <stack>
#include <functional>

class Calculate {
    enum TypeOfToken {
        MIN, MAX, OPENBR, CLOSEBR, COMMA, NUMBER, OTHER
    };

    struct Token {
        std::string value;
        TypeOfToken type;
        bool operator==(const Token& other) { return value == other.value && other.type == type; }
        Token() : type(OTHER), value("X") {};


        explicit Token(TypeOfToken type_, std::string value_) : type(type_), value(std::move(value_)) {}
    };

    static TypeOfToken GetTokenType(const std::string &token);

    static std::vector<Token> TransformToTokens(const std::string &expression);

    static std::queue<Token> TransformExpression(const std::vector<Token> &string_to_tokens);

    static int Result(std::queue<Token> &output_string);

public:
    static int PublicResult(const std::string &expression) {
        std::vector<Token> tokens = TransformToTokens(expression);
        std::queue<Token> output_opz = TransformExpression(tokens);
        return Result(output_opz);
    }
};

#endif //TASK_24_02_22_TASK6_H
