#include <boost/algorithm/string.hpp>
#include <boost/dll/import.hpp>
#include <boost/function.hpp>
#include <boost/smart_ptr/shared_ptr.hpp>
#include <cstdlib>
#include <core/plugins.hpp>
#include <iostream>
#include <boost/thread/thread.hpp>
#include <boost/chrono.hpp>
#include <boost/function.hpp>
#include <boost/date_time/local_time/local_time.hpp>

namespace dll = boost::dll;
namespace dt = boost::date_time;
namespace lt = boost::local_time;

using create_plugin_type = boost::shared_ptr<cvnd::plugin>();

struct plugin_data {
    boost::function<create_plugin_type> creator;
    boost::shared_ptr<cvnd::plugin> instance;
};

int main(int argc, char* argv[]) {
    auto path_var = std::getenv("CVND_PATH");
    auto plugins_var = std::getenv("CVND_PLUGINS");
    std::vector<std::string> names;
    std::vector<plugin_data> plugins;
    //boost::shared_ptr<lt::time_zone> zone(new lt::posix_time_zone("CET"));

    boost::split(names, plugins_var, boost::is_any_of(","), boost::token_compress_on);

    for (auto&& name : names) {
	auto path_obj = dll::fs::path(path_var);
	auto create_plugin = dll::import_alias<create_plugin_type>(
		path_obj / name, "create_plugin",
		dll::load_mode::append_decorations);

	plugins.push_back({ create_plugin, create_plugin() });
    }

    while (true) {
	boost::this_thread::sleep_for(boost::chrono::seconds(1));
	for (auto i = 0; i < plugins.size(); i++) {
	    std::cout << "Plugin = " << plugins[i].instance->name() << ", Input = 5, Output = " << plugins[i].instance->invoke(5) << '\n';
	}
    }

    return 0;
}
