//#include <iostream>
//#include <vector>
//#include <string>
//#include <memory>
//
//void process(std::shared_ptr<int>ptr)
//{
//	std::cout << "inside the process function:" << ptr.use_count() << "\n";
//}
//
//int main()
//{
//	auto p = new int();
//	auto sp = std::make_shared<int>();
//	//process(sp);//�Ϸ���ֻ�轫 sp ��Ϊ shared_ptr ���Ƶ� process()��
//
//	//process(new int());//���Ϸ��� ��ָͨ�벻����ʽת��Ϊ����ָ�롣
//
//	//process(p);//���Ϸ�,��ָͨ�벻����ʽת��Ϊ����ָ�롣
//
//	//process(std::shared_ptr<int>(p));//�Ϸ�,���������ǲ��õġ�
//	//��Ϊ������ָ����ԭʼָ��һ��ʹ�ÿ��ܻᵼ�����⡣˫���ͷ�
//	return 0;
//}