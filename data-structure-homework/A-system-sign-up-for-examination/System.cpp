#include"System.h"

System::System():_number_student(0) {
	//��ʼ��ͷָ���βָ��
	_student = NULL;
	_last_student = NULL;
}
System::~System() {

}
void System::insert() {
	//ͷָ��Ϊ�յĻ�����ͷѧ�������򴴽�ѧ����Ϣ������β
	//ѧ��������һ
	//����ѧ����Ϣ
	Student* stu;
	if (_student == NULL)                         
	{
		_student = new Student;
		_last_student = _student;
		_student->_next_student = NULL;
		stu = _student;
	}
	else
	{
		_last_student->_next_student = new Student;
		stu = _last_student->_next_student;
		stu->_next_student = NULL;
		_last_student = stu;
	}
	_number_student += 1;
	cin >> stu->_exam_number >> stu->_name >> stu->_sex >> stu->_age >> stu->_classification;
}

bool System::insert(const int& x) {
	//��������λ�ô����Ѵ��ڣ����λ��+1�����ش���
	//�������ָ��λ�ã�ѧ������һ
	//����ѧ����Ϣ
	if (x > _number_student + 1)return false;
	Student* stu;
	stu = _student;
	
	for (int i = 1; i < x-1; i++)
	{
		stu = stu->_next_student;
	}
	Student* transition = stu->_next_student;
	stu->_next_student = new Student;
	stu = stu->_next_student;
	stu->_next_student = transition;

	_number_student += 1;
	cout << "����������Ҫ����Ŀ����Ŀ��ţ��������Ա����估�������" << endl;
	cin >> stu->_exam_number >> stu->_name >> stu->_sex >> stu->_age >> stu->_classification;
	return true;

}
bool System::cutoff(const int& x) {
	//ɾ��ָ�����ŵ�ѧ����Ϣ
	//�Ҳ������ش���
	//�ҵ�ɾ����ѧ������һ
	Student* stu;
	Student*laststu = NULL;
	stu = _student;

	while (stu != NULL&&stu->_exam_number != x)
	{
		laststu = stu;
		stu = stu->_next_student;
	}
	if (stu == NULL)
		return false;

	if (laststu == NULL)
		_student = _student->_next_student;
	else
		laststu->_next_student = stu->_next_student;
	cout << "��ɾ���Ŀ�����Ϣ�ǣ�";
	cout << stu->_exam_number << "   " << stu->_name << "   " << stu->_sex << "   " << stu->_age << "   " << stu->_classification << endl;
	delete stu;
	_number_student -= 1;
	return true;

}
bool System::search(const int& x) {
	//�ҵ�ָ�����ŵ�ѧ��ɾ��
	Student*stu;
	stu = _student;

	while (stu != NULL&&stu->_exam_number != x)
	{
		stu = stu->_next_student;
	}
	if (stu == NULL)
		return false;
	cout << "����" << "   " << "����" << "   " << "�Ա�" << "   " << "����" << "   " << "�������" << endl;
	cout << stu->_exam_number << "   " << stu->_name << "   " << stu->_sex << "   " << stu->_age << "   " << stu->_classification<<endl;
	return true;
}

bool System::modify(const int&x) {
	//�ҵ�ָ�����ŵ�ѧ��
	//������������Ϣ
	Student* stu;
	stu = _student;

	while (stu != NULL&&stu->_exam_number != x)
	{
		stu = stu->_next_student;
	}
	if (stu == NULL)
		return false;
	cout << "�������Ľ��޸ĺ�Ŀ�����Ϣ���룡" << endl;
	cout << "����" << "   " << "����" << "   " << "�Ա�" << "   " << "����" << "   " << "�������" << endl;
	cin >> stu->_exam_number >> stu->_name >> stu->_sex >> stu->_age >> stu->_classification;
	return true;
}

bool System::count() {
	//�����п�����Ϣ���
	if (_student == NULL)
		return false;
	Student* stu;
	stu = _student;
	while (stu != NULL) {
		cout << stu->_exam_number <<"   "<< stu->_name <<"   "<< stu->_sex <<"   "<<stu->_age<<"   "<< stu->_classification << endl;
		stu=stu->_next_student;
	}
	return true;
}
