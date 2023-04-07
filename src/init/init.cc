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

int main(int argc, char** argv)
{
	auto parser = optparse::OptionParser().version(VERSION);

	parser.add_option("-a", "--address").dest("address").set_default("127.0.0.1").help("Destination Address. Default: %default");
	parser.add_option("-p", "--port").dest("port").action("store").type("int").set_default(30200).help("Destination Port. Default: %default");
	parser.add_option("-t", "--test").dest("test").action("store").type("bool").set_default(false).help("Enable Test Environment.");
	parser.add_option("-m", "--mode").dest("mode").action("store").type("int").set_default(CLI_MODE).help("Program Mode. (0: CLI_MODE, 1: GUI_MODE, 2: TUI_MODE). Default: %default");
	
	optparse::Values options = parser.parse_args(argc, argv);
	
	ProgramMode = (int)options.get("mode");

	if (options.get("help"))
	{
		parser.print_help();
		return 0;
	}

	if (init_miniaudio() == ERROR)
	{
		returnError(error_type);
		return 1;
	}
	if (init_cppserver() == ERROR)
	{
		returnError(error_type);
		return 1;
	}
	if (init_ux() == ERROR)
	{
		returnError(error_type);
		return 1;
	}
	if (init_threads() == ERROR)
	{
		returnError(error_type);
		return 1;
	}

	getchar();
	stop_miniaudio_playback();
	stop_miniaudio_capture();

	return 0;
}

void returnError(int err)
{
	if (err == INIT_MINIAUDIO_ERROR)
	{
		printf("audiograph error occured: initiating");
		return;
	}
}
