## Introduction
Internal repository of estimating relative camera pose from ORB features. (Descriptions to be updated ...) <br />

## Contributors:
Yiran Ding (yiran_ding@brown.edu) <br />
Chiang-Heng Chien (chiang-heng_chien@brown.edu)

## How to compile and run the code
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

## How to push your commits
IMPORTANT: DO NOT PUSH YOUR OWN BUILD FOLDER!! <br />
When finish editing the script, type
```bash
git status
```
and you will see what changes you've made from the latest version. Add files you wish to push to this repository by
```bash
git add <file_name>
```
or remove files you do not want to be placed in this repository by
```bash
git rm <file_name>
```
and after all files are added/removed, add a commit with a description
```bash
git commit -m <commit_description>
```
Finally, push your commit
```bash
git push
```
Refresh this repository page and you shall see the updates!

## Extractor
This is an ORB feature extractor isolated from ORB-SLAM2. To run it after a successful compilation, ``cd`` to the ``bin`` folder under ``build`` and do
```bash
$ ./ORBextractor-main /path/to/your/image
```
and you will see a pop-up window showing colorful ORB features.
