#include "cv.h"

Curriculum::Curriculum()
{

}

Curriculum::~Curriculum()
{

}

void Curriculum::addProfessionalExperience(QString exp)
{   if(!this->professionalExperience.contains(exp)){
    this->professionalExperience.append(exp);
    }
    return;
}

void Curriculum::addEducation(QString edu)
{
    if(!this->education.contains(edu)){
       this->education.append(edu);
       }
    return;
}

void Curriculum::addLanguage(QString lang)
{
    if(!this->languages.contains(lang)){
       this->languages.append(lang);
       }
    return;
}

void Curriculum::addSkill(QString skill)
{
    if(!this->skills.contains(skill)){
       this->skills.append(skill);
       }
    return;
}

void Curriculum::addProgrammingLanguage(QString pl)
{
    if(!this->programmingLanguages.contains(pl)){
       this->programmingLanguages.append(pl);
       }
    return;
}

void Curriculum::addFramaworkTech(QString frmTech)
{
    if(!this->frameworksTecnologies.contains(frmTech)){
       this->frameworksTecnologies.append(frmTech);
       }
    return;
}

void Curriculum::addHobbie(QString hobbie)
{
    if(!this->hobbies.contains(hobbie)){
       this->hobbies.append(hobbie);
       }
    return;
}

QList<QString> Curriculum::getProfessionalExperience()
{
    return professionalExperience;
}

QList<QString> Curriculum::getEducation()
{
    return education;
}

QList<QString> Curriculum::getLanguages()
{
    return languages;
}

QList<QString> Curriculum::getSkills()
{
    return skills;
}

QList<QString> Curriculum::getProgrammingLanguages()
{
    return programmingLanguages;
}

QList<QString> Curriculum::getFrameworksTecnologies()
{
    return frameworksTecnologies;
}

QList<QString> Curriculum::getHobbies()
{
    return hobbies;
}
