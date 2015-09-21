// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/sourceroute/SourceRoute.java
#include <org/mpisws/p2p/transport/sourceroute/SourceRoute.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/IllegalArgumentException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuffer.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/util/ArrayList.hpp>
#include <java/util/Collection.hpp>
#include <java/util/Iterator.hpp>
#include <java/util/List.hpp>

template<typename T, typename U>
static T java_cast(U* u)
{
    if(!u) return static_cast<T>(nullptr);
    auto t = dynamic_cast<T>(u);
    if(!t) throw new ::java::lang::ClassCastException();
    return t;
}

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

org::mpisws::p2p::transport::sourceroute::SourceRoute::SourceRoute(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

org::mpisws::p2p::transport::sourceroute::SourceRoute::SourceRoute(::java::util::List* path) 
    : SourceRoute(*static_cast< ::default_init_tag* >(0))
{
    ctor(path);
}

org::mpisws::p2p::transport::sourceroute::SourceRoute::SourceRoute(::java::lang::Object* address) 
    : SourceRoute(*static_cast< ::default_init_tag* >(0))
{
    ctor(address);
}

org::mpisws::p2p::transport::sourceroute::SourceRoute::SourceRoute(::java::lang::Object* local, ::java::lang::Object* remote) 
    : SourceRoute(*static_cast< ::default_init_tag* >(0))
{
    ctor(local,remote);
}

void org::mpisws::p2p::transport::sourceroute::SourceRoute::ctor(::java::util::List* path)
{
    super::ctor();
    this->path = new ::java::util::ArrayList(static_cast< ::java::util::Collection* >(path));
    for (auto _i = npc(java_cast< ::java::util::List* >(this->path))->iterator(); _i->hasNext(); ) {
        ::java::lang::Object* i = java_cast< ::java::lang::Object* >(_i->next());
        {
            if(i == nullptr)
                throw new ::java::lang::IllegalArgumentException(::java::lang::StringBuilder().append(u"path["_j)->append(static_cast< ::java::lang::Object* >(i))
                    ->append(u"] is null"_j)->toString());

        }
    }
}

void org::mpisws::p2p::transport::sourceroute::SourceRoute::ctor(::java::lang::Object* address)
{
    super::ctor();
    this->path = new ::java::util::ArrayList(int32_t(1));
    npc(path)->add(static_cast< ::java::lang::Object* >(address));
}

void org::mpisws::p2p::transport::sourceroute::SourceRoute::ctor(::java::lang::Object* local, ::java::lang::Object* remote)
{
    super::ctor();
    this->path = new ::java::util::ArrayList(int32_t(2));
    npc(path)->add(static_cast< ::java::lang::Object* >(local));
    npc(path)->add(static_cast< ::java::lang::Object* >(remote));
}

int32_t org::mpisws::p2p::transport::sourceroute::SourceRoute::hashCode()
{
    auto result = int32_t(399388937);
    for (auto _i = npc(path)->iterator(); _i->hasNext(); ) {
        ::java::lang::Object* i = java_cast< ::java::lang::Object* >(_i->next());
        
                        result ^= npc(i)->hashCode();

    }
    return result;
}

bool org::mpisws::p2p::transport::sourceroute::SourceRoute::equals(::java::lang::Object* o)
{
    if(o == nullptr)
        return false;

    if(!(dynamic_cast< SourceRoute* >(o) != nullptr))
        return false;

    auto that = java_cast< SourceRoute* >(o);
    return npc(java_cast< ::java::util::List* >(this->path))->equals(static_cast< ::java::lang::Object* >(npc(that)->path));
}

java::lang::String* org::mpisws::p2p::transport::sourceroute::SourceRoute::toString()
{
    auto result = new ::java::lang::StringBuffer();
    npc(result)->append(u"{"_j);
    for (auto i = int32_t(0); i < npc(path)->size(); i++) {
        auto thePath = java_cast< ::java::lang::Object* >(npc(path)->get(i));
        npc(result)->append(npc(thePath)->toString());
        if(i < npc(path)->size() - int32_t(1))
            npc(result)->append(u" -> "_j);

    }
    npc(result)->append(u"}"_j);
    return npc(result)->toString();
}

java::lang::Object* org::mpisws::p2p::transport::sourceroute::SourceRoute::getFirstHop()
{
    return java_cast< ::java::lang::Object* >(npc(path)->get(0));
}

java::lang::Object* org::mpisws::p2p::transport::sourceroute::SourceRoute::getLastHop()
{
    return java_cast< ::java::lang::Object* >(npc(path)->get(npc(path)->size() - int32_t(1)));
}

int32_t org::mpisws::p2p::transport::sourceroute::SourceRoute::getNumHops()
{
    return npc(path)->size();
}

java::lang::Object* org::mpisws::p2p::transport::sourceroute::SourceRoute::getHop(int32_t i)
{
    return java_cast< ::java::lang::Object* >(npc(path)->get(i));
}

bool org::mpisws::p2p::transport::sourceroute::SourceRoute::isDirect()
{
    return (npc(path)->size() <= 2);
}

bool org::mpisws::p2p::transport::sourceroute::SourceRoute::goesThrough(::java::lang::Object* address)
{
    return npc(path)->contains(static_cast< ::java::lang::Object* >(address));
}

int32_t org::mpisws::p2p::transport::sourceroute::SourceRoute::getHop(::java::lang::Object* identifier)
{
    for (auto i = int32_t(0); i < npc(path)->size(); i++) {
        auto id = java_cast< ::java::lang::Object* >(npc(path)->get(i));
        if(npc(id)->equals(identifier))
            return i;

    }
    return -int32_t(1);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::sourceroute::SourceRoute::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.transport.sourceroute.SourceRoute", 48);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::sourceroute::SourceRoute::getClass0()
{
    return class_();
}

