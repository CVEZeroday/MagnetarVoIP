/********************************************/
/* This source code is part of MagnetarVoIP */
/********************************************/
/*     Copyrights (C) 2023 CVE_zeroday.     */
/*          All rights reserved.            */
/********************************************/
/*           File Name: init.cc             */
/*   Created by CVE_zeroday on 09.03.2023   */
/*               (T.Y.Kim)                  */
/********************************************/

#include <thread>
#include <iostream>

#include <magnetar.h>
#include <include_all.h>
#include <optparse/OptionParser.h>

void returnError(int err)
{
	if (err == INIT_AUDIOGRAPH_ERROR)
	{
		printf("audiograph error occured: initiating");
		return;
	}
}

int main(int argc, char** argv)
{
	int n = 10;
	printf("%d", n);
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

	if (init_audiograph() == ERROR)
	{
		returnError(INIT_AUDIOGRAPH_ERROR);
		return 1;
	}
	if (init_cppserver() == ERROR)
	{
		returnError(INIT_CPPSERVER_ERROR);
		return 1;
	}
	if (init_cli() == ERROR)
	{
		returnError(INIT_CLI_ERROR);
		return 1;
	}

	return 0;
}