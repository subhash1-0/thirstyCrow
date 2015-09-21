// Generated from /pastry-2.1/src/rice/p2p/scribe/ScribePolicy.java
#include <rice/p2p/scribe/ScribePolicy_LimitedScribePolicy.hpp>

#include <java/io/Serializable.hpp>
#include <java/lang/ArrayStoreException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/util/List.hpp>
#include <java/util/Observable.hpp>
#include <rice/p2p/commonapi/NodeHandle.hpp>
#include <SubArray.hpp>
#include <ObjectArray.hpp>

template<typename ComponentType, typename... Bases> struct SubArray;
namespace java
{
    namespace io
    {
typedef ::SubArray< ::java::io::Serializable, ::java::lang::ObjectArray > SerializableArray;
    } // io

    namespace util
    {
typedef ::SubArray< ::java::util::Observable, ::java::lang::ObjectArray > ObservableArray;
    } // util
} // java

namespace rice
{
    namespace p2p
    {
        namespace commonapi
        {
typedef ::SubArray< ::rice::p2p::commonapi::NodeHandle, ::java::util::ObservableArray, ::java::io::SerializableArray > NodeHandleArray;
        } // commonapi

        namespace scribe
        {
typedef ::SubArray< ::rice::p2p::scribe::ScribeClient, ::java::lang::ObjectArray > ScribeClientArray;
        } // scribe
    } // p2p
} // rice

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::p2p::scribe::ScribePolicy_LimitedScribePolicy::ScribePolicy_LimitedScribePolicy(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::p2p::scribe::ScribePolicy_LimitedScribePolicy::ScribePolicy_LimitedScribePolicy(int32_t max, ::rice::environment::Environment* env) 
    : ScribePolicy_LimitedScribePolicy(*static_cast< ::default_init_tag* >(0))
{
    ctor(max,env);
}

void rice::p2p::scribe::ScribePolicy_LimitedScribePolicy::ctor(int32_t max, ::rice::environment::Environment* env)
{
    super::ctor(env);
    this->maxChildren = max;
}

bool rice::p2p::scribe::ScribePolicy_LimitedScribePolicy::allowSubscribe(::rice::p2p::scribe::messaging::SubscribeMessage* message, ScribeClientArray* clients, ::rice::p2p::commonapi::NodeHandleArray* children)
{
    return (npc(children)->length < (maxChildren - int32_t(1)));
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::scribe::ScribePolicy_LimitedScribePolicy::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.scribe.ScribePolicy.LimitedScribePolicy", 48);
    return c;
}

java::util::List* rice::p2p::scribe::ScribePolicy_LimitedScribePolicy::allowSubscribe(Scribe* scribe, ::rice::p2p::commonapi::NodeHandle* source, ::java::util::List* topics, ScribeContent* content)
{
    return super::allowSubscribe(scribe, source, topics, content);
}

java::lang::Class* rice::p2p::scribe::ScribePolicy_LimitedScribePolicy::getClass0()
{
    return class_();
}

