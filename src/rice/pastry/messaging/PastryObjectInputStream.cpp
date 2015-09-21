// Generated from /pastry-2.1/src/rice/pastry/messaging/PastryObjectInputStream.java
#include <rice/pastry/messaging/PastryObjectInputStream.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <rice/pastry/NodeHandle.hpp>
#include <rice/pastry/PastryNode.hpp>

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

rice::pastry::messaging::PastryObjectInputStream::PastryObjectInputStream(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::pastry::messaging::PastryObjectInputStream::PastryObjectInputStream(::java::io::InputStream* stream, ::rice::pastry::PastryNode* node)  /* throws(IOException) */
    : PastryObjectInputStream(*static_cast< ::default_init_tag* >(0))
{
    ctor(stream,node);
}

void rice::pastry::messaging::PastryObjectInputStream::ctor(::java::io::InputStream* stream, ::rice::pastry::PastryNode* node) /* throws(IOException) */
{
    super::ctor(stream);
    this->node = node;
    enableResolveObject(true);
}

java::lang::Object* rice::pastry::messaging::PastryObjectInputStream::resolveObject(::java::lang::Object* input) /* throws(IOException) */
{
    if(dynamic_cast< ::rice::pastry::NodeHandle* >(input) != nullptr) {
        if(node != nullptr) {
            input = npc(node)->coalesce(java_cast< ::rice::pastry::NodeHandle* >(input));
        }
    }
    return input;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::messaging::PastryObjectInputStream::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.pastry.messaging.PastryObjectInputStream", 45);
    return c;
}

java::lang::Class* rice::pastry::messaging::PastryObjectInputStream::getClass0()
{
    return class_();
}

