#include "pitch.h"

bool Pitch::whetherInTitle(std::string sName)
{
    std::string temp = title.toStdString();
    std::transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
    std::transform(sName.begin(), sName.end(), sName.begin(), ::tolower);
    if (temp.find(sName) != std::string::npos)
    {
        return true;
    }
    return false;
}

bool Pitch::whetherInDescription(std::string sName)
{
    std::string temp = content.toStdString();
    std::transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
    std::transform(sName.begin(), sName.end(), sName.begin(), ::tolower);
    if (temp.find(sName) != std::string::npos)
    {
        return true;
    }
    return false;
}

bool Pitch::search(std::string sName)
{
    return (whetherInTitle(sName)||whetherInDescription(sName));
}
