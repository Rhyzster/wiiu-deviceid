#include <string.h>
#include <dynamic_libs/os_functions.h>
#include <system/memory.h>
#include <common/common.h>
#include <screen/tty.h>
#include "main.h"

int __entry_menu(int argc, char **argv)
{		
	// Run the Main function
    int ret = Menu_Main();

	// Return the result of the main function
    return ret;
}
