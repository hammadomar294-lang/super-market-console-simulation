#ifndef MANAGER_H
#define MANAGER_H

#include <string>
#include <stdexcept>
#include "classes/domain/user/User.h"   

using namespace std;


class Manager : public User
{
private:
    string Password;
    string Name;
    
    static int validateID(int id);
    static string validateName(const string& name);
    static string validatePassword(const string& password);
public:
    Manager(int id ,const string &name,const string &password);
    const string & GetName() const;  
    bool CheckPassword(const string & password) const;
};
#endif

