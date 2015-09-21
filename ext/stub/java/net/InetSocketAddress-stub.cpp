// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar
#include <java/net/InetSocketAddress.hpp>

extern void unimplemented_(const char16_t* name);
java::net::InetSocketAddress::InetSocketAddress(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

java::net::InetSocketAddress::InetSocketAddress(int32_t arg0)
    : InetSocketAddress(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0);
}

java::net::InetSocketAddress::InetSocketAddress(InetAddress* arg0, int32_t arg1)
    : InetSocketAddress(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0, arg1);
}

java::net::InetSocketAddress::InetSocketAddress(::java::lang::String* arg0, int32_t arg1)
    : InetSocketAddress(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0, arg1);
}

int64_t& java::net::InetSocketAddress::FIELDS_OFFSET()
{
    clinit();
    return FIELDS_OFFSET_;
}
int64_t java::net::InetSocketAddress::FIELDS_OFFSET_;
sun::misc::Unsafe*& java::net::InetSocketAddress::UNSAFE()
{
    clinit();
    return UNSAFE_;
}
sun::misc::Unsafe* java::net::InetSocketAddress::UNSAFE_;
java::io::ObjectStreamFieldArray*& java::net::InetSocketAddress::serialPersistentFields()
{
    clinit();
    return serialPersistentFields_;
}
java::io::ObjectStreamFieldArray* java::net::InetSocketAddress::serialPersistentFields_;
constexpr int64_t java::net::InetSocketAddress::serialVersionUID;

void ::java::net::InetSocketAddress::ctor(int32_t arg0)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::net::InetSocketAddress::ctor(int32_t arg0)");
}

void ::java::net::InetSocketAddress::ctor(InetAddress* arg0, int32_t arg1)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::net::InetSocketAddress::ctor(InetAddress* arg0, int32_t arg1)");
}

void ::java::net::InetSocketAddress::ctor(::java::lang::String* arg0, int32_t arg1)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::net::InetSocketAddress::ctor(::java::lang::String* arg0, int32_t arg1)");
}

/* private: void ::java::net::InetSocketAddress::ctor(int32_t arg0, ::java::lang::String* arg1) */
/* private: java::lang::String* java::net::InetSocketAddress::checkHost(::java::lang::String* arg0) */
/* private: int32_t java::net::InetSocketAddress::checkPort(int32_t arg0) */
java::net::InetSocketAddress* java::net::InetSocketAddress::createUnresolved(::java::lang::String* arg0, int32_t arg1)
{ /* stub */
    clinit();
    unimplemented_(u"java::net::InetSocketAddress* java::net::InetSocketAddress::createUnresolved(::java::lang::String* arg0, int32_t arg1)");
    return 0;
}

bool java::net::InetSocketAddress::equals(::java::lang::Object* arg0)
{ /* stub */
    unimplemented_(u"bool java::net::InetSocketAddress::equals(::java::lang::Object* arg0)");
    return 0;
}

java::net::InetAddress* java::net::InetSocketAddress::getAddress()
{ /* stub */
    unimplemented_(u"java::net::InetAddress* java::net::InetSocketAddress::getAddress()");
    return 0;
}

java::lang::String* java::net::InetSocketAddress::getHostName()
{ /* stub */
    unimplemented_(u"java::lang::String* java::net::InetSocketAddress::getHostName()");
    return 0;
}

java::lang::String* java::net::InetSocketAddress::getHostString()
{ /* stub */
    unimplemented_(u"java::lang::String* java::net::InetSocketAddress::getHostString()");
    return 0;
}

int32_t java::net::InetSocketAddress::getPort()
{ /* stub */
    unimplemented_(u"int32_t java::net::InetSocketAddress::getPort()");
    return 0;
}

int32_t java::net::InetSocketAddress::hashCode()
{ /* stub */
    unimplemented_(u"int32_t java::net::InetSocketAddress::hashCode()");
    return 0;
}

bool java::net::InetSocketAddress::isUnresolved()
{ /* stub */
    unimplemented_(u"bool java::net::InetSocketAddress::isUnresolved()");
    return 0;
}

/* private: void java::net::InetSocketAddress::readObject(::java::io::ObjectInputStream* arg0) */
/* private: void java::net::InetSocketAddress::readObjectNoData() */
java::lang::String* java::net::InetSocketAddress::toString()
{ /* stub */
    unimplemented_(u"java::lang::String* java::net::InetSocketAddress::toString()");
    return 0;
}

/* private: void java::net::InetSocketAddress::writeObject(::java::io::ObjectOutputStream* arg0) */
extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* java::net::InetSocketAddress::class_()
{
    static ::java::lang::Class* c = ::class_(u"java.net.InetSocketAddress", 26);
    return c;
}

java::lang::Class* java::net::InetSocketAddress::getClass0()
{
    return class_();
}

