// Generated from /pastry-2.1/src/rice/selector/SelectionKeyHandler.java

#pragma once

#include <java/nio/channels/fwd-pastry-2.1.hpp>
#include <rice/selector/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct default_init_tag;

class rice::selector::SelectionKeyHandler
    : public virtual ::java::lang::Object
{

public:
    typedef ::java::lang::Object super;
    virtual void modifyKey(::java::nio::channels::SelectionKey* key);
    virtual void accept(::java::nio::channels::SelectionKey* key);
    virtual void connect(::java::nio::channels::SelectionKey* key);
    virtual void read(::java::nio::channels::SelectionKey* key);
    virtual void write(::java::nio::channels::SelectionKey* key);

    // Generated
    SelectionKeyHandler();
protected:
    SelectionKeyHandler(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
