#pragma once
#include "stdafx.h"

#ifndef PASSWD_H
#define PASSWD_H

typedef struct passwd
{
	wchar_t * user;
	wchar_t * password;
	int		  uid;
	int		  gid;
	wchar_t * extra;
	wchar_t * home_dir;
	wchar_t * shell;

} passwd, *pPasswd;


class Passwd
{
private:
	void replaceAll(_Inout_ std::wstring & source, _In_ const wchar_t * pattern, _In_ const wchar_t * replace);
	void tokenizer(_In_ std::wstring source, _Inout_ std::vector<std::wstring> & out, _In_ const wchar_t *delim);
	std::list<passwd> result;

public:
	void parse(_In_ wchar_t * path);
	std::list<passwd> getResult();
};

#endif // !PASSWD_H