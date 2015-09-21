// Generated from /pastry-2.1/src/rice/p2p/util/testing/XMLParserUnit.java
#include <rice/p2p/util/testing/XMLParserUnit.hpp>

#include <java/io/PrintStream.hpp>
#include <java/io/Reader.hpp>
#include <java/io/StringReader.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/lang/System.hpp>
#include <rice/p2p/util/XMLParser.hpp>

template<typename ComponentType, typename... Bases> struct SubArray;
namespace java
{
    namespace io
    {
typedef ::SubArray< ::java::io::Serializable, ::java::lang::ObjectArray > SerializableArray;
    } // io

    namespace lang
    {
typedef ::SubArray< ::java::lang::CharSequence, ObjectArray > CharSequenceArray;
typedef ::SubArray< ::java::lang::Comparable, ObjectArray > ComparableArray;
typedef ::SubArray< ::java::lang::String, ObjectArray, ::java::io::SerializableArray, ComparableArray, CharSequenceArray > StringArray;
    } // lang
} // java

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::p2p::util::testing::XMLParserUnit::XMLParserUnit(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::p2p::util::testing::XMLParserUnit::XMLParserUnit()
    : XMLParserUnit(*static_cast< ::default_init_tag* >(0))
{
    ctor();
}

void rice::p2p::util::testing::XMLParserUnit::main(::java::lang::StringArray* argv) /* throws(Exception) */
{
    clinit();
    npc(::java::lang::System::out())->println(u"XMLParser Test Suite"_j);
    npc(::java::lang::System::out())->println(u"-------------------------------------------------------------"_j);
    npc(::java::lang::System::out())->println(u"  Running Tests"_j);
    npc(::java::lang::System::out())->print(u"    Testing Simple (1)\t\t\t\t"_j);
    auto parser = new ::rice::p2p::util::XMLParser();
    npc(parser)->setInput(static_cast< ::java::io::Reader* >(new ::java::io::StringReader(u"<test></test>"_j)));
    auto i = npc(parser)->next();
    if((i == ::rice::p2p::util::XMLParser::START_TAG) && (npc(npc(parser)->getName())->equals(static_cast< ::java::lang::Object* >(u"test"_j)))) {
        i = npc(parser)->next();
        if((i == ::rice::p2p::util::XMLParser::END_TAG) && (npc(npc(parser)->getName())->equals(static_cast< ::java::lang::Object* >(u"test"_j)))) {
            i = npc(parser)->next();
            if(i == ::rice::p2p::util::XMLParser::END_DOCUMENT) {
                npc(::java::lang::System::out())->println(u"[ PASSED ]"_j);
            } else {
                npc(::java::lang::System::out())->println(u"[ FAILED ]"_j);
                npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"    Output(5):\t"_j)->append(i)->toString());
            }
        } else {
            npc(::java::lang::System::out())->println(u"[ FAILED ]"_j);
            npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"    Output(2):\t"_j)->append(i)
                ->append(u" "_j)
                ->append(npc(parser)->getName())->toString());
        }
    } else {
        npc(::java::lang::System::out())->println(u"[ FAILED ]"_j);
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"    Output(1):\t"_j)->append(i)
            ->append(u" "_j)
            ->append(npc(parser)->getName())->toString());
    }
    npc(::java::lang::System::out())->print(u"    Testing Simple (2)\t\t\t\t"_j);
    parser = new ::rice::p2p::util::XMLParser();
    npc(parser)->setInput(static_cast< ::java::io::Reader* >(new ::java::io::StringReader(u"<test/>"_j)));
    i = npc(parser)->next();
    if((i == ::rice::p2p::util::XMLParser::START_TAG) && (npc(npc(parser)->getName())->equals(static_cast< ::java::lang::Object* >(u"test"_j)))) {
        i = npc(parser)->next();
        if((i == ::rice::p2p::util::XMLParser::END_TAG) && (npc(npc(parser)->getName())->equals(static_cast< ::java::lang::Object* >(u"test"_j)))) {
            i = npc(parser)->next();
            if(i == ::rice::p2p::util::XMLParser::END_DOCUMENT) {
                npc(::java::lang::System::out())->println(u"[ PASSED ]"_j);
            } else {
                npc(::java::lang::System::out())->println(u"[ FAILED ]"_j);
                npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"    Output(3):\t"_j)->append(i)->toString());
            }
        } else {
            npc(::java::lang::System::out())->println(u"[ FAILED ]"_j);
            npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"    Output(2):\t"_j)->append(i)
                ->append(u" "_j)
                ->append(npc(parser)->getName())->toString());
        }
    } else {
        npc(::java::lang::System::out())->println(u"[ FAILED ]"_j);
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"    Output(1):\t"_j)->append(i)
            ->append(u" "_j)
            ->append(npc(parser)->getName())->toString());
    }
    npc(::java::lang::System::out())->print(u"    Testing Simple Attribute (1)\t\t\t"_j);
    parser = new ::rice::p2p::util::XMLParser();
    npc(parser)->setInput(static_cast< ::java::io::Reader* >(new ::java::io::StringReader(u"<test foo=bar/>"_j)));
    i = npc(parser)->next();
    if((i == ::rice::p2p::util::XMLParser::START_TAG) && (npc(npc(parser)->getName())->equals(static_cast< ::java::lang::Object* >(u"test"_j)))) {
        i = npc(parser)->next();
        if((i == ::rice::p2p::util::XMLParser::END_TAG) && (npc(npc(parser)->getName())->equals(static_cast< ::java::lang::Object* >(u"test"_j)))) {
            i = npc(parser)->next();
            if(i == ::rice::p2p::util::XMLParser::END_DOCUMENT) {
                npc(::java::lang::System::out())->println(u"[ PASSED ]"_j);
            } else {
                npc(::java::lang::System::out())->println(u"[ FAILED ]"_j);
                npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"    Output(3):\t"_j)->append(i)->toString());
            }
        } else {
            npc(::java::lang::System::out())->println(u"[ FAILED ]"_j);
            npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"    Output(2):\t"_j)->append(i)
                ->append(u" "_j)
                ->append(npc(parser)->getName())->toString());
        }
    } else {
        npc(::java::lang::System::out())->println(u"[ FAILED ]"_j);
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"    Output(1):\t"_j)->append(i)
            ->append(u" "_j)
            ->append(npc(parser)->getName())->toString());
    }
    npc(::java::lang::System::out())->print(u"    Testing Simple Attribute (2)\t\t\t"_j);
    parser = new ::rice::p2p::util::XMLParser();
    npc(parser)->setInput(static_cast< ::java::io::Reader* >(new ::java::io::StringReader(u"<test foo='bar'/>"_j)));
    i = npc(parser)->next();
    if((i == ::rice::p2p::util::XMLParser::START_TAG) && (npc(npc(parser)->getName())->equals(static_cast< ::java::lang::Object* >(u"test"_j)))) {
        i = npc(parser)->next();
        if((i == ::rice::p2p::util::XMLParser::END_TAG) && (npc(npc(parser)->getName())->equals(static_cast< ::java::lang::Object* >(u"test"_j)))) {
            i = npc(parser)->next();
            if(i == ::rice::p2p::util::XMLParser::END_DOCUMENT) {
                npc(::java::lang::System::out())->println(u"[ PASSED ]"_j);
            } else {
                npc(::java::lang::System::out())->println(u"[ FAILED ]"_j);
                npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"    Output(3):\t"_j)->append(i)->toString());
            }
        } else {
            npc(::java::lang::System::out())->println(u"[ FAILED ]"_j);
            npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"    Output(2):\t"_j)->append(i)
                ->append(u" "_j)
                ->append(npc(parser)->getName())->toString());
        }
    } else {
        npc(::java::lang::System::out())->println(u"[ FAILED ]"_j);
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"    Output(1):\t"_j)->append(i)
            ->append(u" "_j)
            ->append(npc(parser)->getName())->toString());
    }
    npc(::java::lang::System::out())->print(u"    Testing Simple Attribute (3)\t\t\t"_j);
    parser = new ::rice::p2p::util::XMLParser();
    npc(parser)->setInput(static_cast< ::java::io::Reader* >(new ::java::io::StringReader(u"<test foo=\"bar\"/>"_j)));
    i = npc(parser)->next();
    if((i == ::rice::p2p::util::XMLParser::START_TAG) && (npc(npc(parser)->getName())->equals(static_cast< ::java::lang::Object* >(u"test"_j)))) {
        i = npc(parser)->next();
        if((i == ::rice::p2p::util::XMLParser::END_TAG) && (npc(npc(parser)->getName())->equals(static_cast< ::java::lang::Object* >(u"test"_j)))) {
            i = npc(parser)->next();
            if(i == ::rice::p2p::util::XMLParser::END_DOCUMENT) {
                npc(::java::lang::System::out())->println(u"[ PASSED ]"_j);
            } else {
                npc(::java::lang::System::out())->println(u"[ FAILED ]"_j);
                npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"    Output(3):\t"_j)->append(i)->toString());
            }
        } else {
            npc(::java::lang::System::out())->println(u"[ FAILED ]"_j);
            npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"    Output(2):\t"_j)->append(i)
                ->append(u" "_j)
                ->append(npc(parser)->getName())->toString());
        }
    } else {
        npc(::java::lang::System::out())->println(u"[ FAILED ]"_j);
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"    Output(1):\t"_j)->append(i)
            ->append(u" "_j)
            ->append(npc(parser)->getName())->toString());
    }
    npc(::java::lang::System::out())->print(u"    Testing Simple Attribute (4)\t\t\t"_j);
    parser = new ::rice::p2p::util::XMLParser();
    npc(parser)->setInput(static_cast< ::java::io::Reader* >(new ::java::io::StringReader(u"<test foo=\"bar\"></test>"_j)));
    i = npc(parser)->next();
    if((i == ::rice::p2p::util::XMLParser::START_TAG) && (npc(npc(parser)->getName())->equals(static_cast< ::java::lang::Object* >(u"test"_j)))) {
        i = npc(parser)->next();
        if((i == ::rice::p2p::util::XMLParser::END_TAG) && (npc(npc(parser)->getName())->equals(static_cast< ::java::lang::Object* >(u"test"_j)))) {
            i = npc(parser)->next();
            if(i == ::rice::p2p::util::XMLParser::END_DOCUMENT) {
                npc(::java::lang::System::out())->println(u"[ PASSED ]"_j);
            } else {
                npc(::java::lang::System::out())->println(u"[ FAILED ]"_j);
                npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"    Output(3):\t"_j)->append(i)->toString());
            }
        } else {
            npc(::java::lang::System::out())->println(u"[ FAILED ]"_j);
            npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"    Output(2):\t"_j)->append(i)
                ->append(u" "_j)
                ->append(npc(parser)->getName())->toString());
        }
    } else {
        npc(::java::lang::System::out())->println(u"[ FAILED ]"_j);
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"    Output(1):\t"_j)->append(i)
            ->append(u" "_j)
            ->append(npc(parser)->getName())->toString());
    }
    npc(::java::lang::System::out())->print(u"    Testing Simple Attribute (5)\t\t\t"_j);
    parser = new ::rice::p2p::util::XMLParser();
    npc(parser)->setInput(static_cast< ::java::io::Reader* >(new ::java::io::StringReader(u"<test foo=\"bar\" baz=blah goo=29.33   ></test>"_j)));
    i = npc(parser)->next();
    if((i == ::rice::p2p::util::XMLParser::START_TAG) && (npc(npc(parser)->getName())->equals(static_cast< ::java::lang::Object* >(u"test"_j)))) {
        i = npc(parser)->next();
        if((i == ::rice::p2p::util::XMLParser::END_TAG) && (npc(npc(parser)->getName())->equals(static_cast< ::java::lang::Object* >(u"test"_j)))) {
            i = npc(parser)->next();
            if(i == ::rice::p2p::util::XMLParser::END_DOCUMENT) {
                npc(::java::lang::System::out())->println(u"[ PASSED ]"_j);
            } else {
                npc(::java::lang::System::out())->println(u"[ FAILED ]"_j);
                npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"    Output(3):\t"_j)->append(i)->toString());
            }
        } else {
            npc(::java::lang::System::out())->println(u"[ FAILED ]"_j);
            npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"    Output(2):\t"_j)->append(i)
                ->append(u" "_j)
                ->append(npc(parser)->getName())->toString());
        }
    } else {
        npc(::java::lang::System::out())->println(u"[ FAILED ]"_j);
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"    Output(1):\t"_j)->append(i)
            ->append(u" "_j)
            ->append(npc(parser)->getName())->toString());
    }
    npc(::java::lang::System::out())->print(u"    Testing Simple Attribute (6)\t\t\t"_j);
    parser = new ::rice::p2p::util::XMLParser();
    npc(parser)->setInput(static_cast< ::java::io::Reader* >(new ::java::io::StringReader(u"<test foo=\"bar\" baz=blah goo=29.33   ></test>"_j)));
    i = npc(parser)->next();
    if((i == ::rice::p2p::util::XMLParser::START_TAG) && (npc(npc(parser)->getName())->equals(static_cast< ::java::lang::Object* >(u"test"_j)))) {
        if(npc(npc(parser)->getAttributeValue(static_cast< ::java::lang::String* >(nullptr), u"foo"_j))->equals(static_cast< ::java::lang::Object* >(u"bar"_j)) && npc(npc(parser)->getAttributeValue(static_cast< ::java::lang::String* >(nullptr), u"baz"_j))->equals(static_cast< ::java::lang::Object* >(u"blah"_j)) && npc(npc(parser)->getAttributeValue(static_cast< ::java::lang::String* >(nullptr), u"goo"_j))->equals(static_cast< ::java::lang::Object* >(u"29.33"_j))) {
            i = npc(parser)->next();
            if((i == ::rice::p2p::util::XMLParser::END_TAG) && (npc(npc(parser)->getName())->equals(static_cast< ::java::lang::Object* >(u"test"_j)))) {
                i = npc(parser)->next();
                if(i == ::rice::p2p::util::XMLParser::END_DOCUMENT) {
                    npc(::java::lang::System::out())->println(u"[ PASSED ]"_j);
                } else {
                    npc(::java::lang::System::out())->println(u"[ FAILED ]"_j);
                    npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"    Output(4):\t"_j)->append(i)->toString());
                }
            } else {
                npc(::java::lang::System::out())->println(u"[ FAILED ]"_j);
                npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"    Output(3):\t"_j)->append(i)
                    ->append(u" "_j)
                    ->append(npc(parser)->getName())->toString());
            }
        } else {
            npc(::java::lang::System::out())->println(u"[ FAILED ]"_j);
            npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"    Output(2):\t"_j)->append(i)
                ->append(u" "_j)
                ->append(npc(npc(parser)->getAttributeValue(static_cast< ::java::lang::String* >(nullptr), u"foo"_j))->equals(static_cast< ::java::lang::Object* >(u"bar"_j)))
                ->append(u" "_j)
                ->append(npc(npc(parser)->getAttributeValue(static_cast< ::java::lang::String* >(nullptr), u"baz"_j))->equals(static_cast< ::java::lang::Object* >(u"blah"_j)))
                ->append(u" "_j)
                ->append(npc(npc(parser)->getAttributeValue(static_cast< ::java::lang::String* >(nullptr), u"goo"_j))->equals(static_cast< ::java::lang::Object* >(u"29.33"_j)))->toString());
        }
    } else {
        npc(::java::lang::System::out())->println(u"[ FAILED ]"_j);
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"    Output(1):\t"_j)->append(i)
            ->append(u" "_j)
            ->append(npc(parser)->getName())->toString());
    }
    npc(::java::lang::System::out())->print(u"    Testing Missing Attribute\t\t\t"_j);
    parser = new ::rice::p2p::util::XMLParser();
    npc(parser)->setInput(static_cast< ::java::io::Reader* >(new ::java::io::StringReader(u"<test foo=\"bar\" baz=blah goo=29.33   ></test>"_j)));
    i = npc(parser)->next();
    if((i == ::rice::p2p::util::XMLParser::START_TAG) && (npc(npc(parser)->getName())->equals(static_cast< ::java::lang::Object* >(u"test"_j)))) {
        if(npc(npc(parser)->getAttributeValue(static_cast< ::java::lang::String* >(nullptr), u"foo"_j))->equals(static_cast< ::java::lang::Object* >(u"bar"_j)) && npc(npc(parser)->getAttributeValue(static_cast< ::java::lang::String* >(nullptr), u"baz"_j))->equals(static_cast< ::java::lang::Object* >(u"blah"_j)) && npc(npc(parser)->getAttributeValue(static_cast< ::java::lang::String* >(nullptr), u"goo"_j))->equals(static_cast< ::java::lang::Object* >(u"29.33"_j))&& npc(parser)->getAttributeValue(static_cast< ::java::lang::String* >(nullptr), u"bar"_j) == nullptr) {
            i = npc(parser)->next();
            if((i == ::rice::p2p::util::XMLParser::END_TAG) && (npc(npc(parser)->getName())->equals(static_cast< ::java::lang::Object* >(u"test"_j)))) {
                i = npc(parser)->next();
                if(i == ::rice::p2p::util::XMLParser::END_DOCUMENT) {
                    npc(::java::lang::System::out())->println(u"[ PASSED ]"_j);
                } else {
                    npc(::java::lang::System::out())->println(u"[ FAILED ]"_j);
                    npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"    Output(4):\t"_j)->append(i)->toString());
                }
            } else {
                npc(::java::lang::System::out())->println(u"[ FAILED ]"_j);
                npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"    Output(3):\t"_j)->append(i)
                    ->append(u" "_j)
                    ->append(npc(parser)->getName())->toString());
            }
        } else {
            npc(::java::lang::System::out())->println(u"[ FAILED ]"_j);
            npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"    Output(2):\t"_j)->append(i)
                ->append(u" "_j)
                ->append(npc(npc(parser)->getAttributeValue(static_cast< ::java::lang::String* >(nullptr), u"foo"_j))->equals(static_cast< ::java::lang::Object* >(u"bar"_j)))
                ->append(u" "_j)
                ->append(npc(npc(parser)->getAttributeValue(static_cast< ::java::lang::String* >(nullptr), u"baz"_j))->equals(static_cast< ::java::lang::Object* >(u"blah"_j)))
                ->append(u" "_j)
                ->append(npc(npc(parser)->getAttributeValue(static_cast< ::java::lang::String* >(nullptr), u"goo"_j))->equals(static_cast< ::java::lang::Object* >(u"29.33"_j)))->toString());
        }
    } else {
        npc(::java::lang::System::out())->println(u"[ FAILED ]"_j);
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"    Output(1):\t"_j)->append(i)
            ->append(u" "_j)
            ->append(npc(parser)->getName())->toString());
    }
    npc(::java::lang::System::out())->print(u"    Testing Recursive\t\t\t\t\t"_j);
    parser = new ::rice::p2p::util::XMLParser();
    npc(parser)->setInput(static_cast< ::java::io::Reader* >(new ::java::io::StringReader(u"<test foo=\"bar\" baz=blah goo=29.33   >\n\t<bar/>\t\t\t\n\t</test>"_j)));
    i = npc(parser)->next();
    if((i == ::rice::p2p::util::XMLParser::START_TAG) && (npc(npc(parser)->getName())->equals(static_cast< ::java::lang::Object* >(u"test"_j)))) {
        i = npc(parser)->next();
        if((i == ::rice::p2p::util::XMLParser::TEXT) && (npc(npc(parser)->getText())->equals(static_cast< ::java::lang::Object* >(u"\n\t"_j))) && (npc(parser)->isWhitespace())) {
            i = npc(parser)->next();
            if((i == ::rice::p2p::util::XMLParser::START_TAG) && (npc(npc(parser)->getName())->equals(static_cast< ::java::lang::Object* >(u"bar"_j)))) {
                i = npc(parser)->next();
                if((i == ::rice::p2p::util::XMLParser::END_TAG) && (npc(npc(parser)->getName())->equals(static_cast< ::java::lang::Object* >(u"bar"_j)))) {
                    i = npc(parser)->next();
                    if((i == ::rice::p2p::util::XMLParser::TEXT) && (npc(npc(parser)->getText())->equals(static_cast< ::java::lang::Object* >(u"\t\t\t\n\t"_j))) && (npc(parser)->isWhitespace())) {
                        i = npc(parser)->next();
                        if((i == ::rice::p2p::util::XMLParser::END_TAG) && (npc(npc(parser)->getName())->equals(static_cast< ::java::lang::Object* >(u"test"_j)))) {
                            i = npc(parser)->next();
                            if(i == ::rice::p2p::util::XMLParser::END_DOCUMENT) {
                                npc(::java::lang::System::out())->println(u"[ PASSED ]"_j);
                            } else {
                                npc(::java::lang::System::out())->println(u"[ FAILED ]"_j);
                                npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"    Output(5):\t"_j)->append(i)->toString());
                            }
                        } else {
                            npc(::java::lang::System::out())->println(u"[ FAILED ]"_j);
                            npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"    Output(4):\t"_j)->append(i)
                                ->append(u" "_j)
                                ->append(npc(parser)->getName())->toString());
                        }
                    } else {
                        npc(::java::lang::System::out())->println(u"[ FAILED ]"_j);
                        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"    Output(3t):\t"_j)->append(i)
                            ->append(u" "_j)
                            ->append(npc(parser)->getText())
                            ->append(u" "_j)
                            ->append(npc(parser)->isWhitespace())->toString());
                    }
                } else {
                    npc(::java::lang::System::out())->println(u"[ FAILED ]"_j);
                    npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"    Output(3):\t"_j)->append(i)
                        ->append(u" "_j)
                        ->append(npc(parser)->getName())->toString());
                }
            } else {
                npc(::java::lang::System::out())->println(u"[ FAILED ]"_j);
                npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"    Output(2):\t"_j)->append(i)
                    ->append(u" "_j)
                    ->append(npc(parser)->getName())->toString());
            }
        } else {
            npc(::java::lang::System::out())->println(u"[ FAILED ]"_j);
            npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"    Output(1t):\t"_j)->append(i)
                ->append(u" "_j)
                ->append(npc(parser)->getText())
                ->append(u" "_j)
                ->append(npc(parser)->isWhitespace())->toString());
        }
    } else {
        npc(::java::lang::System::out())->println(u"[ FAILED ]"_j);
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"    Output(1):\t"_j)->append(i)
            ->append(u" "_j)
            ->append(npc(parser)->getName())->toString());
    }
    npc(::java::lang::System::out())->print(u"    Testing Nasty\t\t\t\t\t"_j);
    parser = new ::rice::p2p::util::XMLParser();
    npc(parser)->setInput(static_cast< ::java::io::Reader* >(new ::java::io::StringReader(u"<test foo=\"bar\" baz=   6 goo=  \t29.33   >\n\t<bar   lah\n=\n\n\ndofdo/>\t\t\t\n\t</test>"_j)));
    i = npc(parser)->next();
    if((i == ::rice::p2p::util::XMLParser::START_TAG) && (npc(npc(parser)->getName())->equals(static_cast< ::java::lang::Object* >(u"test"_j)))) {
        i = npc(parser)->next();
        if((i == ::rice::p2p::util::XMLParser::TEXT) && (npc(npc(parser)->getText())->equals(static_cast< ::java::lang::Object* >(u"\n\t"_j))) && (npc(parser)->isWhitespace())) {
            i = npc(parser)->next();
            if((i == ::rice::p2p::util::XMLParser::START_TAG) && (npc(npc(parser)->getName())->equals(static_cast< ::java::lang::Object* >(u"bar"_j)))) {
                i = npc(parser)->next();
                if((i == ::rice::p2p::util::XMLParser::END_TAG) && (npc(npc(parser)->getName())->equals(static_cast< ::java::lang::Object* >(u"bar"_j)))) {
                    i = npc(parser)->next();
                    if((i == ::rice::p2p::util::XMLParser::TEXT) && (npc(npc(parser)->getText())->equals(static_cast< ::java::lang::Object* >(u"\t\t\t\n\t"_j))) && (npc(parser)->isWhitespace())) {
                        i = npc(parser)->next();
                        if((i == ::rice::p2p::util::XMLParser::END_TAG) && (npc(npc(parser)->getName())->equals(static_cast< ::java::lang::Object* >(u"test"_j)))) {
                            i = npc(parser)->next();
                            if(i == ::rice::p2p::util::XMLParser::END_DOCUMENT) {
                                npc(::java::lang::System::out())->println(u"[ PASSED ]"_j);
                            } else {
                                npc(::java::lang::System::out())->println(u"[ FAILED ]"_j);
                                npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"    Output(5):\t"_j)->append(i)->toString());
                            }
                        } else {
                            npc(::java::lang::System::out())->println(u"[ FAILED ]"_j);
                            npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"    Output(4):\t"_j)->append(i)
                                ->append(u" "_j)
                                ->append(npc(parser)->getName())->toString());
                        }
                    } else {
                        npc(::java::lang::System::out())->println(u"[ FAILED ]"_j);
                        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"    Output(3t):\t"_j)->append(i)
                            ->append(u" "_j)
                            ->append(npc(parser)->getText())
                            ->append(u" "_j)
                            ->append(npc(parser)->isWhitespace())->toString());
                    }
                } else {
                    npc(::java::lang::System::out())->println(u"[ FAILED ]"_j);
                    npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"    Output(3):\t"_j)->append(i)
                        ->append(u" "_j)
                        ->append(npc(parser)->getName())->toString());
                }
            } else {
                npc(::java::lang::System::out())->println(u"[ FAILED ]"_j);
                npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"    Output(2):\t"_j)->append(i)
                    ->append(u" "_j)
                    ->append(npc(parser)->getName())->toString());
            }
        } else {
            npc(::java::lang::System::out())->println(u"[ FAILED ]"_j);
            npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"    Output(1t):\t"_j)->append(i)
                ->append(u" "_j)
                ->append(npc(parser)->getText())
                ->append(u" "_j)
                ->append(npc(parser)->isWhitespace())->toString());
        }
    } else {
        npc(::java::lang::System::out())->println(u"[ FAILED ]"_j);
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"    Output(1):\t"_j)->append(i)
            ->append(u" "_j)
            ->append(npc(parser)->getName())->toString());
    }
    npc(::java::lang::System::out())->print(u"    Testing Start Document\t\t\t"_j);
    parser = new ::rice::p2p::util::XMLParser();
    npc(parser)->setInput(static_cast< ::java::io::Reader* >(new ::java::io::StringReader(u"<?xml version='1.0'?><test foo=\"bar\" baz=   6 goo=  \t29.33   >\n\t<bar   lah\n=\n\n\ndofdo/>\t\t\t\n\t</test>"_j)));
    i = npc(parser)->next();
    if((i == ::rice::p2p::util::XMLParser::START_TAG) && (npc(npc(parser)->getName())->equals(static_cast< ::java::lang::Object* >(u"test"_j)))) {
        i = npc(parser)->next();
        if((i == ::rice::p2p::util::XMLParser::TEXT) && (npc(npc(parser)->getText())->equals(static_cast< ::java::lang::Object* >(u"\n\t"_j))) && (npc(parser)->isWhitespace())) {
            i = npc(parser)->next();
            if((i == ::rice::p2p::util::XMLParser::START_TAG) && (npc(npc(parser)->getName())->equals(static_cast< ::java::lang::Object* >(u"bar"_j)))) {
                i = npc(parser)->next();
                if((i == ::rice::p2p::util::XMLParser::END_TAG) && (npc(npc(parser)->getName())->equals(static_cast< ::java::lang::Object* >(u"bar"_j)))) {
                    i = npc(parser)->next();
                    if((i == ::rice::p2p::util::XMLParser::TEXT) && (npc(npc(parser)->getText())->equals(static_cast< ::java::lang::Object* >(u"\t\t\t\n\t"_j))) && (npc(parser)->isWhitespace())) {
                        i = npc(parser)->next();
                        if((i == ::rice::p2p::util::XMLParser::END_TAG) && (npc(npc(parser)->getName())->equals(static_cast< ::java::lang::Object* >(u"test"_j)))) {
                            i = npc(parser)->next();
                            if(i == ::rice::p2p::util::XMLParser::END_DOCUMENT) {
                                npc(::java::lang::System::out())->println(u"[ PASSED ]"_j);
                            } else {
                                npc(::java::lang::System::out())->println(u"[ FAILED ]"_j);
                                npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"    Output(5):\t"_j)->append(i)->toString());
                            }
                        } else {
                            npc(::java::lang::System::out())->println(u"[ FAILED ]"_j);
                            npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"    Output(4):\t"_j)->append(i)
                                ->append(u" "_j)
                                ->append(npc(parser)->getName())->toString());
                        }
                    } else {
                        npc(::java::lang::System::out())->println(u"[ FAILED ]"_j);
                        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"    Output(3t):\t"_j)->append(i)
                            ->append(u" "_j)
                            ->append(npc(parser)->getText())
                            ->append(u" "_j)
                            ->append(npc(parser)->isWhitespace())->toString());
                    }
                } else {
                    npc(::java::lang::System::out())->println(u"[ FAILED ]"_j);
                    npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"    Output(3):\t"_j)->append(i)
                        ->append(u" "_j)
                        ->append(npc(parser)->getName())->toString());
                }
            } else {
                npc(::java::lang::System::out())->println(u"[ FAILED ]"_j);
                npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"    Output(2):\t"_j)->append(i)
                    ->append(u" "_j)
                    ->append(npc(parser)->getName())->toString());
            }
        } else {
            npc(::java::lang::System::out())->println(u"[ FAILED ]"_j);
            npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"    Output(1t):\t"_j)->append(i)
                ->append(u" "_j)
                ->append(npc(parser)->getText())
                ->append(u" "_j)
                ->append(npc(parser)->isWhitespace())->toString());
        }
    } else {
        npc(::java::lang::System::out())->println(u"[ FAILED ]"_j);
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"    Output(1):\t"_j)->append(i)
            ->append(u" "_j)
            ->append(npc(parser)->getName())->toString());
    }
    npc(::java::lang::System::out())->print(u"    Testing Nasty Start Document\t\t\t"_j);
    parser = new ::rice::p2p::util::XMLParser();
    npc(parser)->setInput(static_cast< ::java::io::Reader* >(new ::java::io::StringReader(u"<?xml version='1.0' foo   = 'baz\n'  \t\t ?>\n\n \t<test foo=\"bar\" baz=   6 goo=  \t29.33   >\n\t<bar   lah\n=\n\n\ndofdo/>\t\t\t\n\t</test>"_j)));
    i = npc(parser)->next();
    if((i == ::rice::p2p::util::XMLParser::TEXT) && (npc(npc(parser)->getText())->equals(static_cast< ::java::lang::Object* >(u"\n\n \t"_j))) && (npc(parser)->isWhitespace())) {
        i = npc(parser)->next();
        if((i == ::rice::p2p::util::XMLParser::START_TAG) && (npc(npc(parser)->getName())->equals(static_cast< ::java::lang::Object* >(u"test"_j)))) {
            i = npc(parser)->next();
            if((i == ::rice::p2p::util::XMLParser::TEXT) && (npc(npc(parser)->getText())->equals(static_cast< ::java::lang::Object* >(u"\n\t"_j))) && (npc(parser)->isWhitespace())) {
                i = npc(parser)->next();
                if((i == ::rice::p2p::util::XMLParser::START_TAG) && (npc(npc(parser)->getName())->equals(static_cast< ::java::lang::Object* >(u"bar"_j)))) {
                    i = npc(parser)->next();
                    if((i == ::rice::p2p::util::XMLParser::END_TAG) && (npc(npc(parser)->getName())->equals(static_cast< ::java::lang::Object* >(u"bar"_j)))) {
                        i = npc(parser)->next();
                        if((i == ::rice::p2p::util::XMLParser::TEXT) && (npc(npc(parser)->getText())->equals(static_cast< ::java::lang::Object* >(u"\t\t\t\n\t"_j))) && (npc(parser)->isWhitespace())) {
                            i = npc(parser)->next();
                            if((i == ::rice::p2p::util::XMLParser::END_TAG) && (npc(npc(parser)->getName())->equals(static_cast< ::java::lang::Object* >(u"test"_j)))) {
                                i = npc(parser)->next();
                                if(i == ::rice::p2p::util::XMLParser::END_DOCUMENT) {
                                    npc(::java::lang::System::out())->println(u"[ PASSED ]"_j);
                                } else {
                                    npc(::java::lang::System::out())->println(u"[ FAILED ]"_j);
                                    npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"    Output(5):\t"_j)->append(i)->toString());
                                }
                            } else {
                                npc(::java::lang::System::out())->println(u"[ FAILED ]"_j);
                                npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"    Output(4):\t"_j)->append(i)
                                    ->append(u" "_j)
                                    ->append(npc(parser)->getName())->toString());
                            }
                        } else {
                            npc(::java::lang::System::out())->println(u"[ FAILED ]"_j);
                            npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"    Output(3t):\t"_j)->append(i)
                                ->append(u" "_j)
                                ->append(npc(parser)->getText())
                                ->append(u" "_j)
                                ->append(npc(parser)->isWhitespace())->toString());
                        }
                    } else {
                        npc(::java::lang::System::out())->println(u"[ FAILED ]"_j);
                        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"    Output(3):\t"_j)->append(i)
                            ->append(u" "_j)
                            ->append(npc(parser)->getName())->toString());
                    }
                } else {
                    npc(::java::lang::System::out())->println(u"[ FAILED ]"_j);
                    npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"    Output(2):\t"_j)->append(i)
                        ->append(u" "_j)
                        ->append(npc(parser)->getName())->toString());
                }
            } else {
                npc(::java::lang::System::out())->println(u"[ FAILED ]"_j);
                npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"    Output(1t):\t"_j)->append(i)
                    ->append(u" "_j)
                    ->append(npc(parser)->getText())
                    ->append(u" "_j)
                    ->append(npc(parser)->isWhitespace())->toString());
            }
        } else {
            npc(::java::lang::System::out())->println(u"[ FAILED ]"_j);
            npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"    Output(1):\t"_j)->append(i)
                ->append(u" "_j)
                ->append(npc(parser)->getName())->toString());
        }
    } else {
        npc(::java::lang::System::out())->println(u"[ FAILED ]"_j);
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"    Output(0t):\t"_j)->append(i)
            ->append(u" "_j)
            ->append(npc(parser)->getText())
            ->append(u" "_j)
            ->append(npc(parser)->isWhitespace())->toString());
    }
    npc(::java::lang::System::out())->println(u"-------------------------------------------------------------"_j);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::util::testing::XMLParserUnit::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.util.testing.XMLParserUnit", 35);
    return c;
}

java::lang::Class* rice::p2p::util::testing::XMLParserUnit::getClass0()
{
    return class_();
}

