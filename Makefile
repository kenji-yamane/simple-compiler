CC      := gcc

CFLAGS := -ll -ly
OS     := $(shell uname -s)
ARCH   := $(shell uname -m)
ifeq ($(OS),Linux)
	ifeq ($(ARCH),x86_64)
		CFLAGS := -lfl
	endif
endif

SRC_DIR := src
BUILD   := ./build
OBJ_DIR := $(BUILD)/objects
APP_DIR := $(BUILD)
FLX_SRC := lex.yy.c
BSN_SRC := cminus.tab.c
WARNING := -w

TEST_DIR         := ./test
FIXTURES_DIR     := $(TEST_DIR)/fixtures
LEXICAL_TEST_DIR := $(TEST_DIR)/lexical
SYM_TAB_TEST_DIR := $(TEST_DIR)/symtab

SRC := $(shell ls $(SRC_DIR)/*.c)
FLX := $(shell ls $(SRC_DIR)/*.l)
BSN := $(shell ls $(SRC_DIR)/*.y)
OBJ := $(SRC:%.c=$(OBJ_DIR)/%.o)
DEP := $(OBJ:.o=.d)

COMPILER := compiler
$(APP_DIR)/$(COMPILER): $(OBJ)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -o $@ $^
$(OBJ_DIR)/%.o:%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(WARNING) $(INCLUDE) -c $< -MMD -o $@

LEXICAL_TEST := lexical-test
LEXICAL_SRC  := $(filter-out $(SRC_DIR)/main.c,$(SRC))
LEXICAL_SRC  += $(LEXICAL_TEST_DIR)/main.c
LEXICAL_OBJ  := $(LEXICAL_SRC:%.c=$(OBJ_DIR)/%.o)
$(APP_DIR)/$(LEXICAL_TEST): $(LEXICAL_OBJ)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -o $@ $^


SYM_TAB_TEST := symtab-test
SYM_TAB_SRC  := $(filter-out $(SRC_DIR)/main.c,$(SRC))
SYM_TAB_SRC  += $(SYM_TAB_TEST_DIR)/main.c
SYM_TAB_OBJ  := $(SYM_TAB_SRC:%.c=$(OBJ_DIR)/%.o)
$(APP_DIR)/$(SYM_TAB_TEST): $(SYM_TAB_OBJ)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -o $@ $^

.PHONY: all build format check-lexical clean flex bison info

all: bison flex format build $(APP_DIR)/$(COMPILER)

build:
	@mkdir -p $(BUILD)
	@mkdir -p $(OBJ_DIR)

NON_AUTOMATIC_SRC := $(filter-out $(SRC_DIR)/$(FLX_SRC),$(SRC))
NON_AUTOMATIC_SRC += $(LEXICAL_TEST_DIR)/main.c
HEADERS           := $(shell ls $(SRC_DIR)/*.h)
format:
	clang-format -style=file -i $(NON_AUTOMATIC_SRC) $(HEADERS)

check-lexical: $(APP_DIR)/$(LEXICAL_TEST)
	@$(BUILD)/$(LEXICAL_TEST) $(FIXTURES_DIR)/gcd.cm $(LEXICAL_TEST_DIR)/resulting-gcd-tokens.yml
	@$(BUILD)/$(LEXICAL_TEST) $(FIXTURES_DIR)/sort.cm $(LEXICAL_TEST_DIR)/resulting-sort-tokens.yml
	@cmp $(LEXICAL_TEST_DIR)/expected-gcd-tokens.yml $(LEXICAL_TEST_DIR)/resulting-gcd-tokens.yml
	@cmp $(LEXICAL_TEST_DIR)/expected-sort-tokens.yml $(LEXICAL_TEST_DIR)/resulting-sort-tokens.yml

clean:
	-@rm -rvf $(OBJ_DIR)/*
	-@rm -rvf $(APP_DIR)/*

flex:
	flex -o $(SRC_DIR)/$(FLX_SRC) $(FLX)

bison:
	bison -d $(BSN) -o $(SRC_DIR)/$(BSN_SRC)

info: flex
	@echo "[*] Sources:      $(SRC) "
	@echo "[*] Objects:      $(OBJ) "
	@echo "[*] Dependencies: $(DEP) "
