/////////////////////////////////////////////////////////////////////////////
//                                  ScriptParser
//
// This file is distributed under the MIT License. See the LICENSE file
// for details.
/////////////////////////////////////////////////////////////////////////////


#include <vector>
#include <string>
#include <sstream>
#include "Environment.h"
#include "Script.h"


using std::vector;
using std::string;
using std::istream_iterator;
using std::istringstream;


using arguments = const vector<string>&;
using function = std::function<void(arguments)>;


const string WHITESPACE = " ";


/**
 *  @class ScriptParser
 *
 *  @brief Parses scripts and local input.
 */
class ScriptParser {
public:
    
    ScriptParser();
    
    vector<string> parseInput(string &&input) const noexcept;
    
    Script parseScript(string &&script, Environment<string, function> &&env) const noexcept(false);
    
};
