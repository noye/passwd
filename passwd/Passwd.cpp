// Passwd.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Passwd.h"


void Passwd::replaceAll(std::wstring & source, const wchar_t * pattern, const wchar_t * replace)
{
	std::wstring::size_type pos = 0;
	std::wstring::size_type offset = 0;

	while ((pos = source.find(pattern, offset)) != std::wstring::npos)
	{
		source.replace(source.begin() + pos, source.begin() + pos + wcslen(pattern), replace);
		offset = pos + wcslen(replace);
	}
}

void Passwd::tokenizer(std::wstring source, std::vector<std::wstring> & out, const wchar_t * delim)
{
	std::wstring::size_type last_pos = source.find_first_not_of(delim, 0);
	std::wstring::size_type pos = source.find_first_of(delim, last_pos);


	while (std::wstring::npos != pos || std::wstring::npos != last_pos)
	{
		out.push_back(source.substr(last_pos, pos - last_pos));
		
		last_pos = source.find_first_not_of(delim, pos);
		pos = source.find_first_of(delim, last_pos);
	}

	if (out.empty())
	{
		_wperror(L"check tokens");
		return;
	}
}

void Passwd::parse(wchar_t * path)
{
	std::wifstream handle(path);
	std::wstring content;
	
	while (std::getline(handle, content))
	{
		std::vector<std::wstring> fields;
		passwd passwd_struct = { 0 };

		this->replaceAll(content, L"::", L": :");
		this->tokenizer(content, fields, L":");

		if (fields.empty())
		{
			_wperror(L"passwd fields is empty.");
			return;
		}

		passwd_struct.user = const_cast<wchar_t *>(fields[0].c_str());
		passwd_struct.password = const_cast<wchar_t *>(fields[1].c_str());
		passwd_struct.uid = _wtoi(fields[2].c_str());
		passwd_struct.gid = _wtoi(fields[3].c_str());
		passwd_struct.extra = const_cast<wchar_t *>(fields[4].c_str());
		passwd_struct.home_dir = const_cast<wchar_t *>(fields[5].c_str());
		passwd_struct.shell = const_cast<wchar_t *>(fields[6].c_str());

		this->result.push_back(passwd_struct);

		if (!fields.empty())
			std::vector<std::wstring>().swap(fields);
	}

	handle.close();
}

std::list<passwd> Passwd::getResult()
{
	return this->result;
}