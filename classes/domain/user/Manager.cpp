#include "Manager.h"

int Manager::validateID(int id)
{
    if (id < 0)
        throw invalid_argument("Invalid manager ID");
     return id;
}

string Manager::validateName(const string& name)
{
    if (name.empty())
        throw invalid_argument("Manager name cannot be empty");

    return name;
}

string Manager::validatePassword(const string& password)
{
    if (password.empty())
        throw invalid_argument("Password cannot be empty");

    return password;
}

Manager::Manager(int  id,const string& name ,const string & password)
    : User(id) ,
      Name(validateName(name)),
      Password(validatePassword(password))

{}

const string & Manager::GetName() const
{
    return Name;
}

bool Manager::CheckPassword(const string &password) const
{
    return password == Password;
}
