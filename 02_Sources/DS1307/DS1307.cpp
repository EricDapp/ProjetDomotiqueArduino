/****************************************************************************************************
Name:				DS1307.cpp
--------------------------------------------------
Description:		TBW
--------------------------------------------------
Author:				Eric Dapp
--------------------------------------------------
Creation Date:		17.06.2013
--------------------------------------------------
History:

Date		|	Change
----------
22.06.2013	|	First commit and upload into Git	
----------
24.06.2013	|	- Change the language to english
				- Change the constructor to take the "Serial" as input
****************************************************************************************************/


/******************************
	Define
******************************/
#define DS1307_Address 	0x68


/******************************
	Include
******************************/
#include "DS1307.h" 


/******************************
	Public
******************************/
	// Constructor
DS1307::DS1307 (Print &_serial)
{
 
	Wire.begin();
	serial = &_serial;
}


void DS1307::init ()
{
		// Check if the RTC is present
	if (is_Present ()) {
		
		serial -> println ("RTC found...");
	}
	else {
		serial -> println ("!!! Error: RTC not found !!!");
	}
}


/******************************
	Private
******************************/

	// Check if the RTC is present
uint8_t DS1307::is_Present (void)         	
{
  
	Wire.beginTransmission (DS1307_Address);
	Wire.write ((uint8_t)0x00);
	
	if (Wire.endTransmission () == 0) {
	
		return 1;
	}
	return 0;
}