//#include<iostream>
//#include<string>
//#include<stdexcept>
//#include<memory>
//#include<vector>
//using namespace std;
//
////18.1 �쳣����
////��������ж��������Ĳ����ܹ�������ʱ�ͳ��ֵ��������ͨ�Ų�������Ӧ�Ĵ���
//
////18.1.1 �׳��쳣
////ͨ���׳�һ�����ʽ������һ���쳣��
////���׳��ı��ʽ�������Լ���ǰ�ĵ�������ͬ�������Ķδ�����뽫�������⴦����쳣��
//
////ִ��throwʱ�����ں������佫���ٱ�ִ�С�
////����Ŀ���Ȩ��throwת�Ƶ���֮ƥ���catchģ�顣
////��catch������ͬһ�������еľֲ�catch��Ҳ����λ��ֱ�ӻ��ӵ����˷����쳣�ĺ�������һ�������С�
//
////ջչ��
////�׳��쳣ʱ�������غ�������ջ����㡰���ˡ��������ٶ������catch��ֱ���ҵ�λ�ã����������ֹ��
//
////Note:һ���쳣���û�б�������������ֹ��ǰ�ĳ���
//
////ջչ�������ж����Զ�����
////��ջչ���Ĺ����У�λ�ڵ������ϵ�������ܻ���ǰ�˳���
//
////�����������쳣
////������������Դ�ķ��䣬����ȷ�����ۺ��������������������쳣����Դ���ܱ���ȷ���ͷš�
//
////Warning:��ջչ���Ĺ����У����������͵ľֲ������������������Ϊ��Щ�����������Զ�ִ�еģ��������ǲ�Ӧ���׳��쳣��һ����ջչ���Ĺ��������������׳����쳣������������������û�ܲ������쳣������򽫱���ֹ��
//
////�쳣����
////������ʹ���쳣�׳����ʽ�����쳣������п�����ʼ����
////throw�еı��ʽ����ӵ����ȫ���͡�
////����ñ��ʽ�������ͣ�����Ӧ������뺬��һ���ɷ��ʵ�����������һ���ɷ��ʵĿ������ƶ����캯����
////������������ͻ������ͣ�����ʽ����ת������֮��Ӧ��ָ�����͡�
//
////Warning:�׳�ָ��Ҫ���κζ�Ӧ�Ĵ��������ڵĵط���ָ����ָ�Ķ��󶼱�����ڡ�
//
////18.1.2 �����쳣
////catch�Ӿ��е��쳣������������ֻ����һ���βεĺ����β��б�
////�����������׳��ı��ʽ������Ժ��Բ����βε����֡�
//
////���������;����˴���������ܲ�����쳣���͡� ��ȫ���� ��ֵ����
//
////���catch�Ĳ����ǻ������ͣ������ʹ�������������͵��쳣���������г�ʼ����
//
////�쳣�����ľ�̬���ͽ�����catch�������ִ�еĲ�����
////����ǻ������ͣ����޷�ʹ�����������е��κγ�Ա��
//
////ͨ������£����catch���ܵ��쳣��ĳ���̳���ϵ�йأ�����ý���catch�Ĳ���������������͡�
//
////����ƥ��Ĵ������
////Խ��ר�ŵ�catchԽӦ����������catch�б��ǰ��
//
////��������ֵ�˳����һ����ƥ�䣬��ʹ�þ��м̳й�ϵ�Ķ���쳣ʱ�����catch����˳�������֯�͹���ʹ���������쳣����Ĵ�������ڻ����쳣�Ĵ������֮ǰ��
//
////Ҫ���쳣�����ͺ�catch�����������Ǿ�ȷƥ���
////����ӷǳ�������������ת��
////���������������������װ��
////���鱻ת����ָ�����飨Ԫ�أ����͵�ָ�룬������ת����ָ��ú������͵�ָ�롣
//
////Note:����ڶ��catch��������֮����ڼ̳й�ϵ����Ӧ�ðѼ̳�����׶˵��������ǰ�棬���̳�����˵�����ں��档
//
////�����׳�
////���һ��������catch������������ĳ���쳣����ִ����ĳЩУ������֮�󣬵�ǰ��catch���ܻ�����ɵ���������һ��ĺ������Ŵ����쳣��
////ͨ�������׳��Ĳ������쳣���ݸ���һ��catch��
//throw;
//
////��throwֻ�ܳ�����catch��catchֱ�ӻ��ӵ��õĺ���֮�ڡ�
//
//catch (my_error& eObj) {//��������
//	eObj.status = errCodes::severErr;//�޸����쳣����
//	throw;//�쳣�����status��Ա��severErr
//}
//catch (other_error eObj) {//����������
//	eObj.status = errCodes::badErr;//ֻ�޸����쳣����ľֲ�����
//	throw;//�쳣�����status��Աû�иı�
//}
//
////���������쳣�Ĵ������
////Ϊ��һ���Բ��������쳣��ʹ��ʡ�Ժ���Ϊ�쳣�����������Ĵ�������Ϊ���������쳣�Ĵ�����롣
////�������������͵��쳣ƥ��
//
//void manip(){
//	try {
//		//�������׳�һ���쳣
//	}
//	catch (...) {
//		//�����쳣��ĳЩ�������
//		throw;
//	}
//}
////Note:���catch (...)����������catch���һ����֣���catch (...)�������������λ�á������ڲ��������쳣�������catch��佫��Զ���ᱻƥ�䡣
//
////18.1.3 ����try�����빹�캯��
////�봦���캯����ʼֵ�׳����쳣�����뽫���캯��д�ɺ���try���죨�������Կ飩����ʽ��
//
//template<typename T>
//Blob<T>::Blob(std::initializer_list<T>il)try :data(std::make_shared<std::vector<T>>(il)) {
//	/* */
//}
//catch (const std::bad_alloc& e) { handle_out_of_memory(e); }
//
////Note:�����캯����ʼֵ�쳣��Ψһ�����ǽ����캯��д�ɺ���try���顣
//
////18.1.4 noexcept�쳣˵��
//void recoup(int)noexcept;//�����׳��쳣
//void alloc(int);//�����׳��쳣
//
////Υ���쳣˵��
////���ܸú�������Υ�����쳣˵����������Ȼ����˳������ͨ��
//void f()noexcept {//��ŵ�����׳��쳣
//	throw exception();//Υ�����쳣˵��
//}
//
////noexcept����������������£�ȷ�Ϻ��������׳��쳣����֪����δ����쳣��
//
////Warning:ͨ������£�����������Ҳ�����ڱ���ʱ��֤�쳣˵����
//
////�쳣˵����ʵ��
////bool����
//
//void recoup(int)noexcept(true);//�����׳��쳣
//void alloc(int)noexcept(false);//�����׳��쳣
//
////noexcept�����
////noexcept˵������ʵ�γ���noexcept��������ʹ��
////noexcept�������һԪ�����������ֵ��bool���͵���ֵ�������ʽ�����ڱ�ʾ�����ı��ʽ�Ƿ���׳��쳣��
//
//noexcept(recoup(i));//���recoup���׳��쳣����Ϊtrue������Ϊfalse
//
//noexcept(e);
//
//void f()noexcept(noexcept(g()));//f��g���쳣˵��һ��
//
////Note��noexcept�����㺬�壺�����ں��������б����ʱ�����쳣˵������������Ϊnoexcept�쳣˵����boolʵ�γ���ʱ������һ���������
//
////�쳣˵����ָ�롢�麯���Ϳ�������
////����ָ���Լ���ָ����ָ�ĺ����������һ�µ��쳣˵����
//
////recoup��pf1����ŵ�����׳��쳣
//void (*pf1)(int)noexcept = recoup;
////��ȷ��recoup�����׳��쳣��pf2�����׳��쳣������֮�以������
//void (*pf2)(int) = recoup;
//
//pf1 = alloc;//����alloc�����׳��쳣������pf1�Ѿ�˵�����������׳��쳣
//pf2 = alloc;//��ȷ��pf2��alloc�������׳��쳣
//
////����麯����ŵ���������׳��쳣������������������麯��Ҳ��������ͬ���ĳ�ŵ����֮�෴
//
//class Base {
//public:
//	virtual double f1(double)noexcept;//�����׳��쳣
//	virtual int f2()noexcept(false);//�����׳��쳣
//	virtual void f3();//�����׳��쳣
//};
//class Derived :public Base {
//public:
//	double f1(double);//����Base::f1��ŵ�����׳��쳣
//	int f2()noexcept(false);//��ȷ����Base::f2���쳣˵��һ��
//	void f3()noexcept;//��ȷ��Derived��f3���˸��ϸ���޶������������
//};
//
////���������ϳɿ������Ƴ�Աʱ��ͬʱҲ����һ���쳣˵����
//
////18.1.5 �쳣����
////exception:bad_cast��runtime_error��logic_error��bad_alloc
////runtime_error:overflow_error��underflow_error��range_error
////logic_error:domain_error��invalid_argument��out_of_range��length_error
//
////���Ӧ�ó�����쳣��
////Ϊĳ�����Ӧ�ó����趨���쳣��
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
////���Խ�ͣ���ʾ���쳣�����Խ���⡣
//
////����ʱ������߼�����
//
////ʹ�������Լ����쳣����
////�������ӷ����������󲢷�ͬһ�鼮�����׳�һ���쳣
//Sales_data&
//Sales_data::operator+=(const Sales_data& rhs) {
//	if (isbn() != rhs.isbn())
//		throw isbn_mismatch("wrong isbns", isbn(), rhs.isbn());
//	units_sold += rhs.units_sold;
//	revenue += rhs.revenue;
//	return *this;
//}
//
////ʹ��֮ǰ�趨���������쳣��
//Salse_data item1, item2, sum;
//while (cin >> item1 >> item2) {//��ȡ����������Ϣ
//	try {
//		sum = item1 + item2;//�������ǵĺ�
//		//�˴�ʹ��sum
//	}
//	catch (const isbn_mismatch& e) {
//		cerr << e.what() << ": left isbn(" << e.left >> ")right isbn(" << e.right << ")" << endl;
//	}
//}
//
////18.2 �����ռ�
////����⽫���ַ�����ȫ�������ռ佫���������ռ���Ⱦ
//
//class cplusplus_primer_Query{...};
//string cplusplus_primer_make_plural(size_t, string&);
//
////�����ռ�ָ���ȫ�������ռ䣬����ÿ�������ռ���һ��������
//
////18.2.1 �����ռ䶨��
//namespace cplusplus_primer{
//	class Sales_data{/*...*/};
//	Sales_data operator+(const Sales_data&, const Sales_data&);
//	class Query{/*...*/ };
//	class Query_base {/*...*/ };
//}//�����ռ����������ֺţ��������
//
////Note:�����ռ��������������ֺš�
//
////ÿ�������ռ䶼��һ��������
//cplusplus_primer::Query q = cplusplus_primer::Query("hello");
//
//AddisonWesley::Query q = AddisonWesley::Query("hello");
//
////�����ռ�����ǲ�������
////���Զ����ڼ�����ͬ�ĵط�
//namespace nsp {
//	/*...*/
//}
////���֮ǰû����Ϊnsp�������ռ䶨�壬�򴴽�һ���µ������ռ䣬���򣬴��Ѿ����ڵ������ռ䶨�岢Ϊ�����һЩ�³�Ա��������
//
////���������Ͳ���ص������ռ�Ӧ��ʹ�õ������ļ��ֱ��ʾÿ�����ͣ���������͹��ɵļ��ϣ���
//
////���屾��������ռ�
////---Sales_data.h---
////#includeӦ�ó����ڴ������ռ�Ĳ���֮ǰ
//#include<string>
//namespace cplusplus_primer {
//	class Sales_data{/*...*/};
//	Sales_data operator+(const Sales_data&, const Sales_data&);
//	//Sales_data�������ӿں���������
//}
//
////---Sales_data.cc---
////ȷ��#include�����ڴ������ռ�Ĳ���֮ǰ
//#include"Sales_data.h"
//namespace cplusplus_primer {
//	//Sales_data��Ա������������Ķ���
//}
//
////---user.cc---
////Sales_data.hͷ�ļ�������λ�������ռ�cplusplus_primer��
//#include"Sales_data.h"
//int main() {
//	using cplusplus_primer::Sales_data;
//	Sales_data trans1, trans2;
//	//...
//	return 0
//}
//
////���������ռ��Ա
//#include"Sales_data.h"
//namespace cplusplus_primer {//���´������ռ�cplusplus_primer
//	//�����ռ��ж���ĳ�Ա����ֱ��ʹ�����֣���ʱ����ǰ׺
//	std::istream&
//		operator>>(std::istream&in,Sales_data &s){/*...*/}
//}
//
////Ҳ���������ռ䶨����ⲿ����������ռ�ĳ�Ա��
//
////�����ռ�֮�ⶨ��ĳ�Ա����ʹ�ú���ǰ׺������
//cplusplus_primer::Sales_data
//cplusplus_primer::operator+(const Sales_data& lhs, const Sales_data& rhs) {
//	Sales_data ret(lhs);
//	//...
//}
//
////���������ռ�ĳ�Ա���Զ����������ռ��ⲿ���������Ķ��������������������ռ�����ռ��С�
//
////ģ��������
////���붨����ԭʼģ�������������ռ��С�
//
////���뽫ģ��������������std�ĳ�Ա
//namespace std {
//	template<> struct hash<Sales_data>;
//}
//
////��std�������ģ���������������󣬾Ϳ����������ռ�std���ⲿ��������
//template <> struct std::hash<Sales_data> {
//	size_t operator()(const Sales_data& s)const {
//		return hash<string>()(s.bookNo) ^
//			hash<unsigned>()(s.units_sold) ^
//			hash<double>()(s.revenue);
//	}
//};
//
////ȫ�������ռ�
////ȫ���������ж�������֣����������ࡢ�����������ռ�֮�ⶨ������֣�Ҳ���Ƕ�����ȫ�������ռ��С�
////��ʽ����
//::member_name;
//
////Ƕ�׵������ռ�
//namespace cplusplus_primer {
//	//��һ��Ƕ�׵������ռ䣬�����˿��Query����
//	namespace QueryLib {
//		class Query{/*...*/};
//		Query operator&(const Query&, const Query&);
//	}
//	//�ڶ���Ƕ�׵������ռ䣬�����˿��Sales_data����
//	namespace Bookstore {
//		class Quote{/*...*/};
//		class Disc_quote:public Quote{/*...*/};
//	}
//}
//
//cplusplus_primer::QueryLib::Query;
//
////���������ռ�
////�ɱ���������ռ�ֱ��ʹ��
//inline namespace FifthEd {
//	//��ʾ�����5��Ĵ���
//}
//
//namespace FifthEd {//��ʽ����
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
////δ�����������ռ�
////������ĳ���������ļ��ڲ����������ǲ��ܿ�Խ����ļ�
//
////Note:�����������ռ䲻ͬ��δ�����������ռ�����ض����ļ��ڲ���Ч����������Χ����������ͬ�ļ���
//
//int i;//i��ȫ������
//namespace {
//	int i;
//}
////�����ԣ�i�Ķ���ȳ�����ȫ���������ֳ�����ΪǶ�׵�δ�����������ռ���
//i = 10;
//
//namespace local {
//	namespace {
//		int i;
//	}
//}
////��ȷ��������Ƕ�׵�δ�����ռ��i��ȫ���������е�i��ͬ
////local::i = 42;
//
////18.2.2 ʹ�������ռ��Ա
//
////�����ռ�ı���
////����Ϊ�����ռ��趨һ���̵Ķ��ͬ���
//
//namespace cplusplus_primer{/*...*/}
//
//namespace primer = cplusplus_primer;
//
//namespace Qlib = cplusplus_primer::QueryLib;
//Qlib::Query q;
//
////Note:һ�������ռ�����кü���ͬ��ʻ���������б������������ռ�ԭ�������ֵȼۡ�
//
////using��������Ҫ����
////һ��using����һ��ֻ���������ռ��һ����Ա��
//
////���Գ�����ȫ�֡��ֲ��������ռ䡢����������С�
////������������У�ֻ��ָ������Ա��
//
////usingָʾ
////ָʾ������
////���ƣ�����ʹ�������ռ����ֵļ�д��ʽ
////��ͬ���޷�������Щ�����ǿɼ��ģ���Ϊ�������ֶ��ǿɼ���
//
////Warning:����ṩһ����std�������ռ��usingָʾ��δ���κ�������ƵĻ�����������������ʹ�ö������ɵ����ֳ�ͻ���⡣
//
////usingָʾ��������
////���н������ռ��Ա���������������ռ䱾���usingָʾ������������������
//
////usingָʾһ�㱻�����ǳ��������������������С�
//
////�����ռ�A�ͺ���f������ȫ����������
//namespace A {
//	int i, j;
//}
//void f() {
//	using namespace A;//��A�е�����ע�뵽ȫ����������
//	cout << i * j << endl;//ʹ�������ռ�A�е�i��j
//}
//
////using ָʾʾ��
//namespace blip {
//	int i = 16, j = 15, k = 23;
//}
//int j = 0;//��ȷ��blip��j�����������ռ���
//void manip() {
//	//usingָʾ��blip�е����ֱ�����ӡ���ȫ����������
//	using namespace blip;//���ʹ����j������::j��blip::j֮�������ͻ
//	++i;//��blip::i�趨Ϊ17
//	++j;//�����Դ���ȫ��j����blip::j��
//	++::j;//��ȷ����ȫ��j�趨Ϊ1
//	++blip::j;//��ȷ����blip::j�趨Ϊ16
//	int k = 97;//��ǰ�ľֲ�k������blip::k
//	++k;//����ǰ�ľֲ�k�趨Ϊ98
//}
//
////ͷ�ļ���using������ָʾ
////ͷ�ļ�������䶥���������к���usingָʾ����������Ὣ����ע�뵽���а����˸�ͷ�ļ����ļ��С�
//
////ͷ�ļ����ֻ�������ĺ����������ռ���ʹ��usingָʾ������
//
////�����ռ䱾���ʵ���ļ��оͿ���ʹ��usingָʾ��
//
////18.2.3 �ࡢ�����ռ���������
//
////�����������β���ÿ�����������
//
//namespace A {
//	int i;
//	namespace B {
//		int i;//��B��������A::i
//		int j;
//		int f1() {
//			int j;//j��f1�ľֲ�������������A::B::j
//			return i;//����B::i
//		}
//	}//�����ռ�B�������˺�B�ж�������ֲ��ٿɼ�
//	int f2() {
//		return j;//����jû�б�����
//	}
//	int j = i;//��A::i���г�ʼ��
//}
//
////�����ڸó�Ա�н��в��ң�Ȼ�������в��ң��������ࣩ������������������в��ҡ�
//
//namespace A {
//	int i;
//	int k;
//	class C1 {
//	public:
//		C1():i(0),j(0){}//��ȷ����ʼ��C1::i��C1::j
//		int f1() { return k; }//����A::k
//		int f2() { return h; }//����hδ����
//		int f3();
//	private:
//		int i;//��C1��������A::i
//		int j;
//	};
//	int h = i;//��A::i���г�ʼ��
//}
//
////��Աf3������C1�������ռ�A���ⲿ
//int A::C1::f3() { return h; }//��ȷ������A::h
//
////��������ʹ��
//
////���ԴӺ������޶����Ƴ���������ʱ���������Ĵ����޶������෴����ָ�������ҵ�������
//
////ʵ����صĲ������������β�
//std::string s;
//std::cin >> s;
//
//operator>>(std::cin, s);
//
////������������һ�������͵Ķ���ʱ�������ڳ��������������⻹�����ʵ���������������ռ䡣
//
//using std::operator>>;//��Ҫʹ��cin>>s�ͱ����и�using����
//
//std::operator>>(std::cin, s);//��ȷ����ʽ��ʹ��std::>>
//
////������std::move��std::forward
////Ҫô����һ������ع���ȷ��ĳ�ε���Ӧ��ִ�к������ĸ��汾
////ҪôӦ�ó����������ִ�к����ı�׼��汾
//
////��Ԫ������ʵ����صĲ���
////һ�������δ����������������һ�γ�������Ԫ�����У���������Ϊ�����������������ռ�ĳ�Ա��
//
//namespace A {
//	class C {
//		//������Ԫ������Ԫ����֮��û����������
//		//��Щ������ʽ�س�Ϊ�����ռ�A�ĳ�Ա
//		friend void f2();//�����������������򲻻ᱻ�ҵ�
//		friend void f(const C&);//����ʵ����صĲ��ҹ�����Ա��ҵ�
//	};
//}
//
//int main() {
//	A::C cobj;
//	f(cobj);//��ȷ��ͨ����A::C�е���Ԫ���������ҵ�A::f
//	f2();//����A::f2û�б�����
//}
//
////18.2.4 �����������ռ�
////using������ָʾ�ܽ�ĳЩ������ӵ���ѡ��������
//
////��ʵ����صĲ���������
////����ÿ��ʵ���ࣨ�Լ�ʵ����Ļ��ࣩ�����������ռ�����Ѱ��ѡ������
////����Щ�����ռ��������뱻���ú���ͬ���ĺ�����������ӵ���ѡ����
////��ʹ����ĳЩ�����ڵ�����䴦���ɼ�Ҳ�����
//
//namespace NS {
//	class Quote{/*...*/};
//	void dispaly(const Quote&){/*...*/}
//}
////Bulk_item�Ļ��������������ռ�NS��
//class Bulk_item:public NS::Quote{/*....*/};
//int main() {
//	Bulk_item book1;
//	display(book1);
//	return 0;
//}
//
////������using����
////using���������������һ�����֣�����һ���ض��ĺ���
//using NS::print(int);//���󣺲���ָ���β��б�
//using NS::print();//��ȷ��using����ֻ����һ������
//
////һ��using�������������غ��������а汾��ȷ����Υ�������ռ�Ľӿڡ�
//
////һ��using��������ĺ��������ظ�����������������������е�����ͬ��������
//
////������usingָʾ
////usingָʾ�������ռ�ĳ�Ա����������������С�
//
//namespace libs_R_us {
//	extern void print(int);
//	extern void print(double);
//}
////��ͨ������
//void print(const string&);
////���usingָʾ��������ӵ�print���õĺ�ѡ������
//using namespace libs_R_us;
////print���ô�ʱ�ĺ�ѡ������������
////libs_R_us��print(int)
////libs_R_us��print(double)
////��ʽ������print(const string&);
//void fooBar(int ival) {
//	print("Value :");//����ȫ�ֺ���print(const string&);
//	print(ival);//����libs_R_us::print(int)
//}
//
////����usingָʾ������һ�������к����β��б���ȫ��ͬ�ĺ����������������
////ֻ��ָ�����õİ汾
//
////��Խ���usingָʾ������
//namespace AW {
//	int print(int);
//}
//namespace Primer {
//	double print(double);
//}
////usingָʾ�Ӳ�ͬ�������ռ��д�����һ�����غ�������
//using namespace AW;
//using namespace Primer;
//long double print(long double);
//int main() {
//	print(1);//����AW::print(int)
//	print(3.1);//����Primer::print(double)
//	return 0;
//}
//
////18.3 ���ؼ̳�����̳�
////���ؼ̳���ָ�Ӷ��ֱ�ӻ����в����������������
////���ؼ̳е�������̳������и��������
//
////18.3.1 ���ؼ̳�
//class Bear :public ZooAnimal {
//	class Panda :public Bear,public Endangered{/*...*/};
//};
//
////���ؼ̳е��������б�Ҳֻ�ܰ����Ѿ�����������࣬������Щ�಻����final�ġ�
//
////��ĳ�������������б��У�ͬһ������ֻ�ܳ���һ�Ρ�
//
////���ؼ̳е��������ÿ�������м̳�״̬
////Panda:Bear Endangered
////Bear:ZooAnimal Bear
////Emdamgered:Endangered Panda
//
////�����๹�캯����ʼ�����л���
////����һ��������Ķ���ͬʱ���첢��ʼ���������л����Ӷ���
//
////���ؼ̳е�������Ĺ��캯��Ҳֻ�ܳ�ʼ������ֱ�ӻ���
//
////��ʽ�س�ʼ�����л���
//Panda::Panda(std::string name,bool onExhibit)
//	:Bear(name,onExhibit,"Panda"),
//	Endangered(Endangered::critical){ }
//
////��ʽ��ʹ��Bear��Ĭ�Ϲ��캯����ʼ��Bear�Ӷ���
//Panda::Panda():Endangered(Endangered::critical){}
//
////�̳еĹ��캯������ؼ̳�
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
////����D1��ͼ�����������ж��̳�D1::D1(const string&)
//struct D1:public Base1,public Base2
//{
//	using Base1::Base1;//��Base1�̳й��캯��
//	using Base2::Base2;//��Base2�̳й��캯��
//};
//
////���һ��������Ķ�������м̳�����ͬ�Ĺ��캯���������Ϊ������캯�������Լ��İ汾
//struct D2:public Base1,public Base2
//{
//	using Base1::Base1;//��Base1�̳й��캯��
//	using Base2::Base2;//��Base2�̳й��캯��
//	//D2�����Զ���һ������string�Ĺ��캯��
//	D2(const string&s):Base1(s),Base2(s){}
//	D2() = default;//һ��D2�������Լ��Ĺ��캯������������
//};
//
////������������ؼ̳�
////���������ĵ���˳���빹�캯���෴
//
////���ؼ̳е�������Ŀ������ƶ�����
////���ؼ̳е�����������������Լ��Ŀ���/��ֵ���캯���͸�ֵ������������������������ִ�п������ƶ���ֵ������
//
////ֻ��ʹ�úϳɰ汾���Ż��Զ�ִ��
//
//Panda ying_yang("ying_yang");
//Panda ling_ling = ying_yang;//ʹ�ÿ������캯��
//
////18.3.2 ����ת����������
////��ֻ��һ�����������£��������ָ����������Զ�ת����һ���ɷ��ʻ����ָ������á�
//
////������࣬������ĳ���ɷ��ʻ����ָ�������ֱ��ָ��һ�����������
//
////����Panda�Ļ������õ�һϵ�в���
//void print(const Bear&);
//void highlight(const Endangered &);
//ostream& operator<<(ostream&, const ZooAnimal&);
//Panda ying_yang("ying_yang");
//print(ying_yang);//��һ��Panda���󴫵ݸ�һ��Bear������
//highlight(ying_yang);//��һ��Panda���󴫵ݸ�һ��Endangered������
//cout << ying_yang << endl;//��һ��Panda���󴫵ݸ�һ��ZooAnimal������
//
//void print(const Bear&);
//void print(const Endangered&);
//
//Panda ying_yang("ying_yang");
//print(ying_yang);//�����Դ���
//
////����ָ�����ͻ��������͵Ĳ���
//Bear* pb = new Panda("ying_yang");
//pb->print();//��ȷ��Panda::print()
//pb->cuddle();//���󣺲�����Bear�Ľӿ�
//pb->highlight();//���󣺲�����Bear�Ľӿ�
//delete pb;//��ȷ��Panda::~panda()
//
//Endangered* pe = new Panda("ying_yang");
//pe->print();//��ȷ��Panda::print()
//pe->toes();//���󣺲�����Endangered�Ľӿ�
//pe->cuddle();//���󣺲�����Endangered�Ľӿ�
//pe->highlight();//��ȷ��Panda::highlight()
//delete pe;//��ȷ��Panda::~Panda()
//
////18.3.3 ���ؼ̳��µ���������
////Warning:��һ����ӵ�ж������ʱ���п��ܳ�����������������������м̳���ͬ����Ա���������ʱ������ǰ׺�޶���ֱ��ʹ�ø����ֽ����������ԡ�
//
//double d = ying_yang.max_weight();
//
////��ʱ��ʹ������̳е������β��б�ͬҲ���ܷ�������
//
////��Ҫ����Ǳ�ڵĶ����ԣ���õİ취������������Ϊ�ú�������һ���°汾��
//
//double Panda::max_weight()const {
//	return std::max(ZooAnimal::max_weight(),
//		Endangered::max_weight());
//}
//
////18.3.4 ��̳�
////��̳е�Ŀ������ĳ����������������ŵԸ�⹲�����Ļ��ࡣ
//
////����Ļ����Ӷ����Ϊ�����
//
////����������ڼ̳���ϵ�г��ֶ��ٴΣ����������ж�ֻ����Ψһһ�������������Ӷ���
//
////��һ��Panda��
////����������������ʵ����ǰ���־��Ѿ�����������Ĳ�����
//
////Note:������ֻӰ���ָ�����������������н�һ�����������࣬������Ӱ�������౾��
//
////ʹ�������
////public��virtual��˳������
//class Raccoon :public virtual ZooAnimal{/*...*/};
//class Bear:virtual public ZooAnimal{/*...*/};
//
//class Panda:public Bear,public Raccon,public Endangered{};
//
////֧�������ĳ�������ת��
//void dance(const Bear&);
//void rummage(const Raccoon);
//ostream& operator<<(ostream&, const ZooAnimal&);
//Panda ying_yang;
//dance(ying_yang);//��ȷ����һ��Panda���󵱳�Bear����
//rummage(ying_yang);//��ȷ����һ��Panda���󵱳�Raccoon����
//cout << ying_yang;//��ȷ����һ��Panda���󵱳� ZooAnimal����
//
////������Ա�Ŀɼ���
////��Ϊ��ÿ��������������ֻ��Ψһһ��������Ӷ������Ըû���ĳ�Ա���Ա�ֱ�ӷ��ʣ����Ҳ�����������ԡ�
//
////���������Ա������һ��������ʣ���һ����������������Ϊ�ó�Ա�Զ���һ���µİ汾��
//
////18.3.5 ���캯������̳�
////���������У������������ײ���������ʼ���ġ�
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
////��̳еĶ���Ĺ��췽ʽ
////����ʹ���ṩ����ײ������๹�캯���ĳ�ʼֵ��ʼ���ö����������Ӳ���
////����������ֱ�ӻ����������б��г��ֵĴ������ζ�����г�ʼ��
//
////Note:������������ڷ�����๹�죬�������ڼ̳���ϵ�еĴ����λ���޹�
//
////���캯�������������Ĵ���
////һ��������ж������ࡣ
////��Щ����Ӷ����������������б��г��ֵ�˳������������ι��졣
//
//class Character{/*...*/};
//class BookCharacter:public Character{/*...*/};
//class ToyAnimal{/*...*/};
//class TeddyBear:public BookCharacter,public Bear,public virtual ToyAnimal{/*...*/};
//
//ZooAnimal();//Bear�������
//ToyAnimal();//ֱ�������
//Character();//��һ���������ļ�ӻ���
//BookCharacter();//��һ��ֱ�ӷ������
//Bear();//�ڶ���ֱ�ӷ������
//TeddyBear();//��ײ��������