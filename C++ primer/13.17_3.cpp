//#include <iostream>
//
//class numbered {
//public:
//
//	numbered() {
//		msyn = unique++;
//	}
//
//	numbered(const numbered& n) {
//		msyn = unique++;
//	}
//
//	int msyn;
//	static int unique;
//};
//
//int numbered::unique = 10;
//
//void f(const numbered& s) {
//	std::cout << s.msyn << std::endl;
//}
//
//int main() {
//	numbered a, b = a, c = b;
//	f(a);
//	f(b);
//	f(c);
//}