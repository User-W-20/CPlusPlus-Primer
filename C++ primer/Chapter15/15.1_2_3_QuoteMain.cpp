//#include"15.1_2_3_Quote.h"
//#include<iostream>
//#include<string>
//#include<map>
//#include<functional>
//
// ���Ա���ڻ�����ʹ��virtual�ؼ������εĳ�Ա���������������า�ǣ�override��������֧�ֶ�̬��
// 
// private��ֻ�ܱ� ���� ���ʣ��������޷�ֱ�ӷ��ʡ�
// protected�����˱��࣬������Ҳ�ܷ��ʡ�
// 
//double print_total(std::ostream& os, const Quote& item, size_t n)
//{
//	double ret = item.net_price(n);
//
//	os << "ISBN:" << item.isbn() << "  #sold:" << n << "total due:" << ret << std::endl;
//	return ret;
//}
//int main()
//{
//	Quote q("978-7-121-15535-2", 50.0); // ����һ�� Quote ����
//	print_total(std::cout, q, 3);
//
//	return 0;
//}