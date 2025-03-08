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
//void biggies_partition(std::vector<std::string>& vs, std::size_t sz)
//{
//	elimdups(vs);
//
//	auto pivot = std::partition(vs.begin(), vs.end(), [sz](const std::string& s) {return s.size() >= sz; });
//
//	for (auto it = vs.begin(); it != pivot; ++it)
//		std::cout << *it << " ";
//		
//}
//
//void biggies_stable_partition(std::vector<std::string>& vs, std::size_t sz)
//{
//	elimdups(vs);
//
//	auto pivot = std::stable_partition(vs.begin(), vs.end(), [sz](const std::string& s) {return s.size() >= sz; });
//
//	for (auto it = vs.begin(); it != pivot; ++it)
//		std::cout << *it << " ";
//}
//
//int main()
//{
//	std::vector<std::string> v{
//		"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"
//	};
//	std::cout << "ex10.18: ";
//	std::vector<std::string> v1(v);
//	biggies_partition(v1, 4);
//	std::cout << std::endl;
//
//	// ex10.19
//	std::cout << "ex10.19: ";
//	std::vector<std::string> v2(v);
//	biggies_stable_partition(v2, 4);
//	std::cout << std::endl;
//
//	return 0;
//}