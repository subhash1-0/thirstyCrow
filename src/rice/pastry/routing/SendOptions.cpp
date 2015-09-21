// Generated from /pastry-2.1/src/rice/pastry/routing/SendOptions.java
#include <rice/pastry/routing/SendOptions.hpp>

#include <java/io/ObjectInputStream.hpp>
#include <java/io/ObjectOutputStream.hpp>
#include <java/lang/NullPointerException.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::pastry::routing::SendOptions::SendOptions(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::pastry::routing::SendOptions::SendOptions() 
    : SendOptions(*static_cast< ::default_init_tag* >(0))
{
    ctor();
}

rice::pastry::routing::SendOptions::SendOptions(bool random, bool noShortCuts, bool shortestPath, bool allowMultipleHops, bool rerouteIfSuspected) 
    : SendOptions(*static_cast< ::default_init_tag* >(0))
{
    ctor(random,noShortCuts,shortestPath,allowMultipleHops,rerouteIfSuspected);
}

constexpr bool rice::pastry::routing::SendOptions::defaultRandom;

constexpr bool rice::pastry::routing::SendOptions::defaultNoShortCuts;

constexpr bool rice::pastry::routing::SendOptions::defaultShortestPath;

constexpr bool rice::pastry::routing::SendOptions::defaultAllowMultipleHops;

constexpr bool rice::pastry::routing::SendOptions::defaultRerouteIfSuspected;

void rice::pastry::routing::SendOptions::ctor()
{
    super::ctor();
    random = defaultRandom;
    noShortCuts = defaultNoShortCuts;
    shortestPath = defaultShortestPath;
    allowMultipleHops = defaultAllowMultipleHops;
    rerouteIfSuspected_ = defaultRerouteIfSuspected;
}

void rice::pastry::routing::SendOptions::ctor(bool random, bool noShortCuts, bool shortestPath, bool allowMultipleHops, bool rerouteIfSuspected)
{
    super::ctor();
    this->random = random;
    this->noShortCuts = noShortCuts;
    this->shortestPath = shortestPath;
    this->allowMultipleHops = allowMultipleHops;
    this->rerouteIfSuspected_ = rerouteIfSuspected;
}

bool rice::pastry::routing::SendOptions::canRandom()
{
    return random;
}

bool rice::pastry::routing::SendOptions::makeNoShortCuts()
{
    return noShortCuts;
}

bool rice::pastry::routing::SendOptions::requireShortestPath()
{
    return shortestPath;
}

bool rice::pastry::routing::SendOptions::multipleHopsAllowed()
{
    return allowMultipleHops;
}

void rice::pastry::routing::SendOptions::setMultipleHopsAllowed(bool b)
{
    allowMultipleHops = b;
}

bool rice::pastry::routing::SendOptions::rerouteIfSuspected()
{
    return rerouteIfSuspected_;
}

void rice::pastry::routing::SendOptions::setRerouteIfSuspected(bool b)
{
    rerouteIfSuspected_ = b;
}

void rice::pastry::routing::SendOptions::readObject(::java::io::ObjectInputStream* in) /* throws(IOException, ClassNotFoundException) */
{
    random = npc(in)->readBoolean();
    noShortCuts = npc(in)->readBoolean();
    shortestPath = npc(in)->readBoolean();
    allowMultipleHops = npc(in)->readBoolean();
}

void rice::pastry::routing::SendOptions::writeObject(::java::io::ObjectOutputStream* out) /* throws(IOException, ClassNotFoundException) */
{
    npc(out)->writeBoolean(random);
    npc(out)->writeBoolean(noShortCuts);
    npc(out)->writeBoolean(shortestPath);
    npc(out)->writeBoolean(allowMultipleHops);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::routing::SendOptions::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.pastry.routing.SendOptions", 31);
    return c;
}

java::lang::Class* rice::pastry::routing::SendOptions::getClass0()
{
    return class_();
}

