#ifndef EX4_EXCEPTION_H
#define EX4_EXCEPTION_H

#include <iostream>
#include <string>
#include <exception>

//Why no cpp? Are we supposed to implement the functions directly inside the classes? Yes :) Says so in the exercise

//----------------------------------Class DeckFileNotFound-----------------------------------------

class DeckFileNotFound : public std::exception {
public:
    const char* what() const noexcept override;    
};

const char* DeckFileNotFound::what() const noexcept
{
    return "Deck File Error: File not found";
}

//----------------------------------Class DeckFileInvalidSize--------------------------------------

class DeckFileInvalidSize : public std::exception {
public:
    const char* what() const noexcept override;
};

const char* DeckFileInvalidSize::what() const noexcept
{
    return "Deck File Error: Deck size is invalid";
}

//----------------------------------Class DeckFileFormatError--------------------------------------

class DeckFileFormatError : public std::exception {
public:
    //Constructor
    DeckFileFormatError(const int lineNum);
    const char* what() const noexcept override;
private:
    int m_lineNumber;
};

DeckFileFormatError::DeckFileFormatError(const int lineNum) :
    m_lineNumber(lineNum)
{}

const char* DeckFileFormatError::what() const noexcept
{
    return ("Deck File Error: File format error in line" + to_string(m_lineNumber));
}

#endif //EX4_EXCEPTION_H
