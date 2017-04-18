#ifndef RUE_H_INCLUDED
#define RUE_H_INCLUDED

class Crossing
{
    private:
        int m_x;
        int m_y;
        std::vector<Crossing> m_sucessor;
        std::vector<std::string> m_street;


    public:
        getSucessor();
        getState();
        setSucessor(Crossing next);
        Corssing(int x, int y);
};

#endif // RUE_H_INCLUDED
