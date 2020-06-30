#include <iostream>
#include <string>

using namespace std;


#include "ThreadCommon.h"
#include "ClassToFunctionThreadTest.h"


#include <opencv2/core/mat.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/calib3d.hpp>
#include <opencv2/imgproc.hpp>

using namespace cv;

class WorkToOpenCV
{
	public:
		void FindCamers();

};


void main()
{
	WorkToOpenCV OPCV;

	OPCV.FindCamers();



	/*ThreadCommon* THC[2];
	ClassToFunctionThread* STFT = new ClassToFunctionThread();

	string Parametrs2[] =
	{
		"C:\\Users\\Public\\Pictures\\Sample Pictures",
		"*.jpg"
	};

	THC[1] = new ThreadCommon();  
	
	
	delete THC[0];
	delete THC[1];

	
	delete STFT;   */
	getchar();
}



void WorkToOpenCV::FindCamers()
{
	VideoCapture* capture = new VideoCapture(0);

	if (capture->isOpened())
	{
		cout << "Yes" << endl;
	}
	else
	{
		cout << "No" << endl;
	}

	delete capture;

}