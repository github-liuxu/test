#include <stdio.h>
#include "FFReadWriter.h"

int main() {
    printf("Hello, World!\n");
    VideoReader *videoReader = new VideoReader();
    videoReader->Open("/Users/liudongxu/金晨卜卦.mp4");
    videoReader->SetRange(0, 10000000);
    AVFrame *frame = videoReader->ReadAVFrame();
    // LXVideoFrame *frame = videoReader->ReadVideoFrame();
    VideoWriter *videoWriter = new VideoWriter();
    videoWriter->OpenFile("/Users/liudongxu/金晨卜卦_out.mp4");
    videoWriter->StartFileWriter(1920, 1080);
    bool suc = videoWriter->WriterAVFrame(frame);
    while (videoWriter->WriterAVFrame(frame) != true)
    {
        /* code */
        frame = videoReader->ReadAVFrame();
    }
    
    videoWriter->WriterTrailer();
    // printf("frame width: %d, height: %d\n", frame->GetFrameBuffer()->width, frame->GetFrameBuffer()->height);
    return 0;
}