#ifndef BOOLEANS_CPP
#define BOOLEANS_CPP

#include <cstdio>
#include <cstring>
#include <cctype>
#include <fstream>

bool static isEmptyOrSpaces(const char* str) {
    while (*str) {
        if (!isspace((unsigned char)*str)) {
            return false;
        }
        str++;
    }
    return true;
}

extern bool b_isStarted;

bool CheckFileAndContinueToNextPhase(const char* Filename, const char ExpectedPhrase) {
    std::ifstream file(Filename);
    if (!file) 
        return false; // file doesn't exist

    std::string FileContent;
    std::

}

#endif // !BOOLEANS_CPP
