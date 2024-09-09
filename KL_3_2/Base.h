#pragma once
#include <string>
#include <cctype>
#include <iostream>
#include <vector>

using namespace std;

class Base
{
private:
	string name;
	Base* head_object = nullptr;
	vector <Base*> obey_objects;
	char object_type;

protected:
	int state;

public:
	Base(Base* head_object, string object_name = "object0", char object_type = '0');
	void set_object_name(string name);
	string get_object_name();
	void output_object_tree(int counter = 0);
	void output_state_object_tree(int counter = 0);
	void change_head_object(Base* new_head_object);
	Base* get_head_object();
	Base* downstairs_search(string object_name);
	Base* absolute_search(string object_name);
	Base* get_obeyObjects(int number);
	void state_change(int object_state);
	int get_object_type();

};

