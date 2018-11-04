#include <string>
#include <list>
#include <iostream>
#include <vector>
#include "project.h"

Project::Project()
{
    title = "";
    url = "";
    description = "";
    contactInfo = "";
    comment = "";
    addDate = "";
}

Project::Project(std::string t, std::string u, std::string d, std::string c1, std::string c2, std::string a, std::vector<std::string> f)
{
    title = t;
    url = u;
    description = d;
    contactInfo = c1;
    comment = c2;
    addDate = a;
    for (unsigned int i = 0; i < f.size(); i++)
    {
        features.push_back(f[i]);
    }
}

std::string Project::getTitle() const
{
    return title;
}

std::string Project::getUrl() const
{
    return url;
}

std::string Project::getDescription() const
{
    return description;
}

std::string Project::getContactInfo() const
{
    return contactInfo;
}

std::string Project::getComment() const
{
    return comment;
}

std::string Project::getAddDate() const
{
    return addDate;
}

std::vector<std::string> Project::getFeatures() const
{
    return features;
}

void Project::modifyTitle(std::string newTitle)
{
    title = newTitle;
}

void Project::modifyUrl(std::string newUrl)
{
    url = newUrl;
}

void Project::modifyDescription(std::string newDescription)
{
    description = newDescription;
}

void Project::modifyContactInfo(std::string newContactInfo)
{
    contactInfo = newContactInfo;
}

void Project::modifyComment(std::string newComment)
{
    comment = newComment;
}