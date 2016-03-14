/////////////////////////////////////////////
// Modified by...
// Name : Sanghun Kim
// ID   : 015072150
// email: ksanghun@myseneca.ca 
/////////////////////////////////////////////



#ifndef SICT_GENERAL_H__
#define SICT_GENERAL_H__

#define TAX 0.13             //The tax value for the NFI items MAX_SKU_LEN(7)        The maximum size of a SKU
#define MAX_SKU_LEN 7
#define DISPLAY_LINES 10     //Product lines to display before each pause
#define MIN_YEAR 2000        //The min and max for year to be used for date validation MAX_YEAR(2030)
#define MAX_YEAR 2030        //The min and max for year to be used for date validation MAX_YEAR(2030)
#define MAX_NO_RECS 2000     //The maximum number of records in the data file.


// error code //
#define NO_ERROR   0  //--No error the date is valid 
#define CIN_FAILED 1  //--istream failed when entering information 
#define YEAR_ERROR 2  //--Year value is invalid 
#define MON_ERROR  3  //--Month value is invalid 
#define DAY_ERROR  4  //--Day value is invalid


#endif