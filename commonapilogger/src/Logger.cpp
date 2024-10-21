#include "logger/Logger.hpp"
#include "logger/LoggerPlugin.hpp"
#include "logger/Parameter.hpp"

using namespace commonApi::logger;

std::shared_ptr<Logger> Logger::create(std::shared_ptr<commonApi::ComAPIEventLoop> com, const std::string& ident, int facility)
{
    const Parameters parameters = {ident, facility};
    return commonApi::Plugin::create<Logger>(com, COMMONAPILOGGER_PLUGIN_CREATOR_NAME_STR, &parameters);
}
