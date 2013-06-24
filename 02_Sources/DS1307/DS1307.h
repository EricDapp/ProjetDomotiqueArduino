/****************************************************************************************************
Name:				DS1307.h
--------------------------------------------------
Description:		TBW
--------------------------------------------------
Author:				Eric Dapp
--------------------------------------------------
Creation Date:		17.06.2013
--------------------------------------------------
History:

Date		|	Changement
----------
22.06.2013	|	First commit and upload into Git	
----------
24.06.2013	|	- Change the language to english
				- Change the constructor to take the "Serial" as input
****************************************************************************************************/


/******************************
	Define
******************************/
#ifndef DS1307_HEADER
#define DS1307_HEADER


/******************************
	Include
******************************/
#include <Wire.h>


/******************************
	Library Description
******************************/
class DS1307 {
    
	public:
	
		DS1307(Print &_serial);	// Constructor 
		
		void init(void);			// Initialization function
		
	private:
			// Attributs
		Print* serial;
			
			// Fonctions
		uint8_t is_Present(void);	// Check that the RTS is present
};

#endif

