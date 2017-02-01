#ifndef _MODULE_INTEFACE__HPP
#define _MODULE_INTEFACE__HPP

#include <iostream>
#include <map>
#include <string>

#include <Ts3Api/Server.hpp>

using namespace std;

class Module_interface {
	friend class Modules_manager;
protected:
	struct module_informations {
		string module_name = "New module";
		string module_prefix = "nw";
		string module_version = "0.1a";

		float minimum_api_versiion = 0.1;
		float minimum_ebot_version = 0.1;
	};

	struct callback_function_return {
		string message = "Error";

		bool success = false;
	};

protected:
	Ts3Api::Server *server = NULL;

	map<string, void*> callback_functions;

	void set_server_object(Ts3Api::Server* server) { this->server = server; };
public:
	virtual void _callbacks()=0;

	virtual void module_loop()=0;
};




#endif