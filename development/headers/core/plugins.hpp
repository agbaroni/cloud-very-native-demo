#ifndef __CVND_PLUGINS_HPP__
#define __CVND_PLUGINS_HPP__

#include <string>

namespace cvnd {

    class plugin {
	public:
	    virtual ~plugin() {}

	    virtual double invoke(double) = 0;

	    virtual std::string name() const = 0;
    };

}

#endif /* __CVND_PLUGINS_HPP__ */
