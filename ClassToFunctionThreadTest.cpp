#include "ClassToFunctionThreadTest.h"

void ClassToFunctionThread::ShowMessage(string s[])
{
	if (s != nullptr)
		FindFilesToPath(s[0], s[1]);
	else
		cout << "NULL" << endl;
}

void ClassToFunctionThread::FindFilesToPath(string patch, string type)
{
	WIN32_FIND_DATA FindFileData;
	HANDLE hf;
	string serch = patch + "\\" + type;
	hf = FindFirstFile(serch.c_str(), &FindFileData);
	ofstream resultFile(patch + "\\Images.pac", ios::binary);
	if (hf != INVALID_HANDLE_VALUE)
	{
		do
		{
			cout << FindFileData.cFileName << endl;
			string pathToWrite = (patch + "\\" + FindFileData.cFileName) + "\n";
			ifstream readFile((patch + "\\" + FindFileData.cFileName), ios::binary);
			readFile.seekg(0, ios_base::end);
			int size = readFile.tellg();
			readFile.seekg(0);
			char* Image = new char[size];
			readFile.read(Image, size);
			resultFile.write(Image, size);
			resultFile.write("#BreakPoint", 12);
			readFile.close();
			delete[] Image;
		} while (FindNextFile(hf, &FindFileData) != 0);
		resultFile.close();
		FindClose(hf);
	}
}
