#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 101
char a[MAX_SIZE];
int top = -1;

void push(char ele) {
    if (top < MAX_SIZE - 1) {  // Corrected condition
        a[++top] = ele;
    } else {
        printf("Stack is full. Cannot push: %c\n", ele);  // Changed %d to %c
    }
}

int pop() {
    if (top >= 0) {
        return a[top--];
    } else {
        printf("Stack is empty. Cannot pop.\n");
        return -1; // Return an error value when stack is empty
    }
}

int isEmpty() {
    return top == -1;
}

char* decimalToBinary(int decimal) {
    char* ans = (char*)malloc(33 * sizeof(char));  // Allocate memory for 32 bits + null terminator
    if (!ans) {
        printf("Memory allocation failed.\n");
        exit(1);  // Exit if allocation fails
    }

    int i = 0;
    if (decimal == 0) {
        ans[i++] = '0';
    } else {
        while (decimal > 0) {
            push((decimal % 2) + '0');
            decimal /= 2;
        }

        while (!isEmpty()) {
            ans[i++] = pop();
        }
    }
    ans[i] = '\0'; // Null-terminate the string
    return ans;
}

int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        int decimal;
        scanf("%d", &decimal);
        char* ans = decimalToBinary(decimal);

        if (ans) {
            printf("%s\n", ans);
            free(ans);  // Free allocated memory
        }
    }

    return 0;
}