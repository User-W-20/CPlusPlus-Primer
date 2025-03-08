//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <iterator>
//#include <numeric>
//#include"Sales_data.h"
//
//bool compareIsbn(const Sales_data& item1, const Sales_data* item2)
//{
//	return item1.isbn() < item2->isbn();
//}
//
//int main()
//{
//	std::istream_iterator<Sales_data>in_iter(std::cin), in_eof;
//	std::vector<Sales_data>vec;
//
//	while (in_iter != in_eof)
//		vec.push_back(*in_iter++);
//	sort(vec.begin(), vec.end(), compareIsbn);
//	for (auto beg = vec.cbegin(), end = beg; beg != vec.cend(); beg = end) {
//		end = find_if(beg, vec.cend(), [beg](const Sales_data& data) {return data.isbn() != beg->isbn(); });
//
//		std::cout << std::accumulate(beg, end, Sales_data(beg->isbn())) << std::endl;
//	}
//}