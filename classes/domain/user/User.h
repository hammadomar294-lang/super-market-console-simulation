#include <string>

using namespace std;


class User
{
private:
    int Id;

public:
    User(int id) : Id(id) {}
    int GetId() const;
    virtual ~User();
};


