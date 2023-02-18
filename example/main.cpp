#include "example/FrameSource/FrameSourceFactory.h"
//#include "include/FrameSource/"
#include "include/SuperResolution/SuperResolutionBase.h"
#include "include/SuperResolution/SuperResolutionFactory.h"

#include <iostream>

using namespace std;
using namespace cv;

int main(int argc, char** argv)
{
    /*******************************************************************************
     *
     * Create a Super Resolution object and set default props
     *
     *******************************************************************************/
    std::cout<<"Started Super Resolution Job";
    auto superResolution = SuperResolutionFactory::CreateSuperResolutionBase();

    auto alpha = 0.7;
    auto beta = 0.10;
    auto lambda = 0.04;
    auto p = 1;
    auto maxIterationCount = 50;

    auto srFactor = 1;
    auto bufferSize = 3;

    superResolution->SetProps(alpha, beta, lambda, p, maxIterationCount);
    superResolution->SetBufferSize(bufferSize);
    superResolution->SetSRFactor(srFactor);

    /*******************************************************************************
     *
     * set Data Source
     *
     *******************************************************************************/

    /***********************         From Video             ***********************/
//    const string videoFileName = "/home/athrva/super_resolution/data/original.mp4";

//    auto videoFrameSource = FrameSourceFactory::createFrameSourceFromVideo(videoFileName);

//    superResolution->SetFrameSource(videoFrameSource);
//    auto resultNameFormat = "/home/athrva/super_resolution/results/Exp_4*4_frame_%02d.jpg";

    /***********************         From Image List         ***********************/

    auto startIndex = 0;
    auto totalImageCount = 5;
    auto fileNameFormat = "/home/athrva/super_resolution/data/custom/IMG_20230218_161353267_BURST%03d.jpg";
    auto resultNameFormat = "/home/athrva/super_resolution/results/custom_result_%02d.png";
    superResolution->SetBufferSize(5);
    superResolution->SetSRFactor(2);
    /*******************************
    *
    *  This is test case for Adyoron,
    *  uncomment it if run want get
    *  Text test case result
    *
    ******************************/
//    auto startIndex = 0;
//    auto totalImageCount = 61;
//    auto fileNameFormat = "/home/athrva/super_resolution/data/Adyoron/%06d.png";
//    auto resultNameFormat = "/home/athrva/super_resolution/results/Adyoron_4*4_result_%02d.png";
//    superResolution->SetBufferSize(8);
//    superResolution->SetSRFactor(2);
    /*******************************
    *
    *  This is test case for EIA,
    *  uncomment it if run want get
    *  Text test case result
    *
    ******************************/
//    auto startIndex = 0;
//    auto totalImageCount = 16;
//    auto fileNameFormat = "../data/eia/%06d.png";
//    auto resultNameFormat = "../result/eia_4*4_result_%02d.png";
//    superResolution->SetBufferSize(totalImageCount);
//    superResolution->SetSRFactor(4);

    /*******************************
    *
    *  This is test case for Text,
    *  uncomment it if run want get
    *  Text test case result
    *
    ******************************/
//    auto startIndex = 1;
//    auto totalImageCount = 29;
//    auto fileNameFormat = "/home/athrva/super_resolution/data/text/%06d.png";
//    auto resultNameFormat = "/home/athrva/super_resolution/results/text_4*4_result_%02d.png";
//    superResolution->SetBufferSize(29);
//    superResolution->SetSRFactor(4);

    /*******************************
     *
     *  This is test case for Emily,
     *  uncomment it if run want get
     *  Emliy test case result
     *
     ******************************/
//    	auto startIndex = 1;
//    	auto totalImageCount = 82;
//        auto fileNameFormat = "/home/athrva/super_resolution/data/Emily/%06d.png";
//        auto resultNameFormat = "/home/athrva/super_resolution/results/Emily_4*4_result_%02d.png";
//    	superResolution->SetBufferSize(53);
//    	superResolution->SetSRFactor(4);

    std::cout<<"Super Resolution Buffer is set.";
    auto imageListFrameSource = FrameSourceFactory::createFrameSourceFromImageList(totalImageCount, fileNameFormat,
                                                                                   startIndex);

    superResolution->SetFrameSource(imageListFrameSource);

    /*******************************************************************************
     *
     * Processing Super Resolution
     *
     *******************************************************************************/
    auto index = 0;
    Mat currentFrame;
//  }
//#if true
    while (true)
    {
        cout << index << "..";
        auto currentStatus = superResolution->NextFrame(currentFrame);

//        imshow("High Resolution Frame", currentFrame);

//        waitKey(10);

        char name[190];
        sprintf(name, resultNameFormat, index);
        imwrite(name, currentFrame);

        if (currentStatus == -1)
            break;

        ++index;
    }
    cv::waitKey(0);
    destroyAllWindows();

    cout << endl;
    cout << "All Done!" << endl;

    return 0;
}
//#endif
