#ifndef __CVND_P1_HPP__
#define __CVND_P1_HPP__

#include <boost/dll/alias.hpp>
#include <boost/smart_ptr/shared_ptr.hpp>
#include "core/plugins.hpp"

namespace cvnd {

    class p1 : public plugin {
	public:
	    static boost::shared_ptr<p1> create();

	    ~p1();

	    double invoke(double) override;

	    std::string name() const override;

	private:
	    p1();
    };

}

#endif /* __CVND_P1_HPP__ */
