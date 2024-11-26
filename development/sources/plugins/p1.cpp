#include "plugins/p1.hpp"
#include <boost/smart_ptr/make_shared.hpp>

using namespace cvnd;

BOOST_DLL_ALIAS(cvnd::p1::create, create_plugin)

boost::shared_ptr<p1> p1::create() {
    return boost::shared_ptr<p1>(new p1);
}

p1::p1() {}

p1::~p1() {}

double p1::invoke(double x) {
    return x * 2;
}

std::string p1::name() const {
    return "p1";
}
