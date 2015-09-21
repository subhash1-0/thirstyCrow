// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar
#include <java/security/MessageDigest.hpp>

extern void unimplemented_(const char16_t* name);
java::security::MessageDigest::MessageDigest(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

java::security::MessageDigest::MessageDigest(::java::lang::String* arg0)
    : MessageDigest(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0);
}

constexpr int32_t java::security::MessageDigest::INITIAL;
constexpr int32_t java::security::MessageDigest::IN_PROGRESS;
sun::security::util::Debug*& java::security::MessageDigest::pdebug()
{
    clinit();
    return pdebug_;
}
sun::security::util::Debug* java::security::MessageDigest::pdebug_;
bool& java::security::MessageDigest::skipDebug()
{
    clinit();
    return skipDebug_;
}
bool java::security::MessageDigest::skipDebug_;

void ::java::security::MessageDigest::ctor(::java::lang::String* arg0)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::security::MessageDigest::ctor(::java::lang::String* arg0)");
}

java::lang::Object* java::security::MessageDigest::clone()
{ /* stub */
    unimplemented_(u"java::lang::Object* java::security::MessageDigest::clone()");
    return 0;
}

int8_tArray* java::security::MessageDigest::digest()
{ /* stub */
    unimplemented_(u"int8_tArray* java::security::MessageDigest::digest()");
    return 0;
}

int8_tArray* java::security::MessageDigest::digest(::int8_tArray* arg0)
{ /* stub */
    unimplemented_(u"int8_tArray* java::security::MessageDigest::digest(::int8_tArray* arg0)");
    return 0;
}

int32_t java::security::MessageDigest::digest(::int8_tArray* arg0, int32_t arg1, int32_t arg2)
{ /* stub */
    unimplemented_(u"int32_t java::security::MessageDigest::digest(::int8_tArray* arg0, int32_t arg1, int32_t arg2)");
    return 0;
}

java::lang::String* java::security::MessageDigest::getAlgorithm()
{ /* stub */
return algorithm ; /* getter */
}

int32_t java::security::MessageDigest::getDigestLength()
{ /* stub */
    unimplemented_(u"int32_t java::security::MessageDigest::getDigestLength()");
    return 0;
}

java::security::MessageDigest* java::security::MessageDigest::getInstance(::java::lang::String* arg0)
{ /* stub */
    clinit();
    unimplemented_(u"java::security::MessageDigest* java::security::MessageDigest::getInstance(::java::lang::String* arg0)");
    return 0;
}

java::security::MessageDigest* java::security::MessageDigest::getInstance(::java::lang::String* arg0, ::java::lang::String* arg1)
{ /* stub */
    clinit();
    unimplemented_(u"java::security::MessageDigest* java::security::MessageDigest::getInstance(::java::lang::String* arg0, ::java::lang::String* arg1)");
    return 0;
}

java::security::MessageDigest* java::security::MessageDigest::getInstance(::java::lang::String* arg0, Provider* arg1)
{ /* stub */
    clinit();
    unimplemented_(u"java::security::MessageDigest* java::security::MessageDigest::getInstance(::java::lang::String* arg0, Provider* arg1)");
    return 0;
}

java::security::Provider* java::security::MessageDigest::getProvider()
{ /* stub */
return provider ; /* getter */
}

bool java::security::MessageDigest::isEqual(::int8_tArray* arg0, ::int8_tArray* arg1)
{ /* stub */
    clinit();
    unimplemented_(u"bool java::security::MessageDigest::isEqual(::int8_tArray* arg0, ::int8_tArray* arg1)");
    return 0;
}

void java::security::MessageDigest::reset()
{ /* stub */
    unimplemented_(u"void java::security::MessageDigest::reset()");
}

java::lang::String* java::security::MessageDigest::toString()
{ /* stub */
    unimplemented_(u"java::lang::String* java::security::MessageDigest::toString()");
    return 0;
}

void java::security::MessageDigest::update(int8_t arg0)
{ /* stub */
    unimplemented_(u"void java::security::MessageDigest::update(int8_t arg0)");
}

void java::security::MessageDigest::update(::int8_tArray* arg0)
{ /* stub */
    unimplemented_(u"void java::security::MessageDigest::update(::int8_tArray* arg0)");
}

void java::security::MessageDigest::update(::java::nio::ByteBuffer* arg0)
{ /* stub */
    unimplemented_(u"void java::security::MessageDigest::update(::java::nio::ByteBuffer* arg0)");
}

void java::security::MessageDigest::update(::int8_tArray* arg0, int32_t arg1, int32_t arg2)
{ /* stub */
    unimplemented_(u"void java::security::MessageDigest::update(::int8_tArray* arg0, int32_t arg1, int32_t arg2)");
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* java::security::MessageDigest::class_()
{
    static ::java::lang::Class* c = ::class_(u"java.security.MessageDigest", 27);
    return c;
}

java::lang::Class* java::security::MessageDigest::getClass0()
{
    return class_();
}

