#include <iostream>
#include <windows.h>
#include <conio.h>
#include <string>
using namespace std;

int main (int argc, char *argv[])
{

	TCHAR s[100];
    DWORD a = GetCurrentDirectory(100, s);
	std::string origin_file = std::string(s);
	origin_file.append("\\glut.h");
	

	//C:\Program Files (x86)\Microsoft Visual Studio 2012\VC\include


	
	LPCSTR destination_file =  "C:\\Program Files (x86)\\Microsoft Visual Studio 2012\\VC\\include\\glut.h";
	cout << "Origin:" << origin_file << endl;
	cout << "Destination:" << destination_file << endl;
	
	if (CopyFile (origin_file.c_str(), destination_file, true))
	{
		cout << "File copied successfully!";
	}
	else
	{
		cout << "File could not be copied successfully. Did you Run as Administrator?";
	}
	_getch();	
	return 1;
}
