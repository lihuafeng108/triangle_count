#include <iostream>
#include "triangle.h"

using namespace std;                                           //�˾�Ҳ������main�������г���

//����ͼ�ΰ����н�����Զ����ţ����ѱ����ͬһ��ֱ�ߵĵ��г���
static const int point_on_line[][LINE_POINT_MAX] = 
{
    {1, 2, 3, 4},
    {1, 5, 6, 10},
    {1, 7, 11},
    {7, 8, 9, 10},
    {11, 8, 5, 2},
    {11, 9, 6, 3},
    {11, 10, 4},
};

static const int point_num = 11;

int main(void)
{
    int i, j, k;
    class striangle_cout striangle;
    
    striangle.get_poiner_of_line_array(point_on_line);
    striangle.set_line_num(sizeof(point_on_line) / (sizeof(int)*LINE_POINT_MAX));
    
    for(i=1; i<point_num+1; i++)
    {
        for(j=1; j<point_num+1; j++)
        {
            for(k=1; k<point_num+1; k++)
            {
                striangle.triangle_recognize(i, j, k);
            }
        }
    }
    
    cout<<"��������εĸ���:"<<striangle.get_striangle_cout()<<endl;
}