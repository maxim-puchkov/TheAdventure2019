/////////////////////////////////////////////////////////////////////////////
//                              TokenizedString
//
// This file is distributed under the MIT License. See the LICENSE file
// for details.
/////////////////////////////////////////////////////////////////////////////

#include "TokenizedString.h"


using std::vector;
using std::string;
using std::regex;
using std::sregex_token_iterator;





TokenizedString::TokenizedString(const string &text)
: source(text) {
    this->tokenize();
}


TokenizedString::TokenizedString(string &&text)
: source(std::move(text)) {
    this->tokenize();
}


bool TokenizedString::isFinished() {
    return this->tokenIterator == this->end;
}


string TokenizedString::nextToken() {
    if (!this->isFinished()) {
        string token = this->tokenIterator->str();
        this->advance();
        return token;
    }
    return EMPTY_STR_TOKEN;
}


vector<string> TokenizedString::nextTokens(int count) {
    vector<string> tokens;
    for (int i = 0; i < count; i++) {
        tokens.push_back(this->nextToken());
    }
    return tokens;
}


string TokenizedString::split() {
    std::stringstream result("");
    while (this->tokenIterator != this->end) {
        result << this->nextToken();
        if (!this->isFinished()) {
            result << WHITESPACE;
        }
    }
    return result.str();
}





/* Private */

void TokenizedString::tokenize() {
    this->tokenIterator = sregex_token_iterator(source.begin(), source.end(), not_whitespace);
    this->end = sregex_token_iterator();
}


void TokenizedString::advance() {
    this->tokenIterator++;
}

