/*
 * Assignment2.cpp
 *
 *  Created on: 23/03/2013
 *      Author: Daniel Burnham-King
 *				BRNDAN022
 *	
 *	The Driver
 */

#include <iostream>
#include "cmdline_parser.h"
#include "Bucket_String.h"
#include <sstream>


int main(int argc, char * argv[])
{	using namespace BRNDAN022;
//Code from assignment 1 (to be reused for cmdline input)	
	// Instantiate the parser
	cmdline_parser parser;

	// Try parse command line arguments
	if(!parser.process_cmdline(argc, argv))
	{
		std::cout << "testme";
		// Complain to the standard error stream
		std::cerr << "Couldn't process command line arguments" << std::endl;
		return 1;
	}	
/*
*	testing
*/
	//create a bucket string with bucket size 7
	Bucket_String test(7);
	//create a string input stream
	std::istringstream testString("0abdcdefg");
	//test operator overloading by dumping the streams contents into the bucketString
	testString>>test;
	//output the contents of the string
	std::cout<<"output Test "<<test<<std::endl;
	std::cout<<"OUTPUT TEST "<<test[1]<<std::endl;


	// Print command line help to the standard output stream, if required
	//if(parser.should_print_help())
	//	{ parser.print_help(std::cout);	}

	//Instantiate the database:
	//std::string dbFileNamep = parser.get_database_filename();

//end of code from assignment 1

	return 0;

}