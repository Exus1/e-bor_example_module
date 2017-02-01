#include <Module_interface.hpp>
#include <string>
#include <iostream>

using namespace std;

class New_module : public Module_interface {
public:
	void _callbacks() {

	}

	void module_loop() {
		cout << "Hi, I'm your new plugin" << endl;
		sleep(1);
	}
};

extern "C" Module_interface* module_downloader() {
	return new New_module();
}
