//#include <iostream>
//#include <string>
//#include <memory>
//
//using std::string; using std::unique_ptr;
//
//int main()
//{
//	unique_ptr<string> p1(new string("pezy"));
//	//unique_ptr<string> p2(p1);//copy
//	//���� ���� ��unique_ptr<string>������ʽɾ���������캯��
//
//	//unique_ptr<string> p3 = p1; // assign
//	//���� ���� ��unique_ptr<string>������ʽɾ���������캯��
//
//	std::cout << *p1 << std::endl;
//	p1.reset(nullptr);
//	return 0;
//}