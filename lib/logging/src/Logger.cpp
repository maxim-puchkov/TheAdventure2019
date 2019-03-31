#include "Logger.h"
#include <boost/log/core.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/utility/setup/file.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>

using logger::Logger;


Logger::Logger() {}

void Logger::init() {
	
	boost::log::core::get()->add_global_attribute(
    	"TimeStamp", boost::log::attributes::local_clock()
    );

	boost::log::register_simple_formatter_factory<boost::log::trivial::severity_level, char>("Severity");

    boost::log::add_file_log (
        boost::log::keywords::file_name = "adventure2019.log",
        boost::log::keywords::auto_flush = true,
        boost::log::keywords::format = "[%TimeStamp%] [%Severity%] %Message%"
    ); 
}


void Logger::write(Logger::LOG_TYPE type, std::string& message) {
	switch(type) {
		case Logger::LOG_TYPE::DEBUG:
			BOOST_LOG_TRIVIAL(debug) << message;
			break;
		case Logger::LOG_TYPE::INFO:
			BOOST_LOG_TRIVIAL(info) << message;
			break;
		case Logger::LOG_TYPE::ERROR:
			BOOST_LOG_TRIVIAL(error) << message;
			break;
	}
}


