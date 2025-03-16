//#include<string>
//#include<iostream>
//#include<vector>
//#include<memory>
//#include<set>
//#include<algorithm>
////15.1 OOP:概述
////面向对象程序设计：数据抽象、继承和动态绑定。
//
////继承
////基类—继承—派生类
////虚函数 virtual
//
//class Quote
//{
//public:
//	std::string isbn()const;
//	virtual double net_price(std::size_t n)const;
//};
//
////派生类列表 class xx:base{};
//
//class Bulk_quote:public Quote
//{
//public:
//	double net_price(std::size_t)const override;
//};
////显式注明使用哪个成员函数改写了基类的虚函数，override
//
////动态绑定:在运行时选择函数的版本，也称运行时绑定
//
////计算并打印销售给定的某种书籍所得的费用
//double print_total(std::ostream& os, const Quote& item, std::size_t n)
//{
//	//根据传入的item形参的对象类型调用Quote::net_price
//	//或者Bulk_quote::net_price
//	double ret = item.net_price(n);
//	os << "ISBN" << item.isbn() << "# sold: " << n << "total due" << ret << std::endl;
//	return ret;
//}
//
////Note:在c++语言中，当我们使用基类的引用（或指针）调用一个虚函数时将发生动态绑定
//
////15.2 定义基类和派生类
////15.2.1 定义基类
//
//class  Quote
//{
//public:
//	Quote() = default;
//	Quote(const std::string &book,double sales_price):bookNo(book),price(sales_price){}
//	std::string isbn()const { return bookNo; }
//
//	//返回给定数量书籍的销售总额
//	//派生类负责改写并使用不同的折扣计算算法
//	virtual double net_price(std::size_t n)const { return n * price; }
//	
//	virtual ~Quote() = default;//对析构函数进行动态绑定
//private:
//	std::string bookNo;//书籍ISBN编号
//protected:
//	double price = 0.0;//普通状态下不打折的价格
//};
//
////Note:基类通常都应该定义一个虚析构函数，即使该函数不执行任何实际操作也是如此。
//
////成员函数与继承
////派生类需要提供自己的新定义以覆盖从基类继承而来的旧定义.
//
////1：基类希望派生类覆盖的函数。通常将其定义为虚函数
////2：基类希望派生类直接继承而不改变的函数。
//
////任何构造函数以外的非静态函数都可以是虚函数。
//
////访问控制与继承
////派生类有权访问，其他用户禁止访问。protected
//
////15.2.2 定义派生类
////派生类列表： class xx:public/private/protected base
//
//class Bulk_quote :public Quote
//{
//public:
//	Bulk_quote() = default;
//	Bulk_quote(const std::string&, double, std::size_t, double);
//	//覆盖基类的函数版本以实现基于大量购买的折扣政策
//	double net_price(std::size_t)const override;
//private:
//	std::size_t min_qty = 0;//适用折扣政策的最低购买量
//	double discount = 0.0;//以小数表示的折扣额
//};
//
////大多数类都只继承自一个类，“单继承”
//
////派生类中的虚函数
////派生类显式地注明它使用某个成员函数覆盖了他继承的虚函数。const后加override。
//
////派生类对象及派生类向基类的类型转换
////派生类中含有基类的组成部分，能把派生类对象当做基类对象使用。也能把基类的指针和引用绑定到派生类对象中的基类部分。“派生类到基类的类型转换”。  隐式执行
//
////Note:在派生类对象中含有与基类对应的组成部分，这一事实是继承的关键
//
////派生类构造函数
////Note:每个类控制它自己的成员初始化过程
//
////Bulk_quote(const std::string& book, double p, std::size_t qty, double disc) :Quote(book, p), min_qty(qty), discount(disc){};
//
////Note:首先初始化基类部分，然后按照说明的顺序依次初始化派生类的成员
//
////派生类使用基类的成员
//
////如果到达了购买书籍的某个最低限量值，就可以享受折扣价格了
//double Bulk_quote::net_price(std::size_t cnt)const
//{
//	if (cnt >= min_qty)
//		return cnt * (1 - discount) * price;
//	else
//		return cnt * price;
//}
//
////继承与静态成员
//
//class Base
//{
//public:
//	static void statmen();
//};
//class Derived :public Base
//{
//	void f(const Derived&);
//};
//
//void Derived::f(const Derived& derived_obj)
//{
//	Base::statmen();//正确，Base定义了statmen
//	Derived::statmen();//正确，Derived继承了statmem
//	//正确：派生类的对象能访问基类的静态成员
//	derived_obj.statmen();//通过Derived对象访问
//	statmen;//通过this对象访问
//}
//
////派生类的声明
////class Bulk_quote :public Quote;//错误：派生列表不能出现在这里
////class Bulk_quote;//正确：声明派生类的正确方式
//
////被用作基类的类
////class Quote;//声明但未定义
//////错误：Quote必须被定义
////class Bulk_quote:public Quote{/**/ };
//
////一个类是基类，同时它也可以是一个派生类
////class Base{/**/ };
////class D1:public Base{/**/};
////class D2:public D1{/**/};
////Base是D1的直接基类，也是D2的间接基类
//
////防止继承的发生
////类名后跟final
////class NoDerived final{/**/};//不能作为基类
////class Base{/**/};
//////Last是final的，不能继承
////class Last final:Base{};//Last不能作为基类
////class Bad:NoDerived{};//NoDerived是final的
////class Bad2:Last{};//Last是final的
//
////15.2.3 类型转换与继承
//
////可以将基类的指针或引用绑定到派生类对象上.
//
////Note:和内置指针一样，智能指针类也支持派生类向基类的类型转换，这意味着我们可以将一个派生类对象的指针存储在一个基类的智能指针内。
//
////静态类型与动态类型
////静态类型编译时可知，动态类型运行时可知
//
////如果表达式既不是引用也不是指针，则它的动态类型永远与静态类型一致。
//
////Note:基类的指针或引用的静态类型可能与其动态类型不一致。
//
////不存在从基类向派生类的隐式类型转换
////一个基类的对象可能是派生类的一部分，也可能不是，所以不存在从基类向派生类的自动类型转换
//
////Quote base;
////Bulk_quote* bulkP = &base;//不能将基类转换成派生类
////Bulk_quote& bulkP = base;//不能将基类转换成派生类
//
////即使一个基类指针或引用绑定到一个派生类对象上，也不能执行从基类向派生类的转换
////Bulk_quote bulk;
////Quote* itemP = &bulk;//正确：动态类型是BUlk_quote
////Bulk_quote* bulkP = itemP;//错误：不能将基类转换成派生类
//
////如果基类含一个或多个虚函数，使用dynamic_cast请求一个类型转换，该转换的安全检查将在运行时执行。 
////如果已知基类向派生类的转换是安全的，可以用static_cast，强制覆盖掉编译器的检查工作。
//
////在对象之间不存在类型转换
////切掉
////Note:当我们使用一个派生类对象为一个基类对象初始化或赋值时，只有该派生类对象中的基类部分会被拷贝、移动和赋值，它的派生类部分将被忽略掉。
//
////15.3 虚函数
////必须为每一个虚函数都提供定义，不管是否用到
//
////对虚函数的调用可能在运行时才被解析
////Quote base("0-201-82470-1", 50);
////print_total(std::cout, base, 10);//调用Quote::net_price
////Bulk_quote derived("0-201-82470-1", 50, 5, .19);
////print_total(std::cout, derived, 10);//调用Bulk_quote::net_price
//
////动态绑定只有当通过指针或者引用调用虚函数时才发生。
////base = derived;//把derived的Quote部分拷贝给base
////base.net_price(20);//调用Quote::net_price
//
////Note:但且仅当对通过指针或引用调用虚函数时，才会在运行时解析该调用，也只有在这种情况下对象的动态类型才有可能与静态类型不同。
//
////派生类中的虚函数
////派生类中虚函数的返回类型也必须与基类函数匹配。
////但是当类的虚函数返回类型是类的本身的指针或者引用时。上述规则无效
//
////Note:基类中的虚函数在派生类中隐含地也是一个虚函数。当派生类覆盖了某个虚函数时，该函数在基类中的形参必须与派生类中的形参严格匹配
//
////final和override说明符
//struct B
//{
//	virtual void f1(int)const;
//	virtual void f2();
//	void f3();
//};
//
//struct D1:B
//{
//	void f1(int)const override;//正确：f1与基类中的f1匹配
//	void f2(int)override;//错误 B没有形如f2(int)的函数
//	void f3()override;//错误 f3不是虚函数
//	void f4()override;//错误 B没有名为f4的函数
//};
//
//struct D2:B
//{
//	//从B中继承f2()和f3(),覆盖f1(int)
//	void f1(int)const final;//不允许后续的其他类覆盖f1(int)
//};
//
//struct D3:D2
//{
//	void f2();//正确：覆盖从间接基类B继承而来的f2
//	void f1(int)const;//错误：D2已经将f2声明成final
//};
//
////虚函数与默认实参
////如果虚函数使用默认实参，则基类和派生类中定义的默认实参最好一致。
//
////回避虚函数的机制
////强行调用基类中定义的函数版本而不管baseP的动态类型到底是什么
////double undiscounted = baseP->Quote::net_price(42);
//
////Note:通常情况下，只有成员函数（或友元）中的代码才需要使用作用于运算符来回避虚函数的机制。
//
////如果一个派生类虚函数需要调用它的基类版本，但是没有使用作用域运算符，则在运行时该调用将被解析为对派生类版本自身的调用，从而导致无限递归。
//
////15.4 抽象基类
//
////纯虚函数
////纯虚函数无须定义  声明语句的分号之前书写=0
//
////用户保存折扣值和购买量的类，派生类使用这些数据可以实现不同的价格策略
//class Disc_quote :public Quote
//{
//public:
//	Disc_quote() = default;
//	Disc_quote(const std::string&book,double price,std::size_t qty,double disc):Quote(book,price),quantity(qty),discount(disc){}
//	double net_price(std::size_t)const = 0;
//protected:
//	std::size_t quantity = 0;//折扣适用的购买量
//	double discount = 0.0;//表示折扣的小数值
//};
//
////含有纯虚函数的类是抽象基类
////含有（或者未经覆盖直接继承）纯虚函数的类是抽象基类.
//
////Disc_quote 声明了纯虚函数，而Bulk_quote 将覆盖该函数
////Disc_quote discounted;//错误：不能定义Disc_quote 的对象
////Bulk_quote bulk;//正确：Bulk_quote中没有纯虚函数
//
////Note:不能创建抽象基类的对象.
//
////派生类构造函数只初始化它的直接基类
////当同一书籍的销售量超过某个值时启用折扣
////折扣的值是一个小于1的正的小数值，以此来降低正常销售价格
//
//class Bulk_quote :public Disc_quote
//{
//public:
//	Bulk_quote() = default;
//	Bulk_quote(const std::string&book,double price,std::size_t qty,double disc):Disc_quote(book,price,qty,disc){}
//	//覆盖基类中的函数版本以实现一种新的折扣策略
//	double net_price(std::size_t)const override;
//};
//
////重构负责重新设计类的体系以便将操作和/或数据从一个类移动到另一个类中。
//
////15.5 访问控制与继承
//
////受保护的成员
//class Base
//{
//protected:
//	int prot_mem;
//};
//class Sneaky :public Base
//{
//	friend void clobber(Sneaky&);//可以访问Sneraky::prot_mem
//	friend void clobber(Base&);//不能访问Base::prot_mem
//	int j;//默认私有
//};
////正确：clobber能访问Sneaky对象的private和protected成员
////void clobber(Sneaky& s) { s.j = s.prot_mem = 0; }
////错误：clobber不能访问Base的protected成员
////void clobber(Base& b) { b.prot_mem = 0; }
//
////派生类的成员和友元只能访问派生类对象中的基类部分的受保护成员。
//
////公有、私有和受保护继承
//class Base
//{
//public:
//	void pub_mem();
//private:
//	char priv_mem;
//protected:
//	int prot_mem;
//};
//
//struct Pub_Derv :public Base
//{
//	int f() { return prot_mem; }//正确：可以访问protected成员
//	//char g() { return priv_mem; }//错误：private成员对于派生类是不可访问的
//};
//
//struct Priv_Derv :private Base
//{
//	int f1()const { return prot_mem; }//private不影响派生类的访问权限
//};
//
//struct  Derived_from_Public:public Pub_Derv
//{
//	int use_base() { return prot_mem; }
//	//正确：Base::prot_mem在Pub_Derv中仍然是protected的
//};
//
//struct  Derived_from_Private:public Priv_Derv
//{
//	int use_base() { return prot_mem; }
//	//错误：Base::prot_mem在Priv_Derv中是private的
//};
//
////派生类向基类转换的可访问性
////对于代码中的某个给定节点来说，如果基类是公有成员可以访问的，则派生类向基类的类型转换也是可以访问的；反之则不行。
//
////友元与继承
//class Base
//{
//	friend class Pal;//Pal在访问Base的派生类时不具有特殊性
//
//	public:
//	void pub_mem();
//private:
//	char priv_mem;
//protected:
//	int prot_mem;
//};
//
//class Pal
//{
//public:
//	int f(Base b) { return b.prot_mem; }//正确：Pal是Base的友元
//	int f2(Sneaky s) { return s.j; }//错误：Pal不是Sneaky的友元
//	//对基类的访问权限由基类本身控制，即使对于派生类的基类部分也是如此
//	int f3(Sneaky s) { return s.prot_mem; }//正确：Pal是Base的友元
//};
//
////D2对Base的protected和private成员不具有特殊的访问能力
//class D3 :public Pal
//{
//public:
//	int mem(Base b)
//	{
//		return b.prot_mem;//错误：友元关系不能继承
//	}
//};
//
////不能继承友元关系；每个类负责控制各成员的访问权限
//
////改变个别成员的可访问性 通过using
//class Base
//{
//public:
//	std::size_t size()const { return n; }
//protected:
//	std::size_t n;
//};
//class Derived :private Base
//{
//public:
//	//保持对象尺寸相关的成员访问级别
//	using Base::size;
//protected:
//	using Base::n;
//};
//
////Note:派生类只能为那些它可以访问的名字提供using声明。
//
////默认的继承保护级别
//class Base{};
//struct D1:Base{};//默认public继承
//class D2:Base{};//默认private继承
//
////Note:一个私有派生类的类最好显式地将private声明出来，而不要仅仅依赖于默认的设置。显式声明的好处是可以令私有继承关系清晰明了，不至于产生误会。
//
////15.6 继承中的类作用域
//
////在编译时进行名字查找
//class Disc_quote :public Quote
//{
//public:
//	Disc_quote() = default;
//	Disc_quote(const std::string& book, double price, std::size_t qty, double disc) :Quote(book, price), quantity(qty), discount(disc) {}
//	double net_price(std::size_t)const = 0;
//	std::pair <size_t ,double>discount_policy()const
//	{
//		return { quantity,discount };
//	}
//
//	protected:
//		std::size_t quantity = 0;//折扣适用的购买量
//		double discount = 0.0;//表示折扣的小数值
//};
//
//Bulk_quote bulk;
//Bulk_quote* bulkP = &bulk;//静态类型和动态类型一致
//Quote* itemP = &bulk;//静态类型和动态类型不一致
//bulkP->discount_policy();//正确：bulkP的类型是Bulk_quote*
//itemP->discount_policy();//错误：itemP的类型是Quote*
//
////名字冲突与继承
//struct Base
//{
//	Base() :mem(0){}
//protected:
//	int mem;
//};
//
//struct Derived :Base
//{
//	Derived(int i):mem(i){}//用i初始化Derived::mem
//							//Base::mem进行默认初始化
//	int get_mem(){ return mem; }//返回Derived::mem
//
//protected:
//	int mem;//隐藏基类中的mem
//};
//
//Derived d(42);
//std::cout << d.get_mem() << std::endl;
//
////Note:派生类的成员将隐藏同名的基类成员。
//
////通过作用域运算符来使用隐藏的成员
//struct Derived :Base
//{
//	Derived(int i) :mem(i) {}//用i初始化Derived::mem
//	//Base::mem进行默认初始化
//	int get_mem() { return Base::mem; }//返回Derived::mem
//
//protected:
//	int mem;//隐藏基类中的mem
//};
//
////除了覆盖继承而来的虚函数之外，派生类最好不要重用其他定义在基类中的名字。
//
////一如往常，名字查找先于类型检查
//struct Base
//{
//	int memfcn();
//}; 
//struct Dervied:Base
//{
//	int memfcn(int);//隐藏基类中的memfcn
//};
//Derived d; Base b;
//b.memfcn();//调用Base::memfcn
//d.memfcn(10);//调用Derived::memfcn
//d.memfcn();//错误：参数列表为空的memfcn被隐藏了
//d.Base::memfcn();//正确：调用Base::memfcn
//
////虚函数与作用域
//class Base
//{
//public:
//	virtual int fcn();
//};
//class D1 :public Base
//{
//public:
//	//隐藏基类的fcn，这个fcn不是虚函数
//	//D1继承了Base::fcn（）的含义
//	int fcn(int);//形参列表与Base中的fcn不一致
//	virtual void f2();//是一个新的虚函数，在Base中不存在
//};
//class D2 :public D1
//{
//public:
//	int fcn(int);//是一个非虚函数，隐藏了D1::fcn(int)
//	int fcn();//覆盖了Base的虚函数fcn
//	void f2();//覆盖率D1的虚函数f2
//};
//
////通过基类调用隐藏的虚函数
//Base bobj; D1 d1obj; D2 d2obj;
//Base* bp1 = &bobj, * bp2 = &d1obj, * bp3 = &d2obj;
//bp1->fcn();//虚调用，将在运行时调用Base::fcn
//bp2->fcn();//虚调用，将在运行时调用Base::fcn
//bp3->fcn();//虚调用，将在运行时调用D2::fcn
//
//D1* d1p = &d1obj; D2* d2p = &d2obj;
//bp2->f2();//错误：Base没有名为f2的成员
//b1p->f2();//虚调用，将在运行时调用D1::f2
//b2p->f2();//虚调用，将在运行时调用D2::f2
//
//Base* p1 = &d2obj; D1* p2 = &d2obj; D2* p3 = &d2obj;
//p1->fcn(42);//错误：Base中没有接受一个int的fcn
//p2->fcn(42);//静态绑定：调用D1::fcn(int)
//p3->fcn(42);//静态绑定：调用D2::fcn(int)
//
////覆盖重载的函数
////为重载的成员提供一条using声明语句.
//
////15.7 构造函数与拷贝控制
//
////15.7.1 虚析构函数
//class Quote
//{
//public:
//	//如果我们删除的是一个指向派生类对象的基类指针，则需要虚析构函数
//	virtual ~Quote() = default;//动态绑定析构函数
//};
//
//Quote* itemP = new Quote;//静态类型与动态类型一致
//delete itemP;//调用Quote的析构函数
//itemp = new Bulk_quote;//静态类型与动态类型不一致
//delete itemP;//调用Bulk_quote的析构函数
//
////warning：如果基类的析构函数不是虚函数，则delete一个指向派生类对象的基类指针将产生未定义的行为。
//
////虚析构函数将阻止合成移动操作
////即使通过=default使用了合成的版本。
//
////15.7.2 合成拷贝控制与继承
////无论基类成员是合成的版本还是自定义的版本都没有太大的影响。唯一要求的是相应成员应该可以访问并且不是一个被删除的函数。
//
////派生类中删除的拷贝控制与基类的关系
//class B
//{
//public:
//	B();
//	B(const B&) = delete;
//	//其他成员，不含有移动构造函数
//};
//class D :public B
//{
//	//没有声明任何构造函数
//};
//D d;//正确：D的合成默认构造函数使用b的默认构造函数
//D d2(d);//错误：D的合成拷贝构造函数是被删除的
//D d3(std::move(d));//错误：隐式的使用D的被删除的拷贝构造函数
//
////移动操作与继承
//class Quote
//{
//public:
//	Quote() = default;//对成员依次进行默认初始化
//	Quote(const Quote&) = default;//对成员依次拷贝
//	Quote(Quote&&) = default;//对成员依次拷贝
//	Quote& operator=(const Quote&) = default;//拷贝赋值
//	Quote& operator=(Quote&&) = default;//移动赋值
//	virtual ~Quote() = default;
//};
//
////15.7.3 派生类的拷贝控制成员
////warning：当派生类定义了拷贝或移动操作时，该操作负责拷贝或移动包括基类部分成员在内的整个对象
//
////定义派生类的拷贝或移动构造函数
//class Base{};
//class D :public Base
//{
//public:
//	//默认情况下，基类的默认构造函数初始化对象的基类部分
//	//要想使用拷贝或移动构造函数，必须在构造函数初始值列表中
//	//显式的调用该构造函数
//	D(const D& d) :Base(d)//拷贝基类成员
//		/*D的成员初始值*/ {}
//	D(D&&d):Base(std::move(d))//移动基类成员
//		/*D的成员初始值*/ {}
//};
//
////D的这个拷贝函数很可能是不正确的定义
////基类部分被默认初始化，而非拷贝
//D(const D&d)/* 成员初始值，但是没有提供基类初始值*/
//{ }
//
////warning：在默认情况下，基类默认构造函数初始化派生类对象的基类部分。如果我们想拷贝（或移动）基类部分，则必须在派生类的构造函数初始值列表中显式地使用基类的拷贝（或移动）构造函数。
//
////派生类赋值运算符
////Base::operator=(const Base&) 不会被自动调用
//D& operator=(const D& rhs)
//{
//	Base::operator=(rhs);//为基类部分赋值
//	//按照过去的方式为派生类的成员赋值
//	//酌情处理自赋值及释放已有资源等情况
//	return *this;
//}
//
////派生类析构函数
//class D :public Base
//{
//public:
//	//Base::~Base被自动调用执行
//	~D(){}
//};
////销毁顺序与创建相反，先派生类析构，再基类析构，沿着继承体系的反方向直至最后
//
////在构造函数和析构函数中调用虚函数
////Note:如果构造函数或析构函数调用了某个虚函数，则我们应该执行与构造函数或析构函数所属类型相对应的虚函数版本。
//
////15.7.4 继承的构造函数
//class Bulk_quote :public Disc_quote
//{
//public:
//	using Disc_quote::Disc_quote;//继承Disc_quote的构造函数
//	double net_price(std::size_t)const;
//};
//
//derived(parms):base(args){}
//
////等同于
//Bulk_quote(const std::string&book,double price,std::size_t qty,double disc):Disc_quote(book,price,qty,disc){}
//
////继承的构造函数的特点
////构造函数的using声明不会改变该构造函数的访问级别
//
////using声明语句不能指定explicit或constexpr
//
////如果基类含有几个构造函数，除了两个例外，大多数时候派生类会继承所以这些构造函数
//
////第一个例外：派生类可以继承一部分构造函数，而为其他构造函数定义自己的版本。
//
////第二个例外：默认、拷贝和移动构造不会被继承。
//
////15.8 容器和继承  间接存储
//
//std::vector<Quote>basket;
//basket.push_back(Quote("0-201-82470-1", 50));//正确：但是只能把对象的Quote部分拷贝给basket
//std::cout << basket.back().net_price(15) << std::endl;//调用Quote定义的版本，打印750，即15*$50
//
////warning：当派生类对象被赋值给基类对象时，其中的派生类部分将被“切掉”，因此容器和存在继承关系的类型无法兼容。
//
////在容器中放置（智能）指针而非对象
//std::vector < std::shared_ptr<Quote> >basket;
//basket.push_back(std::make_shared<Quote>("0-201-82470-1", 50));
//basket.push_back{ std::make_shared<Bulk_quote>("0-201-82470-1", 50 ,10,.25) )};
//std::cout << basket.back()->net_price(15) << std::endl;//调用Quote定义的版本；打印562.5，即在15*$50中扣除折扣金额
//
////15.8.1 编写Basket类
//class Basket
//{
//public:
//	//Basket使用合成的默认构造函数和拷贝控制成员
//	void add_item(const std::shared_ptr<Quote>& sale) { items.insert(sale); }
//	//打印每本书的总价和购物篮中所有书的总价
//	double total_receipt(std::ostream&)const;
//private:
//	//该函数用于比较shared_ptr，multiset成员会用到他
//	static bool compare(const std::shared_ptr<Quote>& lhs, const std::shared_ptr<Quote>& rhs) { return lhs->isbn() < rhs->isbn(); }
//	//multiset保存多个报价，按照compare成员排序
//	std::multiset<std::shared_ptr<Quote>, decltype(compare)*>items{ compare };
//};
//
////定义Basket的成员
//double Basket::total_receipt(std::ostream& os)const
//{
//	double sum = 0.0;//保存实时计算出的总价格
//	//iter指向ISBN相同的一批元素中的第一个
//	//upper_bound返回一个迭代器，该迭代器指向这批元素的尾后位置
//	for (auto iter = items.cbegin(); iter != items.cend(); iter = items.upper_bound(*iter))
//	{
//		//我们知道在当前Basket中至少有一个该关键字的元素
//		//打印该书籍对应的项目
//		sum += print_total(os, **iter, items.count(*iter));
//	}
//	os << "Total Sale:" << sum << std::endl;//打印最终总价格
//	return sum;
//}
//
////隐藏指针
//Basket bsk;
//bsk.add_item(std::make_shared<Quote>("123", 45));
//bsk.add_item(std::make_shared<Bulk_quote>("345", 45,3,.15));
//
//void add_item(const Quote& sale);//拷贝给定的对象
//void add_item( Quote&& sale);//移动给定的对象
//
////模拟虚拷贝
//class Quote
//{
//public:
//	//该函数返回当前对象的一份动态分配的拷贝
//	//这些对象使用引用限定符
//	virtual Quote* clone()const& { return new Quote(*this); }
//	virtual Quote* clone()&& { return new Quote(std::move(*this)); }
//};
//
//class Bulk_quote :public Quote
//{
//	Bulk_quote* clone()const& { return new Bulk_quote(*this); }
//	Bulk_quote* clone()&& { return new Bulk_quote(std::move(*this)); }
//};
//
//class Basket
//{
//public:
//	void add_item(const Quote&sale)//拷贝给定的对象
//	{
//		items.insert(std::shared_ptr<Quote>(sale.clone()));
//	}
//	void add_item(Quote&&sale)//移动给定的对象
//	{
//		items.insert(std::shared_ptr<Quote>(std::move(sale).clone()));
//	}
//};
//
////15.9 文本查询程序再探
//
////15.9.1 面向对象的解决方案
////公有派生类对象应该可以用在任何需要基类对象的地方
//
////15.9.2 Query_base类和Query类
////抽象基类，具体的查询类型从中派生，所有成员都是private的
//class Query_base
//{
//	friend class Query;
//protected:
//	using line_no = TextQuery::line_no;//用于eval函数
//	virtual ~Query_base() = default;
//private:
//	//eval返回与当前Query匹配的QueryResult
//	virtual QueryResult eval(const TextQuery&)const = 0;
//	//rep是表示查询的一个string
//	virtual std::string rep()const = 0;
//};
//
////Query类
////管理Query_base继承体系的接口类
//class Query
//{
//	//这些运算符需要访问接受shared_ptr的构造函数，而该函数是私有的
//	friend Query operator~(const Query&);
//	friend Query operator|(const Query&, const Query&);
//	friend Query operator&(const Query&, const Query&);
//public:
//	Query(const std::string&);//构建一个新的WordQuery
//	//接口函数：调用对应的Query_base操作
//	QueryResult eval(const TextQuery&t)const
//	{
//		return q->eavl(t);
//	}
//
//	std::string rep()const { return q->rep(); }
//private:
//	Query(std::shared_ptr<Query_base>query):q(query){}
//	std::shared_ptr<Query_base>q;
//};
//
////Query的输出运算符
//std::ostream&
//operator<<(std::ostream& os, const Query& query)
//{
//	//Query::rep通过它的Query_base指针对rep（）进行了虚调用
//	return os << query.rep();
//}
//
//Query andq = Query(sought1) & Query(sought2);
//std::cout << andq << std::endl;
//
////15.9.3 派生类
////WordQuery类
//class WordQuery :public Query_base
//{
//	friend class Query;//Query 使用WordQuery的构造函数
//	WordQuery(const std::string& s) :query_word(s){}
//	//具体的类：WordQuery将定义所有继承而来的纯虚函数
//	QueryResult eval(const TextQuery& t)const { return t.query(query_word); }
//	std::string rep()const { return query_word; }
//		std::string query_word;//要查找的单词
//};
//
//inline
//Query::Query(const std::string &s):q(new WordQuery(s)){}
//
////NotQuery类及~运算符
//class NotQuery :public Query_base
//{
//	friend Query operator~(const Query&);
//	NotQuery(const Query& q) :query(q){}
//
//	//具体的类：NotQuery将定义所有继承而来的纯虚函数
//	std::string rep()const { return "~(" + query.rep() + ")"; }
//	QueryResult eval()(const TextQuery&)const;
//	Query query;
//};
//
//inline Query operator~(const Query& operand)
//{
//	return std::shared_ptr<Query_base>(new NotQuery(operand));
//}
//
////分配一个新的NotQuery对象
////将所得的NotQuery指针绑定到一个shared_ptr<Query_base>
//std::shared_ptr<Query_base>tmp(new NotQuery(expr));
//return Query(tmp);//使用接受一个shared_ptr的Query构造函数
//
////BinaryQuery类 抽象基类
//class BinaryQuery :public Query_base
//{
//protected:
//	BinaryQuery(const Query&l,const Query&r,std::string s):lhs(l),rhs(r),opSym(s){}
//
//	//抽象类：BinaryQuery不定义eval
//	Query lhs, rhs;//左侧和右侧运算对象
//	std::string opSym;//运算符的名字
//
//	std::string rep()const { return "(" + lhs.rep() + " " + opSym + " " + rhs.rep() + ")"; }
//};
//
////Note:BinaryQuery不定义eval，而是继承了该纯虚函数。因此，BinaryQuery也是一个抽象基类没，不能创建BinaryQuery类型的对象
//
////AndQuery类、OrQuery类及相应的运算符
//class AndQuery :public BinaryQuery
//{
//	friend Query operator&(const Query&, const Query&);
//	AndQuery(const Query&left, const Query& right):BinaryQuery(left,right,"&"){}
//	//具体的类：AndQuery继承了rep并且定义了其他纯虚函数
//	QueryResult eval(const TextQuery&)const;
//};
//
//inline Query operator&(const Query& lhs, const Query& rhs)
//{
//	return std::shared_ptr<Query_base>(new AndQuery(lhs, rhs));
//}
//
//class OrQuery :public BinaryQuery
//{
//	friend Query operator|(const Query&, const Query&);
//	OrQuery(const Query&left, const Query& right):BinaryQuery(left,right,"&"){}
//	QueryResult eval(const TextQuery&)const;
//};
//
//inline Query operator|(const Query& lhs, const Query& rhs)
//{
//	return std::shared_ptr<Query_base>(new OrQuery(lhs, rhs));
//}
//
////15.9.4 eval函数
////OrQuery::eval
////返回运算对象查询结果set的并集
//QueryResult OrQuery::eval(const TextQuery& text)const
//{
//	//通过Query成员 lhs和rhs进行虚调用
//	//通过eval返回每个运算对象的QueryResult
//	auto right = rhs.eval(text), left = lhs.eval(text);
//	//将左侧运算对象的行号拷贝到结果set中
//	auto ret_lines = std::make_shared<std::set<line_no>>(left.begin(), left.end());
//	//插入右侧运算对象所得的行号
//	ret_lines->insert(right.begin(), right.end());
//	//返回一个新的QueryResult，表示lhs和rhs的并集
//	return QueryResult(rep(), ret_lines, left.get_file();
//}
//
////AndQuery::eval
////返回运算对象查询结果set的交集
//QueryResult AndQuery::eval(const TextQuery& text)const
//{
//	//通过Query运算对象进行虚调用，以获得运算对象的查询结果set
//	auto left = lhs.eval(text), right = rhs.eval(text);
//	//保存left和right交集的set
//	auto ret_lines = std::make_shared<std::set<line_no>>();
//	//将两个范围的交集写入一个目的迭代器中
//	//本次调用的目的迭代器向ret添加元素
//	std::set_intersection(left.begin(), left.end(), right.begin(), right.end(), std::inserter(*ret_lines, ret_lines->begin()));
//	return QueryResult(rep(), ret_lines, left.get_file());
//}
//
////NotQuery::eval
////返回运算对象的结果set不存在的行
//QueryResult NotQuery::eval(const TextQuery& text)const
//{
//	//通过Query运算对象对eval进行虚调用
//	auto result = query.eval(text);
//	//开始时结果set为空
//	auto ret_lines = std::make_shared<std::set<line_no>>();
//	//必须在运算对象出现的所有行中进行迭代
//	auto beg = result.begin(), end = result.end();
//	//对于输入文件的每一行，如果该行不在result当中，则将其添加到ret_lines
//	auto sz = result.get_file()->size();
//	for (size_t n = 0; n != sz; ++n)
//	{
//		//如果还没有处理完result的所有行
//		//检查当前行是否存在
//		if (beg == end || *beg != n)
//		{
//			ret_lines->inesert(n);//如果不在result中，添加这一行
//		}
//		else if (beg != end)
//		{
//			++beg;//否则继续获取result的下一行（如果有的话）
//		}
//	}
//	return QueryResult(rep(), ret_lines, result.get_file());
//}