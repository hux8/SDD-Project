#include "pitch.h"

#include <cctype>
#include<algorithm>

// Constructors
Pitch::Pitch() {
    date = 0;
    title = "";
    content = "";
}

Pitch::Pitch (int date_, const std::string & title_, const std::string & content_) {
    date = date_;
    title = title_;
    content = content_;
}

// Modifiers
void Pitch::modify_title (const std::string & title_) {
    title = title_;
}

void Pitch::modify_content (const std::string & content_) {
    content = content_;
}

// Search Functions
bool Pitch::inTitle (std::string sWord) const {
    std::string temp = title;
    std::transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
    std::transform(sWord.begin(), sWord.end(), sWord.begin(), ::tolower);
    if (temp.find(sWord) != std::string::npos) {
        return true;
    }
    return false;
}

bool Pitch::inContent (std::string sWord) const {
    std::string temp = content;
    std::transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
    std::transform(sWord.begin(), sWord.end(), sWord.begin(), ::tolower);
    if (temp.find(sWord) != std::string::npos) {
        return true;
    }
    return false;
}

// Operators
/*
 * Defines the "<" operator for this class
 * 
 * @param p1, p2: Pitches being compared
 * @returns: TRUE if p1.date < p2.date, FALSE otherwise
 */
bool Pitch::operator < (const Pitch & p1, const Pitch & p2) const {
    return p1.get_date() < p2.get_date();
}
