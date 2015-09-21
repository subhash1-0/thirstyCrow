// Generated from /pastry-2.1/src/rice/pastry/standard/PartitionHandler.java
#include <rice/pastry/standard/PartitionHandler_run_1.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/Exception.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/String.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/pastry/NodeHandle.hpp>
#include <rice/pastry/standard/PartitionHandler.hpp>

template<typename T, typename U>
static T java_cast(U* u)
{
    if(!u) return static_cast<T>(nullptr);
    auto t = dynamic_cast<T>(u);
    if(!t) throw new ::java::lang::ClassCastException();
    return t;
}

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::pastry::standard::PartitionHandler_run_1::PartitionHandler_run_1(PartitionHandler *PartitionHandler_this)
    : super(*static_cast< ::default_init_tag* >(0))
    , PartitionHandler_this(PartitionHandler_this)
{
    clinit();
    ctor();
}

void rice::pastry::standard::PartitionHandler_run_1::receiveResult(::rice::pastry::NodeHandle* result)
{
    if(result != nullptr) {
        PartitionHandler_this->rejoin(java_cast< ::rice::pastry::NodeHandle* >(result));
    } else {
        if(npc(PartitionHandler_this->logger)->level <= ::rice::environment::logging::Logger::INFO)
            npc(PartitionHandler_this->logger)->log(u"getNodeHandleToProbe returned null"_j);

    }
}

void rice::pastry::standard::PartitionHandler_run_1::receiveResult(::java::lang::Object* result)
{ 
    receiveResult(dynamic_cast< ::rice::pastry::NodeHandle* >(result));
}

void rice::pastry::standard::PartitionHandler_run_1::receiveException(::java::lang::Exception* result)
{
    if(npc(PartitionHandler_this->logger)->level <= ::rice::environment::logging::Logger::INFO)
        npc(PartitionHandler_this->logger)->logException(u"exception in PartitionHandler"_j, result);

}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::standard::PartitionHandler_run_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::pastry::standard::PartitionHandler_run_1::getClass0()
{
    return class_();
}

