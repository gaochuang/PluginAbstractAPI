#ifndef COMMON_API_LOGGER_PLUGIN_HPP_
#define COMMON_API_LOGGER_PLUGIN_HPP_

#include <string>

#include <plugin/Defines.hpp>
#include "logger/Logger.hpp"
#include "logger/Parameter.hpp"

#define COMMONAPI_LOGGER_PLUGIN_CREATOR_NAME commonapi_logger_create_plugin

#define COMMONAPILOGGER_PLUGIN_CREATOR_NAME_STR COMMONAPI_XSTR(COMMONAPI_LOGGER_PLUGIN_CREATOR_NAME)

#define COMMONAPILOGGER_PLUGIN_CREATOR_IMPL_NAME COMMONAPI_MAKE_CREATOR_IMPL_NAME(COMMONAPI_LOGGER_PLUGIN_CREATOR_NAME)

COMMONAPI_DECLARE_PLUGIN_CREATOR_WITH_ARGS(::commonApi::logger::Logger,
                                        COMMONAPI_LOGGER_PLUGIN_CREATOR_NAME,
                                        _services,
                                        const ::commonApi::logger::Parameters& params);


#define COMMONAPI_DEFINE_LOGGER_PLUGIN_CREATOR(_services, _params)                                                        \
    decltype(COMMONAPILOGGER_PLUGIN_CREATOR_IMPL_NAME({}, {}))                                                            \
    COMMONAPI_LOGGER_PLUGIN_CREATOR_NAME(                                                                                 \
       std::shared_ptr<::commonApi::PluginServices> _services,  const void* arg)                                           \
    {                                                                                                                      \
        return COMMONAPILOGGER_PLUGIN_CREATOR_IMPL_NAME(_services, *static_cast<const ::commonApi::logger::Parameters*>(arg));  \
    }                                                                                                                       \
    COMMONAPI_DEFINE_PLUGIN_CREATOR_WITH_ARGS(                                                                             \
        ::commonApi::logger::Logger,                                                                                        \
        COMMONAPILOGGER_PLUGIN_CREATOR_IMPL_NAME,                                                                           \
        _services,                                                                                                          \
        const ::commonApi::logger::Parameters& _params)

#endif
