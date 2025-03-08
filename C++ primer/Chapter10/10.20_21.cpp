//#include <iostream>
//#include <string>
//#include <vector>
//#include <algorithm>
//
//
//using std::vector;
//using std::count_if;
//using std::string;
//
//std::size_t bigerThan6(vector<string>& v)
//{
//	return count_if(v.begin(), v.end(), [](const string& s) {return s.size() > 6; });
//
//}
//
//int main()
//{
//	vector<string> v{
//	   "alan","moophy","1234567","1234567","1234567","1234567"
//	};
//	std::cout << "ex10.20: " << bigerThan6(v) << std::endl;
//
//	int i = 7;
//	auto check_and_decrement = [&i]() {return i > 0 ? !--i : !i; };
//	std::cout << "ex10.21: ";
//	while (!check_and_decrement())
//		std::cout << i << " ";
//	std::cout << std::endl;
//	return 0;
//}