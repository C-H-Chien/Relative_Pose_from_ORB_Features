#ifndef ORBEXTRACTOR_H
#define ORBEXTRACTOR_H
 
#include <vector>
#include <list>
#include <opencv2/opencv.hpp>
 
 
namespace findORB
{
 
class ExtractorNode
{
public:
    ExtractorNode():bNoMore(false){}
 
    void DivideNode(ExtractorNode &n1, ExtractorNode &n2, ExtractorNode &n3, ExtractorNode &n4);
 
    std::vector<cv::KeyPoint> vKeys;
    cv::Point2i UL, UR, BL, BR;
    std::list<ExtractorNode>::iterator lit;
    bool bNoMore;
};
 
class ORBextractor
{
public:
   
    enum {HARRIS_SCORE=0, FAST_SCORE=1 };
 
    ORBextractor(int nfeatures, float scaleFactor, int nlevels,
                 int iniThFAST, int minThFAST);
 
    ~ORBextractor(){}
 
    // Compute the ORB features and descriptors on an image.
    // ORB are dispersed on the image using an octree.
    // Mask is ignored in the current implementation.
    // Overload operator () as exporter
    void operator()( cv::InputArray image, cv::InputArray mask,
      std::vector<cv::KeyPoint>& keypoints,
      cv::OutputArray descriptors);
 
    int inline GetLevels(){
        return nlevels;}
 
    float inline GetScaleFactor(){
        return scaleFactor;}
 
    std::vector<float> inline GetScaleFactors(){
        return mvScaleFactor;
    }
 
    std::vector<float> inline GetInverseScaleFactors(){
        return mvInvScaleFactor;
    }
 
    std::vector<float> inline GetScaleSigmaSquares(){
        return mvLevelSigma2;
    }
 
    std::vector<float> inline GetInverseScaleSigmaSquares(){
        return mvInvLevelSigma2;
    }
 
    //存放各层级图片
    std::vector<cv::Mat> mvImagePyramid;
 
protected:
    // Calculate Gaussian pyramid
    void ComputePyramid(cv::Mat image);
 
    /// Compute the features in each layer by dividing an image into grids
    /// Use FAST corner to detect each grid, and use DistributeOctTree() to select the FAST features to make them evenly distributed
    void ComputeKeyPointsOctTree(std::vector<std::vector<cv::KeyPoint> >& allKeypoints);
    // Assign the keypoints to the QuadTree
    std::vector<cv::KeyPoint> DistributeOctTree(const std::vector<cv::KeyPoint>& vToDistributeKeys, const int &minX,
                                           const int &maxX, const int &minY, const int &maxY, const int &nFeatures, const int &level);
 
    void ComputeKeyPointsOld(std::vector<std::vector<cv::KeyPoint> >& allKeypoints);
    // Save the matched points in the patches near the keypoints
    std::vector<cv::Point> pattern;
 
    int nfeatures; // the number of the features
    double scaleFactor;  // the scaling factor between 2 consecutive layers
    int nlevels;    // the number of the levels of the pyramid
    int iniThFAST;  // the threshold of FAST
    int minThFAST;  // the lowered threshold if no FAST feature is detected
 
    // the number of the features in each layer
    std::vector<int> mnFeaturesPerLevel;
    // the maximum coordinates of the patch circle
    std::vector<int> umax;
    // the scaling factor of each layer comparing to the original image
    std::vector<float> mvScaleFactor;
    // the inversed scaling factor of each layer comparing to the original image
    std::vector<float> mvInvScaleFactor;
    // the squared value of the scaling factors方
    std::vector<float> mvLevelSigma2;
    std::vector<float> mvInvLevelSigma2;
};
 
} //namespace ORB_SLAM
 
#endif
