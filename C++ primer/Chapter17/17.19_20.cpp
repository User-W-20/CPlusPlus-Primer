//#include <iostream>
//#include <string>
//#include <regex>
//using std::cout;
//using std::cin;
//using std::endl;
//using std::string;
//using std::regex;
//using std::sregex_iterator;
//using std::smatch;
//
//
//bool valid(const smatch& m);
//
//int main() {
//	string phone = R"((\()?\d{3}(\))?([-. ]?)\d{3}([-. ]?)\d{4})";
//	regex r(phone);
//	smatch m;
//	string s;
//	bool valid_record;
//	while (std::getline(cin, s)) {
//		valid_record = false;
//		for (sregex_iterator it(s.begin(), s.end(), r), end_it; it != end_it; ++it) {
//			valid_record = true;
//			if (valid(*it))
//				cout << "valid phone number: " << it->str() << endl;
//			else
//				cout << "invalid phone number: " << it->str() << endl;
//		}
//		if (!valid_record)
//			cout << "invalid record!" << endl;
//	}
//	return 0;
//}
//
//bool valid(const smatch& m)
//{
//	if (m[1].matched)  
//		return m[2].matched && (m[3].str().empty() || m[3].str() == " ");
//	else  
//		return !m[2].matched && m[3].str() == m[4].str();
//}