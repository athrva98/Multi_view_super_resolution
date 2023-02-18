#pragma once

#include "example/FrameSource/EmptyFrameSource.hpp"
#include "example/FrameSource/VideoFrameSource.hpp"
#include "example/FrameSource/ImageListFrameSource.hpp"

class FrameSourceFactory
{
public:
	static cv::Ptr<FrameSource> createEmptyFrameSource()
	{
		return new EmptyFrameSource();
	}

	static cv::Ptr<FrameSource> createFrameSourceFromVideo(const string& videoFileName)
	{
		return new VideoFrameSource(videoFileName);
	}

	static Ptr<FrameSource> createFrameSourceFromImageList(const int& image_count, string file_name_format, int start_index = 0)
	{
		return  new ImageListFrameSource(image_count, file_name_format, start_index);
	}
};

