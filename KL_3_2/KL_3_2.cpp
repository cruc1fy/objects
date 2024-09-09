#include "Base.h"
#include "Application.h"

#include <iostream>

int main()
{
    Application object0(nullptr);
    object0.build_tree_objects();
    return object0.exec_app();
}


