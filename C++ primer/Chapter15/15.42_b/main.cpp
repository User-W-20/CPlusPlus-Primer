//#include<iostream>
//using std::cout; using std::cin; using std::endl;
//
//#include<fstream>
//using std::ifstream;
//#include<string>
//using std::string;
//#include<vector>
//using std::vector;
//
//#include"QueryHistory.h"
//#include"QueryResult.h"
//#include"TextQuery.h"
//#include"Query.h"
//#include"AndQuery.h"
//#include"NotQuery.h"
//#include"OrQuery.h"
//
//int main()
//{
//    // 1. ��ȡ�ļ�
//    ifstream file("C:\\Users\\X\\source\\repos\\C++ primer\\C++ primer\\Chapter15\\15.42_b\\test.txt");
//    if (!file) {
//        std::cerr << "�޷����ļ�!" << endl;
//        return 1;
//    }
//
//    TextQuery tq(file);  // ���� TextQuery
//
//    // 2. ���Ե��ʲ�ѯ
//    cout << "��ѯ����  :\n";
//    Query q1("Alice");
//    print(cout, q1.eval(tq)) << endl;
//
//    // 3. ���� AND ��ѯ
//    cout << "��ѯ  And:\n";
//    Query q2 = Query("Alice Emma") & Query("bird");
//    print(cout, q2.eval(tq)) << endl;
//
//    // 4. ���� OR ��ѯ
//    cout << "��ѯ  Or:\n";
//    Query q3 = Query("no") | Query("tells");
//    print(cout, q3.eval(tq)) << endl;
//
//    // 5. ���� NOT ��ѯ
//    cout << "��ѯ Not:\n";
//    std::string x;
//    std::cin >> x;
//    Query q4 = ~Query(x);
//    print(cout, q4.eval(tq)) << endl;
//
//    // 6. ���� QueryHistory
//    QueryHistory history;
//    history.add_query(q1);
//    history.add_query(q2);
//    history.add_query(q3);
//    history.add_query(q4);
//
//    cout << "��ѯ��ʷ��¼:\n";
//    for (size_t i = 0; i < 4; ++i) {
//        cout << "Query " << i << ":\n";
//        print(cout, history[i].eval(tq)) << endl;
//    }
//
//    return 0;
//}