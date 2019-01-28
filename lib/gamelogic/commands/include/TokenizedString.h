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
#include <iostream>
#include <sstream>


using std::vector;
using std::string;
using std::regex;
using std::sregex_token_iterator;


const string EMPTY_STR_TOKEN = "";
const string WHITESPACE = " ";


/**
 *  @class TokenizedString
 *
 *  @brief Every word is a token
 *
 *  Breaks up strings at whitespaces. Can be improved
 *  to help parsing complex commands.
 */
class TokenizedString {
public:
    
    TokenizedString(const string &text);
    
    TokenizedString(string &&text);
    
    bool isFinished();
    
    string nextToken();
    
    vector<string> nextTokens(int count);
    
    string split();
    
private:
    
    string source;
    
    sregex_token_iterator tokenIterator;
    
    sregex_token_iterator end;
    
    regex not_whitespace = regex("[^\\s]+");
    
    void tokenize();
    
    void advance();
    
};

#endif /* TokenizedString_h */
