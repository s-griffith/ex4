#ifndef EX4_EXCEPTION_H
#define EX4_EXCEPTION_H

#include <iostream>
#include <string>
#include <exception>


//----------------------------------Class DeckFileNotFound-----------------------------------------

class DeckFileNotFound : public std::exception {
public:
    const char* what() const noexcept override
    {
        return "Deck File Error: File not found";
    }    
};


//----------------------------------Class DeckFileInvalidSize--------------------------------------

class DeckFileInvalidSize : public std::exception {
public:
    const char* what() const noexcept override
    {
        return "Deck File Error: Deck size is invalid";
    }
};


//----------------------------------Class DeckFileFormatError--------------------------------------

class DeckFileFormatError : public std::exception {
public:
    //Constructor
    DeckFileFormatError(const int lineNum) :
        m_lineNumber(lineNum)
    {}

    const char* what() const noexcept override
    {
        const char* line = std::to_string(m_lineNumber).c_str();
        return("Deck File Error: File format error in line" + *line);
        //return ("Deck File Error: File format error in line" + to_string(m_lineNumber));
        //The original line gives a compilation error. to_string wanted a const char* and not basic_string. Need to check that this actually works out.
    }
private:
    int m_lineNumber;
};

#endif //EX4_EXCEPTION_H
