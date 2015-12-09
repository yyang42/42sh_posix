NAME = test.out
RENDU_PATH = ../..
FRAMEWORK_PATH = ../../../moulitest/testframework/v3
CC_LIBS = -ltowel -L $(RENDU_PATH)/libs/libtowel -I $(RENDU_PATH)/libs/libtowel/includes -I $(RENDU_PATH)/includes/builtin 
RENDU_SOURCE = $(shell find $(RENDU_PATH)/srcs -name "*.c" -type f -follow -print)
RENDU_MAKE_ARG =
