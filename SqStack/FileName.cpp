#include<iostream>//���������
#define MAXSIZE 10//˳��ջ�������
using namespace std;//��׼�����ռ�
typedef int ElemType;//��int �����
class SqStack//˳��ջ��
{
public://��������
	ElemType* base;//ջ�ף�����ջ�ĵ�ַ
	ElemType* top;//ջ����������ջ�ͳ�ջ�������ݵĲ���������top��û�н��в���ʱ��ָ����Ǵ�����ݵ���һ��ַ��Ҳ����*top��û��ֵ�ģ�
	SqStack()//���캯�������������Զ����ó�ʼ��
	{
		this->initSqStack();
	}
	~SqStack()//�������������������Զ����ã��ͷ�ջ���ڴ������ϵͳ
	{
		delete this->base;//�ͷ��ڴ�
	}
	bool initSqStack();//��ʼ��
	bool push(ElemType& elem);//��ջ�������ò����������岻���������ÿ��Խ�ʡ�ռ䣨ֵ���ݵĻ���Ҫ���ٿռ䣩
	bool pop(ElemType& elem);//��ջ������������ã���Ϊ�������ã��βο��Ըı�ʵ�Σ��������ܱ�֤��������elem����ֵ��
	void printSqStack();//��ӡ˳��ջ����ջ����ջ�����δ�ӡ����
	int stackLength();//ջ�ĳ���
};
bool SqStack::initSqStack()//��ʼ��
{
	this->base = new ElemType[MAXSIZE];//�����ϵͳ����ռ䣬�������ڶ������ѵ�ַ����ջ��ָ�뱣��
	if (this->base == NULL)//�ж��Ƿ�����ɹ�
	{
		return false;
	}
	this->top = this->base;//û�����ݣ�ջ��Ҫ��ջ�׵ĵ�ַ����һ��
}
bool SqStack::push(ElemType& elem)//��ջ
{
	if (this->top - this->base == MAXSIZE)//���ջ���Ѿ����������������ջ
	{
		return false;
	}
	*this->top++ = elem;//*Ϊ�����ò�����Ŀ���ǶԵ�ַ��ֵ���в�����һ����Ҫ�ȸ�ֵ��Ȼ��ջ��ָ��������ƫ��
	return true;
}
bool SqStack::pop(ElemType& elem)//��ջ
{
	if (this->base == this->top)//���ջ��ָ�����ջ��ָ�룬˵������һ����ջ�����ܽ��г�ջ����
	{
		return false;//����ʧ��
	}
	elem = *--this->top;//��ջʱ��ջ��ָ��һ��Ҫ������ƫ�ƣ��ڰѵ�ַ�����ø���elem,��Ϊelem�����ã�����elem��ֵ�����˸ı�
}
void SqStack::printSqStack()//��ӡջ��
{
	if (this->base == this->top)//���ջ��Ϊ�գ�ֱ�ӷ���
	{
		return;
	}
	ElemType* p = this->top;//��p����top���в�������ֹtop��ʧ
	while (p != this->base)//���topû������ƫ�Ƶ�base,��һֱ��ӡ
	{
		cout << *--p << " ";//��ƫ�ƣ��ٽ�����
	}
	cout << endl;//�����
}
int SqStack::stackLength()
{
	return this->top - this->base;//������ַ������������Զ�����int���͵�ֵ�����ȣ�
}
void showMenu()//�˵��������û�����
{
	cout << "  *****************" << endl;
	cout << "  *  ��̬˳��ջ   *" << endl;
	cout << "  *  1����ʼ��    *" << endl;
	cout << "  *  2����  ջ    *" << endl;
	cout << "  *  3����  ջ    *" << endl;
	cout << "  *  4����  ��    *" << endl;
	cout << "  *  5����  ��    *" << endl;
	cout << "  *  0����  ��    *" << endl;
	cout << "  *****************" << endl;
	cout << "����������ѡ��:";
}
int main()
{
	SqStack s;//����˳�����󣨴����ɹ����Զ���ʼ����
	int select;//ѡ�����
	while (true)//���û���ȷѡ��
	{
		showMenu();
		cin >> select;
		switch (select)
		{
		case 1:
			if (s.initSqStack())
			{
				cout << "��ʼ���ɹ���" << endl;
			}
			else
			{
				cout << "��ʼ��ʧ�ܣ�" << endl;
			}
			system("pause");//ͣ��
			system("cls");//����
			break;
		case 2:
		{
			cout << "������������ջ������:" << endl;
			ElemType elem;
			cin >> elem;
			if (s.push(elem))
			{
				cout << elem << "����ջ��" << endl;
			}
			else
			{
				cout << "��ջʧ�ܣ�" << endl;
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
				cout << elem << "�ѳ�ջ��" << endl;
			}
			else
			{
				cout << "��ջʧ�ܣ�" << endl;
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
			cout << "˳��ջ�ĳ���Ϊ��" << s.stackLength() << endl;
			system("pause");
			system("cls");
			break;
		default:
			cout << "��ӭ�´�ʹ�ã�" << endl;
			system("pause");
			return 0;
			break;
		}
	}
}