#ifndef __pitch_h_
#define __pitch_h_

class Pitch {
    public:
        // Constructor
        Pitch (int date_, const std::string & title_, const std::string & content_) {
            date = date_;
            title = title_;
            content = content_;
        }

        // Accessors
        const int get_date() const { return date; }
        const std::string & get_title() const { return title; }
        const std::string & get_content() const { return content; }

        // Modifiers
        void Pitch::modify_title (const std::string & title_) { title = title_; };
        void Pitch::modify_content (const std::string & content_); { content = content_; }

        /**
         * Defines the "<" operator for this class
         * 
         * @param p1, p2: Pitches being compared
         * @returns: TRUE if p1.date < p2.date, FALSE otherwise
         */
        bool operator<(const Pitch& p1, const Pitch& p2) {
            return p1.get_date() < p2.get_date();
        }

    private:
        int date;
        std::string titile;
        std::string content;
}

#endif
