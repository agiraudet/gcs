# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agiraude <agiraude@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/06 15:43:27 by agiraude          #+#    #+#              #
#    Updated: 2022/12/15 15:10:15 by agiraude         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:=	libgcs.a

DEPS		:=	-lSDL2 -lSDL2_ttf

BUILD_DIR	:=	./build

SRCS_DIR	:=	./srcs

SRCS		:=	Elem.cpp \
				Widget.cpp \
				Button.cpp \
				Bloc.cpp \
				Root.cpp \
				Label.cpp \
				TextInput.cpp \
				TextField.cpp \
				Gui.cpp \
				Frame.cpp \
				utils.cpp

SRCS_GUI	:=	exampleGui.cpp

SRCS_ROOT	:=	exampleRoot.cpp

OBJS		:=	$(SRCS:%.cpp=$(BUILD_DIR)/%.o)

OBJS_GUI	:=	$(SRCS_GUI:%.cpp=$(BUILD_DIR)/%.o)

OBJS_ROOT	:=	$(SRCS_ROOT:%.cpp=$(BUILD_DIR)/%.o)

INC_DIRS	:=	./includes

INC_FLAGS	:=	$(addprefix -I, $(INC_DIRS))

CXXFLAGS	:=	-MD -Wall -Wextra -Werror -Wno-unused-parameter -Wno-unused-variable -Wno-unused-private-field -g $(INC_FLAGS)

CXX			:=	clang++

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

example: gui root

gui: $(OBJS) $(OBJS_GUI)
	$(CXX) $(CXXFLAGS) $(OBJS) $(OBJS_GUI) $(DEPS) -o exampleGui

root: $(OBJS) $(OBJS_ROOT)
	$(CXX) $(CXXFLAGS) $(OBJS) $(OBJS_ROOT) $(DEPS) -o exampleRoot

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(BUILD_DIR)/%.o: $(SRCS_DIR)/%.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@ 

all: $(NAME)

clean:
	rm -rf $(BUILD_DIR)

fclean: clean
	rm -f $(NAME)
	rm -f exampleRoot
	rm -f exampleGui

re: fclean all

-include $(OBJS:.o=.d)

.PHONY: all clean fclean re
