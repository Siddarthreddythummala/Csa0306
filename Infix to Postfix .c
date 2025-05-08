#include <stdio.h>
#include <ctype.h>

#define size 100
char stack[size];
int top = -1;

void push(char ch) {
    stack[++top] = ch;
}

char pop() {
    if (top == -1) return '\0';
    return stack[top--];
}

char peek() {
    if (top == -1) return '\0';
    return stack[top];
}

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

void infixToPostfix(char* infix) {
    char ch, postfix[size];
    int i = 0, j = 0;

    while ((ch = infix[i++]) != '\0') {
        if (isalnum(ch)) {
            postfix[j++] = ch;
        } else if (ch == '(') {
            push(ch);
        } else if (ch == ')') {
            while (peek() != '(') {
                postfix[j++] = pop();
            }
            pop(); // remove '('
        } else {
            while (top != -1 && precedence(peek()) >= precedence(ch)) {
                postfix[j++] = pop();
            }
            push(ch);
        }
    }

    while (top != -1) {
        postfix[j++] = pop();
    }

    postfix[j] = '\0'; 
    printf("Postfix: %s\n", postfix);
}

int main() {
    char infix[size];
    printf("Enter the infix expression: ");
    scanf("%s", infix);
    infixToPostfix(infix);
    return 0;
}
