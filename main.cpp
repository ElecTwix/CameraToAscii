#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include "iostream"

using namespace cv;

std::string brightness = " .:-=+*#%@";

char GetChar(unsigned char * p)
{

    int avg = (p[0] + p[1] + p[2])/3;

    switch (avg) {
        case 0 ... 30:
            return brightness[0];
            break;
        case 31 ... 60:
            return brightness[1];
            break;
        case 61 ... 90:
            return brightness[2];
            break;
        case 91 ... 120:
            return brightness[3];
            break;
        case 121 ... 150:
            return brightness[4];
            break;
        case 151 ... 170:
            return brightness[5];
            break;
        case 171 ... 200:
            return brightness[6];
            break;
        case 201 ... 230:
            return brightness[7];
            break;
        case 231 ... 250:
            return brightness[8];
            break;

    }
    return brightness[0];




}




int main(int, char**)
{
    VideoCapture cap(0);
    if(!cap.isOpened()) return -1;

    Mat frame, frame2, ascii;
    //namedWindow("edges",1);
    for(;;)
    {
        cap >> frame;
        cv::resize(frame, frame2, cv::Size(120, 60));


        for(int i = 1; i < 60; i++)
        {
            for(int j = 1; j < 120; j++)
            {
                unsigned char * p = frame2.ptr(i, j);
                //std::cout << p[0];

                std::cout << GetChar(p);

            }

            std::cout << "\n";

        }

        //imshow("Frame2", frame2);

        if(waitKey(30) >= 0) break;
    }
    return 0;
}
