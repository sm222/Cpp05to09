
#ifndef INTERN_HPP_
#define INTERN_HPP_

# include "AForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

# if (DEV == 1)
#  define DEV4 1
# else
#  define DEV4 0
# endif

// Class declaration
class Intern {
  public:
    Intern(void);
    Intern(const Intern &other);
    Intern &operator=(const Intern &rhs);
    ~Intern(void);
  //
    class NotRealForm : public std::exception {
      const char *what(void) const throw();
    };
    //
    AForm *makeForm(std::string type, std::string target);
    private:
      const std::string _name[3];
      typedef AForm *(*_Ft)(std::string);
      const  _Ft list[3];
      
};

///  typedef void (Harl::*Msg)(void);
//Msg msg[4];

#endif // INTERN_HPP_
