#include<iostream>//输入输出流
#define MAXSIZE 10//顺序栈最大容量
using namespace std;//标准命名空间
typedef int ElemType;//给int 起别名
class SqStack//顺序栈类
{
public://公共属性
	ElemType* base;//栈底，保存栈的地址
	ElemType* top;//栈定，负责入栈和出栈，对数据的操作（这里top在没有进行操作时候，指向的是存放数据的下一地址，也就是*top是没有值的）
	SqStack()//构造函数，创建对象自动调用初始化
	{
		this->initSqStack();
	}
	~SqStack()//析构函数，对象销毁自动调用，释放栈底内存给操作系统
	{
		delete this->base;//释放内存
	}
	bool initSqStack();//初始化
	bool push(ElemType& elem);//入栈，这里用不用引用意义不大，利用引用可以节省空间（值传递的话，要开辟空间）
	bool pop(ElemType& elem);//出栈，这里必须引用，因为利用引用，形参可以改变实参，这样才能保证传进来的elem被赋值了
	void printSqStack();//打印顺序栈，从栈顶到栈底依次打印数据
	int stackLength();//栈的长度
};
bool SqStack::initSqStack()//初始化
{
	this->base = new ElemType[MAXSIZE];//向操作系统申请空间，并创建在堆区，把地址交给栈底指针保管
	if (this->base == NULL)//判断是否申请成功
	{
		return false;
	}
	this->top = this->base;//没有数据，栈顶要与栈底的地址保持一致
}
bool SqStack::push(ElemType& elem)//入栈
{
	if (this->top - this->base == MAXSIZE)//如果栈顶已经到达了最大，则不能入栈
	{
		return false;
	}
	*this->top++ = elem;//*为解引用操作，目的是对地址的值进行操作，一定是要先赋值，然后栈顶指针再向上偏移
	return true;
}
bool SqStack::pop(ElemType& elem)//出栈
{
	if (this->base == this->top)//如果栈底指针等于栈顶指针，说明这是一个空栈，不能进行出栈操作
	{
		return false;//返回失败
	}
	elem = *--this->top;//出栈时，栈顶指针一定要先向下偏移，在把地址解引用赋给elem,因为elem是引用，所以elem的值发生了改变
}
void SqStack::printSqStack()//打印栈表
{
	if (this->base == this->top)//如果栈表为空，直接返回
	{
		return;
	}
	ElemType* p = this->top;//让p代替top进行操作，防止top丢失
	while (p != this->base)//如果top没有向下偏移到base,就一直打印
	{
		cout << *--p << " ";//先偏移，再解引用
	}
	cout << endl;//最后换行
}
int SqStack::stackLength()
{
	return this->top - this->base;//两个地址相减，编译器自动返回int类型的值（长度）
}
void showMenu()//菜单，方便用户操作
{
	cout << "  *****************" << endl;
	cout << "  *  动态顺序栈   *" << endl;
	cout << "  *  1、初始化    *" << endl;
	cout << "  *  2、入  栈    *" << endl;
	cout << "  *  3、出  栈    *" << endl;
	cout << "  *  4、遍  历    *" << endl;
	cout << "  *  5、长  度    *" << endl;
	cout << "  *  0、退  出    *" << endl;
	cout << "  *****************" << endl;
	cout << "请输入您的选项:";
}
int main()
{
	SqStack s;//创建顺序表对象（创建成功，自动初始化）
	int select;//选择变量
	while (true)//让用户正确选择
	{
		showMenu();
		cin >> select;
		switch (select)
		{
		case 1:
			if (s.initSqStack())
			{
				cout << "初始化成功！" << endl;
			}
			else
			{
				cout << "初始化失败！" << endl;
			}
			system("pause");//停顿
			system("cls");//清屏
			break;
		case 2:
		{
			cout << "请输入你想入栈的数据:" << endl;
			ElemType elem;
			cin >> elem;
			if (s.push(elem))
			{
				cout << elem << "已入栈！" << endl;
			}
			else
			{
				cout << "入栈失败！" << endl;
			}
			system("pause");
			system("cls");
		}
		break;
		case 3:
		{
			ElemType elem;
			if (s.pop(elem))
			{
				cout << elem << "已出栈！" << endl;
			}
			else
			{
				cout << "出栈失败！" << endl;
			}
			system("pause");
			system("cls");
		}
		break;
		case 4:
			s.printSqStack();
			system("pause");
			system("cls");
			break;
		case 5:
			cout << "顺序栈的长度为：" << s.stackLength() << endl;
			system("pause");
			system("cls");
			break;
		default:
			cout << "欢迎下次使用！" << endl;
			system("pause");
			return 0;
			break;
		}
	}
}