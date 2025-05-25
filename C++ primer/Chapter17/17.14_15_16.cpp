//#include <iostream>
//#include <string>
//#include <regex>
//using std::string;
//using std::cout;
//using std::cin;
//using std::endl;
//using std::regex;
//using std::regex_error;
//
//int main(){
//	/*try{
//		regex r("[[:alnum:]+\\.(cpp|cxx|cc)$", regex::icase);
//	}
//	catch (regex_error& e){
//		cout << e.what() << "code: " << e.code() << endl;
//	}*/
//
//	regex r("[[:alpha:]][^c]ei[[:alpha:]]*", regex::icase);
//	string s;
//	/*cout << "Please input a word! Input 'q' to quit!" << endl;
//	while (cin >> s && s != "q") {
//		if(std::regex_search(s,r))
//			cout << "Input word " << s << " is okay!" << endl;
//		else
//			cout << "Input word " << s << " is not okay!" << endl;
//
//		cout << "Please input a word! Input 'q' to quit!" << endl;
//	}*/
//
//	cout << endl;
//
//	r.assign("[^c]ei", regex::icase);
//	cout << "Please input a word! Input 'q' to quit!" << endl;
//	while (cin >> s && s != "q") {
//		if(std::regex_match(s,r))
//			cout << "Input word " << s << " is okay!" << endl;
//		else
//			cout << "Input word " << s << " is not okay!" << endl;
//
//		cout << "Please input a word! Input 'q' to quit!" << endl;
//	}
//	return 0;
//}