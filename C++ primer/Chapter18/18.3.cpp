//#include<iostream>
//#include<stdexcept>
//#include<memory>
//#include<fstream>
//#include<vector>
//
//struct intArry
//{
//	intArry():p(nullptr){}
//
//	explicit intArry(std::size_t s):p(new int[s]){}
//
//	~intArry() {
//		delete[] p;
//	}
//
//	int* p;
//};
//
//void exercise(int* b, int* e) {
//	std::vector<int>v(b, e);//v����������������
//
//	//�ɴ���
//	//int* p = new int[v.size()];��̬�����int���齫�޷����ͷ�
//
//	//��1
//	intArry p(v.size());
//
//	//��2
//	std::shared_ptr<int>p(new int[v.size()], [](int* p) {delete p; });//ʹ��lambdaɾ������
//
//	std::ifstream("ints");
//}
//
//int main() {
//	std::range_error r("error");
//	throw r;
//
//	std::exception* p = &r;
//	throw p;
//}


