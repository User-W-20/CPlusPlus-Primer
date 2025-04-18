#include<iostream>
#include<vector>
#include<string>
#include<utility>
#include<memory>
#include<unordered_set>
using namespace std;
//16.1 定义模板

//如果两个值相等，返回0，如果v1小返回-1，如果v2小返回1
int compare(const string& v1, const string& v2)
{
	if (v1 < v2)return -1;
	if (v2 < v1)return 1;
	return 0;
}

int compare(const double& v1, const double& v2)
{
	if (v1 < v2)return -1;
	if (v2 < v1)return 1;
	return 0;
}

//16.1.1 函数模板
template <typename T>
int compare(const T& v1, const T& v2)
{
	if (v1 < v2)return -1;
	if (v2 < v1)return 1;
	return 0;
}

//template后跟模板参数列表 用逗号分隔的一个或多个模板参数，<>

//Note:在模板定义中，模板参数的列表不能为空

//使用模板时，（隐式或显式地）指定模板实参，将其绑定到模板参数上

//实例化函数模板
cout << compare(1, 0) << endl;//T为int

//编译器用推断出的模板参数实例化一个特定版本的函数。

//实例化出int compare(const int&,const int&)
cout << compare(1, 0) << endl;
//实例化出int compare(const vector<int>&,const vector<int>&)
vector<int>vec1{ 1,2,3 }, vec2{ 4,5,6 };
cout << compare(vec1, vec2) << endl;//T vector<int>

int compare(const int& v1, const int& v2)
{
	if (v1 < v2)return -1;
	if (v2 < v1)return 1;
	return 0;
}

//模板类型参数
//正确：返回类型与参数类型相同
template <typename T>T foo(T* p)
{
	T tmp = *p;//tmp的类型是指针p指向的类型
	//...
	return tmp;
}

//错误：U之前必须加上class或typename
template<typename T, U>T calc(const T&, const U&);

//在模板参数列表中，class和typename没区别
template<typename T, class U>T calc(const T&, const U&);

//非类型模板参数
template<unsigned N, unsigned M>
int compare(const char(&p1)[N], const char(&p2[M])
{
	return strcmp(p1, p2);
}
compare("hi", "mom");
int compare(const char(&p1)[3], const char(&p2)[4]);

//Note:非类型模板参数实参必须是常量表达式

//即使用于指针也正确的compare版本
template<typename T>int comapre(const T& v1, const T& v2)
{
	if (less<T>()(v1, v2))return -1;
	if (less<T>()(v2, v1))return 1;
	return 0;
}

//模板参数应该尽量减少对实参类型的要求

//模板编译
//Note:函数模板和类模板成员函数的定义通常放在头文件中

//大多数编译错误在实例化期间报告
	//第一个阶段是编译模板本身时。
	//第二个阶段是编译器遇到模板使用时。
	//第三个阶段是模板实例化时。

if (v1 < v2)return -1;//要求类型T的对象支持<操作
if (v2 < v1)return 1;//要求类型T的对象支持<操作
return 0;//返回int，不依赖于T

Sales_data data1, data2;
cout << comapre(data1, data2) << endl;//错误：Sales_data为定义<  实例化时才发现

//warning：保证传递给模板的实参支持模板所要求的操作，以及这些操作在模板中能正确工作，是调用者的责任。

//16.1.2 类模板
	//用来生成类的蓝图。 <>中提供额外信息

//定义类模板
template <typename T>class Blob
{
public:
	typedef T value_type;
	typedef typename vector<T>::size_type size_type;

	Blob();
	Blob(std::initializer_list<T>il);

	size_type size()const { return data->size(); }
	bool empty()const { return data->element_type(); }

	void push_back(const T& t) { data->push_back(t); }

	void push_back(T&& t) { data->push_back(std::move(t)); }
	void pop_back();

	T& back();
	T& operator[](size_type i);

private:
	shared_ptr<vector<T>>data;
	void check(size_type i, const string& msg)const;
};

//实例化类模板
//额外信息是显式模板实参列表，被绑定到模板参数

Blob<int> ia;//空Blob<int>
Blob<int> ia2 = { 0,1,2,3,4 };//5个元素的Blob<int>

template <> class Blob<int>
{
	typedef typename std::vector<int>::size_type size_type;
	Blob();
	Blob(std::initializer_list<int>il);
	//...
	int& operator[](size_type i);

private:
	shared_ptr<vector<int>>data;
	void check(size_type i, const string& msg)const;
};

Blob<string>names;//保存string的blob
Blob<double>prices;//不同的元素类型

//Note:一个类模板的每个实例都形成一个独立的类。类型Blob<string>与任何其他Blob类型都没有关联，也不会对任何其他Blob类型的成员有特殊访问的权限。

//在模板作用域中引用模板类型
shared_ptr<vector<T>>data;
shared_ptr<vector<string>>data;//string
shared_ptr<vector<int>>data;//int

//类模板的成员函数
ret - type StrBlob::member - name(pram - list);

template <typename T>
ret - type Blob<T>::member - name(parm - list);

//check和元素访问成员
template <typename T>
void Blob<T>::check(size_type i, const string & msg)const
{
	if (i >= data->size())
		throw std::out_of_range(msg);
}

template <typename T>
T& Blob<T>::back()
{
	check(0, " back on empty Blob");
	return data->back();
}

template <typename T>
T& Blob<T>::operator[](size_type i)
{
	check(i, "subscript out of range");
	return (*data)[i];
}

template <typename T>
void Blob<T>::pop_back()
{
	check(0, "pop_back on empty Blob");
	data->pop_back();
}

//Blob构造函数
template<typename T>
Blob<T>::Blob() :data(make_shared<vector<T>>()) {}

template <typename T>
Blob<T>::Blob(initializer_list<T>il) : data(make_shared<vector<T>>(il)) {}

Blob<string> articles = { "a","an","the" };

//类模板成员函数的实例化
//实例化Blob<int>和接受initializer_list<int>的构造函数
Blob<int>squares = { 0,1,2,3,4,5,6,7,8,9 };

//实例化Blob<int>::size() const
for (size_t i = 0; i != squares.size(); ++i)
squares[i] = i * i;//实例化Blob<int>::operator[](size_t)

//Note:默认情况下，对于一个实例化了的类模板，其成员只有在使用时才被实例化.。

//在类代码内简化模板类名的使用
//在类模板自己的作用域中，可以直接使用模板名而不提供实参
//若试图访问一个不存在的元素，BlobPtr抛出一个异常
template <typename T>
class BlobPtr
{
public:
	BlobPtr() :curr(0) {}
	BlobPtr(Blob<T>& a, size_t sz - 0) :wptr(a.data), curr(sz) {}
	T& operator*()const
	{
		auto p = check(curr, "dereference past end");
		return (*p)[curr];//(*p)为本对象指向的vector
	}

	//递增与递减
	BlobPtr& operator++();//前置运算符
	BlobPtr& operator--();

private:
	//若检查成功，check返回一个指向vector的shared_ptr
	shared_ptr<vector<T>> check(size_t, const string&)const;

	//保存一个weak_ptr ，表示底层vector可能被销毁
	weak_ptr<vector<T>>wptr;

	size_t curr;//数组中的当前位置
};

BlobPtr<T>& operator++();
BlobPtr<T>& operator--();

//在类模板外使用类模板名

//后置：递增/递减对象但返回原值
template<typename T>
BlobPtr<T> BlobPtr<T>::operator++(int)
{
	//无须检查，调用前置递增时会进行检查
	BlobPtr ret = *this;//保存当前值
	++*this;//推荐一个元素，前置++检查递增是否合法
	return ret;//返回保存的状态
}

BlobPtr<T>ret = *this;

//Note:在一个类模板的作用域内，可以直接使用模板名而不必指定模板实参。

//类模板和友元
//如果类模板包含非类模板友元，则友元被授权可以访问所有模板实例。  
//如果友元本身是模板，类可以授权给所有友元模板实例，也可以只授权给特定实例。

//一对一友好关系
//建立对应实例以及其友元间的友好关系。

//前置声明，在Blob中声明友元所需要的
template <typename >class BlobPtr;
template<typename>class Blob;//==中的参数所需要的
template <typename T>
bool operator==(const Blob<T>&, const Blob<T>&);

template<typename T>class Blob
{
	//每个Blob实例将访问权限授予用相同类型实例化的BlobPtr和相等运算符
	friend class BlobPtr<T>;
	friend bool operator==<T> (const Blob<T>&, const Blob<T>&);

};

Blob<char>ca;//BlobPtr<char>和operator==<char>都是本对象的友元
Blob<int>ia;//BlobPtr<int>和operator==<int>都是本对象的友元

//通用和特定的模板友好关系
//前置声明，在将模板的一个特定实例声明为友元时要用到
template <typename T>class Pal;
class C//普通的非模板类
{
	friend class Pal<C>;//用类C实例化的Pal是C的一个友元
	//Pal2的所有实例都是C的友元，无须前置声明
	template<typename T>friend class Pal2;

};

template<typename T>class C2//C2本身是一个类模板
{
	//C2的每个实例将相同实例化的Pal声明为友元
	friend class Pal<T>;//Pal的模板声明必须在作用域之内
	//Pal2的所以实例都是C2的每个实例的友元，不需要前置声明
	template<typename X>friend class Pal2;
	//Pal3是一个非模板类，是C2所以实例的友元
	friend class Pal3;//不需要Pal的前置声明
};

//令模板自己的类型参数成为友元
template <typename Type>class Par
{
	friend Type;//将访问权限授予用来实例化Bar的类型
};

//模板类型别名
typedef Blob<string>strBlob;
//无法定义一个typedef引用Blob<T>

template <typename T>using twin = pair<T, T>;
twin<string>authors;//authors是一个pair<string,string>

twin<int>win_loss;//pair<int,int>
twin<double>area;

template<typename T>using partNo = pair<T, unsigned>;
partNo<string>books;//pair<string,unsigned>
partNo<Vehicle>cars;//pair<Vehicle,unsigned>
partNo<Student>kids;//pair<Student,unsigned>

//类模板的static成员
template<typename T>class Foo
{
public:
	static std::size_t count() { return ctr; }
	//Foo<X>::count
private:
	static std::size_t ctr;
	//Foo<X>::ctr
};

//实例化static成员Foo<string>::ctr和Foo<string>::count
Foo<string>fs;
//所有三个对象共享相同的Foo<int>::ctr和Foo<int>::count成员
Foo<int>fi, fi2, fi3;

template <typename T>
size_t Foo<T>::ctr = 0;//定义并初始化ctr

Foo<int>fi;//实例化Foo<int>类和static数据成员ctr
auto ct = Foo<int>::count();//实例化Foo<int>::count
ct = fi.count();//使用Foo<int>::count
ct = Foo::count();//错误：使用哪个模板实例的count？
//static成员函数只有在使用时才实例化

//16.1.3 模板参数
template <typename Foo>Foo calc(const Foo & a, const Foo & b)
{
	Foo tmp = a;//tmp的类型与参数和返回类型一样

	return tmp;//返回类型和参数类型一样
}

//模板参数与作用域
typedef double A;
template <typename A, typename B>void f(A a, B b)
{
	A tmp = a;//tmp的类型为模板参数A的类型，而非double
	double B;//错误：重声明模板参数B
}

//错误：非法重用模板参数名V
template <typename V, typename V>{/**/}//...

//模板声明
//声明但不定义compare和Blob
template<typename T>int compare(const T&, const T&);
template<typename T>class Blob;

//3个calc都指向相同的函数模板
template <typename T>T calc(const T&, const T&);//声明
template <typename U>U calc(const U&, const U&);//声明

//模板的定义
template<typename Type>
Type calc(const Type & a, const Type & b) {/**/ }

//一个特定文件所需要的所有模板的声明通常一起放置在文件开始位置。出现于任何使用这些模板的代码之前。

//使用类的类型成员
template <typename T>
typename T::value_type top(const T & c)
{
	if (!c.empty())
		return c.back();
	else
		return typename T::value_type();
}

//Note:当我们希望通知编译器一个名字表示类型时，必须使用关键字typename，而不能使用class。

//默认模板实参
//compare有一个默认模板实参less<T>和一个默认函数实参F()
template <typename T, typename F = less<T>>
int compare(const T & v1, const T & v2, F f = F())
{
	if (f(v1, v2))return -1;
	if (f(v2, v1))return 1;
	return 0;
}

bool i = compare(0, 42);//使用less;i为-1
//结果依赖于item1和item2中的isbn
Sales_data item1(cin), item2(cin);
bool j = compare(item1, item2, compreIsbn);

//模板默认实参与类模板
template <class T = int >class Numbers//默认为int
{
public:
	Numbers(T v = 0) :val(v) {}

private:
	T val;
};

Numbers<long double> lots_of_precision;
Numbers<> average_precision;

//16.1.4成员模板
//一个类（无论普通还是类模板）可以包含本身是模板的成员函数。 成员模板不能是虚函数。

//普通（非模板）类的成员模板
//函数对象类，对给定指针执行delete
class DebugDelete
{
public:
	DebugDelete(ostream& s = cerr) :os(s) {}
	//T的类型由编译器推断
	template<typename T>void operator()(T* p)const
	{
		os << "deleting unique_ptr" << endl;
		delete p;
	}
private:
	ostream& os;
};

double* p = new double;
DebugDelete d;//可像delete表达式一样使用的对象
d(p);//调用DebugDelete::operator()(double *p),释放p
int* ip = new int;
//在一个临时DebugDelete对象上调用operator()(int *)
DebugDelete()(ip);

//销毁p指向的对象
//实例化DebugDelete::operator()<int>(int *)
unique_ptr<int, DebugDelete>p(new int, DebugDelete());
//销毁sp指向的对象
//实例化DebugDelete::operator()<string>(string*)
unique_ptr<string, DebugDelete>sp(new string, DebugDelete());

//DebugDelete的成员模板实例化样例
void DebugDelete::operator()(int* p)const { delete p; }
void DebugDelete::operator()(string * p)const { delete p; }

//类模板的成员模板
template<typename T>class Blob
{
	template<typename It>Blob(It b, It e);
};

template<typename T>//类的类型参数
template<typename It>//构造函数的类型参数
Blob<T>::Blob(It b, It e) :
	data(make_shared<vector<T>>(b, e)) {
}

//实例化与成员模板
int ia[] = { 0,1,2,3,4,5,6,7,8,9 };
vector<long>vi = { 0,1,2,3,4,5,6,7,8,9 };
list<const char*>w = { "now","is","the","time" };
//实例化Blob<int>类及其接受两个int*参数的构造函数
Blob<int>a1(begin(ia), end(ia));
//实例化Blob<int>类的接受两个vector<long>::iterator的构造函数
Blob<int>a2(vi.begin(), vi.end());
//实例化Blob<string>类及其接受两个list<const char*>::iterator的构造函数
Blob<string>a3(w.begin(), w.end());

Blob<int>::Blob(int*, int*);

//16.1.5 控制实例化
//用显式实例化避免开销。
extern template declaration;//实例化声明
template declaration;//实例化定义

//实例化声明与定义
extern template class Blob<string>;//声明
template int compare(const int&, const int&);//定义

//对于给定的实例化版本，可能有多个extern声明，但必须只有一个定义

//Application.cc
//这些模板类型必须在程序其他位置进行实例化
extern template class Blob<string>;
extern template int compare(const int&, const int&);
Blob<string>sa1, sa2;//实例化会出现在其他位置
//Blob<int>及其接受initializer_list的构造函数在本文件中实例化
Blob<int>a1 = { 0,1,2,3,4,5,6,7,8,9 };
Blob<int>a2(a1);//拷贝构造函数在本文件中实例化
int i = comapre(a1[0], a2[0]);//实例化出现在其他位置

//templateBuild.cc
//实例化文件必须为每个在其他文件中声明为extern的类型和函数提供一个（非extern）的定义
template int compare(const int&, const int&);
template class Blob<string>;//实例化类模板的所有成员

//warning:对每个实例化声明，在程序中某个位置必须有其显式的实例化定义。

//实例化定义会实例化所有成员

//Note:在一个类模板的实例化定义中，所用类型必须能用于模板的所有成员函数。

//16.1.6 效率与灵活性

//在运行时绑定删除器
//删除器必须保存一个指针或一个封装了指针的类

//del的值只有运行时才知道；通过一个指针来调用他
del ? del(p) : delete p;//del(p)需要运行时跳转到del的地址

//在编译时绑定删除器
//del在编译时绑定；直接调用实例化的删除器
del(p);//无运行时额外开销

//unique_ptr 避免间接调用删除器的运行时开销
//shared_ptr 使用户重载删除器更为方便

//16.2 模板实参推断 
//从函数实参来确定模板实参的过程

//16.2.1 类型转换与模板类型参数
//顶层const无论在形参还是实参，都会被忽略
//const转换
//数组或函数指针转换

template <typename T>T fobj(T, T);//实参被拷贝
template<typename T>T fref(const T&, const T&);//引用
string s1("a value");
const string s2("another value");
fobj(s1, s2);// 调用fobj(string, string);const 被忽略
fref(s1, s2);//调用fref(const string&,const string&)
//将s1转换为const是允许的
int a[10], b[42];
fobj(a, b);//调用f(int*,int*)
fref(a, b);//错误：数组类型不匹配

//Note:将实参传递给带模板类型的函数形参时，能够自动应用的类型转换只有const转换及数组或函数到指针的转换。

//使用相同模板参数类型的函数形参
//一个模板类型参数可以用作多个函数形参的类型。

long lng;
compare(lng, 1024);//错误：不能实例化compare(long,int)

//实参类型可以不同，当必须兼容
template<typename A, typename B>
int flexibleCompare(const A & v1, const B & v2)
{
	if (v1 < v2)return -1;
	if (v2 < v1)return 1;
	return 0;
}

long lng;
flexibleCompare(lng, 1024);//正确：调用flexibleCompare(long,int)

//正常类型转换应用于普通函数实参
//不涉及模板类型参数的类型
template<typename T>ostream& print(ostream & os, const T & obj)
{
	return os << obj;
}

print(cout, 42);//实例化print(ostream&,int)
ofstream f("output");
print(f, 10);//使用print(ostream&,int);将f转换为ostream&

//Note:如果函数参数类型不是模板参数，则对实参进行正常的类型转换。

//16.6.2 函数模板显式实参

//指定显式模板实参
	//编译器无法推断T1,它未出现在函数列表中
template<typename T1, typename T2, typename T3>
T1 sum(T2, T3);

//T1是显式指定的，T2和T3是从函数实参类型推断而来的
auto val3 = sum<long long>(i, lng);//long long sum(int,long)

//糟糕的设计：用户必须指定所有三个模板参数
template<typename T1, typename T2, typename T3>
T3 alternative_sum(T2, T1);

//错误：不能推断前几个模板参数
auto val3 = alternative_sum<long long>(i, lng);

//正确：显式指定了所有三个参数
auto val2 = alternative_sum<long long, int, long>(i, lng);

//正确类型转换应用于显式指定的实参
long lng;
compare(lng, 1024);//错误：模板参数不匹配
comapre<long>(lng, 1024);//正确：实例化compare(long,long)
comapre<int>(lng, 1024);//正确：实例化compare(int,int)

//16.2.3 尾置返回类型与类型转换
template<typename It>
? ? ? &fcn(It beg, It end)
{
	//处理序列
	return *beg;//返回序列中一个元素的引用
}

vector<int>v1 = { 1,2,3 };
Blob<string>ca = { "hi","bye" };
auto& i = fcn(vi.begin(), vi.end());//fcn应该返回int&
auto& s = fcn(ca.begin(), ca.end());//fcn应该返回string&

//尾置返回允许我们在参变列表之后声明返回类型
template<typename It>
auto fcn(It beg, It end) -> decltype(*beg)
{
	//处理序列
	return *beg;//返回序列中一个元素的引用
}

//进行类型转换的标准库模板类
	//type_traits
remove_reference<decltype(*beg)>::type

//为了使用模板参数类，必须使用typename
template<typename It>
auto fcn2(It beg, It end) ->
typename remove_reference<decltype(*beg)>::type
{
	//处理序列
	return *beg;//返回序列中一个元素的引用
}

//16.2.4 函数指针和实参推断
template<typename T>int compare(const T&, const T&);
//pf1指向实例int compare(const int&, const int&);
int(*pf1)(const int&, const int&) = compare;

//func 的重载版本；每个版本接受一个不同的函数指针类型
void func(int(*))(const string&, const string&);
void func(int(*))(const int&, const int&);
func(compare);//错误：使用compare的哪个实例？

//正确：显式指出实例化哪个compare版本
func(compare<int>);//传递compare(const int&, const int&);

//Note:当参数是一个函数模板实例的地址时，程序上下文必须满足：对每个模板参数，能唯一确认其类型或值。

//16.2.5 模板实参推断和引用
template<typename T>void f(T & p);
//编译器会应用正确的引用绑定规则；const是底层的，不是顶层的

//从左值引用函数参数推断类型
template<typename T>void f1(T&);//实参必须是一个左值
//对f1的调用使用实参所引用的类型作为模板参数类型
f1(i);//i int,T是int
f1(ci);//ci  const int ,T是const int
f1(5);//错误：传递给一个&参数的实参必须是一个左值

template<typename T>void f2(const T&);//可以接受一个右值
//f2中的参数是const &;实参中的const是无关的
//在每个调用中，f2的函数参数都被推断为const int&
f2(i);//i int,T是int
f2(ci);//ci  const int ,T是const int
f2(5);//一个const & 参数可以绑定到一个右值;T是int

//从右值引用函数参数推断类型
template<typename T>void f3(T&&);
f3(42);//实参是一个int类型的右值；模板参数T是int

//引用折叠和右值引用参数
	//X& &,X& &&和X&& &都被折叠成类型X&
	//类型X&& &&折叠床X&&

//Note:引用折叠只能应用于间接创建的引用的引用，如类型别名或模板参数

f3(i);//实参是一个左值；模板参数T是一个int&
f3(ci);//实参是一个左值；模板参数T是一个const int&

void f3<int&>(int&&&);//当T是int&时，函数参数折叠为int& &&

void f3<int&>(int&);//当T是int&时，函数参数折叠为int&

//Note:如果一个函数参数是指向模板参数类型的右值引用（如，T&&），则可以传递给他任意类型的实参。如果将一个左值传递给这样的参数，则函数参数被实例化为一个普通的左值引用（T&）。

//编写接受右值引用参数的模板函数
template<typename T>
void f3(T && val)
{
	T t = val;//拷贝还是绑定一个引用？
	t = fcn(t);//赋值只改变t还是既改变t又改变val？
	if (val == t) {/* ... */ }//若T是引用类型，则一直为true
}

template<typename T>void f(T&&);//绑定到非const右值
template<typename T>void f(const T&);//左值和const值

//16.2.6 理解std::move
//强制转换为右值

//std::move是如何定义的
	//在返回类型和类型转换中也要用到typename
	//remove_reference
template<typename T>
typename remove_reference<T>::type&& move(T && t)
{
	//static_cast
	return static_cast<typename remove_reference<T>::type&&>(t);
}

string s1("hi!"), s2;
s2 = std::move(string("bye!"));//正确：从一个右值移动数据
s2 = std::move("s1");//正确：但在赋值之后，s1的值是不确定的

//std::move是如何工作的
string&& move(string && t);

string&& move(string & t);

//从一个左值static_cast到一个右值引用是允许的

//16.2.7 转发
	//接受一个可调用对象和另外两个参数的模板
	//对“翻转”的参数调用给定的可调用对象
	//flip1是一个不完整的实现：顶层const和引用丢失了
template<typename F, typename T1, typename T2>
void flip1(F f, T1 t1, T2 t2)
{
	f(t2, t1);
}

void f(int v1, int& v2)//v2是一个引用
{
	cout << v1 << " " << ++v2 << endl;
}

f(42, i);//f改变了实参i
flip1(f, j, 42);//通过flip1调用f不会改变j

void flip1(void(*fcn)(int, int&), int t1, int t2);

//定义能保持类型信息的函数参数
template<typename F, typename T1, typename T2>
void flip2(F f, T1 && t1, T2 && t2)
{
	f(t2, t1);
}

//Note:如果一个函数参数是指向模板类型参数的右值引用（T&&），它对应的实参的const属性和左值/右值属性将得到保持。

	//不能用于接受右值引用的参数的函数
void g(int&& i, int& j)
{
	cout << i << " " << j << endl;
}

flip2(g, i, 42);//错误：不能从左值实例化int&&

//在调用中使用std::forward 保持类型信息
template<typename Type>intermediary(Type && arg)
{
	finalFcn(std::forward<Type>(arg));
}

//Note:当用一个指向模板参数类型的右值引用函数参数(T&&)时，forward会保持实参类型的所有细节。

template<typename F, typename T1, typename T2>
void filp(F f, T1 && t1, T2 && t2)
{
	f(std::forward<T2>(t2), std::forward<T1>(t1));
}

//Note:与std::move相同，对std::forward不使用using声明是一个好主意。

//16.3 重载与模板
//warning:正确定义一组重载的函数模板需要对类型间的关系及模板函数允许的有限的实参类型转换有深刻的理解。

//编写重载模板
	//打印任何我们不能处理的类型
template<typename T>string debug_rep(const T & t)
{
	ostringstream ret;
	ret << t;//使用T的输出运算符打印t的一个表示形式
	return ret.str();//返回ret绑定的string的一个副本
}

//打印指针的值，后跟指针指向的对象
//注意：此函数不能用于char*
template<typename T>string debug_rep(T * p)
{
	ostringstream ret;
	ret << "pointer: " << p;//打印指针本身的值
	if (p)
		ret << " " << debug_rep(*p);//打印p指向的值
	else
		ret << " null pointer";//或指出p为空
	return ret.str();//返回ret绑定的string的一个副本
}

string s("hi");
cout << debug_rep(s) << endl;

cout << debug_rep(&s) << endl;

//多个可行模板
const string* sp = &s;
cout << debug_rep(sp) << endl;

//Note:当有多个重载模板对一个调用提供相同好的匹配时，应该选最特例化的版本。

//非模板和模板重载
	//打印双引号包围的string
string debug_rep(const string & s)
{
	return '"' + s + '"';
}

string s("hi");
cout << debug_rep(s) << endl;

//Note:对于一个调用，如果一个非函数模板与一个函数模板提供同样好的匹配，则选择非模板版本。

//重载模板和类型转换
cout << debug_rep("hi world") << endl;//调用debug_rep(T*)

//将字符指针转换为string，并调用string版本的debug_rep
string debug_rep(char* p)
{
	return debug_rep(string(p));
}

string debug_rep(const char* p)
{
	return debug_rep(string(p));
}

//缺少声明可能导致程序行为异常
template<typename T>string debug_rep(const T & t);
template<typename T>string debug_rep(T * p);
//为了使debug_rep(char* )的定义正确工作，下面的声明也必须再作用域中
string debug_rep(const string&);
string debug_rep(char* p)
{
	//如果接受一个const string& 的版本声明不在作用域中
	//返回语句将调用debug_rep(const T&)的T实例化为string的版本
	return debug_rep(string(p));
}

//在定义任何函数之前，记得声明所有重载的函数版本。这样就不必担心编译器由于未遇到希望调用的函数而实例化一个并非所需的版本。

//16.4 可变参数模板
	//接受可变数目参数的模板函数或模板类。
	//可变数目的参数：参数包
	//模板参数包：零个或多个模板参数
	//函数参数包：零个或多个函数参数

	//Args是一个模板参数包；rest是一个函数参数包
	//Args表示零个或多个模板类型参数
	//rest表示零个或多个函数参数
template<typename T, typename ... Args>
void foo(const T & t, const Args&...rest) {/**/ }

int i = 0; double d = 3.14; string s = " how now brown cow";
foo(i, s, 42, d);//包中有三个参数
foo(s, 42, "hi");//包中有二个参数
foo(d, s);//包中有一个参数
foor("hi");//空包

void foo(const int&, const string&, const int&, const double&);
void foo(const string&, const int&, const char[3] &);
void foo(const double&, const string&);
void foo(const char[3] &);

//sizeof...运算符
template<typename ...Args>
void g(Args...args)
{
	cout << sizeof...(Args) << endl;//类型参数的数目
	cout << sizeof...(args) << endl;//函数类型的数目
}

//16.4.1 编写可变参数函数模板
		//用来终止递归并打印最后一个元素的函数
		//此函数必须在可变参数版本的print定义之前声明
template<typename T>
ostream& print(ostream & os, const T & t)
{
	return os << t;//包中最后一个元素之后不打印分隔符
}
//包中除了最后一个元素之外的其他元素都会调用这个版本的print
template<typename T, typename...Args>
ostream& print(ostream & os, const T & t)
{
	return os << t;//包中最后一个元素之后不打印分隔符
}
//包中除了最后一个元素之外的其他元素都会调用这个版本的print
template<typename T, typename... Args>
ostream& print(ostream & os, const T & t, const Args...rest)
{
	os << t << " ,";//打印第一个实参
	return print(os, rest...);//递归调用，打印其他实参
}

//warning:当定义可变参数版本的print时，非可变参数版本必须在作用域中。否则，可变参数版本会无限递归。

//16.4.2 包扩展
template<typename T, typename... Args>
ostream& print(ostream & os, const T & t, const Args...rest)//扩展Args
{
	os << t << " ,";
	return print(os, rest...);//扩展rest
}

print(cout, i, s, 42);//包中有两个参数
ostream& print(ostream & os, const int&, const string&, const int&);
print(os, s, 42);

//理解包扩展
		//在print调用中对每个实参调用debug_rep
template<typename...Args>
ostream& errorMsg(ostream & os, const Args&...rest)
{
	//print(os,debug_rep(a1),debug_rep(a2),...,debug_rep(an)
	return print(os, debug_rep(rest)...);
}

errorMsg(cerr, fcnName, code.num(), otherData, "other", item);

print(cerr, debug_rep(fcnName), debug_rep(code.num()), debug_rep(otherData), debug_rep("other"), debug_rep(item));

//将包传递给debug_rep;print(os,debug_rep(a1,a2,...,an))
print(os, debug_rep(rest)...);//错误：此调用无匹配函数
print(cerr, debug_rep(fcnName, code.num(), otherData, "other", item));

//Note:扩展中的模式会独立地应用于包中的每个元素。

//16.4.3 转发参数包
class StrVec
{
public:
	template<class...Args>void emplace_back(Args&&...);
};

template<class...Args>
inline
void StrVec::emplace_back(Args&&...args)
{
	chk_n_alloc();//如果需要的话重新分配StrVec内存空间
	alloc.construct(first_free++, std::forward<Args>(args)...);
}
svec.empalce_back(10, 'c');//将cccccccccc添加为新的尾元素
std::forward<int>(10), std::forward<char>(c)

svec.empalce_back(s1 + s2);//使用移动构造函数
std::forward<string>(string("the end"));

//16.5 模板特例化
//第一个版本；可以比较任意两个类型
template<typename T>int compare(const T&, const T&);

//第二个版本处理字符串字面常量
template<size_t N,size_t M>
int compare(const char(&)[N], const char(&)[M]);

const char* p1 = "hi", * p2 = "mom";
compare(p1, p2);//调用第一个模板
compare("hi", "mom");//调用有两个非类型参数的版本

//一个特例化版本就是模板的一个独立的定义，在其中一个或多个模板参数被指定为特定的类型。

//定义函数模板特例化
//compare的特殊版本，处理字符数组的指针
template<>
int compare(const char* const& p1, const char* const& p2)
{
	return strcmp(p1, p2);
}

template<typename T>int compare(const T&, const T&);

//函数重载与模板特例化
//Note:特例化的本质是实例化一个模板，而非重载它。因此，特例化不影响函数匹配。

//模板及其特例化版本应该声明在同一个头文件中。所有同名模板的声明应该放在前面，然后是这些模板的特例化版本。

//类模板特例化
//打开std命名空间，以便特例化std::hash
namespace std
{

}//关闭std命名空间；右花括号之后没有分号

//打开std命名空间，以便特例化std::hash
namespace std
{
	template<>//定义一个特例化版本，模板参数为Sales_data
	struct hash<Sales_data>
	{
		//用来散列一个无序容器的类型必须要定义下列内容
		typedef size_t result_type;
		typedef Sales_data argument_type;//默认情况下，此类型需要==
		size_t operator()(const Sales_data& s)const;
		//使用合成的拷贝控制成员和默认构造函数
	};
}
size_t
hash<Sales_data>::operator(const Sales_data& s)const
{
	return hash<string>()(s.bookNo) ^
		hash<unsigned>()(s.units_sold) ^
		hash<double>()(s.revenue);
}

//使用hash<Sales_data>和Sales_data的operator==
unordered_multiset<Sales_data>Sdset;

template<class T>class std::hash;//友元声明所需要的
class Sales_data
{
	friend class std::hash<Sales_data>;
};

//Note:为了让Sales_data的用户能使用hash的特例化版本，应该在Sales_data的头文件中定义该特例化版本。

//类模板部分特例化
//Note:只能部分特例化类模板，而不能部分特例化函数模板。

//原始的、最通用的版本
template<class T>struct  remove_reference
{
	typedef T type;
};

//部分特例化版本，将用于左值引用和右值引用
template <class T>struct remove_reference<T&>//左值引用
{
	typedef T type;
};
template <class T>struct remove_reference<T&&>//右值引用
{
	typedef T type;
};

int i;
//decltype(42)为int，使用原始模板
remove_reference<decltype(42)>::type a;

//decltype(i)为int&,使用第一个(T&)部分特例化版本
remove_reference<decltype(i)>::type b;

//decltype(std::move(i))为int&&,使用第二个(T&&)部分特例化版本
remove_reference<decltype(std::move(i))>::type c;

//特例化成员而不是类
template<typename T>struct Foo
{
	Foo(const T&t=T()):mem{}
	void Bar(){/**/}
	T mem;
};
template<>//特例化一个模板
void Foo<int>::Bar()//特例化Foo<int>的成员Bar
{
	//进行应用于int的特例化处理
}

Foo<string>fs;//实例化Foo<string>::Foo()
fs.Bar();//实例化Foo<string>::Bar()
Foo<int>fi;//实例化Foo<int>::Foo()
fi.Bar();//使用特例化版本的Foo<int>::Bar()