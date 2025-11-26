#pragma once

#ifdef _DEBUG

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#ifndef DBG_NEW 
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ ) 
#define new DBG_NEW 

#endif

#endif


#define		SAFE_DELETE(p)				if(p) { delete p; p = nullptr; }
#define		SAFE_DELETE_ARRAY(p)		if(p) { delete[] p; p = nullptr; }

#define		cleaning()		{ cin.clear(); cin.ignore(256, '\n');}

#define 라인 "================================"
#define 라인프린트 cout << "================================" << '\n'
