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
//		std::cerr<< "无法打开文件 input.txt\n";
//		return -1;
//	}
//
//	TextQuery tq(infile);
//
//	std::string word;
//	std::cout << "请输入要查询的单词，输入 q 退出：\n";
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
//			std::cout<<"\""<<sought<< "\" 未出现在文本中。\n";
//
//		}
//		else
//		{
//			std::cout << "\"" << sought << "\" 出现在 " << lines->size() << " 行：\n";
//			for (const auto& line_num : *lines)
//			{
//				std::cout << "\t(第" << line_num + 1 << " 行): "
//					<< (*content)[line_num] << "\n";
//			}
//		}
//	}
//
//	return 0;
//}