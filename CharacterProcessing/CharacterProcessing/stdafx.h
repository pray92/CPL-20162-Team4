// stdafx.h : 자주 사용하지만 자주 변경되지는 않는
// 표준 시스템 포함 파일 또는 프로젝트 관련 포함 파일이
// 들어 있는 포함 파일입니다.
//

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>



// TODO: 프로그램에 필요한 추가 헤더는 여기에서 참조합니다.
#include <iostream>
#include <fstream>
#include <cstring>
#include <Windows.h>

#include <time.h>
#include <string.h>
#include <iostream>
#include <stdlib.h>

#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2\opencv.hpp"
#include "opencv2\highgui\highgui.hpp"
#include "dirent.h"

#include <math.h>
#include<new>

using namespace std;
using namespace cv;

void ImageCapture();
void MakeCharacter();
void ImageExport();