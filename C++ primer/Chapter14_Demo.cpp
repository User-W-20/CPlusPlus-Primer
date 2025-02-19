#include<iostream>
#include"Sales_data.h"
//14.2.1 重载输出运算符<<
//Sales_data的输出运算符


//std::ostream& operator<<(std::ostream& os, const Sales_data& item)
//{
//	os << item.isbn() << " " << item.units_sold << " " << item.revenue << " " << item.avg_price();
//	return os;
//}

//输出运算符应该主要负责打印对象的内容而非控制格式，输出运算符不应该打印换行符

//14.2.2重载输入运算符>>
//Sales_data的输入运算符

//note:输入运算符必须处理输入可能失败的情况，而输出运算符不需要

//std::istream& operator>>(std::istream& is, Sales_data& item)
//{
//	double price;//不需要初始化，先读入数据到price，之后才使用它
//	is >> item.bookNo >> item.units_sold >> price;
//	if (is)//检查输出是否成功
//		item.revenue = item.units.sold * price;
//	else
//		item = Sales_data();//输入失败：对象被赋予默认状态
//	return is;
//}

//当读取操作发生错误时，输入运算符应该负责从错误中恢复

//14.3 算术和关系运算符

//Sales_data operator+(const Sales_data& lhs, const Sales_data& rhs)
//{
//	Sales_data sum = lhs;//把lhs的数据成员拷贝给sum
//	sum += rhs;//将rhs加到sum中
//	return sum;
//
//}

//Tip:如果类同时定义了算术运算符和相关的复合赋值运算符，则通常情况下应该使用复合赋值运算符来实现算术运算符

//14.3.1相等运算符

//bool operator==(const Sales_data& lhs, const Sales_data& rhs)
//{
//	return lhs.isbn() == rhs.isbn() && lhs.units_sold == rhs.units_sold && lhs.revenue == rhs.revenue;
//}
//
//bool operator!=(const Sales_data& lhs, const Sales_data& rhs)
//{
//	return !(lhs == rhs);
//}

//如果某个类在逻辑上有相等性的含义，则该类应该定义operator==，这样做可以使得用户更容易使用标准库算法来处理这个类

//14.4 赋值运算符
//class StrVec {
//public:
//	StrVec& operator=(std::initializer_list<std::string>);
//private:
//	void	alloc_n_copy();
//};


//Note:可以重载赋值运算符。不论形参类型是什么，赋值运算符都必须定义为成员函数
//StrVec& StrVec::operator=(std::initializer_list<std::string>il)
//{
//	//alloc_n_copy分配内存空间并从给定范围内拷贝元素
//	auto data = alloc_n_copy(il.begin(), il.end());
//	free();	//销毁对象中的元素并释放内存空间
//	elements = data.first();//更新数据成员使其指向新空间
//	first_free = cap = data.second;
//	return *this;
//}

//复合赋值运算符
//作为成员的二元运算符，左侧运算对象绑定到隐式的this指针
//假定两个对象表示同一本书
//Sales_data& Sales_data::operator+=(const Sales_data& rhs)
//{
//	units_sold += rhs.units_sold;
//	revenue += rhs.revenue;
//	return *this;
//}

//赋值运算符必须定义成类的成员，复合赋值运算符通常情况下也应该这么做。这两类运算符都应该返回左侧运算对象都引用。

//14.5 下标运算符

//Note:下标运算符必须是成员函数

//如果一个类包含下标运算符，则他通常会定义两个版本：一个返回普通引用，另一个是类的常量成员并且返回常量引用

//class StrVec {
//public:
//	std::string& operator[](std::size_t n) { return elements[n]; }
//
//	const std::string& operator[](std::size_t n)const { return elements[n]; }
//private:
//	std::string* elements;//指向数组首元素的指针
//};

//假设svec是一个StrVec对象
/*const StrVec cvec = svec;*///把svec的元素拷贝到cvec中

//如果svec中含有元素，对第一个元素运行string 的empty函数
//if (svec.size() && svec[0].empty()) {
//	svec[0] = "zero";//正确：下标运算符返回string的引用
//	cvec[0] = "Zip";//错误：对cvec取下标返回到的是常量引用
//}

//14.6 递增和递减运算符

//定义递增和递减运算符的类应该同时定义前置版本和后置版本。这些运算符应该被定义成类的成员

//定义前置递增/递减运算符

//class StrBlobPtr {
//public:
//	//递增和递减运算符 
//	StrBlobPtr& operator++();//前置运算符
//	StrBlobPtr& operator--();
//};

//为了与内置版本保持一致，前置运算符应该返回递增或递减后对象的引用

////前置版本：返回递增/递减对象的引用
//StrBlobPtr& StrBlobPtr::operator++()
//{
//	//如果curr已经指向容器的尾后位置，则无法递增他
//	check(curr, "increment past end of StrBlobPtr");
//	++curr;//将curr在当前状态下前进移动一个元素
//	return *this;
//}

//StrBlobPtr& StrBlobPtr::operator--()
//{
//	//如果curr是0，则继续递减它将产生一个无效下标
//	--curr;//将curr在当前状态下向后移动一个元素
//	check(curr, "decrement past beging of StrBlobStr");
//	return *this;
//}

//区分前置和后置运算符
//class StrBlobPtr {
//public:
//	//递增和递减运算符
//	StrBlobPtr operator++(int);//后置运算符
//	StrBlobPtr operator--();
//};

//为了与内置版本保持一致，后置运算符应返回对象的原值（递增或递减之前的值），返回的形式是一个值而非引用。

//后置版本：递增/递减对象的值但是返回原值

//Note:因为不会用到int形参，所以无须为其命名
//StrBlobPtr StrBlobPtr::operator++(int)
//{
//	//此处无须检查有效性，调用前置递增运算符才需要检查
//	StrBlobPtr ret = *this;//记录当前的值
//	++*this;//向前移动一个元素，前置++需要检查递增的有效性
//	return ret;//返回之前记录的状态
//}

//StrBlobPtr StrBlobPtr::operator--(int)
//{
//	//此处无须检查有效性，调用前置递减运算符才需要检查
//	StrBlobPtr ret = *this;//记录当前的值
//	--*this;//向后移动一个元素，前置--需要检查递减的有效性
//	return ret;//返回之前记录的状态
//}

//14.7成员访问运算符

//Note:箭头运算符必须是类的成员。解引用运算符通常也是类的成员，尽管并非必须如此。

//class StrBlobPtr {
//public:
//	std::string& operator*()const
//	{
//		auto p = check(curr, "dereference past end");
//		return (*p)[curr];//(*p)是对象所指的vector
//	}
//	std::string* operator->()const
//	{
//		//将实际工作委托给解引用运算符
//		return &this->operator*();
//	}
//};

//Note:重载的箭头运算符必须返回类的指针或者自定义了箭头运算符的某个类的对象。

//14.8 函数调用运算符
//struct absInt
//{
//	int operator()(int val)const {
//		return val < 0 ? -val : val;
//	}
//};

//Note:函数调用运算符必须是成员函数。一个类可以定义多个不同版本的调用运算符，相互之间应该在参数数量或类型上有所区别。

//含有状态的函数对象类
//class PrintString {
//public:
//	PrintString(std::ostream& o = std::cout, char c = ' ') :
//		os(o), sep(c){}
//	void operator()(const std::string& s)const { os << s << sep; }
//private:
//	std::ostream& os;//用于写入的目的流
//	char sep;//用于将不同输出隔开的字符
//};

//14.8.1 lambda是函数对象

//根据单词的长度对其进行排序，对于长度相同的单词按照字母表顺序排序
//class stable_sort {
//public:
//	stable_sort(words.begin(), words.end(), [](const std::string& a, const std::string& b) {return a.size() < b.size(); });
//
//};
//
//class ShoterString {
//public:
//	bool operator()(const std::string& s1, const std::string& s2)const { return s1.size() < s2.size(); }
//};

//表示lambda及对应捕获行为的类

//获得第一个指向满足条件元素的迭代器，该元素满足size（） is>=sz
//auto wc = std::find_if(words.begin(), words.end(), [sz](const std::string& a) {return a.size() >= sz; });

//class SizeComp {
//public:
//	SizeComp(size_t n):sz(n){}//该形参对应捕获的变量
//	//该调用运算符的返回类型，形参和函数体与lambda一致
//	bool operator()(const std::string& s)const { return s.size() >= sz; }
//private:
//	size_t sz;//该数据成员对应通过值捕获的变量
//};

//14.8.3 可调用对象与function

//重载的函数与function
//Note:新版本标准库中的function类与旧版本中的unary_function和binary_function没有关联，后两个类已经被更通用的bind函数替代了

//14.9.1 类型转换运算符
//Note:一个类型转换函数必须是类的成员函数；它不能声明返回类型，形参列表也必须为空。类型转换函数通常应该是const

//定义含有类型转换运算符的类
//class SmallInt {
//public:
//	SmallInt(int i = 0) :val(i)
//	{
//		if (i < 0 || i>255)
//			throw std::out_of_range("Bad SmallInt value");
//	}
//	operator int() const { return val; }
//private:
//	std::size_t val;
//};

//显式的类型转换运算符
//class SmallInt {
//public:
//	//编译器不会自动执行这一类型转换
//	explicit operator int()const { return val; }
//};

//转换为bool
//向bool的类型转换通常用在条件部分，因此operator bool一般定义成explicit的。

//14.9.2避免有二义性的类型转换
//通常情况下，不要为类定义相同的类型转换，也不要在类中定义两个及两个以上转换源或转换目标是算术类型的转换。

//实参匹配和相同的类型转换

//最好不要在两个类之间构造相同的类型转换
//struct B;
//struct A {
//	A() = default;
//	A(const B&);//把一个B转换成A
//};
//
//struct B {
//	operator A()const;//也是把一个B转换成A
//};
//A f(const A&);
//B b;
//A a = f(b);//二义性错误：含义是f(B::operator A())
//			//还是f(A::A(const B&))?

//二义性与转换目标为内置类型的多重类型转换

//struct A
//{
//	A(int = 0);//最好不要创造两个转换源都是算术类型的类型转换
//	A(double);
//	operator int()const;//最好不要创造两个转换源都是算术类型的类型转换
//	operator double()const;
//
//};

//void f2(long double);
//A a;
//f2(a);//二义性错误：含义是f(A::operator int())
//		//还是f(A::operator double())?
//
//long lg;
//A a2(lg);//二义性错误：含义是A::A(int)还是A::A(double)?

//Note:当使用两个用户定义的类型转换时，如果转换函数之前或之后存在标准类型转换，则标准类型转换将决定最佳匹配到底是哪个。

////重载函数与转换构造函数
//struct C
//{
//	C(int);
//};
//
//struct D
//{
//	D(int);
//};
//
//void mainp(const C&);
//void mainp(const D&);
//mainp(10);//二义性错误：mainp（c(10)）or mainp(D(10））？
//mainp(C(10));//显示调用消除二义性


//如果在调用重载函数时我们需要使用构造函数或者强制类型转换来改变实参的类型，则这通常意味着程序的设计存在不足。

//重载函数与用户定义的类型转换
//struct E
//{
//	E(double);
//};
//
//void manip2(const C&);
//void manip2(const E&);
////二义性错误：两个不同用户定义的类型转换都能用在此处
//mainp2(10);//mainp2(C(10))or mainp2(E(double 10))?

//Note:在调用重载函数时，如果需要额外的标准类型转换，则该转换的级别只有当所有可行函数都请求同一个用户定义的类型转换时才可用。如果所需的用户定义的类型转换不止一个，则该调用具有二义性

//14.9.3 函数匹配与重载运算符

//Note:表达式中运算符的候选函数集既应该包括成员函数，也应该包括非成员函数

//class SmallInt {
//	friend SmallInt operator+(const SmallInt&, const SmallInt&);
//
//public:
//	SmallInt(int = 0);//转换源为int的类型转换
//	operator int() const { return val; }//
//
//private:
//	size_t val;
//};
//
//SmallInt s1, s2;
//SmallInt s3 = s1 + s2;//使用重载的operator+
//int i = s3 + 0;//二义性错误

//如果我们对同一个类既提供了转换目标是算术类型的类型转换，也提供了重载的运算符，则将会遇到重载运算符与内置运算符的二义性问题。