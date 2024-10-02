#include<iostream>
#include<string>
#define MAXSIZE 100
using namespace std;
typedef char Elemtype;
typedef struct {
    Elemtype data[MAXSIZE];
    int top = -1;// 栈顶指针
}Stack;
Stack syntaxStack;// 运算符栈
Stack numberStack;// 数字栈
/*
总览：这个代码就是对之前大一下的时候写的四则运算代码的一个回顾和改进，记大一的时候的第一个提交版本是1.0版本，现在先改一个1.1版本来
这个1.1版本，要求自己能对照着已有的算法自己尽最大可能独立写出来代码，包括优先级比较的部分，以此真正实现理解和掌握算法。
为了实现这个要求特地设置的和1.0版本不同，之前那个版本里最后以一个#结尾，但是这个版本不许这么搞。想办法处理输入输出。
1.1版本先做整数的吧，暂不考虑小数了，对于浮点数的支持放到1.2版本里来迭代。
另外也先假设所有的输入都是合法合规的。关于不合法的输入，放到1.2版本来迭代
*/

void push(Stack *s, Elemtype e) {
    // 栈满则不能继续压栈
    if (s->top == MAXSIZE - 1) {
        return;
    }
    // 入栈,并指针+1
    s->data[s->top++] = e;
}
Elemtype pop(Stack *s) {
    // 栈空则不能出栈
    if (s->top == -1) {
        return -999.0;
    }
    // 返回出栈元素并指针-1
    return s->data[s->top--];
}
bool isEmpty(Stack *s) {
    return s->top == -1;
}
Elemtype getTop(Stack *s) {
    if (!isEmpty(s)) {
        return s->data[s->top];
    }
}
char compareBetweenTopAndCurrent(char stackTop, char current) {
    // 优先级：( 大于 */ 大于 +- 大于 )
    switch (current) {
    case '(':
        return '<';
        break;
    case '+':
    case '-':
        if (stackTop == '+' || stackTop == '-' || stackTop == ')') {
            return '>';
            break;
        } else {
            return '<';
            break;
    }
    case '*':
    case '/':
        if (stackTop == ')') {
            return '<';
            break;
        } else {
            return '>';
            break;
        }
    case ')':
        return '>';
        break;
    }
}
int calculate(int firstNum, char op, int secondNum) {
    switch (op) {
    case '+':
        return firstNum + secondNum;
        break;
    case '-':
        return firstNum - secondNum;
        break;
    case '*':
        return firstNum * secondNum;
        break;
    case '/':
        return firstNum / secondNum;
        break;
    }
}
bool isNumber(char c) {
    return c >= '0' && c <= '9';
}
bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}
bool isLeftBracket(char c) {
    return c == '(';
}
void solveQuestion() {
    string expressionString = string();
    getline(cin, expressionString);
    for (int i = 0; i < expressionString.length(), i++) {
        char currentChar = expressionString[i];
        // 遇到操作数时
        if (isNumber(currentChar)) {
            push(&numberStack, currentChar);
        } else if (isOperator(currentChar)) {
            // 遇到运算符时
            if (isEmpty(&numberStack) || getTop(&numberStack) == '(') {
                push(syntaxStack, currentChar);
            }
        }
    }
}
int main() {
    solveQuestion();
    return 0;
}
