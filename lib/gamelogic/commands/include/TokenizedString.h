/////////////////////////////////////////////////////////////////////////////
//                              TokenizedString
//
// This file is distributed under the MIT License. See the LICENSE file
// for details.
/////////////////////////////////////////////////////////////////////////////

#ifndef TokenizedString_h
#define TokenizedString_h

#include <vector>
#include <string>
#include <regex>

using std::vector;
using std::string;
using std::regex;
using std::sregex_token_iterator;

const string EMPTY_STR_TOKEN = "";

/**
 *  @class TokenizedString
 *
 *  @brief Every word is a token
 */
class TokenizedString {
public:
    
    TokenizedString(const string &&text)
    : original(std::move(text)) {
        this->tokenIterator = sregex_token_iterator(original.begin(), original.end(), not_whitespace);
    }
    
    bool isFinished() {
        return this->tokenIterator == this->end;
    }
    
    void advance() {
        this->tokenIterator++;
    }
    
    string nextToken() {
        if (!this->isFinished()) {
            string token = this->tokenIterator->str();
            this->advance();
            return token;
        }
        return EMPTY_STR_TOKEN;
    }
    
    vector<string> nextTokens(int count) {
        vector<string> tokens;
        for (int i = 0; i < count; i++) {
            tokens.push_back(this->nextToken());
        }
        return tokens;
    }
    
private:
    
    sregex_token_iterator tokenIterator;
    
    sregex_token_iterator end = sregex_token_iterator();
    
    string original;
    
    regex not_whitespace = regex("[^\\s]+");
    
};

#endif /* TokenizedString_h */
