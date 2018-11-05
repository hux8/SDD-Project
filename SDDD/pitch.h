#ifndef PITCH_H
#define PITCH_H

#include <stdlib.h>
#include <QString>
class Pitch {
    public:
        // Constructor
        Pitch (int date_, QString title_, QString content_) {
            date = date_;
            title = title_;
            content = content_;
        }

        // Accessors
         int get_date() { return date; }
         QString & get_title() { return title; }
         QString & get_content() { return content; }

        // Modifiers
        void modify_title (QString & title_) { title = title_; }
        void modify_content (QString & content_) { content = content_; }

        bool whetherInTitle(std::string sName);
        bool whetherInDescription(std::string sName);

        bool search(std::string sName);

    private:
        int date;
        QString title;
        QString content;
};


#endif // PITCH_H
