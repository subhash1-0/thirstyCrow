// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar
#include <java/nio/IntBuffer.hpp>

extern void unimplemented_(const char16_t* name);
java::nio::IntBuffer::IntBuffer(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

java::nio::IntBuffer::IntBuffer(int32_t arg0, int32_t arg1, int32_t arg2, int32_t arg3)
    : IntBuffer(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0, arg1, arg2, arg3);
}

java::nio::IntBuffer::IntBuffer(int32_t arg0, int32_t arg1, int32_t arg2, int32_t arg3, ::int32_tArray* arg4, int32_t arg5)
    : IntBuffer(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0, arg1, arg2, arg3, arg4, arg5);
}


void ::java::nio::IntBuffer::ctor(int32_t arg0, int32_t arg1, int32_t arg2, int32_t arg3)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::nio::IntBuffer::ctor(int32_t arg0, int32_t arg1, int32_t arg2, int32_t arg3)");
}

void ::java::nio::IntBuffer::ctor(int32_t arg0, int32_t arg1, int32_t arg2, int32_t arg3, ::int32_tArray* arg4, int32_t arg5)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::nio::IntBuffer::ctor(int32_t arg0, int32_t arg1, int32_t arg2, int32_t arg3, ::int32_tArray* arg4, int32_t arg5)");
}

java::nio::IntBuffer* java::nio::IntBuffer::allocate(int32_t arg0)
{ /* stub */
    clinit();
    unimplemented_(u"java::nio::IntBuffer* java::nio::IntBuffer::allocate(int32_t arg0)");
    return 0;
}

int32_tArray* java::nio::IntBuffer::array()
{ /* stub */
    unimplemented_(u"int32_tArray* java::nio::IntBuffer::array()");
    return 0;
}

int32_t java::nio::IntBuffer::arrayOffset()
{ /* stub */
    unimplemented_(u"int32_t java::nio::IntBuffer::arrayOffset()");
    return 0;
}

/* private: int32_t java::nio::IntBuffer::compare(int32_t arg0, int32_t arg1) */
int32_t java::nio::IntBuffer::compareTo(IntBuffer* arg0)
{ /* stub */
    unimplemented_(u"int32_t java::nio::IntBuffer::compareTo(IntBuffer* arg0)");
    return 0;
}

int32_t java::nio::IntBuffer::compareTo(::java::lang::Object* arg0)
{ 
    return compareTo(dynamic_cast< IntBuffer* >(arg0));
}

bool java::nio::IntBuffer::equals(::java::lang::Object* arg0)
{ /* stub */
    unimplemented_(u"bool java::nio::IntBuffer::equals(::java::lang::Object* arg0)");
    return 0;
}

/* private: bool java::nio::IntBuffer::equals(int32_t arg0, int32_t arg1) */
java::nio::IntBuffer* java::nio::IntBuffer::get(::int32_tArray* arg0)
{ /* stub */
    unimplemented_(u"java::nio::IntBuffer* java::nio::IntBuffer::get(::int32_tArray* arg0)");
    return 0;
}

java::nio::IntBuffer* java::nio::IntBuffer::get(::int32_tArray* arg0, int32_t arg1, int32_t arg2)
{ /* stub */
    unimplemented_(u"java::nio::IntBuffer* java::nio::IntBuffer::get(::int32_tArray* arg0, int32_t arg1, int32_t arg2)");
    return 0;
}

bool java::nio::IntBuffer::hasArray_()
{ /* stub */
    unimplemented_(u"bool java::nio::IntBuffer::hasArray_()");
    return 0;
}

int32_t java::nio::IntBuffer::hashCode()
{ /* stub */
    unimplemented_(u"int32_t java::nio::IntBuffer::hashCode()");
    return 0;
}

java::nio::IntBuffer* java::nio::IntBuffer::put(IntBuffer* arg0)
{ /* stub */
    unimplemented_(u"java::nio::IntBuffer* java::nio::IntBuffer::put(IntBuffer* arg0)");
    return 0;
}

java::nio::IntBuffer* java::nio::IntBuffer::put(::int32_tArray* arg0)
{ /* stub */
    unimplemented_(u"java::nio::IntBuffer* java::nio::IntBuffer::put(::int32_tArray* arg0)");
    return 0;
}

java::nio::IntBuffer* java::nio::IntBuffer::put(::int32_tArray* arg0, int32_t arg1, int32_t arg2)
{ /* stub */
    unimplemented_(u"java::nio::IntBuffer* java::nio::IntBuffer::put(::int32_tArray* arg0, int32_t arg1, int32_t arg2)");
    return 0;
}

java::lang::String* java::nio::IntBuffer::toString()
{ /* stub */
    unimplemented_(u"java::lang::String* java::nio::IntBuffer::toString()");
    return 0;
}

java::nio::IntBuffer* java::nio::IntBuffer::wrap(::int32_tArray* arg0)
{ /* stub */
    clinit();
    unimplemented_(u"java::nio::IntBuffer* java::nio::IntBuffer::wrap(::int32_tArray* arg0)");
    return 0;
}

java::nio::IntBuffer* java::nio::IntBuffer::wrap(::int32_tArray* arg0, int32_t arg1, int32_t arg2)
{ /* stub */
    clinit();
    unimplemented_(u"java::nio::IntBuffer* java::nio::IntBuffer::wrap(::int32_tArray* arg0, int32_t arg1, int32_t arg2)");
    return 0;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* java::nio::IntBuffer::class_()
{
    static ::java::lang::Class* c = ::class_(u"java.nio.IntBuffer", 18);
    return c;
}

java::lang::Class* java::nio::IntBuffer::getClass0()
{
    return class_();
}

