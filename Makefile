CC = gcc
BUILD_DIR = build

SRC = main fight affichage createursquad textures btn weapons personnages
OBJ = $(addprefix $(BUILD_DIR)/, $(addsuffix .o, $(SRC)))

# Détection de l'OS
ifeq ($(OS),Windows_NT)
	CFLAGS = -Iinclude
	LDFLAGS = -Llib -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf
	RM = del /Q
	MKDIR = if not exist $(BUILD_DIR) mkdir $(BUILD_DIR)
	SEP = \\
	EXEC = exec.exe
	RUN = .\\exec.exe
else
	CFLAGS = `sdl2-config --cflags`
	LDFLAGS = `sdl2-config --libs` -lSDL2_image -lSDL2_ttf
	RM = rm -f
	MKDIR = mkdir -p $(BUILD_DIR)
	SEP = /
	EXEC = exec
	RUN = ./exec
endif

all: $(EXEC)

$(BUILD_DIR):
	$(MKDIR)

$(BUILD_DIR)/main.o: main.c head.h personnages.h fight.h createursquad.h weapons.h btn.h textures.h affichage.h | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c main.c -o $@

$(BUILD_DIR)/fight.o: fight.c head.h fight.h personnages.h affichage.h btn.h | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c fight.c -o $@

$(BUILD_DIR)/affichage.o: affichage.c affichage.h textures.h head.h createursquad.h fight.h | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c affichage.c -o $@

$(BUILD_DIR)/createursquad.o: createursquad.c createursquad.h head.h btn.h | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c createursquad.c -o $@

$(BUILD_DIR)/textures.o: textures.c textures.h head.h | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c textures.c -o $@

$(BUILD_DIR)/btn.o: btn.c head.h | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c btn.c -o $@

$(BUILD_DIR)/weapons.o: weapons.c weapons.h | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c weapons.c -o $@

$(BUILD_DIR)/personnages.o: personnages.c head.h personnages.h textures.h | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c personnages.c -o $@

$(EXEC): $(OBJ)
	$(CC) $(OBJ) -o $@ $(LDFLAGS)

clean:
	-$(RM) $(BUILD_DIR)$(SEP)*.o
	-$(RM) $(EXEC)

run: $(EXEC)
	@echo Exécution du programme...
	@$(RUN)
