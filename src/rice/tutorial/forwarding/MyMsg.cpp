// Generated from /pastry-2.1/src/rice/tutorial/forwarding/MyMsg.java
#include <rice/tutorial/forwarding/MyMsg.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/util/ArrayList.hpp>
#include <rice/p2p/commonapi/Id.hpp>
#include <rice/p2p/commonapi/Message.hpp>
#include <rice/p2p/commonapi/NodeHandle.hpp>

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

rice::tutorial::forwarding::MyMsg::MyMsg(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::tutorial::forwarding::MyMsg::MyMsg(::rice::p2p::commonapi::Id* from, ::rice::p2p::commonapi::Id* to) 
    : MyMsg(*static_cast< ::default_init_tag* >(0))
{
    ctor(from,to);
}

void rice::tutorial::forwarding::MyMsg::init()
{
    passport = new ::java::util::ArrayList();
}

void rice::tutorial::forwarding::MyMsg::ctor(::rice::p2p::commonapi::Id* from, ::rice::p2p::commonapi::Id* to)
{
    super::ctor();
    init();
    this->from = from;
    this->to = to;
}

java::lang::String* rice::tutorial::forwarding::MyMsg::toString()
{
    auto path = u""_j;
    for (auto i = int32_t(0); i < npc(passport)->size(); i++) {
        path = ::java::lang::StringBuilder(path).append(::java::lang::StringBuilder().append(static_cast< ::java::lang::Object* >(java_cast< ::rice::p2p::commonapi::NodeHandle* >(npc(passport)->get(i))))->append(u","_j)->toString())->toString();
    }
    return ::java::lang::StringBuilder().append(u"MyMsg along path "_j)->append(path)->toString();
}

int32_t rice::tutorial::forwarding::MyMsg::getPriority()
{
    return ::rice::p2p::commonapi::Message::LOW_PRIORITY;
}

void rice::tutorial::forwarding::MyMsg::addHop(::rice::p2p::commonapi::NodeHandle* hop)
{
    npc(passport)->add(static_cast< ::java::lang::Object* >(hop));
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::tutorial::forwarding::MyMsg::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.tutorial.forwarding.MyMsg", 30);
    return c;
}

java::lang::Class* rice::tutorial::forwarding::MyMsg::getClass0()
{
    return class_();
}

