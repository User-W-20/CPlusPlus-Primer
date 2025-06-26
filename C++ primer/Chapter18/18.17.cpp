//#include<iostream>
//using std::cout;
//using std::endl;
//
//namespace Test0 {
//	namespace Exercise {
//		int ivar = 0;
//		double dvar = 0;
//		const int limit = 1000;
//	}
//	int ivar = 0;
//
//	using Exercise::dvar;
//	using Exercise::limit;
//
//	void mainp() {
//		double dvar = 3.1416;
//		cout << "********** Before call Test0::manip **********" << endl;
//		cout << "Exercise::ivar " <<Exercise::ivar<<endl
//			<< "Exercise::dvar " << Exercise::dvar << endl
//			<< "Exercise::limit " << Exercise::limit << endl
//			<< "Test0::ivar " << Test0::ivar << endl
//			<< "dvar in function manip" << dvar << endl;
//
//		int iobj = limit + 1; //Exercise::limit + 1
//		++ivar;//++Test0::ivar
//		++Test0::ivar;//++Test0::ivar
//
//		cout << "********** After call Test0::manip  **********" << endl;
//		cout << "Exercise::ivar " << Exercise::ivar << endl
//			<< "Exercise::dvar " << Exercise::dvar << endl
//			<< "Exercise::limit " << Exercise::limit << endl
//			<< "Test0::ivar " << Test0::ivar << endl
//			<< "dvar in function manip " << dvar << endl
//			<< "iboj in function manip " << iobj << endl;
//	}
//}
//
//namespace Test1 {
//	namespace Exercise {
//		int ivar = 0;
//		double dvar = 0;
//		const int limit = 1000;
//	}
//	int ivar = 0;
//
//	void mainp() {
//		using Exercise::ivar;
//		using Exercise::limit;
//
//		double dvar = 3.1416;
//
//		cout << "********** Before call Test1::manip **********" << endl;
//		cout << "Exercise::ivar " << Exercise::ivar << endl
//			<< "Exercise::dvar " << Exercise::dvar << endl
//			<< "Exercise::limit " << Exercise::limit << endl
//			<< "Test1::ivar " << Test1::ivar << endl
//			<< "dvar in function manip" << dvar << endl;
//
//		int iobj = limit + 1;//Exercise::limit + 1
//		++ivar;//++ Exercise::ivar
//		++Test1::ivar;// ++ Test1::ivar
//
//
//		cout << "********** After call Test1::manip  **********" << endl;
//		cout << "Exercise::ivar " << Exercise::ivar << endl
//			<< "Exercise::dvar " << Exercise::dvar << endl
//			<< "Exercise::limit " << Exercise::limit << endl
//			<< "Test1::ivar " << Test1::ivar << endl
//			<< "dvar in function manip " << dvar << endl
//			<< "iboj in function manip " << iobj << endl;
//	}
//}
//
//namespace Test2 {
//	namespace Exercise {
//		int ivar = 0;
//		double dvar = 0;
//		const int limit = 1000;
//	}
//	int ivar = 0;
//
//	using namespace Exercise;
//
//	void mainp() {
//		double dvar = 3.1416;
//
//		cout << "********** Before call Test2::manip **********" << endl;
//		cout << "Exercise::ivar " << Exercise::ivar << endl
//			<< "Exercise::dvar " << Exercise::dvar << endl
//			<< "Exercise::limit " << Exercise::limit << endl
//			<< "Test2::ivar " << Test2::ivar << endl
//			<< "dvar in function manip" << dvar << endl;
//
//		int iobj = limit + 1;//Exercise::limit+1
//		//++ivar;//"Test2::ivar" ����ȷ
//		//������Exercise::ivar����Test2::ivar
//		++Test2::ivar;// ++ Test2::ivar
//
//		cout << "********** After call Test2::manip  **********" << endl;
//		cout << "Exercise::ivar " << Exercise::ivar << endl
//			<< "Exercise::dvar " << Exercise::dvar << endl
//			<< "Exercise::limit " << Exercise::limit << endl
//			<< "Test2::ivar " << Test2::ivar << endl
//			<< "dvar in function manip " << dvar << endl
//			<< "iboj in function manip " << iobj << endl;
//	}
//}
//
//namespace Test3 {
//	namespace Exercise
//	{
//		int ivar = 0;
//		double dvar = 0;
//		const int limit = 1000;
//	}
//
//	int ivar = 0;
//
//	void mainp() {
//		using namespace Exercise;
//
//		double dvar = 3.1416;
//
//		cout << "********** Before call Test3::manip **********" << endl;
//		cout << "Exercise::ivar " << Exercise::ivar << endl
//			<< "Exercise::dvar " << Exercise::dvar << endl
//			<< "Exercise::limit " << Exercise::limit << endl
//			<< "Test3::ivar " << Test3::ivar << endl
//			<< "dvar in function manip" << dvar << endl;
//
//		int iobj = limit + 1;//Exercise::limit + 1
//		//++ivar;//"ivar" ����ȷ
//		++Test3::ivar;// ++ Test3::ivar
//
//		cout << "********** After call Test3::manip  **********" << endl;
//		cout << "Exercise::ivar " << Exercise::ivar << endl
//			<< "Exercise::dvar " << Exercise::dvar << endl
//			<< "Exercise::limit " << Exercise::limit << endl
//			<< "Test3::ivar " << Test3::ivar << endl
//			<< "dvar in function manip " << dvar << endl
//			<< "iboj in function manip " << iobj << endl;
//	}
//}
//
//int main() {
//	Test0::mainp();
//	cout << endl;
//
//	Test1::mainp();
//	cout << endl;
//
//	Test2::mainp();
//	cout << endl;
//
//	Test3::mainp();
//	cout << endl;
//
//	return 0;
//}