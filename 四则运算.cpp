#include<iostream>
#include<string>
#define MAXSIZE 100
using namespace std;
typedef char Elemtype;
typedef struct {
    Elemtype data[MAXSIZE];
    int top = -1;// ջ��ָ��
}Stack;
Stack syntaxStack;// �����ջ
Stack numberStack;// ����ջ
/*
���������������Ƕ�֮ǰ��һ�µ�ʱ��д��������������һ���ع˺͸Ľ����Ǵ�һ��ʱ��ĵ�һ���ύ�汾��1.0�汾�������ȸ�һ��1.1�汾��
���1.1�汾��Ҫ���Լ��ܶ��������е��㷨�Լ��������ܶ���д�������룬�������ȼ��ȽϵĲ��֣��Դ�����ʵ�����������㷨��
Ϊ��ʵ�����Ҫ���ص����õĺ�1.0�汾��ͬ��֮ǰ�Ǹ��汾�������һ��#��β����������汾������ô�㡣��취�������������
1.1�汾���������İɣ��ݲ�����С���ˣ����ڸ�������֧�ַŵ�1.2�汾����������
����Ҳ�ȼ������е����붼�ǺϷ��Ϲ�ġ����ڲ��Ϸ������룬�ŵ�1.2�汾������
*/

void push(Stack *s, Elemtype e) {
    // ջ�����ܼ���ѹջ
    if (s->top == MAXSIZE - 1) {
        return;
    }
    // ��ջ,��ָ��+1
    s->data[s->top++] = e;
}
Elemtype pop(Stack *s) {
    // ջ�����ܳ�ջ
    if (s->top == -1) {
        return -999.0;
    }
    // ���س�ջԪ�ز�ָ��-1
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
    // ���ȼ���( ���� */ ���� +- ���� )
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
        // ����������ʱ
        if (isNumber(currentChar)) {
            push(&numberStack, currentChar);
        } else if (isOperator(currentChar)) {
            // ���������ʱ
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
