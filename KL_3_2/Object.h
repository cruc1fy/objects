#pragma once
#include "Base.h"
class Object : public Base
{
public:
	Object(Base* head_object, string object_name = "object0", char object_type = '0');
};
