NAME			=	ft_containers

SRCS			=	test_set.cpp

VPATH			=	.

OBJ_DIR			:=	build_files
OBJS 			=	$(patsubst %,$(OBJ_DIR)/%,$(SRCS:.cpp=.o))
DEPS			=	$(OBJS:.o=.d)
INC				=	-Iinclude/algorithm		\
					-Iinclude/functional	\
					-Iinclude/iterator 		\
					-Iinclude/map			\
					-Iinclude/set			\
					-Iinclude/utils			\
					-Iinclude/vector		\
					-Iinclude/xtree

CC				=	g++
CPP_FLAGS		=	-Wall -Wextra -Werror -std=c++98

all:				$(NAME)

$(NAME):			$(OBJS)
					$(CC) $(OBJS) $(INC) -o $(NAME)

$(OBJ_DIR)/%.o:		%.cpp
					@$(CC) -I$. $(CPP_FLAGS) -c $< -o $@

$(OBJS):		|	$(OBJ_DIR)

$(OBJ_DIR):
					@mkdir $(OBJ_DIR)

clean:
					rm -rf $(OBJ_DIR)

fclean:				clean
					rm -f $(NAME)

re:					fclean all

.PHONY:				all clean fclean re
-include			$(DEPS)