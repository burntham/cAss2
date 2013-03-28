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
#include <fstream>


int main(int argc, char * argv[])
{	using namespace BRNDAN022;
//Code from assignment 1 (to be reused for cmdline input)	
	// Instantiate the parser
	cmdline_parser parser;

	// Try parse command line arguments
	if(!parser.process_cmdline(argc, argv))
	{
		// Complain to the standard error stream
		std::cerr << "Couldn't process command line arguments" << std::endl;
		return 1;
	}	

	//Print command line help to the standard output stream, if required
	if(parser.should_print_help())
		{ parser.print_help(std::cout);	}

	//Instantiate the string thing
	Bucket_String myBuckets(7);
	//Show Copy Constructor is working

///File input::::
	std::string sFileName = parser.get_string_filename();
	char * filename = (char*)sFileName.c_str();
	std::fstream stringFile(filename);
	std::string input;
	std::getline(stringFile, input);
	std::istringstream actualString(input);
////End of File input
//Pass string stored in file to a bucket string
	actualString>>myBuckets;
//etc
	Bucket_String Bucket1 = myBuckets;

	iterator buck= myBuckets.begin();
	iterator buckend= myBuckets.end();

	Bucket_String test1(myBuckets);
	test1.replace((test1.begin()+3),(test1.begin()+40),myBuckets);

	std::cout<<test1<<std::endl;
	//std::cout<<myBuckets<<std::endl;
	//std::cout<<Bucket1<<std::endl;

//end of code from assignment 1
	return 0;
}