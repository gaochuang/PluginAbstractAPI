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
            using HeartbeatCb = std::function<void()>;

            virtual ~ControllableProcess();

            //当该服务结束，需要调用这个回调
            virtual void setTerminateCb(const TerminateCb& cb) = 0;
            //通知其它服务本服务已经ready，可以进行后续，比如跳服务等
            virtual void notifyReady() = 0;
            //设置心跳的回调函数
            virtual void setHeartbeatCb(const HeartbeatCb& cb) = 0;
            //心跳回复
            virtual void heartbeatAck() = 0;

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
