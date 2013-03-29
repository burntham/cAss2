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
//Code from assignment 1 (to be reused for cmdline input) - command line has been slightly edited;
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
//END OF CODE FROM ASSIGNMENT 1 

///File input::::
	std::string sFileName = parser.get_string_filename();
	char * filename = (char*)sFileName.c_str();
	std::fstream stringFile(filename);
	std::string input;
	std::getline(stringFile, input);
	//input string stream for parsing string to Bucket_String
	std::istringstream actualString(input);
////End of File input

//Testing and Output:
  //input bucket size
	int BucketSize;
	std::cout<<"Please enter desired bucket size (0 or a character will default it to 7):";
	std::cin>>BucketSize; 
	BucketSize = (BucketSize==0) ? 7: BucketSize;
	std::cout<<"\n"<<"right oh! - each bucket will contain "<<BucketSize<<" characters."<<std::endl;
	
	//def constructor
	Bucket_String bucketDefault(BucketSize);
	//>>operator
	actualString>>bucketDefault;
	//copy constructor
	Bucket_String bucketCopied(bucketDefault);
	//copy Assignment operator test
	Bucket_String bucketAssigned(7);
	bucketAssigned = bucketDefault;
	//<<operator
	std::cout<<"output of original: ";
	std::cout<<bucketDefault<<std::endl;
	std::cout<<"output of copy constructed: ";
	std::cout<<bucketCopied<<std::endl;
	std::cout<<"output of copy assigned: ";
	std::cout<<bucketAssigned<<std::endl;








	return 0;
}