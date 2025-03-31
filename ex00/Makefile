NAME = bureaucrat
CXX = clang++
CXXFLAGS = -Wextra -Wall -Werror
CXXFLAGS += -std=c++98
CXXFLAGS += -MMD
RM = rm -f

SRCS =	main.cpp Bereaucrat.cpp
OBJS = $(SRCS:.cpp=.o)
DEPS = $(OBJS:.o=.d)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	$(RM) -r $(OBJS) $(DEPS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
