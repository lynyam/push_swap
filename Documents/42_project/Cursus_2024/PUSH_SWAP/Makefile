# Nom de l'exécutable
NAME = push_swap

# Répertoires
SRCS_DIR = src
OBJS_DIR = obj
INCLUDES_DIR = includes
LIB_DIR = lib
TESTS_DIR = tests

# Fichiers source
SRC_FILES = main.c \
            instruction.c \
            parsing.c \
	    utils.c \
	    sorting.c \
            stack_operations.c

# Construction des chemins pour les fichiers source et objets
SRCS = $(addprefix $(SRCS_DIR)/, $(SRC_FILES))
OBJS = $(addprefix $(OBJS_DIR)/, $(SRC_FILES:.c=.o))

# Commandes Make
all: $(NAME)

# Compilateur et options
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I $(INCLUDES_DIR)

# Compilation de l'exécutable final
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

# Compilation des fichiers objets
$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	@mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Nettoyage des fichiers objets
clean:
	rm -rf $(OBJS_DIR)

# Nettoyage complet (y compris l'exécutable)
fclean: clean
	rm -f $(NAME)

# Reconstruction complète
re: fclean all

# Tests
test: $(NAME)
	@mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) $(TESTS_DIR)/test_input.sh $(OBJS) -I $(INCLUDES_DIR) -o test_push_swap
	./test_push_swap

# Phony pour éviter des conflits avec des fichiers existants
.PHONY: all clean fclean re test

