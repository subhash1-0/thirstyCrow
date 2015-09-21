// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar
#include <java/io/DataOutputStream.hpp>

extern void unimplemented_(const char16_t* name);
java::io::DataOutputStream::DataOutputStream(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

java::io::DataOutputStream::DataOutputStream(OutputStream* arg0)
    : DataOutputStream(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0);
}


void ::java::io::DataOutputStream::ctor(OutputStream* arg0)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::io::DataOutputStream::ctor(OutputStream* arg0)");
}

void java::io::DataOutputStream::flush()
{ /* stub */
    unimplemented_(u"void java::io::DataOutputStream::flush()");
}

/* private: void java::io::DataOutputStream::incCount(int32_t arg0) */
int32_t java::io::DataOutputStream::size()
{ /* stub */
    unimplemented_(u"int32_t java::io::DataOutputStream::size()");
    return 0;
}

void java::io::DataOutputStream::write(int32_t arg0)
{ /* stub */
    unimplemented_(u"void java::io::DataOutputStream::write(int32_t arg0)");
}

void java::io::DataOutputStream::write(::int8_tArray* arg0, int32_t arg1, int32_t arg2)
{ /* stub */
    unimplemented_(u"void java::io::DataOutputStream::write(::int8_tArray* arg0, int32_t arg1, int32_t arg2)");
}

void java::io::DataOutputStream::writeBoolean(bool arg0)
{ /* stub */
    unimplemented_(u"void java::io::DataOutputStream::writeBoolean(bool arg0)");
}

void java::io::DataOutputStream::writeByte(int32_t arg0)
{ /* stub */
    unimplemented_(u"void java::io::DataOutputStream::writeByte(int32_t arg0)");
}

void java::io::DataOutputStream::writeBytes(::java::lang::String* arg0)
{ /* stub */
    unimplemented_(u"void java::io::DataOutputStream::writeBytes(::java::lang::String* arg0)");
}

void java::io::DataOutputStream::writeChar(int32_t arg0)
{ /* stub */
    unimplemented_(u"void java::io::DataOutputStream::writeChar(int32_t arg0)");
}

void java::io::DataOutputStream::writeChars(::java::lang::String* arg0)
{ /* stub */
    unimplemented_(u"void java::io::DataOutputStream::writeChars(::java::lang::String* arg0)");
}

void java::io::DataOutputStream::writeDouble(double arg0)
{ /* stub */
    unimplemented_(u"void java::io::DataOutputStream::writeDouble(double arg0)");
}

void java::io::DataOutputStream::writeFloat(float arg0)
{ /* stub */
    unimplemented_(u"void java::io::DataOutputStream::writeFloat(float arg0)");
}

void java::io::DataOutputStream::writeInt(int32_t arg0)
{ /* stub */
    unimplemented_(u"void java::io::DataOutputStream::writeInt(int32_t arg0)");
}

void java::io::DataOutputStream::writeLong(int64_t arg0)
{ /* stub */
    unimplemented_(u"void java::io::DataOutputStream::writeLong(int64_t arg0)");
}

void java::io::DataOutputStream::writeShort(int32_t arg0)
{ /* stub */
    unimplemented_(u"void java::io::DataOutputStream::writeShort(int32_t arg0)");
}

void java::io::DataOutputStream::writeUTF(::java::lang::String* arg0)
{ /* stub */
    unimplemented_(u"void java::io::DataOutputStream::writeUTF(::java::lang::String* arg0)");
}

int32_t java::io::DataOutputStream::writeUTF(::java::lang::String* arg0, DataOutput* arg1)
{ /* stub */
    clinit();
    unimplemented_(u"int32_t java::io::DataOutputStream::writeUTF(::java::lang::String* arg0, DataOutput* arg1)");
    return 0;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* java::io::DataOutputStream::class_()
{
    static ::java::lang::Class* c = ::class_(u"java.io.DataOutputStream", 24);
    return c;
}

void java::io::DataOutputStream::write(::int8_tArray* arg0)
{
    FilterOutputStream::write(arg0);
}

java::lang::Class* java::io::DataOutputStream::getClass0()
{
    return class_();
}

