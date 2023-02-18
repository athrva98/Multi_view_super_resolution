#pragma once
#include <opencv2/core.hpp>
#include <vector>
#include <opencv2/highgui.hpp>
#include "ImageListReaderBase.hpp"
#include <iostream>
class ImageListReader : public ImageListReaderBase
{
public:
	explicit ImageListReader(const std::string& file_name_format = "", int start_index = 0): ImageListReaderBase(file_name_format, start_index)
	{
	}

	void ReadImageList(std::vector<cv::Mat>& imageList, int imageCount) override;
};

inline void ImageListReader::ReadImageList(std::vector<cv::Mat>& image_list, int image_count)
{
    if ((unsigned int)image_count != image_list.size())
		return;

	auto fileNameFormatCStr = fileNameFormat.c_str();
    int CV_LOAD_IMAGE_GRAYSCALE = 0;
	for (auto i = startIndex; i < (image_count + startIndex); ++i)
	{
        char name[90]; // this is very hacky. The name could be longer.
		snprintf(name, sizeof(name), fileNameFormatCStr, i);

        std::string fullName(name);
        auto curImg = cv::imread(fullName, CV_LOAD_IMAGE_GRAYSCALE);
        cv::Mat floatGrayImg;
		curImg.convertTo(floatGrayImg, CV_32FC1);

		floatGrayImg.copyTo(image_list[i - startIndex]);
	}
//    for (unsigned int k = 0; k < image_list.size(); k++)
//    {
//        cv::Mat simg;

//        image_list[k].convertTo(simg, CV_8SC1);
//        cv::imshow("Image", simg);
//        cv::waitKey(35);



//    }
//    cv::destroyAllWindows();
}
