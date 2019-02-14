#include <iostream>
#include <string.h>
#include <stdio.h>
#include "triangle.h"

striangle_cout::striangle_cout()
{
    memset(&m_save_striange, 0, sizeof(m_save_striange));
}

striangle_cout::~striangle_cout()
{
    //do nothing
}

//点是否在输入的数组集合内
int striangle_cout::is_point_in_set(const int *set, int set_size, int point)
{
    for(int i=0; i<set_size; i++)
    {
        if(point == set[i])
        {
            return RET_TRUE;
        }        
    }
    return RET_FALSE;
}

//两点是否在一条直线上
int striangle_cout::is_one_line(int a, int b)
{
    for(int i=0; i<m_line_num; i++)
    {
        if(     ( RET_TRUE == is_point_in_set( &m_point_on_line[i][0], LINE_POINT_MAX, a) )
             && ( RET_TRUE == is_point_in_set( &m_point_on_line[i][0], LINE_POINT_MAX, b) )
          )
        {
            return RET_TRUE;
        }
    }
    
    return RET_FALSE;
}

//三点是否在一条直线上
int striangle_cout::is_one_line(int a, int b, int c)
{    
    for(int i=0; i<m_line_num; i++)
    {
        if(     ( RET_TRUE == is_point_in_set( &m_point_on_line[i][0], LINE_POINT_MAX, a) )
             && ( RET_TRUE == is_point_in_set( &m_point_on_line[i][0], LINE_POINT_MAX, b) )
             && ( RET_TRUE == is_point_in_set( &m_point_on_line[i][0], LINE_POINT_MAX, c) )
          )
        {
            return RET_TRUE;
        }
    }
    
    return RET_FALSE;
}


//三角形点数是否是新的
int striangle_cout::is_new_striangle(int a, int b, int c)
{
    for(int i=0; i<m_save_striange.count; i++)
    {
        if(     ( RET_TRUE == is_point_in_set( &m_save_striange.striange_rem[i][0], 3, a) )
             && ( RET_TRUE == is_point_in_set( &m_save_striange.striange_rem[i][0], 3, b) )
             && ( RET_TRUE == is_point_in_set( &m_save_striange.striange_rem[i][0], 3, c) )
          )
        {
            return RET_FALSE;
        }
    }
    
    return RET_TRUE;
}

//输入三个点数，是否是不重复的三角形点数
int striangle_cout::triangle_recognize(int a, int b, int c)
{
    //1.是否有相同点
    if( (a == b) || (a == c) || (b == c) )
    {
        return RET_FALSE;
    }
    
    //2.是否在同一条线上
    if(RET_TRUE == is_one_line(a, b, c))
    {
        return RET_FALSE;
    }
    
    //3.是否两个点相互在同一条直线上
    if(    (RET_FALSE == is_one_line(a, b))
        || (RET_FALSE == is_one_line(b, c))
        || (RET_FALSE == is_one_line(a, c))
      )
    {
        return RET_FALSE;
    }
    
    //4.是否已经记录过该三角形
    if(RET_FALSE == is_new_striangle(a, b, c))
    {
        return RET_FALSE;
    }
    
    //是一个新的三角形，记录点数
    m_save_striange.striange_rem[m_save_striange.count][0] = a;
    m_save_striange.striange_rem[m_save_striange.count][1] = b;
    m_save_striange.striange_rem[m_save_striange.count][2] = c;
    m_save_striange.count++;
    
    return RET_TRUE;
} 

