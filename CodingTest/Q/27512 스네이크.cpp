#include "pch.h"
#include "Header.h"

void Solve(ifstream* _pLoadStream)
{
	/*
	������ũ ���ӿ��� ���� ��� "����"�� �� �ִ� ���� ���� ���ϱ�
	
	�����̶� 2 �����̸� �� ä�� ��  ����
	¦�� �� or ���̰� �ٸ� ���� 3 �̻��̸� �׳� ��ä��� ����
	>> �� �ΰ��� �׳� �����̶� ¦���� ���� �ٲ� �� �ִ�. �ڵ� �� ����ȭ ������


	������ Ȧ��, �ٸ����� 3 �̻��̸� ��ĭ ���� ����

	*/
	int width, height;
	CIN >> width >> height;

	if (width == 2 || height == 2)
		cout << width * height;
	else if (width % 2 == 0 || height % 2 == 0)
		cout << width * height;
	else
		cout << width * height - 1;

}