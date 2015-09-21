// Generated from /pastry-2.1/src/rice/pastry/standard/StandardAddress.java
#include <rice/pastry/standard/StandardAddress.hpp>

#include <java/io/PrintStream.hpp>
#include <java/lang/Class.hpp>
#include <java/lang/Integer.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/lang/System.hpp>
#include <java/security/MessageDigest.hpp>
#include <java/security/NoSuchAlgorithmException.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/logging/LogManager.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <Array.hpp>

template<typename ComponentType, typename... Bases> struct SubArray;
namespace java
{
    namespace io
    {
typedef ::SubArray< ::java::io::Serializable, ::java::lang::ObjectArray > SerializableArray;
    } // io

    namespace lang
    {
typedef ::SubArray< ::java::lang::CharSequence, ObjectArray > CharSequenceArray;
typedef ::SubArray< ::java::lang::Comparable, ObjectArray > ComparableArray;
typedef ::SubArray< ::java::lang::String, ObjectArray, ::java::io::SerializableArray, ComparableArray, CharSequenceArray > StringArray;
    } // lang
} // java

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::pastry::standard::StandardAddress::StandardAddress(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::pastry::standard::StandardAddress::StandardAddress()
    : StandardAddress(*static_cast< ::default_init_tag* >(0))
{
    ctor();
}

constexpr int64_t rice::pastry::standard::StandardAddress::serialVersionUID;

int32_t rice::pastry::standard::StandardAddress::getAddress(::java::lang::Class* c, ::java::lang::String* instance, ::rice::environment::Environment* env)
{
    clinit();
    ::java::security::MessageDigest* md = nullptr;
    try {
        md = ::java::security::MessageDigest::getInstance(u"SHA"_j);
    } catch (::java::security::NoSuchAlgorithmException* e) {
        auto logger = npc(npc(env)->getLogManager())->getLogger(StandardAddress::class_(), nullptr);
        if(npc(logger)->level <= ::rice::environment::logging::Logger::SEVERE)
            npc(logger)->log(u"No SHA support!"_j);

    }
    auto digest = new ::int8_tArray(int32_t(4));
    npc(md)->update(npc(npc(c)->toString())->getBytes());
    (*digest)[int32_t(0)] = (*npc(md)->digest())[int32_t(0)];
    (*digest)[int32_t(1)] = (*npc(md)->digest())[int32_t(1)];
    if((instance == nullptr) || (npc(instance)->equals(static_cast< ::java::lang::Object* >(u""_j)))) {
    } else {
        npc(md)->reset();
        npc(md)->update(npc(instance)->getBytes());
        (*digest)[int32_t(2)] = (*npc(md)->digest())[int32_t(0)];
        (*digest)[int32_t(3)] = (*npc(md)->digest())[int32_t(1)];
    }
    auto myCode = shift((*digest)[int32_t(0)], 24) | shift((*digest)[int32_t(1)], 16) | shift((*digest)[int32_t(2)], 8)| shift((*digest)[int32_t(3)], 0);
    return myCode;
}

int16_t rice::pastry::standard::StandardAddress::getAddress(::java::lang::Class* c, ::rice::environment::Environment* env)
{
    clinit();
    auto myCode = getAddress(c, nullptr, env);
    auto code = static_cast< int16_t >(unshift(myCode, 16));
    return code;
}

int32_t rice::pastry::standard::StandardAddress::shift(int32_t n, int32_t s)
{
    clinit();
    return (n & int32_t(255)) << s;
}

int32_t rice::pastry::standard::StandardAddress::unshift(int32_t n, int32_t s)
{
    clinit();
    return n >> s;
}

void rice::pastry::standard::StandardAddress::main(::java::lang::StringArray* args)
{
    clinit();
    auto c = StandardAddress::class_();
    auto a = getAddress(c, nullptr, nullptr);
    auto b = getAddress(c, u"b"_j, nullptr);
    auto a1 = getAddress(c, nullptr);
    npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(a)->append(u" "_j)
        ->append(::java::lang::Integer::toBinaryString(a))
        ->append(u" "_j)
        ->append(a1)
        ->append(u" "_j)
        ->append(::java::lang::Integer::toBinaryString(a1))->toString());
    npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(b)->append(u" "_j)
        ->append(::java::lang::Integer::toBinaryString(b))->toString());
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::standard::StandardAddress::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.pastry.standard.StandardAddress", 36);
    return c;
}

java::lang::Class* rice::pastry::standard::StandardAddress::getClass0()
{
    return class_();
}

