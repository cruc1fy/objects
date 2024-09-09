#include "Base.h"

Base::Base(Base* head_object, string object_name, char object_type)
{
	this->head_object = head_object;
	this->name = object_name;
	this->state = 1;
	this->object_type = object_type;

	if (head_object)
	{
		this->head_object->obey_objects.push_back(this);
	}

}

void Base::set_object_name(string name)
{
	this->name = name;
}

string Base::get_object_name()
{
	return this->name;
}

void Base::output_state_object_tree(int counter)
{
	for (int i = 0; i < obey_objects.size(); i++)
	{
		for (int i = 0; i <= counter; i++)
		{
			cout << "    ";
		}

		cout << this->obey_objects[i]->get_object_name() << " " << this->obey_objects[i]->object_type;

		if (this->obey_objects[i]->state != 0)
		{
			cout << " is ready" << endl;
		}
		else
		{
			cout << " is not ready" << endl;
		}

		//		cout << "\n";

		if (obey_objects[i]->obey_objects.size() != 0)
		{
			obey_objects[i]->output_state_object_tree(counter + 1);
		}
	}
}

void Base::output_object_tree(int counter)
{
	for (int i = 0; i < obey_objects.size(); i++)
	{
		for (int i = 0; i <= counter; i++)
		{
			cout << "    ";
		}

		cout << this->obey_objects[i]->get_object_name();
		cout << "\n";

		if (obey_objects[i]->obey_objects.size() != 0)
		{
			obey_objects[i]->output_object_tree(counter + 1);
		}
	}
}

void Base::change_head_object(Base* new_head_object)
{
	if (new_head_object == nullptr)
	{
		cout << "ERR: You're trying to create new root object!" << endl;
		return;
	}
	if (this->head_object == nullptr)
	{
		cout << "ERR: You're trying to change root object's head object!" << endl;
		return;
	}
	for (int i = 0; i < obey_objects.size(); i++)
	{
		if (obey_objects[i] == new_head_object)
		{
			cout << "ERR: You're trying to create recursive tree!" << endl;
			return;
		}
		obey_objects[i]->change_head_object(new_head_object);
	}
	for (int i = 0; i < head_object->obey_objects.size(); i++)
	{
		if (head_object->obey_objects[i] == this)
		{
			head_object->obey_objects.erase(head_object->obey_objects.begin() + i);
		}
	}
	this->head_object = new_head_object;
	new_head_object->obey_objects.push_back(this);

}

Base* Base::get_head_object()
{
	return head_object;
}

Base* Base::downstairs_search(string object_name)
{
	Base* temp = nullptr;

	if (this->get_object_name() == object_name)
	{
		return this;
	}

	for (int i = 0; i < this->obey_objects.size(); i++)
	{
		if (temp != nullptr)
		{
			break;
		}
		if (obey_objects[i]->name == object_name)
		{
			temp = obey_objects[i];
			break;
			//cout << obey_objects[i]->get_object_name() << endl;
		}
		else
		{
			temp = obey_objects[i]->downstairs_search(object_name);
		}
	}
	return temp;
}

Base* Base::absolute_search(string object_name)
{
	Base* buffer = this;
	while (buffer->head_object != nullptr)
	{
		buffer = buffer->head_object;
	}

	return buffer->downstairs_search(object_name);
}

Base* Base::get_obeyObjects(int number)
{
	return this->obey_objects[number];
}

void Base::state_change(int object_state)
{
	Base* buffer = this;
	bool is_enabled = true;

	if (object_state != 0)
	{
		while (buffer->head_object != nullptr)
		{
			if (buffer->head_object->state == 0)
			{
				is_enabled = false;
				break;
			}

			buffer = buffer->head_object;
		}

		if (buffer->state == 0)
		{
			is_enabled = false;
		}

		if (is_enabled == true)
		{
			this->state = object_state;
		}
	}
	else
	{
		this->state = object_state;
		for (int i = 0; i < this->obey_objects.size(); i++)
		{
			obey_objects[i]->state_change(object_state);
		}
	}
}

int Base::get_object_type()
{
	return object_type;
}