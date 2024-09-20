#ifndef COMMON_API_CONTROLLABLE_PROCESS_HPP
#define COMMON_API_CONTROLLABLE_PROCESS_HPP

#include "plugin/Plugin.hpp"

#include <functional>
#include <memory>

namespace commonApi
{
    class ComAPIEventLoop;

    namespace controllableprocess
    {
        class ControllableProcess: public Plugin
        {
        public:
            using TerminateCb = std::function<void()>;

            virtual ~ControllableProcess();

            virtual void setTerminateCb(const TerminateCb& cb) = 0;

            static std::shared_ptr<ControllableProcess> create(std::shared_ptr<ComAPIEventLoop> ga);

            ControllableProcess(const ControllableProcess&) = delete;
            ControllableProcess(ControllableProcess&&) = delete;
            ControllableProcess& operator=(const ControllableProcess&) = delete;
            ControllableProcess& operator=(ControllableProcess&&) = delete;
        protected:
            ControllableProcess() = default;
        };
    }
}

#endif
