//#include <iostream>
//#include <string>
//#include <vector>
//#include <algorithm>
//
//void elimdups(std::vector<std::string>& s)
//{
//	std::sort(s.begin(), s.end());
//	auto new_end = std::unique(s.begin(), s.end());
//	s.erase(new_end, s.end());
//}
//
//void biggies(std::vector<std::string>& vs, std::size_t sz)
//{
//	using std::string;
//	elimdups(vs);
//
//	std::stable_sort(vs.begin(), vs.end(), [](const string& lhs, const string& rhs) {return lhs.size() < rhs.size(); });
//
//	auto wc = std::find_if(vs.begin(), vs.end(), [sz](const string& s) {return s.size() >= sz; });
//
//	std::for_each(wc, vs.end(), [](const string& s) {std::cout << s << " "; });
//
//}
//
//int main()
//{
//
//	std::vector<std::string> v
//	{
//		"1234","1234","1234","hi~", "alan", "alan", "cp"
//	};
//	std::cout << "ex10.16: ";
//	biggies(v, 3);
//	std::cout << std::endl;
//	return 0;
//}