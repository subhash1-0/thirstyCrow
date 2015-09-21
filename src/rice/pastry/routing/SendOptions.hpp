// Generated from /pastry-2.1/src/rice/pastry/routing/SendOptions.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <rice/pastry/routing/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <java/io/Serializable.hpp>

struct default_init_tag;

class rice::pastry::routing::SendOptions
    : public virtual ::java::lang::Object
    , public virtual ::java::io::Serializable
{

public:
    typedef ::java::lang::Object super;

private:
    bool random {  };
    bool noShortCuts {  };
    bool shortestPath {  };
    bool allowMultipleHops {  };
    bool rerouteIfSuspected_ {  };

public:
    static constexpr bool defaultRandom { false };
    static constexpr bool defaultNoShortCuts { true };
    static constexpr bool defaultShortestPath { true };
    static constexpr bool defaultAllowMultipleHops { true };
    static constexpr bool defaultRerouteIfSuspected { true };
protected:
    void ctor();
    void ctor(bool random, bool noShortCuts, bool shortestPath, bool allowMultipleHops, bool rerouteIfSuspected);

public:
    virtual bool canRandom();
    virtual bool makeNoShortCuts();
    virtual bool requireShortestPath();
    virtual bool multipleHopsAllowed();
    virtual void setMultipleHopsAllowed(bool b);
    virtual bool rerouteIfSuspected();
    virtual void setRerouteIfSuspected(bool b);

private:
    void readObject(::java::io::ObjectInputStream* in) /* throws(IOException, ClassNotFoundException) */;
    void writeObject(::java::io::ObjectOutputStream* out) /* throws(IOException, ClassNotFoundException) */;

    // Generated

public:
    SendOptions();
    SendOptions(bool random, bool noShortCuts, bool shortestPath, bool allowMultipleHops, bool rerouteIfSuspected);
protected:
    SendOptions(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
