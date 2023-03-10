# Multi-View Image Super-Resolution

## Introduction

This repository contains an implementation of a fast and robust multi-frame super resolution method described in the paper "Fast and Robust Multi-Frame Super Resolution" by Farsiu et al. The method uses a combination of pixelwise median and mean estimators and norm minimization to produce high-resolution images from multiple low-resolution frames.

## Implementation

The implementation follows the algorithm described in the paper. It copies values from the LR grid to the HR grid after proper shifting and zero filling, and copies a selected set of pixels in HR grid back on the LR grid. Each element of the HR grid is the aggregate of the effects of all LR frames, which have one of three forms: addition of zero, addition of a value if the corresponding pixel in the LR frame is smaller or larger than the corresponding pixel in the HR frame.
The method calculates the final super-resolved picture by deblurring. The paper shows that the method results in pixelwise median and mean of all measurements after motion compensation. The method chooses to minimize the measurement error using the L1 norm minimization family.
The paper shows that the method is particularly useful in square or under-determined cases, where only one measurement is available for each HR pixel. For these cases, an extra term called regularization term is necessary to remove outliers. The paper describes a robust regularization term, which compensates for missing measurement information with some general prior information about the desirable HR solution. The regularization term is implemented as a penalty factor in the generalized minimization cost function.

## Conclusion

This implementation provides a fast and robust multi-frame super resolution method that is particularly useful in square or under-determined cases. The method combines pixelwise median and mean estimators and norm minimization to produce high-resolution images from multiple low-resolution frames. A robust regularization term is used to remove outliers and improve the rate of convergence. The implementation follows the algorithm described in the paper "Fast and Robust Multi-Frame Super Resolution" by Farsiu et al.

Implemented using OpenCV and STL

### Implementation details.

The build system is QMake. You need to have an installlation of OpenCV to build this project. If you are using UBUNTU, just use ```apt``` to install OpenCV. QMake should automatically find OpenCV using ```pkg-config```. If you are building OpenCV from source, make appropriate changes to the Qmake configuration in the ```.pro``` file.

### References

1. Based on the implementation in, ```https://github.com/zhangxiaoya/FB.git```
2. Paper Reference : Farsiu, Sina et al. ???Fast and robust multiframe super resolution.??? IEEE Transactions on Image Processing 13 (2004): 1327-1344.

