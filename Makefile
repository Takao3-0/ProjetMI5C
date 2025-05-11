CC = gcc
CFLAGS = -Iinclude
LDFLAGS = -Llib -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf
BUILD_DIR = build

SRC = main fight affichage createursquad textures btn weapons personnages
OBJ = $(addprefix $(BUILD_DIR)/, $(addsuffix .o, $(SRC)))

all: exec

$(BUILD_DIR):
	@if not exist $(BUILD_DIR) mkdir $(BUILD_DIR)

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

exec: $(OBJ)
	$(CC) $(OBJ) -o exec $(LDFLAGS)

clean:
	@if exist $(BUILD_DIR)\*.o (del /Q $(BUILD_DIR)\*.o) else (rm -f $(BUILD_DIR)/*.o || true)
	@if exist exec.exe (del /Q exec.exe) else (rm -f exec || true)

run: exec
	@echo Exécution du programme...
	@.\exec.exe

