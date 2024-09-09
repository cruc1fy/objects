#include "Application.h"
#include "Object.h"
#include "Object_2.h"
#include "Object_3.h"
#include "Object_4.h"
#include "Object_5.h"
#include "Object_6.h"


Application::Application(Base* head_object, string object_name, int object_type) : Base(head_object, object_name, object_type)
{

}

/*void Application::build_tree_objects()
{
	Base* current_head_object = this;
	Base* new_head_object;

	string head_object_name;
	string new_object_name;

	cout << "Enter the same names to the both head and new objects to terminate the programm" << endl;
	cout << "Enter root object name: ";
	cin >> head_object_name;

	this->set_object_name(head_object_name);

	cout << "Enter head object's name: ";
	cin >> head_object_name;
	cout << "Enter new object's name: ";
	cin >> new_object_name;

	Base* new_object = new Object(current_head_object, new_object_name);

	new_head_object = new_object;

	if (head_object_name == new_object_name)
	{
		return;
	}

	while (true)
	{
		cout << "Enter head object's name: ";
		cin >> head_object_name;
		cout << "Enter new object's name: ";
		cin >> new_object_name;

		if (head_object_name == new_object_name)
		{
			break;
		}

		if (new_head_object->get_object_name() == head_object_name)
		{
			//			cout << "Otladochniy vivod";
			current_head_object = new_head_object;
		}

		Base* new_object = new Object(current_head_object, new_object_name);

		new_head_object = new_object;


	}
} */

void Application::build_tree_objects()
{
	Base* current_head_object = this;
//	Base* new_head_object;
	char object_type;

	string head_object_name;
	string new_object_name;

	cout << "Enter the same names to the both head and new objects to terminate the programm" << endl;
	cout << "Enter root object name: ";
	cin >> head_object_name;

	this->set_object_name(head_object_name);

	while (true)
	{
		cout << "Enter head object's name: ";
		cin >> head_object_name;
		cout << "Enter new object's name: ";
		cin >> new_object_name;

		if (head_object_name == new_object_name)
		{
			break;
		}

		cout << "Enter object's type(1-6): ";
		cin >> object_type;

		current_head_object = absolute_search(head_object_name);

		switch (object_type)
		{
			case '1':
			{
				Base* new_object = new Object(current_head_object, new_object_name, object_type);
				break;
			}
			case '2':
			{
				Base* new_object_2 = new Object_2(current_head_object, new_object_name, object_type);
				break;
			}
			case '3':
			{
				Base* new_object_3 = new Object_3(current_head_object, new_object_name, object_type);
				break;
			}
			case '4':
			{
				Base* new_object_4 = new Object_4(current_head_object, new_object_name, object_type);
				break;
			}
			case '5':
			{
				Base* new_object_5 = new Object_6(current_head_object, new_object_name, object_type);
				break;
			}
			case '6':
			{
				Base* new_object_6 = new Object_6(current_head_object, new_object_name, object_type);
				break;
			}
		}
	}
}

int Application::exec_app()
{
	string object_name;
	int new_state;
	Base* search_result;


	while (true)
	{
		cout << "Enter object's name to change it's state: ";
		cin >> object_name;

		if (object_name == "C" || object_name == "c")
		{
			break;
		}

		cout << "Enter new state of the object: ";
		cin >> new_state;

		search_result = absolute_search(object_name);

		search_result->state_change(new_state);
	}

	cout << this->get_object_name() << endl;
	output_object_tree();
	cout << endl;
	cout << "Objects tree with state: " << endl;
	cout << endl;
	cout << this->get_object_name();

	if (state != 0)
	{
		cout << " is enabled" << endl;
	}
	else
	{
		cout << " is disabled" << endl;
	}

	output_state_object_tree();
	return 0;
}