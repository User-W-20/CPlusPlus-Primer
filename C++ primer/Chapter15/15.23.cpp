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
//	//bp1->fcn();//����ʱ�������
//	//bp2->fcn();//����ʱ�������
//	//bp3->fcn();//����ʱ�������
//	std::cout << "--------------------------"<<std::endl;
//	D1* d1p = &d1obj; D2* d2p = &d2obj;
//	//bp2->f2();bp2 �� Base*��ֻ�ܷ��� Base �ﶨ��ĳ�Ա���� Base ��û�� f2()
//
//	 d1p->f2();
//	d2p->f2();
//	return 0;
//}
////����ָ�벻�ܵ������������ķ�������ʹ��������� virtual �ġ�