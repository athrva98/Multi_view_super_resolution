#pragma once
#include <string>

#include "example/FrameSource/CaptureFrameSource.hpp"

using namespace std;

class VideoFrameSource : public CaptureFrameSource
{
public:
	explicit VideoFrameSource(const string& videoFileName);
	void reset() override;

private:
	string videoFileName;
};

inline VideoFrameSource::VideoFrameSource(const string& videoFileName) : videoFileName(videoFileName)
{
	reset();
}

inline void VideoFrameSource::reset()
{
	videoCapture.release();
	videoCapture.open(videoFileName);
	CV_Assert(videoCapture.isOpened());
}
