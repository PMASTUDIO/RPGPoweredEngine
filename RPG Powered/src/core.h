#pragma once

#include <iostream>

#ifdef _DEBUG
	#define LOG_ERROR(x) std::cout << x << std::endl;
#else
	#define LOG_ERROR(x) throw std::runtime_error(x);
#endif
