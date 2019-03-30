#define BOOST_LOG_DYN_LINK 1

#include <string>

namespace logger {

class Logger {
public:
  enum class LOG_TYPE : uint8_t {
    DEBUG,
    INFO,
    ERROR
  };

  Logger();
  void init();
  void write(LOG_TYPE type, std::string& message);
};

}
