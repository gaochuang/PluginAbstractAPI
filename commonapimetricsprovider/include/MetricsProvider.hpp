#ifndef COMMON_API_METRICS_PROVIDER_HPP
#define COMMON_API_METRICS_PROVIDER_HPP

#include "plugin/Plugin.hpp"

#include <string>

namespace commonApi
{
    namespace metricsprovider
    {
        enum class DataType
        {
            FLOAT,
            DOUBLE,
            INT32 ,
            UINT32,
            INT64,
            UINT64
        };

        enum class MetricType
        {
            Counter,
            Gauge,
            Summary,
            Untyped,
            Histogram,
            Info,
        };

        enum class MetricFamilyType
        {
            DDEFAULT,
            Histogram,
            UNKNOW
        };

        struct Attribute
        {
            std::string name;
            std::string value;
        };
        
        struct Metrics
        {

        };

        struct MetricsFamily
        {
        };

        struct  MetricsInfo
        {
        
        };

        struct Sample
        {
        };
    }

    class MetricsProvider : public Plugin
    {
    public:
        static std::shared_ptr<MetricsProvider> create(std::shared_ptr<commonApi::ComAPIEventLoop> com, const std::string& name);

        MetricsProvider(MetricsProvider& )  = delete;
        MetricsProvider(MetricsProvider&& ) = delete;

        MetricsProvider& operator=(MetricsProvider&& ) = delete;
        MetricsProvider& operator=(MetricsProvider& ) = delete;
    protected:
        MetricsProvider() = default;
    };
}

#endif
