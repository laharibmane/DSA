#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#define MAX_SIZE 400

struct Stack {
    int maxSize;
    char stackArray[MAX_SIZE];
    int top;
};

void initStack(struct Stack * stack, int size) {
    stack -> maxSize = size;
    stack -> top = -1;
}

void push(struct Stack * stack, char item) {
    if (stack -> top < stack -> maxSize - 1) {
        stack -> stackArray[++stack -> top] = item;
    }
}

char pop(struct Stack * stack) {
    if (stack -> top >= 0) {
        return stack -> stackArray[stack -> top--];
    }
    return ' ';
}

char peek(struct Stack * stack) {
    if (stack -> top >= 0) {
        return stack -> stackArray[stack -> top];
    }
    return ' ';
}

int isEmpty(struct Stack * stack) {
    return stack -> top == -1;
}

int isOperator(char c) {
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^') {
        return 1;
    }
    else return 0;
}
int precedence(char c) {
    if (c == '^') {
        return 3;
    }
    else if (c == '*' || c == '/') {
        return 2;
    }
    else if (c == '-' || c == '+') {
        return 1;
    }
    else return -1;
}
void infixToPostfix(char * infix, char * postfix) {
    int i = 0;
    int j = 0;
    struct Stack * stack = (struct Stack * ) malloc(sizeof(struct Stack));
    initStack(stack,MAX_SIZE);
    
    size_t len = strlen(infix);
    if(infix[len-1] == '\n'){
        infix[len-1] = '\0';
    }

    while (infix[i] != '\0') {
        if (!isOperator(infix[i]) && infix[i]!='(' && infix[i]!=')') {
            postfix[j++] = infix[i++];
        }
        else if(infix[i] == '('){
            push(stack,infix[i]);
        }
        else if(infix[i] == ')'){
            while(!isEmpty(stack) && peek(stack)!='('){
                postfix[j++] = pop(stack);
            }
            pop(stack);
            i++;
        }
        else{
            while(!isEmpty(stack) && precedence(peek(stack)) >= precedence(infix[i])){
                postfix[j++] = pop(stack);
            }
            push(stack,infix[i]);
            i++;
        }
    }
    while(!isEmpty(stack)){
        postfix[j] = pop(stack);
        j++;
    }
    postfix[j] = '\0';
}

int main() {
    int t;
    scanf("%d", & t);
    getchar(); // Consume the newline

    while (t--) {
        char infixExpression[MAX_SIZE];
        char postfixExpression[MAX_SIZE];
        fgets(infixExpression, MAX_SIZE, stdin);
        infixToPostfix(infixExpression, postfixExpression);
        printf("%s\n", postfixExpression);
    }

    return 0;
}
