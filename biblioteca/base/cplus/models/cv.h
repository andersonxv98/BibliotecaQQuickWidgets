#ifndef CV_H
#define CV_H

#include "personaldata.h"
#include <QObject>

class Curriculum : public QObject
{Q_OBJECT
public:
    Curriculum();
    ~Curriculum();

    void addProfessionalExperience(QString exp);
    void addEducation(QString edu);
    void addLanguage(QString lang);
    void addSkill(QString skill);
    void addProgrammingLanguage(QString pl);
    void addFramaworkTech(QString frmTech);
    void addHobbie(QString hobbie);

    PersonalData getPersonalData();
    QList<QString> getProfessionalExperience();
    QList<QString> getEducation();
    QList<QString> getLanguages();
    QList<QString> getSkills();
    QList<QString> getProgrammingLanguages();
    QList<QString> getFrameworksTecnologies();
    QList<QString> getHobbies();

private:
                                             //Surname Name, Age, Email, Tel, Location
    PersonalData personalData= PersonalData("Marques Anderson", 24,"anderson_rockX@hotmail.com", "+5518991982841",
                                            "Prof. Kenjiro nishi, Presidente Prudente, Brazil");

    QList<QString> professionalExperience= {"Analysis and System Development: {Anglo Prudente - Presidente Prudente, BR}, {2021- Present}"};

    QList<QString> education= {"Analysis and System Development: January 2020 - Present"};

    QList<QString> languages = {"Português", "English", "Spanish"};

    QList<QString> skills= {"Analysis and Systems Development","OOP","Software Engineering",
                            "Project management","Programmer skills"};

    QList<QString> programmingLanguages = {"Python", "C#", "C++", "Php", "JavaScript"};

    QList<QString> frameworksTecnologies ={"Qt(qml, QWidgets)", "Laravel", "React",
                                           "Tensorflow Keras","Unity", "MySQl", "MongoDb",".Net","Maui"};

    QList<QString> hobbies = {"play guitar and violin","play video games","outdoor running"};

};
#endif // CV_H
