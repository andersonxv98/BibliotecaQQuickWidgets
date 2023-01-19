#include "personaldata.h"

PersonalData::PersonalData(std::string name, int age, std::string email, std::string tel, std::string location)
{
    this->setName(name);
    this->setAge(age);
    this->setEmail(email);
    this->setTel(tel);
    this->setLocation(location);
}

std::string PersonalData::getName() const
{
    return name;
}

void PersonalData::setName(const std::string &newName)
{
    name = newName;
}

int PersonalData::getAge() const
{
    return age;
}

void PersonalData::setAge(int newAge)
{
    age = newAge;
}

std::string PersonalData::getEmail() const
{
    return email;
}

void PersonalData::setEmail(const std::string &newEmail)
{
    email = newEmail;
}

std::string PersonalData::getTel() const
{
    return tel;
}

void PersonalData::setTel(const std::string &newTel)
{
    tel = newTel;
}

std::string PersonalData::getLocation() const
{
    return location;
}

void PersonalData::setLocation(const std::string &newLocation)
{
    location = newLocation;
}
