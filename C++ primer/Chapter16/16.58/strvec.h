//#pragma once
//
//#include<string>
//
//class StrVec
//{
//public:
//	StrVec():element(nullptr),first_free(nullptr),cap(nullptr){}
//
//	StrVec(std::initializer_list<std::string>il);
//
//	StrVec(const StrVec& s);
//
//	StrVec& operator=(const StrVec& rhs);
//
//	~StrVec();
//
//	void push_back(const std::string& s);
//
//	template<typename...Args>
//	void emplace_back(Args&&...);
//
//	std::size_t size()const { return first_free - element; }
//	std::size_t capacity()const { return cap - element; }
//
//	std::string* begin()const { return element; }
//	std::string* end()const { return first_free; }
//
//	void reserve(std::size_t n);
//
//	void resize(std::size_t n);
//	void resize(std::size_t n, const std::string& s);
//
//
//private:
//	std::string* element;
//	std::string* first_free;
//	std::string* cap;
//
//	std::allocator<std::string>alloc;
//
//	void reallocate();
//	void chk_n_alloc() { if (size() == capacity()) reallocate(); }
//
//	void free();
//
//	void wy_alloc_n_move(std::size_t n);
//
//	std::pair<std::string*, std::string*>
//		alloc_n_copy(std::string* b, std::string* e);
//};
//
//template<typename ...Args>
//inline void 
//StrVec::emplace_back(Args&&...args)
//{
//	chk_n_alloc();
//	alloc.construct(first_free++, std::forward<Args>(args)...);
//}