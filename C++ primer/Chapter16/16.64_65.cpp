//#include <iostream>
//#include <vector>
//#include <cstring>
//#include <sstream>
//
//template<typename T>
//std::string	debug_rep(T* t)
//{
//	std::ostringstream ret;
//	ret << t;
//	std::cout << " T *t" << std::endl;
//	return ret.str();
//}
//
//template<>
//std::string debug_rep(const char* str)
//{
//	std::string ret(str);
//	std::cout << "const char* str" << std::endl;
//	return ret;
//}
//
//template<>
//std::string debug_rep(char* str)
//{
//	std::string ret(str);
//	std::cout << " char* str" << std::endl;
//	return ret;
//}
//
//int main()
//{
//	char p[] = "alan";
//	std::cout << debug_rep(p) << "\n";
//	return 0;
//}