#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include <opencv2/opencv.hpp>
#include "../ORBextractor/ORBextractor.hpp"
#include "../ORBmatcher/ORBmatcher.hpp"
 
using namespace std;
 
// Set the parameters required for ORB feature extraction
int nFeatures = 1000; // the number of the ORB features on the pyramid
int nLevels = 8; // the number of the levels of the pyramid
float fScaleFactor = 1.2; // the scaling factor of the pyramid
int fIniThFAST = 20; // the threshold of FAST
int fMinThFAST = 8; // the minimum threshold of FAST
 
int main(int argc, char** argv) {
    cv::Mat image = cv::imread(argv[1],0); // Input image
    // ./runextractor /home/mikasa/StereoMIS/P2_2/left_frames/6210.png
    vector<cv::KeyPoint> Keypoints;
    cv::Mat mDescriptors;
 
    findORB::ORBextractor ORBextractor =  findORB::ORBextractor(nFeatures, fScaleFactor, nLevels, fIniThFAST, fMinThFAST);
 
    cout << endl  << "ORB Extractor Parameters: " << endl;
    cout << "- Number of Features: " << nFeatures << endl;
    cout << "- Scale Levels: " << nLevels << endl;
    cout << "- Scale Factor: " << fScaleFactor << endl;
    cout << "- Initial Fast Threshold: " << fIniThFAST << endl;
    cout << "- Minimum Fast Threshold: " << fMinThFAST << endl;
 
    ORBextractor(image, cv::Mat(), Keypoints, mDescriptors);
 
    cv::Mat outimg;
    cv::drawKeypoints(image, Keypoints, outimg);
    cv::imshow("ORB features", outimg);
    cv::waitKey(0);
    return 0;
 
}
