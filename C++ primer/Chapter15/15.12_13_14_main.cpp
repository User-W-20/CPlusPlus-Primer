//#include <iostream>
//#include <string>
//#include"15.12_13_14_Bulk_quote.h"
//#include"15.12_13_14_quote.h"
//#include"15.12_13_14_Limit_quote.h"
//
////�б�Ҫ��һ����Ա����ͬʱ������override��final��Ϊʲô��
////�б�Ҫ��
////override ȷ���ú��������˻�����麯������ֹ��ƴд����������ƥ�䵼�µ��������⡣
////final ��ֹ�������һ����д�ú�����ȷ����ʵ�ֲ��ᱻ�޸ġ�
////�����ϣ����������дĳ���麯��������ͬʱʹ�� override �� final��
//
//class base
//{
//public:
//	std::string name() { return basename; }
//	virtual void print(std::ostream& os) { os << basename; }
//
//private:
//	std::string basename = "base\n";
//};
//
//class derived :public base
//{
//public:
//	void print(std::ostream& os) override { base::print(os); os << " derived\n " << i; }
//private:
//	int i;
//};
//
//void print_debug(const Quote& q);
//double print_total(std::ostream& os, const Quote& item, size_t n);
//
//int main()
//{
//	base bobj;
//	base* bp1 = &bobj;
//	base& br1 = bobj;
//	derived dobj;
//	base* bp2 = &dobj;
//	base& br2 = dobj;
//
//
//	bobj.print(std::cout);
//
//	dobj.print(std::cout);
//
//	std::cout << bp1->name();
//
//	std::cout << bp2->name();
//
//	br1.print(std::cout);
//
//	br2.print(std::cout);
//	return 0;
//}
//
//double print_total(std::ostream& os, const Quote& item, size_t n)
//{
//	double ret = item.net_price(n);
//
//	os << "ISBN:" << item.isbn()
//		<< "# sold: " << n << " total due: " << ret << std::endl;
//
//	return ret;
//}
//
//
//void print_debug(const Quote& q)
//{
//	q.debug();
//}