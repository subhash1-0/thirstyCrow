// Generated from /pastry-2.1/src/rice/tutorial/rawserialization/MyApp.java
#include <rice/tutorial/rawserialization/MyApp_MyApp_1.hpp>

#include <rice/tutorial/rawserialization/MyApp.hpp>
#include <rice/tutorial/rawserialization/MyMsg.hpp>

rice::tutorial::rawserialization::MyApp_MyApp_1::MyApp_MyApp_1(MyApp *MyApp_this)
    : super(*static_cast< ::default_init_tag* >(0))
    , MyApp_this(MyApp_this)
{
    clinit();
    ctor();
}

rice::p2p::commonapi::Message* rice::tutorial::rawserialization::MyApp_MyApp_1::deserialize(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, int16_t type, int32_t priority, ::rice::p2p::commonapi::NodeHandle* sender) /* throws(IOException) */
{
    switch (type) {
    case MyMsg::TYPE:
        return new MyMsg(buf, MyApp_this->endpoint);
    }

    return nullptr;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::tutorial::rawserialization::MyApp_MyApp_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::tutorial::rawserialization::MyApp_MyApp_1::getClass0()
{
    return class_();
}

