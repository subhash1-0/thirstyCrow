// Generated from /pastry-2.1/src/rice/p2p/util/rawserialization/JavaDeserializer.java
#include <rice/p2p/util/rawserialization/JavaDeserializer.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <rice/p2p/commonapi/Endpoint.hpp>
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

rice::p2p::util::rawserialization::JavaDeserializer::JavaDeserializer(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::p2p::util::rawserialization::JavaDeserializer::JavaDeserializer(::java::io::InputStream* stream, ::rice::p2p::commonapi::Endpoint* endpoint)  /* throws(IOException) */
    : JavaDeserializer(*static_cast< ::default_init_tag* >(0))
{
    ctor(stream,endpoint);
}

void rice::p2p::util::rawserialization::JavaDeserializer::ctor(::java::io::InputStream* stream, ::rice::p2p::commonapi::Endpoint* endpoint) /* throws(IOException) */
{
    super::ctor(stream);
    this->endpoint = endpoint;
    enableResolveObject(true);
}

java::lang::Object* rice::p2p::util::rawserialization::JavaDeserializer::resolveObject(::java::lang::Object* input) /* throws(IOException) */
{
    if(dynamic_cast< ::rice::p2p::commonapi::NodeHandle* >(input) != nullptr) {
        if(endpoint != nullptr) {
            input = npc(endpoint)->coalesce(java_cast< ::rice::p2p::commonapi::NodeHandle* >(input));
        }
    }
    return input;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::util::rawserialization::JavaDeserializer::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.util.rawserialization.JavaDeserializer", 47);
    return c;
}

java::lang::Class* rice::p2p::util::rawserialization::JavaDeserializer::getClass0()
{
    return class_();
}

