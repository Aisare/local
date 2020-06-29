#include <iostream>
#include <string>

using namespace std;


#include "ThreadCommon.h"





void FunctionShowMessage(string s)
{
	cout << s << endl;
}

#include <Windows.h>

#include <fstream>



class ClassToFunctionThread
{

public: 
	static void ShowMessage(string s[])
	{
		FindFilesToPath(s[0],s[1]);
	}
	static void FindFilesToPath(string patch,string type)
	{
		WIN32_FIND_DATA FindFileData;
		HANDLE hf;
		string serch = patch + "\\"+ type;
		hf = FindFirstFile(serch.c_str(), &FindFileData);
		ofstream resultFile(patch+"\\Images.pac", ios::binary);
		if (hf != INVALID_HANDLE_VALUE)
		{
			do
			{
				cout << FindFileData.cFileName << endl;
				string pathToWrite = (patch + "\\"+FindFileData.cFileName) + "\n";
				ifstream readFile((patch + "\\" + FindFileData.cFileName), ios::binary);
				readFile.seekg(0, ios_base::end);
				int size = readFile.tellg();
				readFile.seekg(0);
				char* Image = new char[size];
				readFile.read(Image, size);
				resultFile.write(Image, size);
				resultFile.write("#BreakPoint", 12);
				readFile.close();
				delete [] Image;
			} while (FindNextFile(hf, &FindFileData) != 0);
			resultFile.close();
			FindClose(hf);
		}
	}


};


void main()
{

	ThreadCommon* THC[2];
	ClassToFunctionThread* STFT = new ClassToFunctionThread();

	string Parametrs[] =
	{
		"C:\\Users\\1\\Documents\\Heroes of the Storm\\Screenshots",
		"*.jpg"
	};

	THC[0] = new ThreadCommon(STFT->ShowMessage, Parametrs);

	string Parametrs2[] =
	{
		"C:\\Users\\Public\\Pictures\\Sample Pictures",
		"*.jpg"
	};

	THC[1] = new ThreadCommon(STFT->ShowMessage, Parametrs2);
	
	
	delete THC[0];
	delete THC[1];

	
	delete STFT;
}