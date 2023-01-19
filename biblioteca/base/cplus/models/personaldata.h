#ifndef PERSONALDATA_H
#define PERSONALDATA_H

#include <string>



class PersonalData
{
public:
    PersonalData(std::string name,int age ,std::string email, std::string tel, std::string location);
    std::string getName() const;
    void setName(const std::string &newName);

    int getAge() const;
    void setAge(int newAge);

    std::string getEmail() const;
    void setEmail(const std::string &newEmail);

    std::string getTel() const;
    void setTel(const std::string &newTel);

    std::string getLocation() const;
    void setLocation(const std::string &newLocation);

private:
    std::string name;
    int age;
    std::string email;
    std::string tel;
    std::string location;
};

#endif // PERSONALDATA_H
