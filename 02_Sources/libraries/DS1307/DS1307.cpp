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
#define	_DS1307_Address 	0x68
#define _Oscillator_Address	0x00


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
		
		serial -> println ("RTC: Found...");
	}
	else {
		serial -> println ("RTC: NOT found !!!");
	}
	
	serial -> println ("RTC: Start...");
	start_Clock ();
	
}


/******************************
	Private
******************************/

	// Check if the RTC is present
uint8_t DS1307::is_Present (void)         	
{
  
	Wire.beginTransmission (_DS1307_Address);
	Wire.write ((uint8_t)_Oscillator_Address);
	
	if (Wire.endTransmission () == 0) {
	
		return 1;
	}
	return 0;
}


void DS1307::start_Clock (void)        			// Set the ClockHalt bit low to start the RTC
{
  Wire.beginTransmission (_DS1307_Address);
  Wire.write ((uint8_t)_Oscillator_Address);                 	// Register 0x00 holds the oscillator start/stop bit
  Wire.endTransmission ();
  Wire.requestFrom (_DS1307_Address, 1);
  second = Wire.read () & 0x7f;       			// Save actual seconds and AND sec with bit 7 (sart/stop bit) = clock started
  Wire.beginTransmission (_DS1307_Address);
  Wire.write ((uint8_t)_Oscillator_Address);
  Wire.write ((uint8_t)second);              	// Write seconds back and start the clock
  Wire.endTransmission ();
}

void DS1307::stop_Clock (void)         			// Set the ClockHalt bit high to stop the RTC
{
  Wire.beginTransmission (_DS1307_Address);
  Wire.write ((uint8_t)_Oscillator_Address);                 	// Register 0x00 holds the oscillator start/stop bit
  Wire.endTransmission ();
  Wire.requestFrom (_DS1307_Address, 1);
  second = Wire.read() | 0x80;       			// Save actual seconds and OR sec with bit 7 (sart/stop bit) = clock stopped
  Wire.beginTransmission (_DS1307_Address);
  Wire.write ((uint8_t)_Oscillator_Address);
  Wire.write ((uint8_t)second);                 // Write seconds back and stop the clock
  Wire.endTransmission ();
}




	// Get Second
/*uint8_t DS1307::get_Second () {
	
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
	
	
}*/
