#include"System.h"

System::System():_number_student(0) {
	//初始化头指针和尾指针
	_student = NULL;
	_last_student = NULL;
}
System::~System() {

}
void System::insert() {
	//头指针为空的话创建头学生，否则创建学生信息于链表尾
	//学生人数加一
	//输入学生信息
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
	//如果插入的位置大于已存在（最大位置+1）返回错误
	//否则插入指定位置，学生数加一
	//输入学生信息
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
	cout << "请依次输入要插入的考生的考号，姓名，性别，年龄及报考类别！" << endl;
	cin >> stu->_exam_number >> stu->_name >> stu->_sex >> stu->_age >> stu->_classification;
	return true;

}
bool System::cutoff(const int& x) {
	//删除指定考号的学生信息
	//找不到返回错误
	//找到删除，学生数减一
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
	cout << "你删除的考生信息是：";
	cout << stu->_exam_number << "   " << stu->_name << "   " << stu->_sex << "   " << stu->_age << "   " << stu->_classification << endl;
	delete stu;
	_number_student -= 1;
	return true;

}
bool System::search(const int& x) {
	//找到指定考号的学生删除
	Student*stu;
	stu = _student;

	while (stu != NULL&&stu->_exam_number != x)
	{
		stu = stu->_next_student;
	}
	if (stu == NULL)
		return false;
	cout << "考号" << "   " << "姓名" << "   " << "性别" << "   " << "年龄" << "   " << "报考类别" << endl;
	cout << stu->_exam_number << "   " << stu->_name << "   " << stu->_sex << "   " << stu->_age << "   " << stu->_classification<<endl;
	return true;
}

bool System::modify(const int&x) {
	//找到指定考号的学生
	//重新输入其信息
	Student* stu;
	stu = _student;

	while (stu != NULL&&stu->_exam_number != x)
	{
		stu = stu->_next_student;
	}
	if (stu == NULL)
		return false;
	cout << "请完整的将修改后的考生信息输入！" << endl;
	cout << "考号" << "   " << "姓名" << "   " << "性别" << "   " << "年龄" << "   " << "报考类别" << endl;
	cin >> stu->_exam_number >> stu->_name >> stu->_sex >> stu->_age >> stu->_classification;
	return true;
}

bool System::count() {
	//将所有考生信息输出
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
