// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/util/OptionsFactory.java

#pragma once

#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/util/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct default_init_tag;

class org::mpisws::p2p::transport::util::OptionsFactory
    : public virtual ::java::lang::Object
{

public:
    typedef ::java::lang::Object super;
    static ::java::util::Map* addOption(::java::util::Map* existing, ::java::lang::String* s, ::java::lang::Object* i);
    static ::java::util::Map* addOption(::java::util::Map* existing, ::java::lang::String* s1, ::java::lang::Object* i1, ::java::lang::String* s2, ::java::lang::Object* i2);
    static ::java::util::Map* addOption(::java::util::Map* existing, ::java::lang::String* s1, ::java::lang::Object* i1, ::java::lang::String* s2, ::java::lang::Object* i2, ::java::lang::String* s3, ::java::lang::Object* i3);
    static ::java::util::Map* copyOptions(::java::util::Map* existing);
    static ::java::util::Map* merge(::java::util::Map* options, ::java::util::Map* options2);
    static ::java::util::Map* removeOption(::java::util::Map* options, ::java::lang::String* option);

    // Generated
    OptionsFactory();
protected:
    OptionsFactory(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
