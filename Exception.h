#include <iostream>

//Why no cpp? Are we supposed to implement the functions directly inside the classes?

class DeckFileNotFound : public std::exception {
public:
    const char* what() const noexcept override;    
};

class DeckFileInvalidSize : public std::exception {
public:
    const char* what() const noexcept override;
};

const char* DeckFileNotFound::what() const noexcept
{
    return "Deck File Error: File not found";
}

const char* DeckFileInvalidSize::what() const noexcept
{
    return "Deck File Error: Deck size is invalid";
}