//#include"textquery.h"
//#include<iostream>
//#include<fstream>
//
//
//int main()
//{
//	std::ifstream infile("input.txt");
//	if (!infile)
//	{
//		std::cerr<< "�޷����ļ� input.txt\n";
//		return -1;
//	}
//
//	TextQuery tq(infile);
//
//	std::string word;
//	std::cout << "������Ҫ��ѯ�ĵ��ʣ����� q �˳���\n";
//
//	while (true)
//	{
//		std::cout<< ">>> ";
//		std::cin >> word;
//
//		if (word == "q")break;
//
//		auto result = tq.query_return_tuple(word);
//		const auto& sought = std::get<0>(result);
//		const auto& lines = std::get<1>(result);
//		const auto& content = std::get<2>(result);
//
//		if (lines->empty())
//		{
//			std::cout<<"\""<<sought<< "\" δ�������ı��С�\n";
//
//		}
//		else
//		{
//			std::cout << "\"" << sought << "\" ������ " << lines->size() << " �У�\n";
//			for (const auto& line_num : *lines)
//			{
//				std::cout << "\t(��" << line_num + 1 << " ��): "
//					<< (*content)[line_num] << "\n";
//			}
//		}
//	}
//
//	return 0;
//}