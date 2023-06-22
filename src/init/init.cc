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

/*
* 1. Summary
*   This file is for initiating MagnetarVoIP.
*   This file contains a function for interfacing main thread to error processing system.
*   This file contains main function.
*
* 2. Global Variables
*   <none>
*
* 3. Functions
* int main(int argc, char** argv)
*   1. Parse the options
*   2. Save the parsed options
*   3. initiate modules
*   4. If initialization failed, call returnError()
*   5. If program ended (When MAIN_FLAG in Intialized is off), exit the program
*
* void returnError(int err)
*   1. Process error situations
*
*/

#include <thread>
#include <iostream>

#include <magnetar.h>

#include "init.h"
#include "init_ux.h"
#include "init_miniaudio.h"
#include "init_network.hpp"
#include "macros.h"
#include "settings.h"
#include "aio.h"
#include "core_thread.h"

#include <optparse/OptionParser.h>

int32_t main(int argc, char** argv)
{
  auto parser = optparse::OptionParser().version(VERSION);

  parser.add_option("-a", "--address").dest("address").set_default("127.0.0.1").help("Destination Address. Default: %default");
  parser.add_option("-p", "--port").dest("port").action("store").type("int").set_default(30200).help("Destination Port. Default: %default");
  parser.add_option("-t", "--test").dest("test").action("store").type("bool").set_default(false).help("Enable Test Environment.");
  parser.add_option("-s", "--server").dest("server").action("store").type("bool").set_default(true).help("Enable Server Mode. Default: %default");
  parser.add_option("-m", "--mode").dest("mode").action("store").type("int").set_default(CLI_MODE).help("Program Mode. (0: CLI_MODE, 1: GUI_MODE, 2: TUI_MODE). Default: %default");

  optparse::Values options = parser.parse_args(argc, argv);

  std::string _addr = (std::string)options.get("address");
  strncpy(Address, _addr.c_str(), 0x10);
  Port = (int32_t)options.get("port");
  TestMode = (int32_t)options.get("test"); 
  IsServer = (int32_t)options.get("server");
  ProgramMode = (int32_t)options.get("mode");

  if (options.get("help"))
  {
    parser.print_help();
    return 0;
  }

  if (init_miniaudio() == MAGNETARVOIP_ERROR)
  {
    returnError(error_type);
    return 1;
  }
  if (init_cppserver() == MAGNETARVOIP_ERROR)
  {
    returnError(error_type);
    return 1;
  }
  if (init_threads() == MAGNETARVOIP_ERROR)
  {
    returnError(error_type);
    return 1;
  }
  if (init_rtp() == 1)
  {
    returnError(error_type);
    return 1;
  }

  return 0;
}

void returnError(int32_t err)
{
  if (err == INIT_MINIAUDIO_ERROR)
  {
    printf("audiograph error occured: initiating");
    return;
  }
}
