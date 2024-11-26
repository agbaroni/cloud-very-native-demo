#include "plugins/p2.hpp"
#include <boost/smart_ptr/make_shared.hpp>

using namespace cvnd;

BOOST_DLL_ALIAS(cvnd::p2::create, create_plugin)

boost::shared_ptr<p2> p2::create() {
    return boost::shared_ptr<p2>(new p2);
}

p2::p2() {}

p2::~p2() {}

double p2::invoke(double x) {
    return x * 3;
}

std::string p2::name() const {
    return "p2";
}
