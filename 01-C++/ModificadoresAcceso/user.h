#ifndef user_h
#define user_h

#include <string>

class User {
    // private
    private : std::string name;
    private : std::string email;
    private : std::string password;
    
    // public
    public : User(std::string name, std::string email, std::string password) {
        this->name = name;
        this->email = email;
        this->password = password;
    }
    public : std::string getName() {
        return this->name;
    }
    public : std::string getEmail() {
        return this->email;
    }
    
    public : std::string getPassword(std::string email) {
        if(email == this->email) {
            return this->password;
        }
        return "El email no coincide con el registrado.";
    }
};



#endif