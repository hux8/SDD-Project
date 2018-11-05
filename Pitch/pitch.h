#ifndef __pitch_h_
#define __pitch_h_

#include <string>

class Pitch {
    public:
        // Constructors
        Pitch();
        Pitch (int date_, const std::string & title_, const std::string & content_);

        // Accessors
        const int get_date() const { return date; }
        const std::string & get_title() const { return title; }
        const std::string & get_content() const { return content; }

        // Modifiers
        void Pitch::modify_title (const std::string & title_);
        void Pitch::modify_content (const std::string & content_);

        // Search Functions
        bool inTitle (std::string sWord) const;
        bool inContent (std::string sWord) const;

        // Operators
        /*
         * Defines the "<" operator for this class
         * 
         * @param p1, p2: Pitches being compared
         * @returns: TRUE if p1.date < p2.date, FALSE otherwise
         */
        bool operator< (const Pitch & p1, const Pitch & p2) const;

    private:
        int date;
        std::string titile;
        std::string content;
}

#endif
