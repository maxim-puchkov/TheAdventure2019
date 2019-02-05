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


using std::vector;
using std::string;
using std::istream_iterator;
using std::istringstream;


using arguments = const vector<string>&;
using script = std::function<void(arguments)>;


/**
 *  @class ScriptParser
 *
 *  @brief Parses scripts and local input.
 *
 *  Parses and validates string input structure.
 */
class ScriptParser {
public:
    
    ScriptParser();
    
    ~ScriptParser();
    
    void parseScript(string &&input, Environment<string, script> &&env) const noexcept(false);
    
    // void createCommand(const string &name, command function);
    
private:
    
    // static void init(ScriptParser *p);
    
    // Environment<string, command> env;
    
};
