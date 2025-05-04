//#include<iostream>
//#include<vector>
//#include<list>
//#include<string>
//
//namespace ch16
//{
//	template<typename Iterator, typename Value>
//	auto find(Iterator first, Iterator last, Value const& value)
//	{
//		for (; first != last; ++first)
//		{
//			if (*first == value)
//				return first;
//		}
//		return last;
//	}
//
//	template<typename Iterator, typename Predicate>
//	Iterator find_if(Iterator first, Iterator last, Predicate pred)
//	{
//		for (; first != last; ++first)
//		{
//			if (pred(*first))
//				return first;
//		}
//		return last;
//	}
//
//	template<typename Iterator>
//	void print_range(Iterator first, Iterator last)
//	{
//		for (; first != last; ++first)
//			std::cout << *first << std::endl;
//		std::cout << "\n";
//	}
//}
//
//
//int main()
//{
//	std::vector<int> v = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
//	auto is_in_vector = v.cend() != ch16::find(v.cbegin(), v.cend(), 5);
//	std::cout << (is_in_vector ? "found\n" : "not found\n");
//
//	std::list<std::string> l = { "aa", "bb", "cc", "dd", "ee", "ff", "gg" };
//	auto is_in_list = l.cend() != ch16::find(l.cbegin(), l.cend(), "zz");
//	std::cout << (is_in_list ? "found\n" : "not found\n");
//
//	std::vector<std::string> sl = { "hello","world","peter","my","friend","joy" };
//	auto has_long_string = ch16::find_if(sl.begin(), sl.end(), [](const std::string& s) {return s.size() > 3; });
//	
//	ch16::print_range(sl.begin(), sl.end());
//
//	return 0;
//}