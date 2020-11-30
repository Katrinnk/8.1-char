#define _CRT_SECURE_NO_WARNINGS 
#include <iostream> 

using namespace std;
bool Count(char* str) {
    char* strTail = str;
    while (true) {
        size_t pos = strcspn(strTail, "BASIC");
        char c = strTail[pos];
        if (c == 0) return false;
        strTail += pos;
        if (strncmp(strTail, "B", 1) == 0 && strncmp(strTail, "A", 1) == 0 && strncmp(strTail, "S", 1) == 0 && strncmp(strTail, "I", 1) && strncmp(strTail, "C", 1))
        {
            return true;
        }
        else {
            strTail++;
        }
    }
}

void Change(char* str, char* newStr) {
    char* strTail = str;
    char* newStrTail = newStr;
    while (true) {

        size_t pos = strcspn(strTail, "BASIC");

        strncpy_s(newStrTail, pos + 1, strTail, pos);

        char c = strTail[pos];
        if (c == 0) break;

        newStrTail += pos;
        strTail += pos;

        if (strncmp(strTail, "B", 2) == 0 && strncmp(strTail, "A", 2) == 0 && strncmp(strTail, "S", 2) == 0 && strncmp(strTail, "I", 2) == 0 && strncmp(strTail, "C", 2) == 0) {
            strncpy_s(newStrTail, 6, "Delphi", 5);
            newStrTail += 6;
            strTail += 5;
        }
        else {
            strncpy_s(newStrTail++, 2, strTail++, 1);
        }
    }
    return;
}

int main() {
    char str[101];
    char newStr[151] = "";

    cout << "Enter string:" << endl;
    cin.getline(str, 100);

    bool changed = Count(str);
    Change(str, newStr);

    cout << "String: " << str << endl << endl;
    if (changed) {
        cout << "String was modified." << endl;
        cout << "Modified string (result): " << newStr << endl;
    }
    else {
        cout << "String was not modified." << endl;
    }

    return 0;
}
