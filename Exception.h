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
        std::string tmpLineString = "Deck File Error: File format error in line " + std::to_string(m_lineNumber);
        const char* tmpLineChar = tmpLineString.c_str();
        return tmpLineChar;
        /*std::string line = std::to_string(m_lineNumber);
        return (const char*) "Deck File Error: File format error in line " + line.c_str();*/
    }
private:
    int m_lineNumber;
};

#endif //EX4_EXCEPTION_H
