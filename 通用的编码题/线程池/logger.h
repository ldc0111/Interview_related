/*************************************************************************
	> File Name: logger.h
	> Author: 
	> Mail: 
	> Created Time: 2020年03月22日 星期日 20时26分35秒
 ************************************************************************/

#ifndef _LOGGER_H
#define _LOGGER_H
#include <iostream>
#include <sstream>
#include <map>

#define LOG_TRACE(level) logger::log(__FILE__,__func__,__LINE__,level)
#define LOG_INFO LOG_TRACE(logger::INFO)
#define LOG_DEBUG LOG_TRACE(logger::DEBUG)
#define LOG_WARN LOG_TRACE(logger::WARN)
#define LOG_ERROR LOG_TRACE(logger::ERROR)
#define LOG_SET(levels) logger::log.set_val(levels)

namespace logger{


const int INFO = 1;
const int DEBUG = 2;
const int WARN = 4;
const int ERROR = 8;
std::map<int, std::string> LogLevelStr = {
   {INFO, "INFO"},       
   {DEBUG, "DEBUG"},       
   {WARN, "WARN"},       
   {ERROR, "ERROR"},       
};

class Logger{
    private:

    class LoggerStream : public std::ostringstream{
        public:
        LoggerStream(const char * file_name,
                     const char * func_name,
                     int line_no,
                     Logger & raw_obj,
                     int l): raw_obj(raw_obj),line_no(line_no){
            std::ostringstream &now = *this;
            now << "[" << file_name << " project]";
            now << " [" << func_name << "]";
            now << " [" << LogLevelStr[l] << "] ";
            flag = raw_obj.logger_level_conf & l;
        }
        LoggerStream(const LoggerStream &ls):raw_obj(ls.raw_obj){}
        ~LoggerStream(){
            if (flag){
                std::unique_lock<std::mutex> lock(raw_obj.m_mutex);
                std::ostringstream &now = *this;
                now << "(" << line_no << ")";
                std::cout << this->str() << std::endl;
                std::cout.flush();
            }
        }
        private:
        Logger &raw_obj;
        int line_no,flag = 1;
    };


    public:
    LoggerStream operator()(const char *file_name, const char *func_name, int line_no, int l) {
        return LoggerStream(file_name, func_name, line_no, *this, l);
    }
    void set_val(int levels){
        logger_level_conf = levels;
    }

    private:
    int logger_level_conf = 15;
    std::mutex m_mutex;
};
Logger log;
}
#endif
