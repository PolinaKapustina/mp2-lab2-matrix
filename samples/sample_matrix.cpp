// ����, ���, ���� "������ ����������������-2", �++, ���
//
// sample_matrix.cpp - Copyright (c) ������� �.�. 07.05.2001
//   ������������ ��� Microsoft Visual Studio 2008 �������� �.�. (20.04.2015)
//
// ������������ ����������������� �������

#include <iostream>
#include "utmatrix.h"
//---------------------------------------------------------------------------

void main()
{
    int n,
    int i = 0;
    setlocale(LC_ALL, "Russian");
    cout << "������������ �������� ��������� ������������� ����������� ������" << endl;
    cout << "������� ������ ������:" << endl;
    cin >> n;
    TMatrix<int> a(n), b(n);
    cout << "��������� ������� A:" << endl;
    cin >> a;
    cout << "��������� ������� B:" << endl;
    cin >> b;
    while (i != 0)
    {
        cout << "������� ����� ��������, ������� ������ ���������:" << endl;
        cout << "1 - �������� ������" << endl;
        cout << "2 - ��������� ������" << endl;
        cout << "0 - ����� �� ���������" << endl;
        cin >> i;
        if (i == 0) break;
        if (i == 1)
            cout << "A + B = " << endl << a + b << endl;
        if (i == 2)
            cout << "A - B = " << endl << a - b << endl;
        if (i != 1 && i != 2)
            cout << "������������ ����� ��������" << endl;
    }

}
//---------------------------------------------------------------------------
