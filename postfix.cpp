#include <iostream>
#include "linkedStack.h"
#include <string>

std::string getExpression();
std::string infixToPostfix(std::string&);
float evaluatePostfixExpression(std::string);
bool isOperator(char);
bool isGreaterPrecedence(char, char);
bool isEqualPrecendence(char, char);

int main(){
    
    std::string infixForm;
    std::string postfixForm;
    float result;

    infixForm = getExpression();
    postfixForm = infixToPostfix(infixForm);
    result = evaluatePostfixExpression(postfixForm);

    std::cout << "Postfix expression: " << postfixForm << std::endl;

    std::cout << "Result: " << result << std::endl;


    return 0;
}

 std::string getExpression(){
    std::string input;
    std::cout << "Please enter an arithmetic expression" << std::endl;
    std::getline(std::cin, input);

    return input;
}

std::string infixToPostfix(std::string &input){
    char current;
    LinkedStack<char> operatorStack;
    std::string output;
    for(int i = 0; i < input.length(); i++){
        current = input[i];
        if(isOperator(current)){
            if(isGreaterPrecedence(current, operatorStack.peek())){
                output += operatorStack.peek();
                operatorStack.pop();
                operatorStack.push(current);
            }
            else if(isEqualPrecendence(current, operatorStack.peek())){
                output += operatorStack.peek();
                operatorStack.pop();
                operatorStack.push(current);
            }
            else{
                operatorStack.push(current);
            }
        }
        else{
            output += current;
        }
    }

    while(!operatorStack.isEmpty()){
        char expression = operatorStack.peek();
        switch(expression){
                case '+':
                        output += '+';
                break;
                case '-':
                        output += '-';
                break;
                case '*':
                        output += '*';
                break;
                case '/':
                        output += '/';
        }
        operatorStack.pop();
    }

    return output;
}
float evaluatePostfixExpression(std::string input){
    char current;
    LinkedStack<float> operandStack;
    float output = 0;

    for(int i = 0; i < input.length(); i++){
        current = input[i];
        if(!isOperator(current)){
            float newCurrent = (float)(current - '0');
            operandStack.push(newCurrent);
        }
        else{
            float operand_1 = operandStack.peek();
            operandStack.pop();
            float operand_2 = operandStack.peek();
            operandStack.pop();
            char expression = current;
            switch(expression){
                case '+':
                        output = operand_1 + operand_2;
                break;
                  case '-':
                        output = operand_2 - operand_1;
                break;
                case '*':
                        output = operand_1 * operand_2;
                break;
                case '/':
                        output = operand_2 / operand_1;
                break;
            }
            operandStack.push(output);
        }
    }
    output = operandStack.peek();
    operandStack.pop();
    return output;
}
bool isOperator(char c){
    if(c == '+' || c == '-' || c == '*' || c == '/'){
        return true;
    }
    else{
        return false;
    }
}

bool isGreaterPrecedence(char current, char top){
    if(top == '*' || top == '/'){
        if(current == '+' || current == '-'){
            return true;
        }
    }
    return false;
}

bool isEqualPrecendence(char current, char top){
    if(current == '+' || current == '-'){
        if(top == '+' || top == '-'){
            return true;
        }
    }
    else if(current == '*' || current == '/'){
        if(top == '*' || top == '/'){
            return true;
        }
    }
    else{
        return false;
    }
}

