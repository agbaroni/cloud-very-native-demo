#ifndef __CVND_P2_HPP__
#define __CVND_P2_HPP__

#include <boost/dll/alias.hpp>
#include <boost/smart_ptr/shared_ptr.hpp>
#include "core/plugins.hpp"

namespace cvnd {

    class p2 : public plugin {
	public:
	    static boost::shared_ptr<p2> create();

	    ~p2();

	    double invoke(double) override;

	    std::string name() const override;

	private:
	    p2();
    };

}

#endif /* __CVND_P2_HPP__ */
