#include <string>

using namespace std;

class date
{
public:
    date(string& data);
    date(u_short y, u_short m, u_short d)
        : year(y)
        , month(m)
        , day(d){};

private:
    u_short year = 0;
    u_short month = 0;
    u_short day = 0;
}

date::date(string& dateStr)
{
    
}