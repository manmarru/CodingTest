#include "pch.h"
#include "Header.h"

#include <string>
#include <vector>

using namespace std;

/*
stl 안쓰려고 일단은 직접 구현했다.
시험볼때는 nultiset 사용하면 된다.
예외처리 귀찮아서 노드 내부에서 안해준 점 아쉽다.
avl 트리가 아니기 때문에 시간복잡도가 O(n) 까지 떨어질 수 있다.


#include <set>
multiset<int> Temp;
레드블랙트리로 알아서 정렬될거고
최대/최소값 삭제는 begin 과 end를 삭제하면 된다.
*/


struct NODE
{
    int m_Data;
    NODE* m_Left = nullptr;
    NODE* m_Right = nullptr;
    NODE* m_Parent = nullptr;

    NODE(int _Data)
        :m_Data{ _Data } {
    }

    void Push(int _Data)
    {
        if (_Data > m_Data)
        {
            if (nullptr == m_Right)
            {
                m_Right = new NODE(_Data);
                m_Right->m_Parent = this;
            }
            else
            {
                m_Right->Push(_Data);
            }
        }
        else
        {
            if (nullptr == m_Left)
            {
                m_Left = new NODE(_Data);
                m_Left->m_Parent = this;
            }
            else
            {
                m_Left->Push(_Data);
            }
        }
    }

    NODE* Erase_Min()
    {
        if (m_Left == nullptr)
        {
            NODE* Root = m_Right;
            delete Root->m_Parent;
            return Root;
        }
        NODE* MinNode = this;
        while (MinNode->m_Left != nullptr)
        {
            MinNode = MinNode->m_Left;
        }
        NODE* Parent = MinNode->m_Parent;

        if (MinNode->m_Right != nullptr)
        {
            Parent->m_Left = MinNode->m_Right;
            Parent->m_Left->m_Parent = Parent;
        }
        else
        {
            Parent->m_Left = nullptr;
        }
        delete MinNode;

        return this;
    }

    NODE* Erase_Max()
    {
        if (m_Right == nullptr)
        {
            NODE* Root = m_Left;
            delete Root->m_Parent;
            return Root;
        }
        NODE* MaxNode = this;
        while (MaxNode->m_Right != nullptr)
        {
            MaxNode = MaxNode->m_Right;
        }
        NODE* Parent = MaxNode->m_Parent;

        if (MaxNode->m_Left != nullptr)
        {
            Parent->m_Right = MaxNode->m_Left;
            Parent->m_Right->m_Parent = Parent;
        }
        else
        {
            Parent->m_Right = nullptr;
        }

        return  this;
    }
};

vector<int> solution(vector<string> operations)
{
    int NodeSize = 0;
    NODE* Root = nullptr;
    // NodeSize = 1 일때 지우려고 하면 여기서 직접 지워야 함.
    for (string Temp : operations)
    {
        if (Temp[0] == 'I')
        {
            int Num = stoi(Temp.substr(2));
            if (NodeSize == 0)
            {
                Root = new NODE(Num);
            }
            else
            {
                Root->Push(Num);
            }
            ++NodeSize;
        }
        else if (Temp[0] == 'D')
        {
            cout << "D";
            if (NodeSize == 0)
                continue;
            if (NodeSize == 1)
            {
                delete Root;
                Root = nullptr;
            }
            else
            {
                Root = (Temp[2] == '1' ? Root->Erase_Max() : Root->Erase_Min());
            }

            --NodeSize;
        }
    }

    vector<int> answer;

    if (NodeSize == 0)
    {
        answer.push_back(0);
        answer.push_back(0);
    }
    else
    {
        NODE* Curr = Root;
        while (Curr->m_Right != nullptr)
        {
            Curr = Curr->m_Right;
        }
        answer.push_back(Curr->m_Data);
        Curr = Root;
        while (Curr->m_Left != nullptr)
        {
            Curr = Curr->m_Left;
        }
        answer.push_back(Curr->m_Data);
    }

    return answer;
}