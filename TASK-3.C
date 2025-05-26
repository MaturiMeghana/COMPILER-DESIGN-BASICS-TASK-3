#include <stdio.h>
#include <string.h>
#include <ctype.h>

char keywords[32][10] = {
    "auto", "break", "case", "char", "const", "continue", "default",
    "do", "double", "else", "enum", "extern", "float", "for", "goto",
    "if", "int", "long", "register", "return", "short", "signed",
    "sizeof", "static", "struct", "switch", "typedef", "union",
    "unsigned", "void", "volatile", "while"
};


int isKeyword(char *word) {
    for (int i = 0; i < 32; i++) {
        if (strcmp(word, keywords[i]) == 0)
            return 1;
    }
    return 0;
}


int isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' ||
           ch == '=' || ch == '<' || ch == '>' || ch == '!';
}

int main() {
    char code[] = "int main() { int a = 5; float b = 6.2; if (a < b) { a = a + 1; } return 0; }";
    char buffer[100];
    int i = 0;

    printf("Lexical Tokens Found:\n\n");

    for (int j = 0; code[j] != '\0'; j++) {
        char ch = code[j];

        if (isalnum(ch) || ch == '_') {
            buffer[i++] = ch;
        } else {
            if (i != 0) {
                buffer[i] = '\0';
                if (isKeyword(buffer))
                    printf("Keyword\t\t: %s\n", buffer);
                else
                    printf("Identifier\t: %s\n", buffer);
                i = 0;
            }

            if (isOperator(ch)) {
           
                if ((ch == '=' || ch == '<' || ch == '>' || ch == '!') && code[j + 1] == '=') {
                    printf("Operator\t: %c%c\n", ch, code[j + 1]);
                    j++; // skip next character
                } else {
                    printf("Operator\t: %c\n", ch);
                }
            }
        }
    }

    return 0;
}
