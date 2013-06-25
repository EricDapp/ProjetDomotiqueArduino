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


	// Get Second
uint8_t DS1307::get_Second () {
	
	return second;
}		

	// Set Second
void set_Second () {
	
	
}

	// Get Minute
uint8_t get_Minute () {
	
	return minute;
}	

	// Set Minute
void set_Minute () {
	
}
	// Get Hour
uint8_t get_Hour (){
	
	return hour;
}

	// Set Hour
void set_Hour (){
	
}
		
	// Get Day Of Week
uint8_t get_Day_Of_Week	() {
	
	return day_Of_Week;
}

	// Set Day Of Week
void set_Day_Of_Week () {
	
	
}
	
	// Get Day
uint8_t get_Day () {
	
	return day;
}

	// Set Day
void set_Day () {
	
	
}

	// Get Month
uint8_t get_Month () {
	
	return month;
}

	// Set Month
void set_Month () {
	
	
}
	
	// Get Year
uint16_t get_Year () {
	
	return year;
}	

	// Set Year
uint16_t set_Year () {
	
	
}
