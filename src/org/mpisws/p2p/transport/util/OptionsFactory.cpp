// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/util/OptionsFactory.java
#include <org/mpisws/p2p/transport/util/OptionsFactory.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/util/HashMap.hpp>
#include <java/util/Iterator.hpp>
#include <java/util/Map.hpp>
#include <java/util/Set.hpp>

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

org::mpisws::p2p::transport::util::OptionsFactory::OptionsFactory(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

org::mpisws::p2p::transport::util::OptionsFactory::OptionsFactory()
    : OptionsFactory(*static_cast< ::default_init_tag* >(0))
{
    ctor();
}

java::util::Map* org::mpisws::p2p::transport::util::OptionsFactory::addOption(::java::util::Map* existing, ::java::lang::String* s, ::java::lang::Object* i)
{
    clinit();
    auto ret = copyOptions(existing);
    npc(ret)->put(s, i);
    return ret;
}

java::util::Map* org::mpisws::p2p::transport::util::OptionsFactory::addOption(::java::util::Map* existing, ::java::lang::String* s1, ::java::lang::Object* i1, ::java::lang::String* s2, ::java::lang::Object* i2)
{
    clinit();
    auto ret = copyOptions(existing);
    npc(ret)->put(s1, i1);
    npc(ret)->put(s2, i2);
    return ret;
}

java::util::Map* org::mpisws::p2p::transport::util::OptionsFactory::addOption(::java::util::Map* existing, ::java::lang::String* s1, ::java::lang::Object* i1, ::java::lang::String* s2, ::java::lang::Object* i2, ::java::lang::String* s3, ::java::lang::Object* i3)
{
    clinit();
    auto ret = copyOptions(existing);
    npc(ret)->put(s1, i1);
    npc(ret)->put(s2, i2);
    npc(ret)->put(s3, i3);
    return ret;
}

java::util::Map* org::mpisws::p2p::transport::util::OptionsFactory::copyOptions(::java::util::Map* existing)
{
    clinit();
    if(existing == nullptr)
        return new ::java::util::HashMap();

    return new ::java::util::HashMap(static_cast< ::java::util::Map* >(existing));
}

java::util::Map* org::mpisws::p2p::transport::util::OptionsFactory::merge(::java::util::Map* options, ::java::util::Map* options2)
{
    clinit();
    auto ret = copyOptions(options2);
    if(options == nullptr)
        return ret;

    for (auto _i = npc(npc(options)->keySet())->iterator(); _i->hasNext(); ) {
        ::java::lang::String* k = java_cast< ::java::lang::String* >(_i->next());
        {
            npc(ret)->put(k, java_cast< ::java::lang::Object* >(npc(options)->get(k)));
        }
    }
    return ret;
}

java::util::Map* org::mpisws::p2p::transport::util::OptionsFactory::removeOption(::java::util::Map* options, ::java::lang::String* option)
{
    clinit();
    auto ret = copyOptions(options);
    npc(ret)->remove(option);
    return ret;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::util::OptionsFactory::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.transport.util.OptionsFactory", 44);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::util::OptionsFactory::getClass0()
{
    return class_();
}

