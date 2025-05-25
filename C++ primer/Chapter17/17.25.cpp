//#include <iostream>
//#include <regex>
//#include <string>
//
//std::string pattern = R"((\()?(\d{3})(\))?([-. ])?(\d{3})([-. ])?(\d{4}))";
//std::string format = "$2.$5.$7";
//std::regex r(pattern);
//std::string s;
//
//int main()
//{
//	while (std::getline(std::cin, s)) {
//		std::smatch result;
//		std::regex_search(s, result, r);
//		if (!result.empty()) {
//			std::cout << result.prefix() << result.format(format) << std::endl;
//		}
//		else {
//			std::cout << "Sorry, No match." << std::endl;
//		}
//	}
//	return 0;
//}