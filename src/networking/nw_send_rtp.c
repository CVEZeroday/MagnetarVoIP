/********************************************/
/* This source code is part of MagnetarVoIP */
/********************************************/
/*     Copyrights (C) 2023 CVE_zeroday.     */
/*          All rights reserved.            */
/********************************************/
/*       File Name: nw_send_rtp.cc          */
/*   Created by CVE_zeroday on 22.06.2023   */
/*               (T.Y.Kim)                  */
/********************************************/

#include <stdint.h>
#include <re/re.h>
#include <re/rem.h>

#include "nw_interface.h"
#include "macros.h"
#include "settings.h"

struct sa local_src;
struct sa local_dst;

static struct rtcp_stats rtcp_stats;
static struct rtp_socket* rtpsock;

uint8_t send_rtp(const uint8_t* data, size_t size)
{

}