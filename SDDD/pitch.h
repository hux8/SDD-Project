#ifndef PITCH_H
#define PITCH_H

#include <stdlib.h>
#include <QString>
class Pitch {
    public:
        // Constructor
    /**
         * @brief Pitch constructor
         * @param date_ is used to set the date of the Pitch
         * @param title_ is used to set the title of the Pitch
         * @param content_ is used to set the content of the Pitch
         */
        Pitch (int date_, QString title_, QString content_) {
            date = date_;
            title = title_;
            content = content_;
        }

        // Accessors
        /**
          * @brief get_date is an accessor
          * @return date
          */
         int get_date() { return date; }

         /**
          * @brief get_title is an accessor
          * @return title
          */
         QString & get_title() { return title; }

         /**
          * @brief get_content is an accessor
          * @return content
          */
         QString & get_content() { return content; }

        // Modifiers

         /**
         * @brief modify_title modifies the title of the Pitch
         * @param title_ is the new title
         */
        void modify_title (QString & title_) { title = title_; }

        /**
         * @brief modify_content modifies the content of the Pitch
         * @param content_ is the new content
         */
        void modify_content (QString & content_) { content = content_; }


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
         * @brief search determines if the Pitch is relevent to the input string
         * @param sName is the input string to look for
         * @return true if it is relevent, false otherwise
         */
        bool search(std::string sName);

    private:
        int date;
        QString title;
        QString content;
};


#endif // PITCH_H
