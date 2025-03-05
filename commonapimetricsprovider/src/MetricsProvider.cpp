#include "MetricsProvider.hpp"
#include "MetricsProviderPlugin.hpp"

using namespace commonApi;
using namespace metricsprovider;

std::shared_ptr<MetricsProvider> MetricsProvider::create(std::shared_ptr<commonApi::ComAPIEventLoop> com, const std::string& name)

{
    return commonApi::Plugin::create<MetricsProvider>(com, COMMONAPIMETRICSPROVIDER_PLUGIN_CREATOR_NAME_STR, name.c_str());
}
