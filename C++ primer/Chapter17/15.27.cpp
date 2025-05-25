//#include<iostream>
//#include<string>
//#include<regex>
//
//std::string pattern = R"((\d{5})([-. ])?(\d{4}))";
//std::string fmt = "$1-$3";
//
//std::regex r(pattern);
//std::string s;
//
//int main()
//{
//	while (std::getline(std::cin, s)) {
//		std::smatch result;
//		std::regex_search(s, result, r);
//
//		if (!result.empty()) {
//			std::cout << result.format(fmt) << std::endl;
//		}
//		else {
//			std::cout << "Sorry, No match." << std::endl;
//		}
//	}
//	return 0;
//}