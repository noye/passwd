#include "stdafx.h"
#include "Passwd.h"

int wmain(int argc, wchar_t *argv[])
{
	if (argc == 2)
	{
		Passwd * pwd = new Passwd();
		pwd->parse(argv[1]);
		std::list<passwd> result = pwd->getResult();
		std::list<passwd>::iterator it = result.begin();
	
		while (result.end() != it)
		{
			if(it->user != NULL)
				wprintf_s(L"[user] : %ws\n", it->user);
			
			if (it->password != NULL)
				wprintf_s(L"[password] : %ws\n", it->password);
			
			if (it->uid != NULL)
				wprintf_s(L"[uid] : %wd\n", it->uid);
			
			if (it->gid != NULL)
				wprintf_s(L"[gid] : %wd\n", it->gid);
			
			if(it->extra != NULL)
				wprintf_s(L"[extra] : %ws\n", it->extra);
			
			if (it->home_dir != NULL)
				wprintf_s(L"[homedir] : %ws\n", it->home_dir);
			
			if(it->shell != NULL)
				wprintf_s(L"[shell] : %ws\n", it->shell);
		
			wprintf_s(L"\n");
			it++;
		}
	}
	else
		wprintf_s(L"passwd.exe [fileName]\n");

	return 0;
}