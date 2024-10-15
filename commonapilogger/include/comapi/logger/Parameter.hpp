#ifndef COMMON_API_PARAMETER_HPP
#define COMMON_API_PARAMETER_HPP

#include <string>

namespace commonApi
{
    namespace logger
    {
        struct Parameters
        {
            std::string indent;
            int facility;
        };
        
    }
}

#endif
