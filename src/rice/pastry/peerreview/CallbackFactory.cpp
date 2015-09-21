// Generated from /pastry-2.1/src/rice/pastry/peerreview/CallbackFactory.java
#include <rice/pastry/peerreview/CallbackFactory.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/IllegalStateException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/util/HashMap.hpp>
#include <java/util/Map.hpp>
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

rice::pastry::peerreview::CallbackFactory::CallbackFactory(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::pastry::peerreview::CallbackFactory::CallbackFactory(::rice::environment::Environment* env)  /* throws(IOException) */
    : CallbackFactory(*static_cast< ::default_init_tag* >(0))
{
    ctor(env);
}

void rice::pastry::peerreview::CallbackFactory::ctor(::rice::environment::Environment* env) /* throws(IOException) */
{
    super::ctor(nullptr, int32_t(0), env);
    localHandleTable = new ::java::util::HashMap();
}

rice::pastry::transport::NodeHandleAdapter* rice::pastry::peerreview::CallbackFactory::getNodeHandleAdapter(::rice::pastry::PastryNode* pn, ::rice::pastry::NodeHandleFactory* handleFactory2, ::rice::pastry::transport::TLDeserializer* deserializer) /* throws(IOException) */
{
    return nullptr;
}

rice::pastry::NodeHandle* rice::pastry::peerreview::CallbackFactory::getLocalHandle(::rice::pastry::PastryNode* pn, ::rice::pastry::NodeHandleFactory* nhf)
{
    auto ret = java_cast< ::rice::pastry::NodeHandle* >(npc(localHandleTable)->remove(pn));
    if(ret == nullptr)
        throw new ::java::lang::IllegalStateException(::java::lang::StringBuilder().append(u"Couldn't find the handle in localHandleTable:"_j)->append(static_cast< ::java::lang::Object* >(pn))->toString());

    return ret;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::peerreview::CallbackFactory::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.pastry.peerreview.CallbackFactory", 38);
    return c;
}

java::lang::Class* rice::pastry::peerreview::CallbackFactory::getClass0()
{
    return class_();
}

