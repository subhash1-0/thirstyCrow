// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar
#include <java/util/HashMap_Node.hpp>

extern void unimplemented_(const char16_t* name);
java::util::HashMap_Node::HashMap_Node(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

java::util::HashMap_Node::HashMap_Node(int32_t arg0, ::java::lang::Object* arg1, ::java::lang::Object* arg2, HashMap_Node* arg3)
    : HashMap_Node(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0, arg1, arg2, arg3);
}


void ::java::util::HashMap_Node::ctor(int32_t arg0, ::java::lang::Object* arg1, ::java::lang::Object* arg2, HashMap_Node* arg3)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::util::HashMap_Node::ctor(int32_t arg0, ::java::lang::Object* arg1, ::java::lang::Object* arg2, HashMap_Node* arg3)");
}

bool java::util::HashMap_Node::equals(::java::lang::Object* arg0)
{ /* stub */
    unimplemented_(u"bool java::util::HashMap_Node::equals(::java::lang::Object* arg0)");
    return 0;
}

java::lang::Object* java::util::HashMap_Node::getKey()
{ /* stub */
return key ; /* getter */
}

java::lang::Object* java::util::HashMap_Node::getValue()
{ /* stub */
return value ; /* getter */
}

int32_t java::util::HashMap_Node::hashCode()
{ /* stub */
    unimplemented_(u"int32_t java::util::HashMap_Node::hashCode()");
    return 0;
}

java::lang::Object* java::util::HashMap_Node::setValue(::java::lang::Object* arg0)
{ /* stub */
}

java::lang::String* java::util::HashMap_Node::toString()
{ /* stub */
    unimplemented_(u"java::lang::String* java::util::HashMap_Node::toString()");
    return 0;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* java::util::HashMap_Node::class_()
{
    static ::java::lang::Class* c = ::class_(u"java.util.HashMap.Node", 22);
    return c;
}

java::lang::Class* java::util::HashMap_Node::getClass0()
{
    return class_();
}

