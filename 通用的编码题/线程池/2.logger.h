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
namespace logger{

class Logger{
    private:
    class loggerstream : public std::ostringstream{
        public:
        loggerstream(){}
        loggerstream(const loggerstream &ls){}
        ~loggerstream(){
            //std::unique_lock<std::mutex> lock(m_mutex);
            std::cout << this->str();
        }
        private:
    };


    public:
    loggerstream operator()(){
        return loggerstream();
    }
};
}
#endif
