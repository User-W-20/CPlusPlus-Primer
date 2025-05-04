//#pragma once
//#include<memory>
//#include<vector>
//#include<stdexcept>
//#include"shared_pointer.hpp"
//#include"DebugDelete.hpp"
//template<typename T>
//class Blob {
//public:
//	typedef T value_type;
//	typedef typename std::vector<T>::size_type size_type;
//
//	Blob();
//	Blob(std::initializer_list<T>il);
//
//	template<typename It>
//	Blob(It b, It e);
//
//	size_type size()const { return data->size(); }
//	bool empty()const { return data->empty(); }
//
//	void push_back(const T& t) { data->push_back(t); }
//	void push_back(T&& t)noexcept { data->push_back(std::move(t)); }
//
//	void pop_back();
//
//	T& back();
//	T& operator[](size_type i);
//
//	const T& back()const;
//	const T& operator[](size_type i)const;
//
//	// 添加移动构造函数
//	Blob(Blob&& other) noexcept : data(std::move(other.data)) {}
//
//	// 添加移动赋值运算符
//	Blob& operator=(Blob&& other) noexcept {
//		if (this != &other) {
//			data = std::move(other.data);
//		}
//		return *this;
//	}
//
//private:
//	my_sharedPtr::shared_pointer<std::vector<T>> data;
//	void check(size_type i, const std::string& msg)const;
//};
//
//template<typename T>
//Blob<T>::Blob()
//	: data(new std::vector<T>(), DebugDelete()) {
//}
//
//template<typename T>
//Blob<T>::Blob(std::initializer_list<T> il)
//	: data(new std::vector<T>(il), DebugDelete()) {
//}
//
//template<typename T>
//template<typename It>
//Blob<T>::Blob(It b, It e)
//	: data(new std::vector<T>(b, e), DebugDelete()) {
//}
//
//template<typename T>
//void Blob<T>::check(size_type i, const std::string& msg)const
//{
//	if (i >= data->size())
//		throw std::out_of_range(msg);
//}
//
//template<typename T>
//T& Blob<T>::back()
//{
//	check(0, "back on empty Blob");
//	return data->back();
//}
//
//template<typename T>
//const T& Blob<T>::back()const
//{
//	check(0, "back on empty Blob");
//	return data->back();
//}
//
//template<typename T>
//T& Blob<T>::operator[](size_type i)
//{
//	check(i, "subscript out of range");
//	return (*data)[i];
//}
//
//template<typename T>
//const T& Blob<T>::operator[](size_type i)const
//{
//	check(i, "subscript out of range");
//	return (*data)[i];
//}
//
//template<typename T>
//void Blob<T>::pop_back()
//{
//	check(0, "pop_back on empty Blob");
//	return data->pop_back();
//}
//
//template class Blob<std::string>;