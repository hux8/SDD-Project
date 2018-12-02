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
    /**
     * @brief Project is the default Project constructor
     */
    Project();

    /**
     * @brief Project is the Project constructor
     * @param t is the title
     * @param u is the url
     * @param d is the date
     * @param c1 is the contactInfo
     * @param c2 is the comment
     * @param a is the date
     * @param f is the features list
     */
    Project(std::string t, std::string u, std::string d, std::string c1, std::string c2, int a, std::vector<std::string> f);

    /**
     * @brief getTitle is the accessor to the title
     * @return title
     */
    std::string getTitle() const;

    /**
     * @brief getUrl is the accessor to the URL
     * @return url
     */
    std::string getUrl() const;

    /**
     * @brief getDescription is the accessor to the description
     * @return description
     */
    std::string getDescription() const;

    /**
     * @brief getContactInfo is the accessor to the contactInfo
     * @return contactInfo
     */
    std::string getContactInfo() const;

    /**
     * @brief getComment is the accessor to the comment
     * @return comment
     */
    std::string getComment() const;

    /**
     * @brief getAddDate is the accessor to the date
     * @return date
     */
    int getAddDate() const;

    /**
     * @brief getFeatures is the accessor to the features list
     * @return features
     */
    std::vector<std::string> getFeatures() const;


    /**
     * @brief modifyTitle modifies the title
     * @param newTitle is the new title
     */
    void modifyTitle(std::string newTitle);

    /**
     * @brief modifyTitle modifies the url
     * @param newTitle is the new url
     */
    void modifyUrl(std::string newUrl);

    /**
     * @brief modifyTitle modifies the description
     * @param newTitle is the new description
     */
    void modifyDescription(std::string newDescription);

    /**
     * @brief modifyTitle modifies the contactInfo
     * @param newTitle is the new contactInfo
     */
    void modifyContactInfo(std::string newContactInfo);

    /**
     * @brief modifyTitle modifies the comment
     * @param newTitle is the new comment
     */
    void modifyComment(std::string newComment);

    /**
     * @brief modifyTitle modifies the features
     * @param newTitle is the new features
     */
    void modifyFeatures(std::vector<std::string> newFeatures);


    /**
     * @brief whetherInTitle deteermines if an input string is in the title
     * @param sName is the input string to look for
     * @return true if the input string is in the title, false otherwise
     */
    bool whetherInTitle(std::string sName);

    /**
     * @brief whetherInDescription deteermines if an input string is in the description(content)
     * @param sName is the input string to look for
     * @return true if the input string is in the description(content), false otherwise
     */
    bool whetherInDescription(std::string sName);

    /**
     * @brief whetherInDescription deteermines if an input string is in the features list
     * @param sName is the input string to look for
     * @return true if the input string is in the features list, false otherwise
     */
    bool whetherInFeatures(std::string sName);

    /**
     * @brief search determines if the Pitch is relevent to the input string
     * @param sName is the input string to look for
     * @return true if it is relevent, false otherwise
     */
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
