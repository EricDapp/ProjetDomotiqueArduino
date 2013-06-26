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
		
		void init(void);				// Initialization function
		
		
		
	private:
			// Attributs
		Print* 		serial;
		
		uint8_t 	second;				// Time components
    	uint8_t 	minute;
   		uint8_t 	hour; 
    	uint8_t 	day_Of_Week;		// Day of Week, 0 = sunday - TBC
    	uint8_t 	day;
    	uint8_t 	month;
    	uint16_t 	year;
			
			// Fonctions
		uint8_t 	is_Present	(void);	// Check that the RTS is present
		void 		start_Clock	(void);	// Start the clock
		void 		stop_Clock	(void);	// Stop the clock
		
		/*uint8_t 	get_Second 	();		// Get/Set Second
		void 		set_Second 	();
		
		uint8_t 	get_Minute 	();		// Get/Set Minute
		void 		set_Minute 	();
		
		uint8_t 	get_Hour 	();		// Get/Set Hour	
		void 		set_Hour 	();
		
		uint8_t 	get_Day_Of_Week	();	// Get/Set Day Of Week
		void 		set_Day_Of_Week ();
		
		uint8_t 	get_Day 	();		// Get/Set Day
		void 		set_Day 	();
		
		uint8_t 	get_Month 	();		// Get/Set Month
		void 		set_Month 	();
		
		uint16_t	get_Year	();		// Get/Set Year
		uint16_t	set_Year	();*/
};

#endif

