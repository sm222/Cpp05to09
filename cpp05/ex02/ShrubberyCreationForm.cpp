#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm() {
  if (DEV3)
    std::cout << MAG << "[*]" << RESET << " void AForm" << std::endl;
}

// Default constructor
ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : 
AForm("ShrubberyCreation", 145, 137), _target(target) {
  if (DEV3)
    std::cout << GIT << "[*]" << RESET << " ShrubberyCreationForm Default constructor" << std::endl;
}

// Copy constructor
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other), _target(other.getTarget()) {
  if (DEV3)
    std::cout << YEL << "[*]" << RESET << " ShrubberyCreationForm Copy constructor" << std::endl;
  *this = other;
}

// Copy assignment overload
ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &rhs) {
  (void)rhs;
  if (DEV3)
    std::cout << ORG << "[*]" << RESET << " ShrubberyCreationForm Copy assignment overload" << std::endl;
  return *this;
}

// Default destructor
ShrubberyCreationForm::~ShrubberyCreationForm() {
  if (DEV3)
    std::cout << RED << "[*]" << RESET << " ShrubberyCreationForm Default destructor" << std::endl;
}

std::string ShrubberyCreationForm::getTarget(void) const {
  return(this->_target);
}


/// art form https://www.asciiart.eu/nature/other

void  ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
  canRun(executor);
  std::string file =  this->getTarget() + "_shrubbery";
  std::ofstream outfile;
  outfile.open(file.c_str());
  if (outfile.fail())
  {
    std::cout << "fail to open file" << std::endl;
    return ;
  }
  outfile << "                                                                                                " << std::endl;
  outfile << "                                                  ..                                            " << std::endl;
  outfile << "                            ..:#%%@@%*%#+%@@#++@@@@@%@@@@@@#*:.+ .                              " << std::endl;
  outfile << "                        .=*=*+=*=*:#-@@-:=*=#@@*-::-@@@%=-=**@%#@@@@%.                          " << std::endl;
  outfile << "                 ..:=*+%@*@@@@+=%@=:*=-+@@@--#+-#@@@+:..@@++%@@#+@-:=*@@@%=                     " << std::endl;
  outfile << "              =#@@@@%@%*@--*::@@@.%*:@@-:--===.+#:@@+*%@@=-@:+*@@:#@@@#@:*%%@*.                 " << std::endl;
  outfile << "            .@*-:*@+@@%-@:-@@@=.:=@@@@@@@@@@@@@@@*.-=::@@@%%*@:::#=*.@*:*#@@@@@@+               " << std::endl;
  outfile << "          +%#++@@%+%--::%#@@@%@@@@.:.:.-=:..:--..@@@@@#.=-:@+*-@-#@@+@====@@-=###@@.            " << std::endl;
  outfile << "        .%=*#==:..-::@@%:-*-+:-%+:=-%@@@@:-==@%@@@==@-=@@%:=-%+#@@==%@@@@@*==:-=@@@@@=          " << std::endl;
  outfile << "       ==*@+#@@#++-.@@@@*.+*..@.:@%@=..+-+@@@*##@=@@@#@@=%@@@*@=@=@-:.====+@@@@@@=-=*@%         " << std::endl;
  outfile << "      .%@@@%=+@*@@@@:=:-=@@@##-#%@=@*+@@@@@+@@@@@@%@@@*=@==:=@@#@@==@@@@@@=@=..-=@@@++@@:       " << std::endl;
  outfile << "     .*%@@#@@@@@@::@@-#@@@@:@-@@+@@@=--=@*:==+%=%%@=#@@@@@@@=-.:#@@@@=...=@+*#@@@@==@@#%.       " << std::endl;
  outfile << "   *@@@::+@@:.:%@=@=@@-@@=@*@:=@#%.@@@@+@+@@@%@@#=++==:==:=@*@*=#:==@@@@@@@@@@@+==@@%=%@@@      " << std::endl;
  outfile << "   :-:#-@=..@@@@--::=@+-.#*@@@.@=@@@==@#@@@*@@@@@@@@@@@@@*@@@@@@=+@@+@==@+====@@#+@@@@@==@#.    " << std::endl;
  outfile << "  %@%@@##@@#@%==:=*@@+#@@@@#=@@@@@%@@@*.:=@@@@@@@==+@@@@@@@@%-==+@@*@@@@%+@@@@@%#**#==@@@@@@.   " << std::endl;
  outfile << "  %@@=@@**==@@@@@@@#@*=-:=#%*@@=%%-@@#@=##%@@@-=#@@@@%@*%=@@=%@@*=@@##@@@@=+@@@@@@@@@@=+@#%=#+  " << std::endl;
  outfile << ".#--=@@--@@@@=@@::@%@%%@@@@@@@===#@*+=+*@#@@@@@@@@@@+@@@@@*=@@@@@@=@@@==#@@@@@@*##*#@#=@@%@@@@* " << std::endl;
  outfile << "%@@@@@@%@@@-@@@=@@-@=@@@===@@@@=@@@@@@@@@*@=-=====-=@@+=@#=@@@===@#%==+@@=+=*====%#@*@@@%@@@=@@ " << std::endl;
  outfile << "@#@@@@#=+=+#-=@@@:===@@@@=@+@@@@#@+%+*+*+@=#@@@@@@*@@=%@@==@@@@@@%#@@@@@@+%@@@@@@@@@@#@@@=--@+@ " << std::endl;
  outfile << ".@%@+=@@@@-+@@@@%%@@@@@=@@@@@@:@@@@@@@%=@@@@@@@=*#@@@@*=@@@@===@=@*#=@@@@@@@@@@==##==%%%@@@@%@: " << std::endl;
  outfile << " *-=@@=@@@@@@@%@@@@@@@@@@=#@=#%@@@@@=@@@@@@@+=@*%#=+#*#@@@@*@@@@==@@@@=@@@@@%%**%@@@@@%#*=@=*.  " << std::endl;
  outfile << " @+=@@@+==@@:--+@@@@-=#=+@@@@%@%@@@@@@@@%@@@#@@@@@@@@@*@@=@@@=#@@@@#===@@@@*#=@@@@@@@@@@@@@@@@  " << std::endl;
  outfile << " @@@@@@@@@@--@@@@@@==@@@@@@@@@%@@@@@@@@@@=*@@@@@@@@@@@@@@@@@@*@@=%#%@%@====@@@@+=+*%@@@@@@@@@-. " << std::endl;
  outfile << " .@@=-=#@@@*====*=@@@@@@@@@@@@@%@#%@=:=@@@@@@@@*=@@+@@@@@@@@@@@@@@@@@@@@@#@=-#@%@@+==*@@@@@@*   " << std::endl;
  outfile << "  .@@@@@**=@@@@@@@@@=-=@@@@@@@@@+@%==@@@+=@@@@@@@@@@@@@@@@@@@@@@@@@=+@@=@@@@@@%=*@@@@@@@=@#@@.  " << std::endl;
  outfile << "  .@@@@%=@@+-#%+%@@@=*@@=@@@@@@=#*@@@@#%@@@%==@++@@@@@@*+@@@@@@=@@@@#@@@@@@@@@@@@@@@@@@@@@@     " << std::endl;
  outfile << "   @@@@@=+@@@+#@@*@@@@@@@*@=*#@#=%%@+=@@@@@@@@@@@*@@*@@@@@@@===@@@@@=@@@@@@@@@@@@@@@*@@.        " << std::endl;
  outfile << "     *@@@@@#%@%=#@#+@#@@@@@@@@@@@@#%%-=@@@@@@@@@@#==@@@@@@@@@@@@@@+@@@@@@@*##@@@*+=*#@@         " << std::endl;
  outfile << "     .@@@@@@##%@@%@@=@@@@@@#+@@@==@@@@@@@@@@@@@@@@@@@@@@@@#@@@@@@=#===+@%*@@@@@@@@@@@.          " << std::endl;
  outfile << "           .-@@@@@*@@::=@@@*=@@=@@=@@+=@@*@@@@@@@@@@@@@@@+@==@@+=@@@@@@#*#%@@@@@@+%#+-@         " << std::endl;
  outfile << "     @@@@@@@@@@@@@@*%=@@@*#@#@@%:@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@=@@@@@@@%@@@@@%@@@@@**#@@@       " << std::endl;
  outfile << "    @@@@@@#**@@@#@@@@@@@@@@@@@@@@@@@@@@@@@*%@+#@@@#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*@@@@@@@      " << std::endl;
  outfile << "     @+#+..:--:-#@@@@@@@@@@@@@@@==*@@@@#@@@@@@@@=@@@@@@@@@@@@@@@@@@@@@@@@@#*=-==+##=.=#*@       " << std::endl;
  outfile << "     @*  @*+:.:-+:.:@#@@#@@%+@@@@@@@@@@%@@@@@@@@@@@@@@@@@@@@@@@@@@@@@#+:...+@@+...-=%  *@       " << std::endl;
  outfile << "     @*.:@@%+=@==@@@*#@@#-:=@=...*...:#@@%%#@#@@#@%%#@%*-..*@+:.%@-:=-:==**+..=@=+@@@:.%@       " << std::endl;
  outfile << "     @@@.#*+--@= .%=--*==:-@ ..%*:-=%#+.... . ==.. :...=#*-.-@=   @--*#@+=*@..+@:-+*#-@@@       " << std::endl;
  outfile << "        @@@@@@@=  -*=-@*#-*@ +.@@.+.@#+*#@%.- %@ : %@***@@.*.@%.= @=+%#@-=#+  =@@@@@@#          " << std::endl;
  outfile << "             :@@@@@@@@@@@++@ . @=.=.@#===@+ . %% . *@-+=%=.+.@. . @=#@@@@@@@@@@@.               " << std::endl;
  outfile << "                      :@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@=.                        " << std::endl;
  outfile << "                                                                                                " << std::endl;
  outfile << "                                                                                                " << std::endl;
  outfile.close();
}