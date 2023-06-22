/********************************************/
/* This source code is part of MagnetarVoIP */
/********************************************/
/*     Copyrights (C) 2023 CVE_zeroday.     */
/*          All rights reserved.            */
/********************************************/
/*       File Name: nw_recv_rtp.cc          */
/*   Created by CVE_zeroday on 22.06.2023   */
/*               (T.Y.Kim)                  */
/********************************************/

#include <gst/gst.h>
#include <gst/rtp/gstrtpbuffer.h>
#include <gst/rtp/gstrtppayloads.h>
#include <string.h>

#include "nw_interface.h"
#include "macros.h"
#include "settings.h"

GAsyncQueue* jitter_buffer;
GstElement* appsink;
GstElement* pipeline_recv;

gboolean on_rtp_packet_recieved(GstElement* element, GstBuffer* buffer, gpointer user_data);

uint8_t init_recv_rtp()
{
  gchar pipeline_recv_str[256] = { 0 };
  g_snprintf(pipeline_recv_str, sizeof(pipeline_recv_str),
             "udpsrc name=udpsrc_rtp, port=%d "
             "caps=\"application/x-rtp, media=audio, payload=%d, clock-rate=%d, encoding-name=OPUS\" !"
             "rtpjitterbuffer latency=0 ! rtpopusdepay !"
             "appsink name=appsink_rtp emit-signals=trye sync=false qos=false async=false", Port, RTP_PAYLOAD_TYPE, SAMPLE_RATE);
  GError* gst_error = NULL;
  pipeline_recv = gst_parse_launch(pipeline_recv_str, &gst_error);

  GstElement* udpsrc = gst_bin_get_by_name(GST_BIN(pipeline_recv), "udpsrc_rtp");
  appsink = gst_bin_get_by_name(GST_BIN(pipeline_recv), "appsink_rtp");

  jitter_buffer = g_async_queue_new();

  g_signal_connect(udpsrc, "pad-added", G_CALLBACK(on_rtp_packet_recieved), jitter_buffer);

  gst_element_set_state(pipeline_recv, GST_STATE_PLAYING);
  return 0;
}

gboolean on_rtp_packet_recieved(GstElement* element, GstBuffer* buffer, gpointer user_data)
{
  GstRTPBuffer buf = GST_RTP_BUFFER_INIT;
  GstMapInfo map_info;
  GstBuffer* payload;

  if (gst_rtp_buffer_map(buffer, GST_MAP_READ, &buf))
  {
    guint8* payload_data = gst_rtp_buffer_get_payload(&buf);
    guint payload_size = gst_rtp_buffer_get_payload_len(&buf);

    payload = gst_buffer_copy_region(buffer, GST_BUFFER_COPY_MEMORY, (payload_data-map_info.data), payload_size);
    
    g_async_queue_push(jitter_buffer, payload);

    gst_rtp_buffer_unmap(&buf);
  }
  return GST_FLOW_OK;
}

void close_recv_rtp()
{
  gst_element_set_state(pipeline_recv, GST_STATE_NULL);
  gst_object_unref(pipeline_recv);
  g_async_queue_unref(jitter_buffer);
}

