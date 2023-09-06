## Introduction
Internal repository of estimating relative camera pose from ORB features. Each folder is an individual repository. <br />
To compile and run any of the repository, simply ``cd`` to that folder and create a ``build`` directory by
```bash
$ mkdir build && cd build
```
and do compilation by first
```bash
$ cmake ..
```
then
```bash
$ make -j
```

## Dependencies
(1) OpenCV 4 or higher <br />
(2) Eigen 3.3.2 or higher <br />

## Extractor
This is an ORB feature extractor isolated from ORB-SLAM2. To run it after a successful compilation, ``cd`` to the ``bin`` folder under ``build`` and do
```bash
$ ./ORBextractor-main /path/to/your/image
```
and you will see a pop-up window showing colorful ORB features.