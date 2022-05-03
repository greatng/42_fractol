NAME			=	fractol
LEAKS			=	-fsanitize=address -fno-omit-frame-pointer
CC			=	gcc
CFLAGS			=	-Wall -Wextra -Werror
RM			=	rm -rf

HEADER_DIR		=	includes
HEADER			=	fractol
HEADERS			=	$(addprefix $(HEADER_DIR)/, $(addsuffix .h, $(HEADER)))

SRC_DIR			=	src
SRC			=	frac_plot fractol mandelbrot julia burningship frac_hook \
					frac_color frac_scale frac_exit

SRCS 			=	$(addprefix $(SRC_DIR)/, $(addsuffix .c, $(SRC)))

OBJ_DIR			=	obj
OBJ			=	$(addprefix $(OBJ_DIR)/, $(addsuffix .o, $(SRC)))

ARCH			=	arch -x86_64
MLX			=	-Lmlx -lmlx -framework OpenGL -framework Appkit

LIBFT_PATH		=	./libft
LIBFT			=	$(LIBFT_PATH)/libft.a

GREEN = \033[38;5;2m
NORMAL = \033[38;5;255m
RED = \033[38;5;1m
BLUE = \033[38;5;4m
SALMON = \033[38;5;174m
HOTPINK = \033[38;5;168m

all:				$(NAME)

$(NAME):			$(LIBFT) $(OBJ)
					@echo "$(GREEN)Compiling:$(NORMAL)"
					$(ARCH) $(CC) $(CFLAGS) $(MLX) $(LIBFT) $(OBJ) $< -o $(NAME)

$(OBJ_DIR)/%.o:			$(SRC_DIR)/%.c $(HEADERS)
					@mkdir -p $(OBJ_DIR)
					@echo "$(GREEN)Compiling:$(NORMAL)"
					$(ARCH) $(CC) -c $< -o $@ 			
					
$(LIBFT):
					@make -C $(LIBFT_PATH) all

leaks:				$(LIBFT) $(OBJ) 
					@echo "$(GREEN)Compiling:$(NORMAL)"
					$(ARCH) $(CC) $(LEAKS) $(MLX) $(LIBFT) $(OBJ) $< -o $(NAME)

clean:
					@make -C $(LIBFT_PATH) clean
					@$(RM) $(NAME)
fclean:				clean
					@make -C $(LIBFT_PATH) fclean
					@$(RM) -rf $(NAME) $(OBJ) $(OBJ_DIR)
					@make pig

re:					fclean all

.PHONY:				all clean fclean re

pig:				
					@echo "$(SALMON)                         .....            :!????7!^:\n\
                   .^!J5PGGBGG5::~!77?77~:G&&&&&&&&#GY!.\n\
                 .?G#&&&&&&&&&B^G&&&&&&&B^G&&&&&&&&&&&#^\n\
                 .P&&&&&&&&&&#!?&&&&&&&&&J~B&&&&&&&&#Y^\n\
                  .JB&&&&&&&G!J&&&&&&&&&&&Y!YB###B5J??^\n\
                   ~??5GGG5?7P&&&&&&&&&&&&&#5JJJJJ5G&&#5^\n\
                 .J&&BPYYY5G&&&&&&&&&&&&&&&&&&&#&&&&&&&&#~\n\
                .Y&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&B^\n\
                !&&&&&&&&&&&&BG#&&&&&&&&&BJY#&&&&&&&&&&&&&P.\n\
               .5&&&&&&&&&&&#^ ?&&&&&&&&&5:^B&&&&&&&&&&&&&&Y.\n\
               ^#&&&&&&&&&&&&BPB$(HOTPINK)#BGGGGGGGBB$(SALMON)#&&&&&&&&&&&&&&&&J.\n\
              .5&&&&&&&&&&&&&$(HOTPINK)#BPPPP5PP55PPPPB$(SALMON)&&&&&&&&&&&&&&&&!\n\
              7&&&&&&&&&&&&&&$(HOTPINK)#PPPP?^5P!~PPPPG&$(SALMON)&&&#######&&&&&5.\n\
             .Y&&&&&#######&&&$(HOTPINK)BGPP55PPP5PPGB#$(SALMON)&&&#BBGBGBB##&&&B:\n\
              J&&&##BBBBBB##&&&&$(HOTPINK)#BBBBBB#PB$(SALMON)&&&&&##BGGPPGBB#&&&P.\n\
              :B&&#BBGPPGGB##&&&&#JYPPPJ?B&&&&&&#BBGGGBB##&&#!\n\
               ^G&&#BBGGGBB#&&&&&&#BPPGB&&&&&&&&########BBP!.\n\
                .?G########&&&&&&&&&&&&&&&&&&&&&&&&#G5YJJJYY5PY!.\n\
                   ^7J5GB#&&&&&&&&&&&&&&&&&&&&&&&&#YJPG##&&&&&@P.\n\
               :~!!777777?B&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&#GJ:\n\
             .J#&&&&&&&&&#&&&&&&&&&&&&&&&&&&&&&&&&&&&#BBP5?!^.\n\
             .7B#&&&&&&&&#&&&&&&&&&&&&&&&&&&&&&&&&&&&Y^.\n\
               .^~!777777Y#&&&&&&&&&&&&&&&&&&&&&&&&&&&?\n\
                        ~&&&&&&&&&&&&&&&&&&&&&&&&&&&&&P.\n\
                        ^#&&&&&&&&&&&&&&&&&&&&&&&&&&&&G.\n\
                         ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~^\n\
					  fract_ol$(NORMAL)"