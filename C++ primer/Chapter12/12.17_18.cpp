//#include <iostream>
//#include <vector>
//#include <string>
//#include <memory>
////Ϊʲô shared_ptr û�� release ��Ա��
//// ��Ϊָ��ͬһ����������� shared_ptr ��Ȼ����ɾ���������
//// ��ˣ��ṩ�����Ա�������塣
//int main()
//{
//	int ix = 1024, * pi = &ix, * pi2 = new int(2048);
//	typedef std::unique_ptr<int> IntP;
//
//	//IntP p0(ix);@brief���󣺴� ��int ���� ��std::unique_ptr<int>::ָ�� { ���� int* }����ת����Ч [-fpermissive]
//
//
//	/*IntP p1(pi); @brief ����Ĵ�����Ա��룬������ʱ�����
//		* ԭ���ǵ� unique_ptr p1 �뿪������ʱ�������� delete
//		* ���ͷŶ��󡣵��ö���û��ʹ�� new ���䡣
//		* ����ϵͳ���׳�һ������
//		* �������*/
//
//	/*IntP p2(pi2); @brief ��δ�����Ա��룬��������ʱ�ᵼ��ָ�����ա�
//		* ԭ���� unique_ptr ���ͷ�ԭʼָ����ָ��Ķ���
//		* ָ��Ķ���
//		* @������*/
//
//	/*IntP p3(&ix); @brief �� unique_ptr �뿪������ʱ��������� delete ���ͷ�δʹ�� new �����* ����
//		* δʹ�� new ����Ķ���
//		* @������*/
//
//
//	//IntP p4(new int(2048));// @brief �Ƽ�
//
//	/*IntP p2(new int(555));
//	IntP p5(p2.get());
//	@brief error : double free or corruption at run time
//		* ���� unique_ptr ָ��ͬһ��������ˣ������������˳�
//		* ��Χʱ������ϵͳ���׳�˫���ͷŻ��𻵡�
//		* @badcode*/
//	return 0;
//}