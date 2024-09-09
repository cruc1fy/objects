#pragma once
#include "Base.h"
class Application : public Base
{
public:
	Application(Base* head_object, string object_name = "object0", int object_type = 0);
	void build_tree_objects();
	int exec_app();

};
