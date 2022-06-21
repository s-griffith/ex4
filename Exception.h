#ifndef EX4_EXCEPTION_H
#define EX4_EXCEPTION_H

#include <iostream>
#include <string>
#include <exception>

//----------------------------------Class DeckFileNotFound-----------------------------------------

class DeckFileNotFound : public std::exception {
public:
    /*
    * Provide information regarding what the error is
    *
    * @return
    *      const char* - description of exception
    */
    const char* what() const noexcept override
    {
        return "Deck File Error: File not found";
    }    
};

//----------------------------------Class DeckFileInvalidSize--------------------------------------

class DeckFileInvalidSize : public std::exception {
public:
    /*
    * Provide information regarding what the error is
    *
    * @return
    *      const char* - description of exception
    */
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
        m_message("Deck File Error: File format error in line ")
    {
        //Add to message the line number in the file where the error was found
        m_message += std::to_string(lineNum);
    }

    /*
    * Provide information regarding what the error is
    *
    * @return
    *      const char* - description of exception
    */
    const char* what() const noexcept override
    {
        return m_message.data();
    }
private:
    std::string m_message;
};

#endif //EX4_EXCEPTION_H
