#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

int main() {

    string complete_input;
    getline(cin, complete_input, '\0');
    
    stringstream string_input(complete_input);
    string line;

    bool isLeftQuote = true;
    while (getline(string_input, line, '\n')) {
        for (int i = 0; i < line.size(); i++) {
            if (line[i] == '\"') {
                if (isLeftQuote) {
                    printf("``");
                } else {
                    printf("''");
                }
                isLeftQuote = !isLeftQuote;
            } else {
                printf("%s", line[i]);
            }
        }
        printf("\n");
    }

    return 0;
}