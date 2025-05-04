//#include<iostream>
//template<typename Printable>
//std::ostream& print(std::ostream& os, Printable const& printable)
//{
//	return os << printable;
//}
//
//template<typename Printable,typename ... Args>
//std::ostream& print(std::ostream& os, Printable const& printable, Args const&...rest)
//{
//	return print(os << printable << ",", rest...);
//}
//
//int main()
//{
//	print(std::cout, 1) << std::endl;
//	print(std::cout, 1, 2) << std::endl;
//	print(std::cout, 1, 2, 3, 4, "sss", 42.4242) << std::endl;
//
//	return 0;
//}