// Generated from /pastry-2.1/src/rice/selector/SelectionKeyHandler.java
#include <rice/selector/SelectionKeyHandler.hpp>

#include <java/lang/Class.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/lang/UnsupportedOperationException.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::selector::SelectionKeyHandler::SelectionKeyHandler(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::selector::SelectionKeyHandler::SelectionKeyHandler()
    : SelectionKeyHandler(*static_cast< ::default_init_tag* >(0))
{
    ctor();
}

void rice::selector::SelectionKeyHandler::modifyKey(::java::nio::channels::SelectionKey* key)
{
    throw new ::java::lang::UnsupportedOperationException(::java::lang::StringBuilder().append(u"modifyKey() cannot be called on "_j)->append(npc(getClass())->getName())
        ->append(u"!"_j)->toString());
}

void rice::selector::SelectionKeyHandler::accept(::java::nio::channels::SelectionKey* key)
{
    throw new ::java::lang::UnsupportedOperationException(::java::lang::StringBuilder().append(u"accept() cannot be called on "_j)->append(npc(getClass())->getName())
        ->append(u"!"_j)->toString());
}

void rice::selector::SelectionKeyHandler::connect(::java::nio::channels::SelectionKey* key)
{
    throw new ::java::lang::UnsupportedOperationException(::java::lang::StringBuilder().append(u"connect() cannot be called on "_j)->append(npc(getClass())->getName())
        ->append(u"!"_j)->toString());
}

void rice::selector::SelectionKeyHandler::read(::java::nio::channels::SelectionKey* key)
{
    throw new ::java::lang::UnsupportedOperationException(::java::lang::StringBuilder().append(u"read() cannot be called on "_j)->append(npc(getClass())->getName())
        ->append(u"!"_j)->toString());
}

void rice::selector::SelectionKeyHandler::write(::java::nio::channels::SelectionKey* key)
{
    throw new ::java::lang::UnsupportedOperationException(::java::lang::StringBuilder().append(u"write() cannot be called on "_j)->append(npc(getClass())->getName())
        ->append(u"!"_j)->toString());
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::selector::SelectionKeyHandler::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.selector.SelectionKeyHandler", 33);
    return c;
}

java::lang::Class* rice::selector::SelectionKeyHandler::getClass0()
{
    return class_();
}

