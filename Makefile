main.o: src/main.c
	g++ src/main.c \
	src/print_menu/print_menu.c \
	src/create_list/create_list.c \
	src/add_product/add_product.c \
	-o bin/main.exe