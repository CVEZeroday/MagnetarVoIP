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

#include <gst/gst.h>
#include <string.h>

#include "nw_interface.h"
#include "macros.h"
#include "settings.h"

GstElement* appsrc;
GstElement* pipeline_send;

uint8_t send_rtp(const uint8_t* data, size_t size)
{
  GstBuffer *buffer = gst_buffer_new_allocate(NULL, size, NULL);
  gst_buffer_fill(buffer, 0, data, size);

  GstFlowReturn flow_return;
  g_signal_emit_by_name(appsrc, "push-buffer", buffer, &flow_return);
  DEBUG_PRINTF("send_rtp: signal emited: %d\n", data[size-1]);
  gst_buffer_unref(buffer);

  if (flow_return != GST_FLOW_OK) {
    DEBUG_PRINTF("Gst Flow Err: %s\n", gst_flow_get_name(flow_return));
    return 1;
  }
  return 0;
}

uint8_t init_send_rtp()
{
  gchar pipeline_send_str[256] = { 0 };
  g_snprintf(pipeline_send_str, sizeof(pipeline_send_str),
             "appsrc name=appsrc_send format=GST_FORMAT_TIME "
             "caps=\"application/x-rtp, media=audio, payload=%d, encoding-name=OPUS\" !" 
             "rtpopuspay !"
             "udpsink host=%s port=%d", RTP_PAYLOAD_TYPE, Address, Port);
  GError* gst_error = NULL;
  pipeline_send = gst_parse_launch(pipeline_send_str, &gst_error);

  if (pipeline_send == NULL) 
  {
    g_printerr("Failed to launch pipeline_send: %s\n", gst_error->message);
    g_clear_error(&gst_error);
    return 1;
  }

  appsrc = gst_bin_get_by_name(GST_BIN(pipeline_send), "appsrc_send");
  if (appsrc == NULL)
  {
    g_printerr("Failed to find appsrc_send element in GStreamer pipeline_send\n");
    gst_object_unref(pipeline_send);
    return 1;
  }

  GstStateChangeReturn sret = gst_element_set_state(pipeline_send, GST_STATE_PLAYING);
  if (sret == GST_STATE_CHANGE_FAILURE)
  {
    g_printerr("Failed to start pipeline_send\n");
    gst_object_unref(pipeline_send);
    return 1;
  }

  DEBUG_PRINTF("Gstreamer sendation pipeline initiated.\n");
  return 0;
}

void close_send_rtp()
{
  gst_element_set_state(pipeline_send, GST_STATE_NULL);
  gst_object_unref(pipeline_send);
}
