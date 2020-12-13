main.o: src/main.c
	g++ src/main.c \
	src/print_menu/print_menu.c \
	src/create_list/create_list.c \
	src/add_product/add_product.c \
	src/update_product/update_product.c \
	src/delete_product/delete_product.c \
	src/save_to_file/save_to_file.c \
	src/load_from_file/load_from_file.c \
	src/show_list/show_list.c \
	src/utils/iterate_list/iterate_list.c \
	-o bin/main.exe