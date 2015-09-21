// Generated from /pastry-2.1/src/rice/p2p/glacier/v2/FragmentAndManifest.java

#pragma once

#include <rice/p2p/glacier/fwd-pastry-2.1.hpp>
#include <rice/p2p/glacier/v2/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <java/io/Serializable.hpp>

struct default_init_tag;

class rice::p2p::glacier::v2::FragmentAndManifest
    : public virtual ::java::lang::Object
    , public virtual ::java::io::Serializable
{

public:
    typedef ::java::lang::Object super;
    ::rice::p2p::glacier::Fragment* fragment {  };
    Manifest* manifest {  };
protected:
    void ctor(::rice::p2p::glacier::Fragment* fragment, Manifest* manifest);

    // Generated

public:
    FragmentAndManifest(::rice::p2p::glacier::Fragment* fragment, Manifest* manifest);
protected:
    FragmentAndManifest(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
