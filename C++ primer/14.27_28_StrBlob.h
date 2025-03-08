//#pragma once
//
//#include <vector>
//using std::vector;
//
//#include <string>
//using std::string;
//
//#include <initializer_list>
//using std::initializer_list;
//
//#include <memory>
//using std::make_shared; using std::shared_ptr;
//	 
//#include <exception>
//#include<stdexcept>
//#ifndef _msc_ver
//#define noexcept noexcept
//#else
//#define noexcept
//#endif
//
//class strblobptr;
//class conststrblobptr;
//
//class strblob
//{
//	using size_type = vector<string>::size_type;
//	friend class conststrblobptr;
//	friend class strblobptr;
//	friend bool operator==(const strblob&, const strblob&);
//	friend bool operator!=(const strblob&, const strblob&);
//	friend bool operator< (const strblob&, const strblob&);
//	friend bool operator> (const strblob&, const strblob&);
//	friend bool operator<=(const strblob&, const strblob&);
//	friend bool operator>=(const strblob&, const strblob&);
//public:
//	strblob():data(make_shared<vector<string>>()){}
//	strblob(std::initializer_list<string>il):data(make_shared<vector<string>>(il)){}
//
//	strblob(const strblob& sb) :data(make_shared<vector<string>>(*sb.data)){}
//	strblob& operator=(const strblob&);
//
//	strblob(strblob&&rhs)noexcept:data(std::move(rhs.data)){}
//	strblob& operator=(strblob&&)noexcept;
//
//	strblobptr begin();
//	strblobptr end();
//
//	conststrblobptr cbegin()const;
//	conststrblobptr cend()const;
//
//	string& operator[](size_t n);
//	const string& operator[](size_t n)const;
//
//	size_type size()const { return data->size(); }
//	bool empty()const { return data ->empty(); }
//
//	void push_back(const string& t) { data->push_back(t); }
//	void push_back(string&& s) { data->push_back(std::move(s)); }
//
//	void pop_back();
//	string& front();
//	string& back();
//	const string& front()const;
//	const string& back()const;
//private:
//	void check(size_type, const string&)const;
//
//	shared_ptr<vector<string>>data;
//
//};
//
//bool operator==(const strblob&, const strblob&);
//bool operator!=(const strblob&, const strblob&);
//bool operator< (const strblob&, const strblob&);
//bool operator> (const strblob&, const strblob&);
//bool operator<=(const strblob&, const strblob&);
//bool operator>=(const strblob&, const strblob&);
//
//inline void strblob::pop_back()
//{
//	check(0, "pop_back on empty strblob");
//	data->pop_back();
//}
//
//inline string& strblob::front()
//{
//	check(0, "front on empty strblob");
//	return data->front();
//}
//
//inline string& strblob::back()
//{
//	check(0, "back on empty strblob");
//	return data->back();
//}
//
//inline const string& strblob::front()const
//{
//	check(0, "front on empty strblob");
//	return data->front();
//}
//
//inline const string& strblob::back() const
//{
//	check(0, "back on empty strblob");
//	return data->back();
//}
//
//inline void	strblob::check(size_type i, const string& msg)const
//{
//	if (i >= data->size())throw std::out_of_range(msg);
//}
//
//inline string& strblob::operator[](size_t n)
//{
//	check(n, "out of range");
//	return data->at(n);
//}
//
//inline const string& strblob::operator[](size_t n)const
//{
//	check(n, "out of range");
//	return data->at(n);
//}
//
//class strblobptr
//{
//	friend bool operator==(const strblobptr&, const strblobptr&);
//	friend bool operator!=(const strblobptr&, const strblobptr&);
//	friend bool operator< (const strblobptr&, const strblobptr&);
//	friend bool operator> (const strblobptr&, const strblobptr&);
//	friend bool operator<=(const strblobptr&, const strblobptr&);
//	friend bool operator>=(const strblobptr&, const strblobptr&);
//public:
//	strblobptr():curr(0){}
//	strblobptr(strblob&s,size_t sz=0):wptr(s.data),curr(sz){}
//
//	string& deref()const;
//	strblobptr& operator++();
//	strblobptr& operator--();
//	strblobptr operator++(int);
//	strblobptr operator--(int);
//	strblobptr& operator+=(size_t);
//	strblobptr& operator-=(size_t);
//	strblobptr operator+(size_t) const;
//	strblobptr operator-(size_t) const;
//
//	string& operator[](size_t n);
//	const string& operator[](size_t n)const;
//private:
//	shared_ptr<vector<string>>check(size_t, const string&)const;
//
//	std::weak_ptr<vector<string>>wptr;
//	size_t curr;
//};
//
//bool operator==(const strblobptr&, const strblobptr&);
//bool operator!=(const strblobptr&, const strblobptr&);
//bool operator< (const strblobptr&, const strblobptr&);
//bool operator> (const strblobptr&, const strblobptr&);
//bool operator<=(const strblobptr&, const strblobptr&);
//bool operator>=(const strblobptr&, const strblobptr&);
//
//
//inline string& strblobptr::deref()const
//{
//	auto p = check(curr, "dereference past end");
//	return (*p)[curr];
//}
//
//inline strblobptr& strblobptr::operator++()
//{
//	check(curr, "increment past end of strblobptr");
//	++curr;
//	return* this;
//}
//
//inline strblobptr& strblobptr::operator--()
//{
//	check(--curr, "decrement past begin of strblobptr");
//	return *this;
//}
//
//inline strblobptr strblobptr::operator++(int)
//{
//	strblobptr ret = *this;
//	++*this;
//	return ret;
//}
//
//inline strblobptr strblobptr::operator--(int)
//{
//	strblobptr ret = *this;
//	--*this;
//	return ret;
//}
//
//inline strblobptr& strblobptr::operator+=(size_t n)
//{
//	curr += n;
//	check(curr, "increment past end of strblobptr");
//	return *this;
//}
//
//inline strblobptr& strblobptr::operator-=(size_t n)
//{
//	curr -= n;
//	check(curr, "increment past end of strblobptr");
//		return *this;
//}
//
//inline strblobptr strblobptr::operator+(size_t n)const
//{
//	strblobptr ret = *this;
//	ret += n;
//	return ret;
//}
//
//inline strblobptr strblobptr::operator-(size_t n)const
//{
//	strblobptr ret = *this;
//	ret -= n;
//	return ret;
//}
//
//inline shared_ptr<vector<string>> strblobptr::check(size_t i, const string& msg)const
//{
//	auto ret = wptr.lock();
//	if (!ret)throw std::runtime_error("unbound strblobptr");
//	if (i >= ret->size())throw std::out_of_range(msg);
//	return ret;
//}
//
//inline string& strblobptr::operator[](size_t n)
//{
//	auto p = check(n, "dereference out of range.");
//	return (*p)[curr];
//}
//
//inline const string& strblobptr::operator[](size_t n)const
//{
//	auto p = check(n, "dereference out of range.");
//	return (*p)[curr];
//}
//
//class conststrblobptr
//{
//	friend bool operator==(const conststrblobptr&, const conststrblobptr&);
//	friend bool operator!=(const conststrblobptr&, const conststrblobptr&);
//	friend bool operator< (const conststrblobptr&, const conststrblobptr&);
//	friend bool operator> (const conststrblobptr&, const conststrblobptr&);
//	friend bool operator<=(const conststrblobptr&, const conststrblobptr&);
//	friend bool operator>=(const conststrblobptr&, const conststrblobptr&);
//public:
//	conststrblobptr() :curr(0) {}
//	conststrblobptr(const strblob& s, size_t sz = 0) :wptr(s.data),curr(sz){}
//
//	const string& deref()const;
//	conststrblobptr& operator++();
//	conststrblobptr& operator--();
//	conststrblobptr operator++(int);
//	conststrblobptr operator--(int);
//	conststrblobptr& operator+=(size_t);
//	conststrblobptr& operator-=(size_t);
//	conststrblobptr operator+(size_t) const;
//	conststrblobptr operator-(size_t) const;
//
//	const string& operator[](size_t)const;
//
//private:
//	std::weak_ptr<vector<string>>wptr;
//	std::shared_ptr<vector<string>>check(size_t, const string&)const;
//
//	size_t curr;
//};
//
//bool operator==(const conststrblobptr&, const conststrblobptr&);
//bool operator!=(const conststrblobptr&, const conststrblobptr&);
//bool operator< (const conststrblobptr&, const conststrblobptr&);
//bool operator> (const conststrblobptr&, const conststrblobptr&);
//bool operator<=(const conststrblobptr&, const conststrblobptr&);
//bool operator>=(const conststrblobptr&, const conststrblobptr&);
//
//inline const string& conststrblobptr::deref()const
//{
//	auto p = check(curr, "dereference past end");
//	return (*p)[curr];
//}
//
//inline conststrblobptr& conststrblobptr::operator++()
//{
//	check(curr, "increment past end of conststrblobptr");
//	++curr;
//	return *this;
//}
//
//inline conststrblobptr& conststrblobptr::operator--()
//{
//	--curr;
//	check(-1, "decrement past begin of conststrblobptr");
//	return *this;
//}
//
//inline conststrblobptr conststrblobptr::operator++(int)
//{
//	conststrblobptr ret = *this;
//	++*this;
//	return ret;
//}
//
//inline conststrblobptr conststrblobptr::operator--(int)
//{
//	conststrblobptr ret = *this;
//	--*this;
//	return ret;
//}
//
//inline conststrblobptr& conststrblobptr::operator+=(size_t n)
//{
//	curr += n;
//	check(curr, "increment past end of conststrblobptr");
//	return *this;
//}
//
//inline conststrblobptr& conststrblobptr::operator-=(size_t n)
//{
//	curr -= n;
//	check(curr, "increment past end of conststrblobptr");
//	return *this;
//}
//
//inline conststrblobptr conststrblobptr::operator+(size_t n)const
//{
//	conststrblobptr ret =*this;
//	ret += n;
//	return ret;
//}
//
//inline conststrblobptr conststrblobptr::operator-(size_t n)const
//{
//	conststrblobptr ret = *this;
//	ret -= n;
//	return ret;
//}
//
//inline std::shared_ptr<vector<string>>conststrblobptr::check(size_t i, const string& msg)const
//{
//	auto ret = wptr.lock();
//	if (!ret)throw std::runtime_error("unbound strblobptr");
//	if (i >= ret->size())throw std::out_of_range(msg);
//	return ret;
//}
//
//inline const string& conststrblobptr::operator[](size_t n)const
//{
//	auto p = check(n, "dereference out of range.");
//	return (*p)[curr];
//}
