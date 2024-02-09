I think yuv420p is the raw format. It doesnt matter if yuv or h264 for now, but i dont seem to get the right command line to use with https://github.com/aler9/rtsp-simple-server
Does work

This line correctly shows my camera video (also before i installed additional 500MB with the -dev plugins from qengineering tutorial)
gst-launch-1.0 libcamerasrc ! video/x-raw, width=640, height=480, framerate=30/1 ! videoconvert ! videoscale ! autovideosink

using libcamera-vid -t 0 --inline --listen -o tcp://0.0.0.0:8888 from https://www.tomshardware.com/how-to/use-raspberry-pi-camera-with-bullseye i can access the stream by tcp/h264://raspberrypi.local:8888
Does not work

Originally i tried to follow https://www.wtip.net/blog/2021/08/raspberry-pi-camera-rtsp-streaming-with-multiple-resolution-feeds/
The python script here https://gist.github.com/wtip/3057c777d2887919af2f1d3872c21405 uses something like
HQcmd = "gst-launch-1.0 fdsrc ! h264parse ! rtspclientsink location=rtsp://myuser:mypass@localhost:8554/hqstream debug=false"

gst-launch-1.0 libcamerasrc ! h264parse ! rtspclientsink location=rtsp://localhost:8554/stream1 gives WARNING: erroneous pipeline: could not link libcamerasrc0 to h264parse0

gst-launch-1.0 libcamerasrc !  rtspclientsink location=rtsp://localhost:8554/stream1 gives

ERROR: from element /GstPipeline:pipeline0/GstRTSPClientSink:rtspclientsink0: Could not open resource for reading and writing.
Additional debug info:
../gst/rtsp-sink/gstrtspclientsink.c(3250): gst_rtsp_client_sink_connect_to_server (): /GstPipeline:pipeline0/GstRTSPClientSink:rtspclientsink0:
Failed to connect. (Generic error)

The rtsp example from rtsp-simple-server says
ffmpeg -re -stream_loop -1 -i file.ts -c copy -f flv rtmp://localhost/mystream

and somewhere else i found
libcamera-vid --timeout 0000 --width 640 --height 480 --framerate 5   --codec h264 --profile high --intra 5 --output - |   gst-launch-1.0 -e libcamerasrc !   rtspclientsink location=rtsp://localhost:8554/stream1 which gives
ERROR V4L2 v4l2_device.cpp:349 'imx219 10-0010': Unable to set controls: Device or resource busy

libcamera-vid --timeout 0000 --width 640 --height 480 --framerate 5   --codec h264 --profile high --intra 5 --output - rtsp://localhost:8554/stream1
"streams" strange characters into my terminal. Comes from https://forums.raspberrypi.com/viewtopic.php?p=1937211&hilit=rtsp+stream+libcamera+vid#p1937211

I even installed vlc (another 150MB) https://forums.raspberrypi.com/viewtopic.php?p=1973706
$ libcamera-vid -t 0 --inline -o - | cvlc -vvv stream:///dev/stdin --sout '#rtp{sdp=rtsp://:8080/}' :demux=h264
but this also gave errors regarding Pulseaudio and unknown query 0x30e in demux_vaControlHelper

I have no further idea how a correct command line may look for terminal or rtsp-simple-server :-(
