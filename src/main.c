#include <main.h>

int Menu_Main(void)
{
	InitOSFunctionPointers();
	InitVPadFunctionPointers();
	
	tty_init(); // Initialize screen and stdout/stdin devoptabs
	s32 mcpHandle = MCP_Open(); //grab handle for access to MCP functions
	
	if(mcpHandle != 0){
		uint32_t id;
		MCP_GetDeviceId(mcpHandle, &id);
		printf("Device ID: ");
		printf("%" PRIu32 "\n\npress home to exit \n",id);
		MCP_Close(mcpHandle);		
	}else{
		//idk what to say if this ever occurs
		printf("error");
	}
	// Wait for the user to press the Home Button
	while(1)
	{
		update_buttons();						// Update buttons state
		if (button_pressed(VPAD_BUTTON_HOME))	// Check if home is pressed
			break;								// Exit the while loop
	}
		
	// Deinitialize screen
	tty_end();

	return 0;
}

