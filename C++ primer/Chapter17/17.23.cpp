//#include<iostream>
//#include<string>
//#include<regex>
//
//using std::cout;
//using std::cin;
//using std::endl;
//using std::string;
//using std::regex;
//using std::sregex_iterator;
//using std::smatch;
//
//bool valid(const smatch& m);
//
//int main()
//{
//	string zipcode = R"(\d{5}([-])?(\d{4})?\b)";
//	regex r(zipcode);
//	smatch m;
//	string s;
//
//	while (std::getline(cin, s)) {
//		for (sregex_iterator it(s.begin(), s.end(), r), end_it; it != end_it; ++it) {
//			if(valid(*it))
//				cout << "valid zipcode number: " << it->str() << endl;
//			else
//				cout << "invalid zipcode number: " << s << endl;
//		}
//	}
//	return 0;
//}
//
//bool valid(const smatch& m)
//{
//	if ((m[2].matched) && (!m[1].matched))
//		return false;
//	else
//		return true;
//}