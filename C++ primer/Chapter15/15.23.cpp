//#include <iostream>
//#include <string>
//
//class Base
//{
//public:
//	virtual int fcn() {
//		std::cout << "Base::fcn()\n"; return 0;
//	}
//
//};
//
//class D1 :public Base
//{
//public:
//	int fcn()override{ std::cout << "D1::fcn()\n"; return 0; }
//
//	virtual void f2(){ std::cout << "D1::f2()\n"; }
//};
//
//class D2 :public D1
//{
//public:
//	int fcn(int);
//	int fcn()override{ std::cout << "D2::fcn()\n"; return 0; }
//	void f2() override { std::cout << "D2::f2()\n"; }
//};
//
//int main()
//{
//	Base bobj;
//	D1 d1obj;
//	D2 d2obj;
//
//	Base* bp1 = &bobj, * bp2 = &d1obj, * bp3 = &d2obj;
//	//bp1->fcn();//运行时，虚调用
//	//bp2->fcn();//运行时，虚调用
//	//bp3->fcn();//运行时，虚调用
//	std::cout << "--------------------------"<<std::endl;
//	D1* d1p = &d1obj; D2* d2p = &d2obj;
//	//bp2->f2();bp2 是 Base*，只能访问 Base 里定义的成员，而 Base 里没有 f2()
//
//	 d1p->f2();
//	d2p->f2();
//	return 0;
//}
////基类指针不能调用子类新增的方法，即使这个方法是 virtual 的。