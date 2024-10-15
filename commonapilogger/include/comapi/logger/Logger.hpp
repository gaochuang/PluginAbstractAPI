#ifndef COMMON_LOG_HPP_
#define COMMON_LOG_HPP_

#include <plugin/Plugin.hpp>

#include <memory>
#include <string>
#include <syslog.h>

namespace commonApi
{
    class ComAPIEventLoop;
    namespace logger
    {
        class Logger: public Plugin
        {
        public:
            virtual void write(int priority, const char* msg, size_t size) = 0;
            virtual void writeAsync(int priority, const char* msg, size_t size) = 0;
            virtual void waitAllWriteAndCompleted() = 0;

            virtual ~Logger() = default;

            //ident < 49 characters
            static std::shared_ptr<Logger> create(std::shared_ptr<commonApi::ComAPIEventLoop> com, const std::string& ident, int facility);
        
        protected:
            Logger() = default;
        };
    }

}

#endif
