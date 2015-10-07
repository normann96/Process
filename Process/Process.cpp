// Process.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <Windows.h>
#include <iostream>
#include <tchar.h>
#include <conio.h>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	//char lpszAppName[] = "Notepad.exe D:\\23.txt";
	STARTUPINFO si = {sizeof(STARTUPINFO)};
	PROCESS_INFORMATION pi;

	/*ZeroMemory(&si, sizeof(STARTUPINFO));
	si.cb = sizeof(STARTUPINFO);*/

	if (!CreateProcess(NULL, "Notepad.exe", NULL, NULL, FALSE, NULL, NULL, NULL, &si, &pi))
	{
		cout << "The new process is not created.\n";
		cout << "Press any key to exit.\n";
		cin.get();
		return GetLastError();
	}
	
	cout << pi.dwProcessId << endl;
	remove("D:\\23.txt");

	system("pause");
	return 0;
}


