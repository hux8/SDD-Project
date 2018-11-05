#ifndef PROJECT_H
#define PROJECT_H

#include <string>
#include <list>
#include <iostream>
#include <ctype.h>
#include <algorithm>
#include <vector>

class Project
{
public:
    Project();
    Project(std::string t, std::string u, std::string d, std::string c1, std::string c2, int a, std::vector<std::string> f);

    std::string getTitle() const;
    std::string getUrl() const;
    std::string getDescription() const;
    std::string getContactInfo() const;
    std::string getComment() const;
    int getAddDate() const;
    std::vector<std::string> getFeatures() const;

    void modifyTitle(std::string newTitle);
    void modifyUrl(std::string newUrl);
    void modifyDescription(std::string newDescription);
    void modifyContactInfo(std::string newContactInfo);
    void modifyComment(std::string newComment);
    void modifyFeatures(std::vector<std::string> newFeatures);

    bool whetherInTitle(std::string sName);
    bool whetherInDescription(std::string sName);
    bool whetherInFeatures(std::string sName);

    bool search(std::string sName);
private:
    std::string title;
    std::string url;
    std::string description;
    std::string contactInfo;
    std::string comment;
    int addDate;
    std::vector<std::string> features;
};

#endif // PROJECT_H
