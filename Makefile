CC      := gcc
CFLAGS  := -lfl
SRC_DIR := src
BUILD   := ./build
OBJ_DIR := $(BUILD)/objects
APP_DIR := $(BUILD)
FLX_SRC := lex.yy.c

SRC := $(shell ls $(SRC_DIR)/*.c)
FLX := $(shell ls $(SRC_DIR)/*.l)
OBJ := $(SRC:%.c=$(OBJ_DIR)/%.o)
DEP := $(OBJ:.o=.d)

COMPILER := compiler
$(APP_DIR)/$(COMPILER): $(OBJ)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -o $@ $^
$(OBJ_DIR)/%.o:%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -MMD -o $@

LEXICAL_TEST := lexical-test
LEXICAL_SRC  := $(filter-out $(SRC_DIR)/main.c,$(SRC))

.PHONY: all build format clean flex info

all: format flex build $(APP_DIR)/$(COMPILER)

build:
	@mkdir -p $(BUILD)
	@mkdir -p $(OBJ_DIR)

NON_AUTOMATIC_SRC := $(filter-out $(SRC_DIR)/$(FLX_SRC),$(SRC))
NON_AUTOMATIC_SRC += lexical_test.c
format:
	clang-format -style=file -i $(NON_AUTOMATIC_SRC)

clean:
	-@rm -rvf $(OBJ_DIR)/*
	-@rm -rvf $(APP_DIR)/*

flex:
	flex -o $(SRC_DIR)/$(FLX_SRC) $(FLX)

info: flex
	@echo "[*] Sources:      $(SRC) "
	@echo "[*] Objects:      $(OBJ) "
	@echo "[*] Dependencies: $(DEP) "
