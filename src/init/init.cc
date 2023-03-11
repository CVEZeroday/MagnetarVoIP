/*******************************************/
/* This source code is part of PulsarVoIP  */
/*******************************************/
/*     Copyrights (C) 2023 CVE_zeroday.    */
/*          All rights reserved            */
/*******************************************/
/*           File Name: init.cc            */
/*   Created by CVE_zeroday on 09.03.2023  */
/*               (T.Y.Kim)                 */
/*******************************************/

#pragma comment(lib, "asio.lib")
#pragma comment(lib, "cppbenchmark.lib")
#pragma comment(lib, "cpp-optparse.lib")
#pragma comment(lib, "cppserver.lib")
#pragma comment(lib, "libsoundio.lib")
#pragma comment(lib, "opus.lib")

#include <thread>
#include <iostream>

#include <optparse/OptionParser.h>



int main(int argc, char** argv)
{
	auto parser = optparse::OptionParser().version("1.0.0.0");

	parser.add_option("-a", "--address").dest("address").set_default("127.0.0.1").help("Destination Address. Default: %default");
	parser.add_option("-p", "--port").dest("port").action("store").type("int").set_default(30200).help("Destination Port. Default: %default");
	parser.add_option("-t", "--test").dest("test").action("store").type("bool").set_default(false).help("Enable Test Environment.");
	
	optparse::Values options = parser.parse_args(argc, argv);

	if (options.get("help"))
	{
		parser.print_help();
		return 0;
	}
}