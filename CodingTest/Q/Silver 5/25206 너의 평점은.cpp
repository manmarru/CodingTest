#include "pch.h"
#include "Header.h"

void Solve(ifstream* _pLoadStream)
{
    char subject[51];
    float result(0.f);
    char grade[3]; // 받은 학점 abc 0+
    float fTmp; //학점단위
    float fSrc = 0.f;//grade 환산
    int iCnt(0); //과목수

    while (CIN >> subject >> fTmp >> grade)
    {
        switch (grade[0])
        {
        case 'A':
            fSrc = 4.0;
            break;
        case 'B':
            fSrc = 3.0;
            break;
        case 'C':
            fSrc = 2.0;
            break;
        case 'D':
            fSrc = 1.0;
            break;
        case 'F': 
            iCnt += fTmp;
            continue;
        case 'P':
            continue;
        default:
            break;
        }
        fSrc += grade[1] == '+' ? 0.5f : 0.f;
        result += fTmp * fSrc;
        iCnt += fTmp;
    }
    cout << result / (float)iCnt << endl;
}