//#include <iostream>
//#include <string>
//#include <vector>
//#include <algorithm>
//#include <numeric>
//#include <list>
//
//template<typename Sequnece>
//inline std::ostream& println(Sequnece const& seq)
//{
//	for (auto const& elem : seq)
//		std::cout << elem << " ";
//	std::cout << std::endl;
//	return std::cout;
//}
//
//inline bool is_Shorter(std::string const& lhs, std::string const& rhs)
//{
//	return lhs.size() < rhs.size();
//}
//
//void elimDups(std::vector<std::string>& vs)
//{
//	std::sort(vs.begin(), vs.end());
//	auto new_end = std::unique(vs.begin(), vs.end());
//	vs.erase(new_end, vs.end());
//}
//
//int main()
//{
//	std::vector<std::string> v{
//		"1234", "1234", "1234", "Hi", "alan", "wang"
//	};
//
//	elimDups(v);
//	std::sort(v.begin(), v.end());
//	std::stable_sort(v.begin(), v.end(), is_Shorter);
//	std::cout << "ex10.11 :\n";
//	println(v);
//	return 0;
//}