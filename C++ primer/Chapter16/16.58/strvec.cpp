//#include"strvec.h"
//#include<memory>
//
//StrVec::StrVec(const StrVec& s)
//{
//	std::pair<std::string*, std::string*>
//		newData = alloc_n_copy(s.begin(), s.end());
//
//	element = newData.first;
//	first_free = cap = newData.second;
//}
//
//StrVec::StrVec(std::initializer_list<std::string>il)
//{
//	std::string* const newData = alloc.allocate(il.size());
//
//	auto p = newData;
//	for (const auto& s : il)
//		alloc.construct(p++, s);
//
//	element = newData;
//	first_free = cap = element + il.size();
//}
//
//StrVec& StrVec::operator=(const StrVec& rhs)
//{
//	std::pair<std::string*, std::string*>
//		newData = alloc_n_copy(rhs.begin(), rhs.end());
//
//	free();
//
//	element = newData.first;
//	first_free = cap = newData.second;
//
//	return *this;
//}
//
//StrVec::~StrVec()
//{
//	free();
//}
//
//void StrVec::push_back(const std::string& s)
//{
//	chk_n_alloc();
//	alloc.construct(first_free++, s);
//}
//
//void StrVec::reserve(std::size_t n)
//{
//	if (n <= capacity())return;
//
//	wy_alloc_n_move(n);
//}
//
//void StrVec::resize(std::size_t n)
//{
//	resize(n, std::string());
//}
//
//void StrVec::resize(std::size_t n, const std::string& s)
//{
//	if (n < size())
//	{
//		for (auto p = element + n; p != first_free;)
//			alloc.destroy(p++);
//
//		first_free = element + n;
//	}
//	else if (n > size())
//	{
//		for (auto i = size(); i != n; ++i)
//			push_back(std::string(s));
//	}
//
//}
//
//void StrVec::reallocate()
//{
//	std::size_t newCapacity = size() ? 2 * size() : 1;
//
//	wy_alloc_n_move(newCapacity);
//}
//
//std::pair<std::string*,std::string*>
//StrVec::alloc_n_copy(std::string* b, std::string* e)
//{
//	std::string* data = alloc.allocate(e - b);
//
//	return { data,std::uninitialized_copy(b,e,data) };
//}
//
//void StrVec::free()
//{
//	if (element)
//	{
//		for (auto p = first_free; p != element;)
//			alloc.destroy(p--);
//
//
//		alloc.deallocate(element, capacity());
//	}
//}
//
//void StrVec::wy_alloc_n_move(std::size_t n)
//{
//	std::size_t newCapacity = n;
//
//	std::string* newData = alloc.allocate(newCapacity);
//
//	std::string* dest = newData;
//
//	std::string* elem = element;
//
//	for (std::size_t i = 0; i != size(); ++i)
//		alloc.construct(dest++, std::move(*elem++));
//
//	free();
//
//	element = newData;
//	first_free = dest;
//	cap = element + newCapacity;
//}