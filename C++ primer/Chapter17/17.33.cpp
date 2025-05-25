//#include<iostream>
//#include<string>
//#include<vector>
//#include<random>
//#include<fstream>
//#include<ctime>
//#include<algorithm>
//#include<utility>
//
//int main() {
//	typedef std::pair<std::string, std::string>ps;
//	std::ifstream i("d.txt");
//	std::vector<ps>dict;
//	std::string str1, str2;
//	while (i >> str1 >> str2) {
//		dict.emplace_back(str1, str2);
//	}
//	i.close();
//
//	std::sort(dict.begin(), dict.end(), [](const ps& ps_1, const ps& ps_2) {return ps_1.first < ps_2.first; });
//
//	i.open("d.txt");
//
//	std::default_random_engine e((unsigned int)(time(0)));
//
//	while (i >> str1) {
//		std::vector<ps>::const_iterator it = std::find_if(dict.begin(), dict.end(), [&str1](const ps& _ps) {return _ps.first == str1; });
//
//		if (it == dict.end()) {
//			std::cout << str1 << ' ';
//		}
//		else {
//			std::uniform_int_distribution<unsigned>u(0, std::find_if(dict.begin(), dict.end(), [&str1](const ps& _ps) {return _ps.first > str1; }) - it - 1);
//
//			std::cout << (it + u(e))->second << ' ';
//		}
//	}
//	return 0;
//}