NAME		= attack
	
CC			= c++
FLAGS		= -Wall -Wextra -Werror -std=c++98
RM			= rm -rf
ART1	= "\t\t\t\t\t\t ██████╗██████╗ ██████╗     ███╗   ███╗ ██████╗ ██████╗ ██╗   ██╗██╗     ███████╗\n\t\t\t\t\t\t██╔════╝██╔══██╗██╔══██╗    ████╗ ████║██╔═══██╗██╔══██╗██║   ██║██║     ██╔════╝\n\t\t\t\t\t\t██║     ██████╔╝██████╔╝    ██╔████╔██║██║   ██║██║  ██║██║   ██║██║     █████╗  \n\t\t\t\t\t\t██║     ██╔═══╝ ██╔═══╝     ██║╚██╔╝██║██║   ██║██║  ██║██║   ██║██║     ██╔══╝  \n\t\t\t\t\t\t╚██████╗██║     ██║         ██║ ╚═╝ ██║╚██████╔╝██████╔╝╚██████╔╝███████╗███████╗\n\t\t\t\t\t\t ╚═════╝╚═╝     ╚═╝         ╚═╝     ╚═╝ ╚═════╝ ╚═════╝  ╚═════╝ ╚══════╝╚══════╝\n\n"
MYNAME	= "\033[36m\t\t\t\t\t\t\t\t\t 𝐙 𝐎 𝐈 𝐑 𝐉 𝐎 𝐍 _ 𝐒 𝐎 𝐁 𝐈 𝐑 𝐎 𝐕 \033[0m"

OBJDIR = .objFiles

FILES		= main Weapon HumanA HumanB

SRC			= $(FILES:=.cpp)
OBJ			= $(addprefix $(OBJDIR)/, $(FILES:=.o))
HEADER		= Weapon.hpp HumanA.hpp HumanB.hpp

#Colors:
GREEN		=	\e[92;5;118m
YELLOW		=	\e[93;5;226m
GRAY		=	\e[33;2;37m
RESET		=	\e[0m
CURSIVE		=	\e[33;3m

#Debug 
ifeq ($(DEBUG), 1)
   OPTS = -g
endif

.PHONY: all clean fclean re bonus norm

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	@$(CC) $(OBJ) $(OPTS) -o $(NAME)
	clear
	@echo $(ART1) $(MYNAME)
	@printf "$(_SUCCESS) $(GREEN)- Executable ready.\n$(RESET)"

$(OBJDIR)/%.o: %.cpp $(HEADER)
	@mkdir -p $(dir $@)
	@$(CC) $(FLAGS) $(OPTS) -c $< -o $@

clean:
	@$(RM) $(OBJDIR) $(OBJ)
	clear
	@echo $(ART1) $(MYNAME)
	@printf "$(YELLOW)    - Object files removed.$(RESET)\n"

fclean: clean
	@$(RM) $(NAME)
	clear
	@echo $(ART1) $(MYNAME)
	@printf "$(YELLOW)    - Executable removed.$(RESET)\n"

re: fclean all
