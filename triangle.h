#define RET_TRUE  1
#define RET_FALSE 0

#define LINE_POINT_MAX  (20)

class striangle_cout
{
  public:
    striangle_cout();
    virtual ~striangle_cout();
    int triangle_recognize(int a, int b, int c);
    int get_striangle_cout()
    {
        return m_save_striange.count;
    }
    void set_line_num(int line_num)
    {
        m_line_num = line_num;
    }
    void get_poiner_of_line_array(const int (*point_on_line)[LINE_POINT_MAX])
    {
        m_point_on_line = point_on_line;
    }
    
  private:
    typedef struct 
    {
        int count;
        int striange_rem[100][3];
    }save_striange_t;
    
    save_striange_t m_save_striange;
    const int (*m_point_on_line)[LINE_POINT_MAX];
    int m_line_num;
    
  private:
    int is_point_in_set(const int *set, int set_size, int point);
    int is_one_line(int a, int b);
    int is_one_line(int a, int b, int c);
    int is_new_striangle(int a, int b, int c);
};