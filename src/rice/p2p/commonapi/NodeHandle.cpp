// Generated from /pastry-2.1/src/rice/p2p/commonapi/NodeHandle.java
#include <rice/p2p/commonapi/NodeHandle.hpp>

#include <java/lang/Integer.hpp>

rice::p2p::commonapi::NodeHandle::NodeHandle(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::p2p::commonapi::NodeHandle::NodeHandle()
    : NodeHandle(*static_cast< ::default_init_tag* >(0))
{
    ctor();
}

java::lang::Integer*& rice::p2p::commonapi::NodeHandle::PROXIMITY_CHANGED()
{
    clinit();
    return PROXIMITY_CHANGED_;
}
java::lang::Integer* rice::p2p::commonapi::NodeHandle::PROXIMITY_CHANGED_;

java::lang::Integer*& rice::p2p::commonapi::NodeHandle::DECLARED_DEAD()
{
    clinit();
    return DECLARED_DEAD_;
}
java::lang::Integer* rice::p2p::commonapi::NodeHandle::DECLARED_DEAD_;

java::lang::Integer*& rice::p2p::commonapi::NodeHandle::DECLARED_LIVE()
{
    clinit();
    return DECLARED_LIVE_;
}
java::lang::Integer* rice::p2p::commonapi::NodeHandle::DECLARED_LIVE_;

constexpr int64_t rice::p2p::commonapi::NodeHandle::serialVersionUID;

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::commonapi::NodeHandle::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.commonapi.NodeHandle", 29);
    return c;
}

void rice::p2p::commonapi::NodeHandle::clinit()
{
    super::clinit();
    static bool in_cl_init = false;
struct clinit_ {
    clinit_() {
        in_cl_init = true;
        PROXIMITY_CHANGED_ = new ::java::lang::Integer(int32_t(1));
        DECLARED_DEAD_ = new ::java::lang::Integer(int32_t(2));
        DECLARED_LIVE_ = new ::java::lang::Integer(int32_t(3));
    }
};

    if(!in_cl_init) {
        static clinit_ clinit_instance;
    }
}

java::lang::Class* rice::p2p::commonapi::NodeHandle::getClass0()
{
    return class_();
}

