//#include<iostream>
//#include<string>
//#include<stdexcept>
//#include<memory>
//#include<vector>
//using namespace std;
//
////18.1 异常处理
////允许程序中独立开发的部分能够在运行时就出现的问题进行通信并做出相应的处理。
//
////18.1.1 抛出异常
////通过抛出一条表达式来引发一个异常。
////被抛出的表达式的类型以及当前的调用链共同决定了哪段处理代码将被用来解处理该异常。
//
////执行throw时，跟在后面的语句将不再被执行。
////程序的控制权从throw转移到与之匹配的catch模块。
////该catch可能是同一个函数中的局部catch，也可能位于直接或间接调用了发生异常的函数的另一个函数中。
//
////栈展开
////抛出异常时，程序沿函数调用栈向外层“回退”，边销毁对象边找catch，直到找到位置，否则程序终止。
//
////Note:一个异常如果没有被捕获，则它将终止当前的程序。
//
////栈展开过程中对象被自动销毁
////在栈展开的过程中，位于调用链上的语句块可能会提前退出。
//
////析构函数与异常
////用类来控制资源的分配，就能确保无论函数正常结束还是遭遇异常，资源都能被正确地释放。
//
////Warning:在栈展开的过程中，运行类类型的局部对象的析构函数。因为这些析构函数是自动执行的，所以它们不应该抛出异常。一旦在栈展开的过程中析构函数抛出了异常，并且析构函数自身没能捕获到这异常，则程序将被终止。
//
////异常对象
////编译器使用异常抛出表达式来对异常对象进行拷贝初始化。
////throw中的表达式必须拥有完全类型。
////如果该表达式是类类型，则相应的类必须含有一个可访问的析构函数和一个可访问的拷贝或移动构造函数。
////如果是数组类型或函数类型，则表达式将被转换成与之对应的指针类型。
//
////Warning:抛出指针要求任何对应的处理代码存在的地方，指针所指的对象都必须存在。
//
////18.1.2 捕获异常
////catch子句中的异常声明看起来像只包含一个形参的函数形参列表。
////如果无须访问抛出的表达式，则可以忽略捕获形参的名字。
//
////声明的类型决定了处理代码所能捕获的异常类型。 完全类型 左值引用
//
////如果catch的参数是基类类型，则可以使用其派生类类型的异常对象对其进行初始化。
//
////异常声明的静态类型将决定catch语句所能执行的操作。
////如果是基类类型，则无法使用派生类特有的任何成员。
//
////通常情况下，如果catch接受的异常与某个继承体系有关，则最好将该catch的参数定义成引用类型。
//
////查找匹配的处理代码
////越是专门的catch越应该置于整个catch列表的前端
//
////按照其出现的顺序逐一进行匹配，当使用具有继承关系的多个异常时必须对catch语句的顺序进行组织和管理，使得派生类异常处理的代码出现在基类异常的处理代码之前。
//
////要求异常的类型和catch声明的类型是精确匹配的
////允许从非常量向常量的类型转换
////允许从派生类向基类的类型装换
////数组被转换成指向数组（元素）类型的指针，函数被转换成指向该函数类型的指针。
//
////Note:如果在多个catch语句的类型之间存在继承关系，则应该把继承链最底端的类放在最前面，而继承链最顶端的类放在后面。
//
////重新抛出
////如果一个单独的catch不能完整处理某个异常。在执行了某些校正操作之后，当前的catch可能会决定由调用链更上一层的函数接着处理异常。
////通过重新抛出的操作将异常传递给另一个catch。
//throw;
//
////空throw只能出现在catch或catch直接或间接调用的函数之内。
//
//catch (my_error& eObj) {//引用类型
//	eObj.status = errCodes::severErr;//修改了异常对象
//	throw;//异常对象的status成员是severErr
//}
//catch (other_error eObj) {//非引用类型
//	eObj.status = errCodes::badErr;//只修改了异常对象的局部副本
//	throw;//异常对象的status成员没有改变
//}
//
////捕获所有异常的处理代码
////为了一次性捕获所有异常，使用省略号作为异常声明，这样的处理代码称为捕获所有异常的处理代码。
////可以与任意类型的异常匹配
//
//void manip(){
//	try {
//		//引发并抛出一个异常
//	}
//	catch (...) {
//		//处理异常的某些特殊操作
//		throw;
//	}
//}
////Note:如果catch (...)与其他几个catch语句一起出现，则catch (...)必须出现在最后的位置。出现在捕获所有异常语句后面的catch语句将永远不会被匹配。
//
////18.1.3 函数try语句块与构造函数
////想处理构造函数初始值抛出的异常，必须将构造函数写成函数try语句快（函数测试块）的形式。
//
//template<typename T>
//Blob<T>::Blob(std::initializer_list<T>il)try :data(std::make_shared<std::vector<T>>(il)) {
//	/* */
//}
//catch (const std::bad_alloc& e) { handle_out_of_memory(e); }
//
////Note:处理构造函数初始值异常的唯一方法是将构造函数写成函数try语句块。
//
////18.1.4 noexcept异常说明
//void recoup(int)noexcept;//不会抛出异常
//void alloc(int);//可能抛出异常
//
////违反异常说明
////尽管该函数明显违反了异常说明，但它仍然可以顺利编译通过
//void f()noexcept {//承诺不会抛出异常
//	throw exception();//违反了异常说明
//}
//
////noexcept可以用在两种情况下：确认函数不会抛出异常、不知道如何处理异常。
//
////Warning:通常情况下，编译器不能也不必在编译时验证异常说明。
//
////异常说明的实参
////bool类型
//
//void recoup(int)noexcept(true);//不会抛出异常
//void alloc(int)noexcept(false);//可能抛出异常
//
////noexcept运算符
////noexcept说明符的实参常与noexcept运算符混合使用
////noexcept运算符是一元运算符，返回值是bool类型的右值常量表达式，用于表示给定的表达式是否会抛出异常。
//
//noexcept(recoup(i));//如果recoup不抛出异常则结果为true，否则为false
//
//noexcept(e);
//
//void f()noexcept(noexcept(g()));//f和g的异常说明一致
//
////Note：noexcept有两层含义：当跟在函数参数列表后面时它是异常说明符；而当作为noexcept异常说明的bool实参出现时，它是一个运算符。
//
////异常说明与指针、虚函数和拷贝控制
////函数指针以及该指针所指的函数必须具有一致的异常说明。
//
////recoup和pf1都承诺不会抛出异常
//void (*pf1)(int)noexcept = recoup;
////正确：recoup不会抛出异常，pf2可能抛出异常，二者之间互不干扰
//void (*pf2)(int) = recoup;
//
//pf1 = alloc;//错误：alloc可能抛出异常，但是pf1已经说明了它不会抛出异常
//pf2 = alloc;//正确：pf2和alloc都可能抛出异常
//
////如果虚函数承诺了它不会抛出异常，则后续派生出来的虚函数也必须做出同样的承诺；与之相反
//
//class Base {
//public:
//	virtual double f1(double)noexcept;//不会抛出异常
//	virtual int f2()noexcept(false);//可能抛出异常
//	virtual void f3();//可能抛出异常
//};
//class Derived :public Base {
//public:
//	double f1(double);//错误：Base::f1承诺不会抛出异常
//	int f2()noexcept(false);//正确：与Base::f2的异常说明一致
//	void f3()noexcept;//正确：Derived的f3做了更严格的限定，这是允许的
//};
//
////当编译器合成拷贝控制成员时，同时也生成一个异常说明。
//
////18.1.5 异常类层次
////exception:bad_cast、runtime_error、logic_error、bad_alloc
////runtime_error:overflow_error、underflow_error、range_error
////logic_error:domain_error、invalid_argument、out_of_range、length_error
//
////书店应用程序的异常类
////为某个书店应用程序设定的异常类
//class out_of_stock :public std::runtime_error {
//public:
//	explicit out_of_stock(const std::string &s):
//		std::runtime_error(s){}
//};
//
//class isbn_mismatch :public std::logic_error {
//public:
//	explicit isbn_mismatch(const std::string&s):
//		std::logic_error(s){}
//	isbn_mismatch(const std::string& s, const std::string& lhs, const std::string& rhs) :std::logic_error(s),left(lhs),right(rhs){}
//		const std::string left, right;
//};
//
////层次越低，表示的异常情况就越特殊。
//
////运行时错误和逻辑错误
//
////使用我们自己的异常类型
////如果参与加法的两个对象并非同一书籍，则抛出一个异常
//Sales_data&
//Sales_data::operator+=(const Sales_data& rhs) {
//	if (isbn() != rhs.isbn())
//		throw isbn_mismatch("wrong isbns", isbn(), rhs.isbn());
//	units_sold += rhs.units_sold;
//	revenue += rhs.revenue;
//	return *this;
//}
//
////使用之前设定的书店程序异常类
//Salse_data item1, item2, sum;
//while (cin >> item1 >> item2) {//读取两条交易信息
//	try {
//		sum = item1 + item2;//计算它们的和
//		//此处使用sum
//	}
//	catch (const isbn_mismatch& e) {
//		cerr << e.what() << ": left isbn(" << e.left >> ")right isbn(" << e.right << ")" << endl;
//	}
//}
//
////18.2 命名空间
////多个库将名字放置在全局命名空间将引发命名空间污染
//
//class cplusplus_primer_Query{...};
//string cplusplus_primer_make_plural(size_t, string&);
//
////命名空间分割了全局命名空间，其中每个命名空间是一个作用域。
//
////18.2.1 命名空间定义
//namespace cplusplus_primer{
//	class Sales_data{/*...*/};
//	Sales_data operator+(const Sales_data&, const Sales_data&);
//	class Query{/*...*/ };
//	class Query_base {/*...*/ };
//}//命名空间结束后无须分号，与块类似
//
////Note:命名空间作用域后面无须分号。
//
////每个命名空间都是一个作用域
//cplusplus_primer::Query q = cplusplus_primer::Query("hello");
//
//AddisonWesley::Query q = AddisonWesley::Query("hello");
//
////命名空间可以是不连续的
////可以定义在几个不同的地方
//namespace nsp {
//	/*...*/
//}
////如果之前没有名为nsp的命名空间定义，则创建一个新的命名空间，否则，打开已经存在的命名空间定义并为其添加一些新成员的声明。
//
////定义多个类型不相关的命名空间应该使用单独的文件分别表示每个类型（或关联类型构成的集合）。
//
////定义本书的命名空间
////---Sales_data.h---
////#include应该出现在打开命名空间的操作之前
//#include<string>
//namespace cplusplus_primer {
//	class Sales_data{/*...*/};
//	Sales_data operator+(const Sales_data&, const Sales_data&);
//	//Sales_data的其他接口函数的声明
//}
//
////---Sales_data.cc---
////确保#include出现在打开命名空间的操作之前
//#include"Sales_data.h"
//namespace cplusplus_primer {
//	//Sales_data成员及重载运算符的定义
//}
//
////---user.cc---
////Sales_data.h头文件的名字位于命名空间cplusplus_primer中
//#include"Sales_data.h"
//int main() {
//	using cplusplus_primer::Sales_data;
//	Sales_data trans1, trans2;
//	//...
//	return 0
//}
//
////定义命名空间成员
//#include"Sales_data.h"
//namespace cplusplus_primer {//重新打开命名空间cplusplus_primer
//	//命名空间中定义的成员可以直接使用名字，此时无须前缀
//	std::istream&
//		operator>>(std::istream&in,Sales_data &s){/*...*/}
//}
//
////也可在命名空间定义的外部定义该命名空间的成员。
//
////命名空间之外定义的成员必须使用含有前缀的名字
//cplusplus_primer::Sales_data
//cplusplus_primer::operator+(const Sales_data& lhs, const Sales_data& rhs) {
//	Sales_data ret(lhs);
//	//...
//}
//
////尽管命名空间的成员可以定义在命名空间外部，但这样的定义必须出现在所属命名空间的外层空间中。
//
////模板特例化
////必须定义在原始模板所属的命名空间中。
//
////必须将模板特例化声明成std的成员
//namespace std {
//	template<> struct hash<Sales_data>;
//}
//
////在std中添加了模板特例化的声明后，就可以在命名空间std的外部定义它了
//template <> struct std::hash<Sales_data> {
//	size_t operator()(const Sales_data& s)const {
//		return hash<string>()(s.bookNo) ^
//			hash<unsigned>()(s.units_sold) ^
//			hash<double>()(s.revenue);
//	}
//};
//
////全局命名空间
////全局作用域中定义的名字（即在所有类、函数及命名空间之外定义的名字）也就是定义在全局命名空间中。
////隐式声明
//::member_name;
//
////嵌套的命名空间
//namespace cplusplus_primer {
//	//第一个嵌套的命名空间，定义了库的Query部分
//	namespace QueryLib {
//		class Query{/*...*/};
//		Query operator&(const Query&, const Query&);
//	}
//	//第二个嵌套的命名空间，定义了库的Sales_data部分
//	namespace Bookstore {
//		class Quote{/*...*/};
//		class Disc_quote:public Quote{/*...*/};
//	}
//}
//
//cplusplus_primer::QueryLib::Query;
//
////内联命名空间
////可被外层命名空间直接使用
//inline namespace FifthEd {
//	//表示本书第5版的代码
//}
//
//namespace FifthEd {//隐式内联
//	class Query_base{/*...*/};
//}
//
//namespace FoutthEd {
//	class Item_base{/*...*/};
//	class Query_base {/*...*/ };
//}
//
//namespace cplusplus_primer {
//#include"FifthEd.h"
//#include"FoutthEd.h"
//}
//
////未命名的命名空间
////可以在某个给定的文件内不连续，但是不能跨越多个文件
//
////Note:和其他命名空间不同，未命名的命名空间仅在特定的文件内部有效，其作用域范围不会横跨多个不同文件。
//
//int i;//i的全局声明
//namespace {
//	int i;
//}
////二义性：i的定义既出现在全局作用域，又出现在为嵌套的未命名的命名空间中
//i = 10;
//
//namespace local {
//	namespace {
//		int i;
//	}
//}
////正确：定义在嵌套的未命名空间的i与全局作用域中的i不同
////local::i = 42;
//
////18.2.2 使用命名空间成员
//
////命名空间的别名
////可以为命名空间设定一个短的多的同义词
//
//namespace cplusplus_primer{/*...*/}
//
//namespace primer = cplusplus_primer;
//
//namespace Qlib = cplusplus_primer::QueryLib;
//Qlib::Query q;
//
////Note:一个命名空间可以有好几个同义词或别名，所有别名都与命名空间原本的名字等价。
//
////using声明：扼要概述
////一条using声明一次只引入命名空间的一个成员。
//
////可以出现在全局、局部、命名空间、类的作用域中。
////在类的作用域中，只能指向基类成员。
//
////using指示
////指示和声明
////类似：可以使用命名空间名字的简写形式
////不同：无法控制哪些名字是可见的，因为所有名字都是可见的
//
////Warning:如果提供一个对std等命名空间的using指示而未做任何特殊控制的话，将重新引入由于使用多个库造成的名字冲突问题。
//
////using指示与作用域
////具有将命名空间成员提升到包含命名空间本身和using指示的最近作用域的能力。
//
////using指示一般被看作是出现在最近的外层作用域中。
//
////命名空间A和函数f定义在全局作用域中
//namespace A {
//	int i, j;
//}
//void f() {
//	using namespace A;//把A中的名字注入到全局作用域中
//	cout << i * j << endl;//使用命名空间A中的i和j
//}
//
////using 指示示例
//namespace blip {
//	int i = 16, j = 15, k = 23;
//}
//int j = 0;//正确：blip的j隐藏在命名空间中
//void manip() {
//	//using指示，blip中的名字被“添加”到全局作用域中
//	using namespace blip;//如果使用了j，则将在::j和blip::j之间产生冲突
//	++i;//将blip::i设定为17
//	++j;//二义性错误：全局j还是blip::j？
//	++::j;//正确：将全局j设定为1
//	++blip::j;//正确：将blip::j设定为16
//	int k = 97;//当前的局部k隐藏了blip::k
//	++k;//将当前的局部k设定为98
//}
//
////头文件与using声明或指示
////头文件如果在其顶层作用域中含有using指示或声明，则会将名字注入到所有包含了该头文件的文件中。
//
////头文件最多只能在它的函数或命名空间中使用using指示或声明
//
////命名空间本身的实现文件中就可以使用using指示。
//
////18.2.3 类、命名空间与作用域
//
////由内向外依次查找每个外层作用域。
//
//namespace A {
//	int i;
//	namespace B {
//		int i;//在B中隐藏了A::i
//		int j;
//		int f1() {
//			int j;//j是f1的局部变量，隐藏了A::B::j
//			return i;//返回B::i
//		}
//	}//命名空间B结束，此后B中定义的名字不再可见
//	int f2() {
//		return j;//错误：j没有被定义
//	}
//	int j = i;//用A::i进行初始化
//}
//
////首先在该成员中进行查找，然后在类中查找（包括基类），接着在外层作用域中查找。
//
//namespace A {
//	int i;
//	int k;
//	class C1 {
//	public:
//		C1():i(0),j(0){}//正确：初始化C1::i和C1::j
//		int f1() { return k; }//返回A::k
//		int f2() { return h; }//错误：h未定义
//		int f3();
//	private:
//		int i;//在C1中隐藏了A::i
//		int j;
//	};
//	int h = i;//用A::i进行初始化
//}
//
////成员f3定义在C1和命名空间A的外部
//int A::C1::f3() { return h; }//正确：返回A::h
//
////先声明后使用
//
////可以从函数的限定名推出查找名字时检查作用域的次序，限定名以相反次序指出被查找的作用域
//
////实参相关的查找与类类型形参
//std::string s;
//std::cin >> s;
//
//operator>>(std::cin, s);
//
////当给函数传递一个类类型的对象时，除了在常规的作用域查找外还会查找实参类所属的命名空间。
//
//using std::operator>>;//想要使用cin>>s就必须有该using声明
//
//std::operator>>(std::cin, s);//正确：显式地使用std::>>
//
////查找与std::move和std::forward
////要么根据一般的重载规则确定某次调用应该执行函数的哪个版本
////要么应用程序根本不会执行函数的标准库版本
//
////友元声明与实参相关的查找
////一个另外的未声明的类或函数如果第一次出现在友元声明中，则我们认为它是最近的外层命名空间的成员。
//
//namespace A {
//	class C {
//		//两个友元，在友元声明之外没有其他声明
//		//这些函数隐式地成为命名空间A的成员
//		friend void f2();//除非另有声明，否则不会被找到
//		friend void f(const C&);//根据实参相关的查找规则可以被找到
//	};
//}
//
//int main() {
//	A::C cobj;
//	f(cobj);//正确：通过在A::C中的友元声明可以找到A::f
//	f2();//错误：A::f2没有被声明
//}
//
////18.2.4 重载与命名空间
////using声明或指示能将某些函数添加到候选函数集。
//
////与实参相关的查找与重载
////将在每个实参类（以及实参类的基类）所属的命名空间中搜寻候选函数。
////在这些命名空间中所有与被调用函数同名的函数都将被添加到候选集中
////即使其中某些函数在调用语句处不可见也是如此
//
//namespace NS {
//	class Quote{/*...*/};
//	void dispaly(const Quote&){/*...*/}
//}
////Bulk_item的基类声明在命名空间NS中
//class Bulk_item:public NS::Quote{/*....*/};
//int main() {
//	Bulk_item book1;
//	display(book1);
//	return 0;
//}
//
////重载与using声明
////using声明语句声明的是一个名字，而非一个特定的函数
//using NS::print(int);//错误：不能指定形参列表
//using NS::print();//正确：using声明只声明一个名字
//
////一个using声明囊括了重载函数的所有版本以确保不违法命名空间的接口。
//
////一个using声明引入的函数将重载该声明语句所属作用域中已有的其他同名函数。
//
////重载与using指示
////using指示将命名空间的成员提升到外层作用域中。
//
//namespace libs_R_us {
//	extern void print(int);
//	extern void print(double);
//}
////普通的声明
//void print(const string&);
////这个using指示把名字添加到print调用的候选函数集
//using namespace libs_R_us;
////print调用此时的候选函数集包括：
////libs_R_us的print(int)
////libs_R_us的print(double)
////显式声明的print(const string&);
//void fooBar(int ival) {
//	print("Value :");//调用全局函数print(const string&);
//	print(ival);//调用libs_R_us::print(int)
//}
//
////对于using指示。引入一个与已有函数形参列表完全相同的函数并不会产生错误。
////只需指明调用的版本
//
////跨越多个using指示的重载
//namespace AW {
//	int print(int);
//}
//namespace Primer {
//	double print(double);
//}
////using指示从不同的命名空间中创建了一个重载函数集合
//using namespace AW;
//using namespace Primer;
//long double print(long double);
//int main() {
//	print(1);//调用AW::print(int)
//	print(3.1);//调用Primer::print(double)
//	return 0;
//}
//
////18.3 多重继承与虚继承
////多重继承是指从多个直接基类中产生派生类的能力。
////多重继承的派生类继承了所有父类的属性
//
////18.3.1 多重继承
//class Bear :public ZooAnimal {
//	class Panda :public Bear,public Endangered{/*...*/};
//};
//
////多重继承的派生类列表也只能包含已经被定义过的类，而且这些类不能是final的。
//
////在某个给定的派生列表中，同一个基类只能出现一次。
//
////多重继承的派生类从每个基类中继承状态
////Panda:Bear Endangered
////Bear:ZooAnimal Bear
////Emdamgered:Endangered Panda
//
////派生类构造函数初始化所有基类
////构造一个派生类的对象将同时构造并初始化它的所有基类子对象
//
////多重继承的派生类的构造函数也只能初始化它的直接基类
//
////显式地初始化所有基类
//Panda::Panda(std::string name,bool onExhibit)
//	:Bear(name,onExhibit,"Panda"),
//	Endangered(Endangered::critical){ }
//
////隐式地使用Bear的默认构造函数初始化Bear子对象
//Panda::Panda():Endangered(Endangered::critical){}
//
////继承的构造函数与多重继承
//struct Base1
//{
//	Base1() = default;
//	Base1(const std::string&);
//	Base1(std::shared_ptr<int>);
//};
//
//struct Base2
//{
//	Base2() = default;
//	Base2(const std::string&);
//	Base2(int);
//};
//
////错误：D1试图从两个基类中都继承D1::D1(const string&)
//struct D1:public Base1,public Base2
//{
//	using Base1::Base1;//从Base1继承构造函数
//	using Base2::Base2;//从Base2继承构造函数
//};
//
////如果一个类从它的多个基类中继承了相同的构造函数，则必须为这个构造函数定义自己的版本
//struct D2:public Base1,public Base2
//{
//	using Base1::Base1;//从Base1继承构造函数
//	using Base2::Base2;//从Base2继承构造函数
//	//D2必须自定义一个接受string的构造函数
//	D2(const string&s):Base1(s),Base2(s){}
//	D2() = default;//一旦D2定义了自己的构造函数，则必须出现
//};
//
////析构函数与多重继承
////析构函数的调用顺序与构造函数相反
//
////多重继承的派生类的拷贝与移动操作
////多重继承的派生类如果定义了自己的拷贝/赋值构造函数和赋值运算符，则必须在完整对象上执行拷贝、移动或赋值操作。
//
////只有使用合成版本，才会自动执行
//
//Panda ying_yang("ying_yang");
//Panda ling_ling = ying_yang;//使用拷贝构造函数
//
////18.3.2 类型转换与多个基类
////在只有一个基类的情况下，派生类的指针或引用能自动转换成一个可访问基类的指针或引用。
//
////多个基类，可以令某个可访问基类的指针或引用直接指向一个派生类对象
//
////接受Panda的基类引用的一系列操作
//void print(const Bear&);
//void highlight(const Endangered &);
//ostream& operator<<(ostream&, const ZooAnimal&);
//Panda ying_yang("ying_yang");
//print(ying_yang);//把一个Panda对象传递给一个Bear的引用
//highlight(ying_yang);//把一个Panda对象传递给一个Endangered的引用
//cout << ying_yang << endl;//把一个Panda对象传递给一个ZooAnimal的引用
//
//void print(const Bear&);
//void print(const Endangered&);
//
//Panda ying_yang("ying_yang");
//print(ying_yang);//二义性错误
//
////基于指针类型或引用类型的查找
//Bear* pb = new Panda("ying_yang");
//pb->print();//正确：Panda::print()
//pb->cuddle();//错误：不属于Bear的接口
//pb->highlight();//错误：不属于Bear的接口
//delete pb;//正确：Panda::~panda()
//
//Endangered* pe = new Panda("ying_yang");
//pe->print();//正确：Panda::print()
//pe->toes();//错误：不属于Endangered的接口
//pe->cuddle();//错误：不属于Endangered的接口
//pe->highlight();//正确：Panda::highlight()
//delete pe;//正确：Panda::~Panda()
//
////18.3.3 多重继承下的类作用域
////Warning:当一个类拥有多个基类时，有可能出现派生类从两个或更多基类中继承了同名成员的情况。此时，不加前缀限定符直接使用该名字将引发二义性。
//
//double d = ying_yang.max_weight();
//
////有时即使派生类继承的两个形参列表不同也可能发生错误
//
////想要避免潜在的二义性，最好的办法是在派生类中为该函数定义一个新版本。
//
//double Panda::max_weight()const {
//	return std::max(ZooAnimal::max_weight(),
//		Endangered::max_weight());
//}
//
////18.3.4 虚继承
////虚继承的目的是令某个类做出声明，承诺愿意共享它的基类。
//
////共享的基类子对象称为虚基类
//
////不论虚基类在继承体系中出现多少次，在派生类中都只包含唯一一个共享的虚基类子对象。
//
////另一个Panda类
////必须在虚派生的真实需求前出现就已经完成虚派生的操作。
//
////Note:虚派生只影响从指定了虚基类的派生类中进一步派生出的类，它不会影响派生类本身。
//
////使用虚基类
////public和virtual的顺序随意
//class Raccoon :public virtual ZooAnimal{/*...*/};
//class Bear:virtual public ZooAnimal{/*...*/};
//
//class Panda:public Bear,public Raccon,public Endangered{};
//
////支持向基类的常规类型转换
//void dance(const Bear&);
//void rummage(const Raccoon);
//ostream& operator<<(ostream&, const ZooAnimal&);
//Panda ying_yang;
//dance(ying_yang);//正确：把一个Panda对象当成Bear传递
//rummage(ying_yang);//正确：把一个Panda对象当成Raccoon传递
//cout << ying_yang;//正确：把一个Panda对象当成 ZooAnimal传递
//
////虚基类成员的可见性
////因为在每个共享的虚基类中只有唯一一个共享的子对象，所以该基类的成员可以被直接访问，并且不会产生二义性。
//
////但是如果成员被多于一个基类访问，则一般情况下派生类必须为该成员自定义一个新的版本。
//
////18.3.5 构造函数与虚继承
////在虚派生中，虚基类是由最底层的派生类初始化的。
//
//Bear::Bear(string name,bool onExhibit):
//ZooAnimal(name,onExhibit,"Bear"){ }
//
//Raccoon::Raccoon(string name,bool onExhibit):
//	ZooAnimal(name, onExhibit, "Reccoon") {}
//
//Panda::Panda(string name,bool onExhibit):
//	ZooAnimal(name,onExhibit,"Panda"),
//	Bear(name,onExhibit),
//	Raccoon(name,onExhibit).
//	Endangered(Endangered::critical),
//	sleeping_flag(false){ }
//
////虚继承的对象的构造方式
////首先使用提供给最底层派生类构造函数的初始值初始化该对象的虚基类子部分
////接下来按照直接基类在派生列表中出现的次序依次对其进行初始化
//
////Note:虚基类总是先于非虚基类构造，与它们在继承体系中的次序和位置无关
//
////构造函数与析构函数的次序
////一个类可以有多个虚基类。
////这些虚的子对象按照它们在派生列表中出现的顺序从左向右依次构造。
//
//class Character{/*...*/};
//class BookCharacter:public Character{/*...*/};
//class ToyAnimal{/*...*/};
//class TeddyBear:public BookCharacter,public Bear,public virtual ToyAnimal{/*...*/};
//
//ZooAnimal();//Bear的虚基类
//ToyAnimal();//直接虚基类
//Character();//第一个非虚基类的间接基类
//BookCharacter();//第一个直接非虚基类
//Bear();//第二个直接非虚基类
//TeddyBear();//最底层的派生类